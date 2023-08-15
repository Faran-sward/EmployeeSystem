/********************************************************************************
** Form generated from reading UI file 'myattendance.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYATTENDANCE_H
#define UI_MYATTENDANCE_H

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

class Ui_MyAttendance
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *signin;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QTableView *sch_table;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QTableView *att_table;

    void setupUi(QWidget *MyAttendance)
    {
        if (MyAttendance->objectName().isEmpty())
            MyAttendance->setObjectName(QString::fromUtf8("MyAttendance"));
        MyAttendance->resize(856, 586);
        gridLayout = new QGridLayout(MyAttendance);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(MyAttendance);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 4, 1, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        signin = new QPushButton(MyAttendance);
        signin->setObjectName(QString::fromUtf8("signin"));
        signin->setStyleSheet(QString::fromUtf8("#signin {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255, 255, 255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: rgb(85,170,0);\n"
"    border: 2px ;\n"
"    border-radius: 10px;\n"
"}"));

        horizontalLayout->addWidget(signin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(MyAttendance);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 2);
        horizontalLayout->setStretch(4, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 4);

        sch_table = new QTableView(MyAttendance);
        sch_table->setObjectName(QString::fromUtf8("sch_table"));
        sch_table->setStyleSheet(QString::fromUtf8("QHeaderView::section{\n"
"color:black;\n"
"}"));

        gridLayout->addWidget(sch_table, 5, 0, 1, 4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 4, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(horizontalSpacer_3, 3, 0, 1, 4);

        att_table = new QTableView(MyAttendance);
        att_table->setObjectName(QString::fromUtf8("att_table"));
        att_table->setStyleSheet(QString::fromUtf8("QHeaderView::section:horizontal{\n"
"	background-color: rgb(85, 170, 255);\n"
"}\n"
"QHeaderView::section{\n"
"color:black;\n"
"}\n"
"\n"
"QTableView\n"
"{\n"
"background-color: rgb(230, 230, 230);\n"
"alternate-background-color:rgb(255,255,255)\n"
"}"));

        gridLayout->addWidget(att_table, 2, 0, 1, 4);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(2, 10);
        gridLayout->setRowStretch(5, 3);

        retranslateUi(MyAttendance);

        QMetaObject::connectSlotsByName(MyAttendance);
    } // setupUi

    void retranslateUi(QWidget *MyAttendance)
    {
        MyAttendance->setWindowTitle(QCoreApplication::translate("MyAttendance", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("MyAttendance", "\346\216\222\347\217\255\350\241\250", nullptr));
        signin->setText(QCoreApplication::translate("MyAttendance", "\350\200\203\345\213\244\347\255\276\345\210\260", nullptr));
        label->setText(QCoreApplication::translate("MyAttendance", "\350\200\203\345\213\244\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyAttendance: public Ui_MyAttendance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYATTENDANCE_H
