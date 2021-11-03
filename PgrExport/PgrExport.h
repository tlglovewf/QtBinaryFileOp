#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PgrExport.h"
#include <QProgressBar>
#include <QLabel>
class PgrExport : public QMainWindow
{
    Q_OBJECT

public:
    PgrExport(QWidget *parent = Q_NULLPTR);
public slots:
	void btnSelect();

signals:
	void process(int v);
	void handle(const QString &nm);
public slots:
	void onProcess(int v);
	void onHandle(const QString &nm);
private:
    Ui::PgrExportClass ui;
	QProgressBar *m_bar = nullptr;
	QLabel		 *m_label = nullptr;
};
