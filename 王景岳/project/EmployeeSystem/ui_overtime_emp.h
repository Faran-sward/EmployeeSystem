/********************************************************************************
** Form generated from reading UI file 'overtime_emp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERTIME_EMP_H
#define UI_OVERTIME_EMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Overtime_Emp
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *request;
    QPushButton *refresh;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QTableView *work_table;

    void setupUi(QWidget *Overtime_Emp)
    {
        if (Overtime_Emp->objectName().isEmpty())
            Overtime_Emp->setObjectName(QString::fromUtf8("Overtime_Emp"));
        Overtime_Emp->resize(898, 508);
        gridLayout = new QGridLayout(Overtime_Emp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        request = new QPushButton(Overtime_Emp);
        request->setObjectName(QString::fromUtf8("request"));
        request->setStyleSheet(QString::fromUtf8("#request {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255, 255, 255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px;\n"
"    border-radius: 10px;\n"
"}\n"
""));

        horizontalLayout->addWidget(request);

        refresh = new QPushButton(Overtime_Emp);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setStyleSheet(QString::fromUtf8("#refresh {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255, 255, 255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: rgb(98,98,98);\n"
"    border: 2px;\n"
"    border-radius: 10px;\n"
"}\n"
""));

        horizontalLayout->addWidget(refresh);

        label = new QLabel(Overtime_Emp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 6);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        work_table = new QTableView(Overtime_Emp);
        work_table->setObjectName(QString::fromUtf8("work_table"));
        work_table->setStyleSheet(QString::fromUtf8("QHeaderView::section:horizontal{\n"
"	background-color: rgb(85, 170, 255);\n"
"}\n"
"QHeaderView::section{\n"
"color:black;\n"
"}\n"
"QTableView\n"
"{\n"
"background-color: rgb(230, 230, 230);\n"
"alternate-background-color:rgb(255,255,255);\n"
"}"));

        gridLayout->addWidget(work_table, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(2, 10);

        retranslateUi(Overtime_Emp);

        QMetaObject::connectSlotsByName(Overtime_Emp);
    } // setupUi

    void retranslateUi(QWidget *Overtime_Emp)
    {
        Overtime_Emp->setWindowTitle(QCoreApplication::translate("Overtime_Emp", "Form", nullptr));
        request->setText(QCoreApplication::translate("Overtime_Emp", "\347\224\263\350\257\267", nullptr));
        refresh->setText(QCoreApplication::translate("Overtime_Emp", "\345\210\267\346\226\260", nullptr));
        label->setText(QCoreApplication::translate("Overtime_Emp", "\345\212\240\347\217\255\347\224\263\350\257\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Overtime_Emp: public Ui_Overtime_Emp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERTIME_EMP_H
