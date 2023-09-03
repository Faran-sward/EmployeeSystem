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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyAttendance
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *signin;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;
    QTableView *sch_table;
    QTableWidget *att_table;

    void setupUi(QWidget *MyAttendance)
    {
        if (MyAttendance->objectName().isEmpty())
            MyAttendance->setObjectName(QString::fromUtf8("MyAttendance"));
        MyAttendance->resize(976, 603);
        MyAttendance->setMaximumSize(QSize(16777215, 16777215));
        MyAttendance->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(MyAttendance);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(7);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(7, 12, 7, 7);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
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
"}\n"
"\n"
"#signin:hover {\n"
" 	border: 2px ;\n"
"	background-color: rgb(85, 170, 127);\n"
"}\n"
""));

        horizontalLayout->addWidget(signin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(MyAttendance);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton = new QPushButton(MyAttendance);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255, 255, 255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"	background-color: rgb(0, 0, 0);\n"
"    border: 2px ;\n"
"    border-radius: 10px;\n"
"}\n"
"#pushButton:hover {\n"
" 	border: 2px;\n"
"	background-color: rgb(122, 122, 122);\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 3);
        horizontalLayout->setStretch(4, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        sch_table = new QTableView(MyAttendance);
        sch_table->setObjectName(QString::fromUtf8("sch_table"));
        sch_table->setMaximumSize(QSize(16777215, 0));
        sch_table->setStyleSheet(QString::fromUtf8("QHeaderView::section{\n"
"color:black;\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QTableView{\n"
"color:black;\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"text-align: center;\n"
"}"));

        gridLayout->addWidget(sch_table, 6, 0, 1, 2);

        att_table = new QTableWidget(MyAttendance);
        att_table->setObjectName(QString::fromUtf8("att_table"));
        att_table->setStyleSheet(QString::fromUtf8("QHeaderView::section:horizontal{\n"
"	background-color: rgb(85, 170, 255);\n"
"    border: 1px solid rgb(255, 255, 255);\n"
"    border-bottom: 0px; \n"
"	font: 12pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QTableWidget\n"
"{\n"
"alternate-background-color: rgb(240,247,254);\n"
"background-color:rgb(255,255,255);\n"
"gridline-color: rgb(196,226,255);\n"
"border: 1px solid rgb(202,202,202);\n"
"text-align: center;\n"
"color:black;\n"
"font: 10pt \"\351\273\221\344\275\223\";\n"
"outline: 0px;\n"
"}"));

        gridLayout->addWidget(att_table, 2, 0, 1, 2);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(2, 10);
        gridLayout->setRowStretch(6, 4);

        retranslateUi(MyAttendance);

        QMetaObject::connectSlotsByName(MyAttendance);
    } // setupUi

    void retranslateUi(QWidget *MyAttendance)
    {
        MyAttendance->setWindowTitle(QCoreApplication::translate("MyAttendance", "Form", nullptr));
        signin->setText(QCoreApplication::translate("MyAttendance", "\350\200\203\345\213\244\347\255\276\345\210\260", nullptr));
        label->setText(QCoreApplication::translate("MyAttendance", "\350\200\203\345\213\244\350\256\260\345\275\225", nullptr));
        pushButton->setText(QCoreApplication::translate("MyAttendance", "\346\230\276\347\244\272\346\216\222\347\217\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyAttendance: public Ui_MyAttendance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYATTENDANCE_H
