/********************************************************************************
** Form generated from reading UI file 'PgrExport.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PGREXPORT_H
#define UI_PGREXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PgrExportClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PgrExportClass)
    {
        if (PgrExportClass->objectName().isEmpty())
            PgrExportClass->setObjectName(QString::fromUtf8("PgrExportClass"));
        PgrExportClass->resize(210, 140);
        PgrExportClass->setMinimumSize(QSize(210, 140));
        PgrExportClass->setMaximumSize(QSize(210, 140));
        centralWidget = new QWidget(PgrExportClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PgrExportClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PgrExportClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 210, 23));
        PgrExportClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PgrExportClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PgrExportClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PgrExportClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PgrExportClass->setStatusBar(statusBar);

        retranslateUi(PgrExportClass);

        QMetaObject::connectSlotsByName(PgrExportClass);
    } // setupUi

    void retranslateUi(QMainWindow *PgrExportClass)
    {
        PgrExportClass->setWindowTitle(QCoreApplication::translate("PgrExportClass", "PgrExport", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PgrExportClass: public Ui_PgrExportClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PGREXPORT_H
