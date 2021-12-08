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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetControlClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnLan;
    QPushButton *btnWLan;

    void setupUi(QMainWindow *NetControlClass)
    {
        if (NetControlClass->objectName().isEmpty())
            NetControlClass->setObjectName(QString::fromUtf8("NetControlClass"));
        NetControlClass->resize(300, 250);
        centralWidget = new QWidget(NetControlClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnLan = new QPushButton(centralWidget);
        btnLan->setObjectName(QString::fromUtf8("btnLan"));

        verticalLayout->addWidget(btnLan);

        btnWLan = new QPushButton(centralWidget);
        btnWLan->setObjectName(QString::fromUtf8("btnWLan"));

        verticalLayout->addWidget(btnWLan);

        NetControlClass->setCentralWidget(centralWidget);

        retranslateUi(NetControlClass);

        QMetaObject::connectSlotsByName(NetControlClass);
    } // setupUi

    void retranslateUi(QMainWindow *NetControlClass)
    {
        NetControlClass->setWindowTitle(QCoreApplication::translate("NetControlClass", "NetControl", nullptr));
        btnLan->setText(QCoreApplication::translate("NetControlClass", "Lan", nullptr));
        btnWLan->setText(QCoreApplication::translate("NetControlClass", "WLan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetControlClass: public Ui_NetControlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETCONTROL_H
