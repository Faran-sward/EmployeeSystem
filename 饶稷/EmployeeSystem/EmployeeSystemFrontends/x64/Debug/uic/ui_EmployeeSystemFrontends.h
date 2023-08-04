/********************************************************************************
** Form generated from reading UI file 'EmployeeSystemFrontends.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEESYSTEMFRONTENDS_H
#define UI_EMPLOYEESYSTEMFRONTENDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeSystemFrontendsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EmployeeSystemFrontendsClass)
    {
        if (EmployeeSystemFrontendsClass->objectName().isEmpty())
            EmployeeSystemFrontendsClass->setObjectName(QString::fromUtf8("EmployeeSystemFrontendsClass"));
        EmployeeSystemFrontendsClass->resize(600, 400);
        menuBar = new QMenuBar(EmployeeSystemFrontendsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        EmployeeSystemFrontendsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EmployeeSystemFrontendsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        EmployeeSystemFrontendsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(EmployeeSystemFrontendsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        EmployeeSystemFrontendsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(EmployeeSystemFrontendsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        EmployeeSystemFrontendsClass->setStatusBar(statusBar);

        retranslateUi(EmployeeSystemFrontendsClass);

        QMetaObject::connectSlotsByName(EmployeeSystemFrontendsClass);
    } // setupUi

    void retranslateUi(QMainWindow *EmployeeSystemFrontendsClass)
    {
        EmployeeSystemFrontendsClass->setWindowTitle(QCoreApplication::translate("EmployeeSystemFrontendsClass", "EmployeeSystemFrontends", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeSystemFrontendsClass: public Ui_EmployeeSystemFrontendsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEESYSTEMFRONTENDS_H
