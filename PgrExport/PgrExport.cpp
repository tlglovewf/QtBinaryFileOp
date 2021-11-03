#include "PgrExport.h"

#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>

#include <QDir>
#include <qdebug.h>

#include "PgrFileHandler.h"
#include <QProcess>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrentRun>

#include <set>

PgrExport::PgrExport(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	QPushButton *btn = new QPushButton(ui.centralWidget);

	const int fixwidth = 200;
	const int fixheight = 30;
	const int spacex = 5;
	const int spacey = 5;
	btn->move(spacex, spacey);
	btn->setFixedWidth(fixwidth);
	btn->setFixedHeight(fixheight);
	btn->setText("select");

	m_bar = new QProgressBar(ui.centralWidget);

	m_bar->move(spacex, fixheight + spacey);
	m_bar->setFixedWidth(fixwidth);
	m_bar->setFixedHeight(fixheight);

	m_label = new QLabel(ui.centralWidget);
	m_label->move(spacex, (fixheight) << 1);
	m_label->setFixedWidth(fixwidth);
	m_label->setFixedHeight(fixheight << 1);
	m_label->setText("No Data");
	connect(btn, SIGNAL(clicked()), this, SLOT(btnSelect()));
	connect(this, SIGNAL(process(int)), this, SLOT(onProcess(int)));
	connect(this, SIGNAL(handle(const QString&)), this, SLOT(onHandle(const QString&)));
}


void PgrExport::onProcess(int v)
{
	if (m_bar)
	{
		m_bar->setValue(v);
	}
}

void PgrExport::onHandle(const QString &nm)
{
	if (m_label)
	{
		m_label->setText(QString::fromLocal8Bit("¥¶¿Ì: \n") + nm);
	 }
}

void PgrExport::btnSelect()
{
	static QString srcDirPath;
	srcDirPath = QFileDialog::getExistingDirectory(
		this, "choose src Directory",
		"/");

	QDir dir(srcDirPath);

	static QStringList files;
	files = dir.entryList({ "*.pgr" }, QDir::Files | QDir::NoDot | QDir::NoDotAndDotDot);

	if (files.empty())
	{
		QMessageBox::information(nullptr,"Warning", "Pgr file not found!", srcDirPath);
	}
	else
	{
		static std::vector<int>  indices;
		indices.clear();
		m_bar->setRange(0, files.size());
		m_bar->setValue(0);
		static std::set<int> curlsts;
		static std::map<int, QString>  ifiles;
		curlsts.clear();
		auto feture = QtConcurrent::run([this]()->void {
			int index = 0;
			for (auto file : files)
			{
				emit handle(file);
				if (!PgrFileHandler::ParseFile((srcDirPath + "/" + file).toStdString(), [this,&index](const ImageHeader &img) {
					indices.push_back(img.idgrab);
				}))
				{
					continue;
				}
				curlsts.insert(*indices.rbegin());
				ifiles.insert(std::make_pair(*indices.rbegin(), file));
				emit process(++index);
			}
			emit handle("Done!");
		});
		static QFutureWatcher<void> watcher;
		static bool sta = false;
		if (!sta)
		{
			connect(&watcher, &QFutureWatcher<void>::finished, this, [&]()
			{
				if (!indices.empty())
				{
					QString path = qApp->applicationDirPath() + "/pgrindex.txt";

					QFile logfile(path);

					if (logfile.open(QIODevice::WriteOnly))
					{
						for (auto u : indices)
						{
							logfile.write((QString::number(u) + "\n").toStdString().c_str());
							if (curlsts.count(u))
							{
								logfile.write((ifiles[u] + "\n").toStdString().c_str());
							}
						}
					}
					QProcess::startDetached("notepad", { path });

				}
			});
			sta = true;
		}
		watcher.setFuture(feture);
		
	}
}
