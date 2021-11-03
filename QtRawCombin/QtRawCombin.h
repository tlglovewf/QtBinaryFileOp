#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtRawCombin.h"
#include <QLabel>
class QtRawCombin : public QMainWindow
{
    Q_OBJECT

public:
    QtRawCombin(QWidget *parent = Q_NULLPTR);


public slots:
	void onCombine();

private:
    Ui::QtRawCombinClass ui;
	QLabel *m_label;
};
