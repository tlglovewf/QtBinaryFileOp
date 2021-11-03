/********************************************************************************
** Form generated from reading UI file 'QtRawCombin.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTRAWCOMBIN_H
#define UI_QTRAWCOMBIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtRawCombinClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtRawCombinClass)
    {
        if (QtRawCombinClass->objectName().isEmpty())
            QtRawCombinClass->setObjectName(QString::fromUtf8("QtRawCombinClass"));
        QtRawCombinClass->resize(600, 400);
        menuBar = new QMenuBar(QtRawCombinClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtRawCombinClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtRawCombinClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtRawCombinClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtRawCombinClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtRawCombinClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtRawCombinClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtRawCombinClass->setStatusBar(statusBar);

        retranslateUi(QtRawCombinClass);

        QMetaObject::connectSlotsByName(QtRawCombinClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtRawCombinClass)
    {
        QtRawCombinClass->setWindowTitle(QCoreApplication::translate("QtRawCombinClass", "QtRawCombin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtRawCombinClass: public Ui_QtRawCombinClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTRAWCOMBIN_H
