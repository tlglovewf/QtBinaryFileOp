/********************************************************************************
** Form generated from reading UI file 'NetControl.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETCONTROL_H
#define UI_NETCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetControlClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NetControlClass)
    {
        if (NetControlClass->objectName().isEmpty())
            NetControlClass->setObjectName(QString::fromUtf8("NetControlClass"));
        NetControlClass->resize(600, 400);
        menuBar = new QMenuBar(NetControlClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        NetControlClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NetControlClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        NetControlClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NetControlClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        NetControlClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NetControlClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        NetControlClass->setStatusBar(statusBar);

        retranslateUi(NetControlClass);

        QMetaObject::connectSlotsByName(NetControlClass);
    } // setupUi

    void retranslateUi(QMainWindow *NetControlClass)
    {
        NetControlClass->setWindowTitle(QCoreApplication::translate("NetControlClass", "NetControl", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetControlClass: public Ui_NetControlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETCONTROL_H
