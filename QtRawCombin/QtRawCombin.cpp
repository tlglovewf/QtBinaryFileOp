#include "QtRawCombin.h"
#include <QPushButton>
#include <QDir>
#include <QFileDialog>
#include <QApplication>
#include <QDebug>
#include <fstream>
#include <QLayout>
#include <QDesktopWidget>
QtRawCombin::QtRawCombin(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	
	auto item = qApp->desktop()->geometry();
	this->setGeometry(item.width() / 2, item.height() / 2, 200, 150);
	QVBoxLayout *layer = new QVBoxLayout;
	ui.centralWidget->setLayout(layer);

	QPushButton *btn = new QPushButton(ui.centralWidget);
	layer->addWidget(btn);

	btn->setText("Select");

	m_label = new QLabel(ui.centralWidget);

	/*m_label->setGeometry(0, 30, 30, 25);*/
	m_label->setText("Choose Raw Data Folder.");
	layer->addWidget(m_label);
	connect(btn, SIGNAL(clicked()), this, SLOT(onCombine()));
}


void QtRawCombin::onCombine()
{
	static QString srcDirPath;
	srcDirPath = QFileDialog::getExistingDirectory(
		this, "choose src Directory",
		"/");

	QDir dir(srcDirPath);

	static QStringList files;
	files = dir.entryList({ "*.raw" }, QDir::Files | QDir::NoDot | QDir::NoDotAndDotDot);
	
	if (files.size() > 1)
	{
		std::ofstream ofile((qApp->applicationDirPath()  + "/out.raw").toStdString(), std::ios::binary);
		
		for (size_t i = 0; i < files.size(); ++i)
		{
			m_label->setText("handle : " + files[i]);
			std::ifstream ifile((srcDirPath + "/" + files[i]).toStdString(), std::ios::binary);
			if (ifile.is_open())
			{
				std::string str((std::istreambuf_iterator<char>(ifile)),
					std::istreambuf_iterator<char>());
				ofile.write(str.c_str(), str.size());
			}
		}
	}

	m_label->setText("trans successfully!\n" + (qApp->applicationDirPath() + "/out.raw"));
}