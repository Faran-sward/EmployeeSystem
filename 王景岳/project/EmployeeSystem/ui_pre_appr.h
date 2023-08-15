/********************************************************************************
** Form generated from reading UI file 'pre_appr.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRE_APPR_H
#define UI_PRE_APPR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pre_Appr
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Pre_Appr)
    {
        if (Pre_Appr->objectName().isEmpty())
            Pre_Appr->setObjectName(QString::fromUtf8("Pre_Appr"));
        Pre_Appr->resize(686, 539);
        verticalLayout = new QVBoxLayout(Pre_Appr);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, 15, 30, 30);
        widget = new QWidget(Pre_Appr);
        widget->setObjectName(QString::fromUtf8("widget"));
        QFont font;
        font.setPointSize(16);
        widget->setFont(font);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label->setFont(font1);

        horizontalLayout->addWidget(label);


        verticalLayout->addWidget(widget);

        tableWidget = new QTableWidget(Pre_Appr);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(Pre_Appr);

        QMetaObject::connectSlotsByName(Pre_Appr);
    } // setupUi

    void retranslateUi(QWidget *Pre_Appr)
    {
        Pre_Appr->setWindowTitle(QCoreApplication::translate("Pre_Appr", "Form", nullptr));
        label->setText(QCoreApplication::translate("Pre_Appr", "\345\276\205\345\256\241\346\211\271\347\274\226\345\210\266\347\224\263\350\257\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Pre_Appr", "\345\221\230\345\267\245\345\267\245\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Pre_Appr", "\345\221\230\345\267\245\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Pre_Appr", "\347\224\263\350\257\267\350\201\214\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Pre_Appr", "\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pre_Appr: public Ui_Pre_Appr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRE_APPR_H
