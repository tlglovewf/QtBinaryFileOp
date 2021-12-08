#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NetControl.h"

class NetControl : public QMainWindow
{
    Q_OBJECT

public:
    NetControl(QWidget *parent = Q_NULLPTR);


public slots:

	void onLan();

	void onWLan();

private:
    Ui::NetControlClass ui;
};
