/********************************************************************************
** Form generated from reading UI file 'dept_info.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPT_INFO_H
#define UI_DEPT_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "subpage/add_dept.h"

QT_BEGIN_NAMESPACE

class Ui_Dept_Info
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *addButton;
    Add_dept *application;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Dept_Info)
    {
        if (Dept_Info->objectName().isEmpty())
            Dept_Info->setObjectName(QString::fromUtf8("Dept_Info"));
        Dept_Info->resize(686, 539);
        gridLayout = new QGridLayout(Dept_Info);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(30, 15, 30, 30);
        widget = new QWidget(Dept_Info);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 40));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(100);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 5, 10, 5);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        addButton = new QPushButton(widget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setMinimumSize(QSize(100, 0));
        addButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(addButton);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        application = new Add_dept(Dept_Info);
        application->setObjectName(QString::fromUtf8("application"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(application->sizePolicy().hasHeightForWidth());
        application->setSizePolicy(sizePolicy2);
        application->setMaximumSize(QSize(0, 16777215));

        gridLayout->addWidget(application, 0, 1, 2, 1);

        tableWidget = new QTableWidget(Dept_Info);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);


        retranslateUi(Dept_Info);

        QMetaObject::connectSlotsByName(Dept_Info);
    } // setupUi

    void retranslateUi(QWidget *Dept_Info)
    {
        Dept_Info->setWindowTitle(QCoreApplication::translate("Dept_Info", "Form", nullptr));
        label->setText(QCoreApplication::translate("Dept_Info", "\351\203\250\351\227\250\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        addButton->setText(QCoreApplication::translate("Dept_Info", " \346\226\260\345\273\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Dept_Info", "\351\203\250\351\227\250\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Dept_Info", "\351\203\250\351\227\250\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Dept_Info", "\346\211\200\345\234\250\346\245\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Dept_Info", "\346\211\200\345\234\250\346\245\274\345\261\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Dept_Info", "\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dept_Info: public Ui_Dept_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPT_INFO_H
