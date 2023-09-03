/********************************************************************************
** Form generated from reading UI file 'allcontract_info.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLCONTRACT_INFO_H
#define UI_ALLCONTRACT_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Allcontract_Info
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *addButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Allcontract_Info)
    {
        if (Allcontract_Info->objectName().isEmpty())
            Allcontract_Info->setObjectName(QString::fromUtf8("Allcontract_Info"));
        Allcontract_Info->resize(905, 600);
        gridLayout = new QGridLayout(Allcontract_Info);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(Allcontract_Info);
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
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
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

        tableWidget = new QTableWidget(Allcontract_Info);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);


        retranslateUi(Allcontract_Info);

        QMetaObject::connectSlotsByName(Allcontract_Info);
    } // setupUi

    void retranslateUi(QWidget *Allcontract_Info)
    {
        Allcontract_Info->setWindowTitle(QCoreApplication::translate("Allcontract_Info", "Form", nullptr));
        label->setText(QCoreApplication::translate("Allcontract_Info", "\345\221\230\345\267\245\345\220\210\345\220\214\344\277\241\346\201\257", nullptr));
        addButton->setText(QCoreApplication::translate("Allcontract_Info", "\344\270\212\344\274\240", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Allcontract_Info", "\345\220\210\345\220\214\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Allcontract_Info", "\345\221\230\345\267\245\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Allcontract_Info", "\345\220\210\345\220\214\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Allcontract_Info", "\345\220\210\345\220\214\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Allcontract_Info", "\347\224\237\346\225\210\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Allcontract_Info", "\345\244\261\346\225\210\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Allcontract_Info", "\345\220\210\345\220\214\351\223\276\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Allcontract_Info: public Ui_Allcontract_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLCONTRACT_INFO_H
