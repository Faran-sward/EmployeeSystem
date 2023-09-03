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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QPushButton *refresh;
    QPushButton *request;
    QTableView *work_table;
    QWidget *application;
    QLabel *label_3;
    QLineEdit *personEdit;
    QLabel *label_6;
    QLineEdit *numEdit;
    QLabel *label_4;
    QLineEdit *startEdit;
    QComboBox *start_m;
    QComboBox *start_h;
    QLabel *label_5;
    QLineEdit *endEdit;
    QComboBox *end_h;
    QComboBox *end_m;
    QPushButton *handapply;
    QPushButton *cancelapply;
    QLabel *label_2;

    void setupUi(QWidget *Overtime_Emp)
    {
        if (Overtime_Emp->objectName().isEmpty())
            Overtime_Emp->setObjectName(QString::fromUtf8("Overtime_Emp"));
        Overtime_Emp->resize(1216, 717);
        gridLayout = new QGridLayout(Overtime_Emp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(Overtime_Emp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

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
"#refresh:hover {\n"
" 	border: 2px;\n"
"	background-color: rgb(202, 202, 202);\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(refresh);

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
"#request:hover {\n"
" 	border: 2px ;\n"
"	background-color: rgb(85, 170, 255);\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(request);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 8);
        horizontalLayout->setStretch(4, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        work_table = new QTableView(Overtime_Emp);
        work_table->setObjectName(QString::fromUtf8("work_table"));
        work_table->setStyleSheet(QString::fromUtf8("QHeaderView::section:horizontal{\n"
"	background-color: rgb(85, 170, 255);\n"
"    border: 1px solid rgb(255, 255, 255);\n"
"    border-bottom: 0px; \n"
"	font: 12pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QTableView\n"
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

        gridLayout->addWidget(work_table, 1, 0, 1, 1);

        application = new QWidget(Overtime_Emp);
        application->setObjectName(QString::fromUtf8("application"));
        application->setMaximumSize(QSize(0, 16777215));
        application->setStyleSheet(QString::fromUtf8("#application{\n"
"	background-color: rgb(152, 152, 226);\n"
"    border-left: 4px solid rgb(85, 170, 255);\n"
"}"));
        label_3 = new QLabel(application);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 61, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        personEdit = new QLineEdit(application);
        personEdit->setObjectName(QString::fromUtf8("personEdit"));
        personEdit->setGeometry(QRect(80, 110, 71, 23));
        personEdit->setStyleSheet(QString::fromUtf8("#personEdit{\n"
"    border-radius: 4px;\n"
"	border: 1px solid black;\n"
"}"));
        label_6 = new QLabel(application);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(180, 110, 41, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        numEdit = new QLineEdit(application);
        numEdit->setObjectName(QString::fromUtf8("numEdit"));
        numEdit->setGeometry(QRect(230, 110, 111, 23));
        numEdit->setStyleSheet(QString::fromUtf8("#numEdit{\n"
"    border-radius: 4px;\n"
"	border: 1px solid black;\n"
"}"));
        label_4 = new QLabel(application);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 190, 81, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        startEdit = new QLineEdit(application);
        startEdit->setObjectName(QString::fromUtf8("startEdit"));
        startEdit->setGeometry(QRect(100, 190, 121, 23));
        startEdit->setStyleSheet(QString::fromUtf8("#startEdit{\n"
"    border-radius: 4px;\n"
"	border: 1px solid black;\n"
"}"));
        start_m = new QComboBox(application);
        start_m->addItem(QString());
        start_m->addItem(QString());
        start_m->setObjectName(QString::fromUtf8("start_m"));
        start_m->setGeometry(QRect(300, 190, 50, 23));
        start_m->setStyleSheet(QString::fromUtf8("#start_m{\n"
"    border:1px solid black;\n"
"    border-radius:4px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        start_h = new QComboBox(application);
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->addItem(QString());
        start_h->setObjectName(QString::fromUtf8("start_h"));
        start_h->setGeometry(QRect(230, 190, 50, 23));
        start_h->setStyleSheet(QString::fromUtf8("#start_h{\n"
"    border:1px solid black;\n"
"    border-radius:4px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        label_5 = new QLabel(application);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 270, 81, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        endEdit = new QLineEdit(application);
        endEdit->setObjectName(QString::fromUtf8("endEdit"));
        endEdit->setGeometry(QRect(100, 270, 121, 23));
        endEdit->setStyleSheet(QString::fromUtf8("#endEdit{\n"
"    border-radius: 4px;\n"
"	border: 1px solid black;\n"
"}"));
        end_h = new QComboBox(application);
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->addItem(QString());
        end_h->setObjectName(QString::fromUtf8("end_h"));
        end_h->setGeometry(QRect(230, 270, 50, 23));
        end_h->setStyleSheet(QString::fromUtf8("#end_h{\n"
"    border:1px solid black;\n"
"    border-radius:4px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        end_m = new QComboBox(application);
        end_m->addItem(QString());
        end_m->addItem(QString());
        end_m->setObjectName(QString::fromUtf8("end_m"));
        end_m->setGeometry(QRect(300, 270, 50, 23));
        end_m->setStyleSheet(QString::fromUtf8("#end_m{\n"
"    border:1px solid black;\n"
"    border-radius:4px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        handapply = new QPushButton(application);
        handapply->setObjectName(QString::fromUtf8("handapply"));
        handapply->setGeometry(QRect(70, 500, 90, 40));
        handapply->setStyleSheet(QString::fromUtf8("#handapply {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255, 255, 255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px;\n"
"    border-radius: 10px;\n"
"}\n"
"#handapply:hover {\n"
" 	border: 2px ;\n"
"	background-color: rgb(85, 170, 255);\n"
"}"));
        cancelapply = new QPushButton(application);
        cancelapply->setObjectName(QString::fromUtf8("cancelapply"));
        cancelapply->setGeometry(QRect(240, 500, 90, 40));
        cancelapply->setStyleSheet(QString::fromUtf8("#cancelapply {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255, 255, 255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: rgb(98,98,98);\n"
"    border: 2px;\n"
"    border-radius: 10px;\n"
"}\n"
"#cancelapply:hover {\n"
" 	border: 2px ;\n"
"	background-color: rgb(202, 202, 202);\n"
"}"));
        label_2 = new QLabel(application);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 40, 140, 27));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(application, 0, 1, 2, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 10);
        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 1);

        retranslateUi(Overtime_Emp);

        QMetaObject::connectSlotsByName(Overtime_Emp);
    } // setupUi

    void retranslateUi(QWidget *Overtime_Emp)
    {
        Overtime_Emp->setWindowTitle(QCoreApplication::translate("Overtime_Emp", "Form", nullptr));
        label->setText(QCoreApplication::translate("Overtime_Emp", "\345\212\240\347\217\255\347\224\263\350\257\267", nullptr));
        refresh->setText(QCoreApplication::translate("Overtime_Emp", "\345\210\267\346\226\260", nullptr));
        request->setText(QCoreApplication::translate("Overtime_Emp", "\347\224\263\350\257\267", nullptr));
        label_3->setText(QCoreApplication::translate("Overtime_Emp", "\347\224\263\350\257\267\344\272\272", nullptr));
        label_6->setText(QCoreApplication::translate("Overtime_Emp", "\345\267\245\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("Overtime_Emp", "\350\265\267\345\247\213\346\227\266\351\227\264", nullptr));
        start_m->setItemText(0, QCoreApplication::translate("Overtime_Emp", "00", nullptr));
        start_m->setItemText(1, QCoreApplication::translate("Overtime_Emp", "30", nullptr));

        start_h->setItemText(0, QCoreApplication::translate("Overtime_Emp", "00", nullptr));
        start_h->setItemText(1, QCoreApplication::translate("Overtime_Emp", "01", nullptr));
        start_h->setItemText(2, QCoreApplication::translate("Overtime_Emp", "02", nullptr));
        start_h->setItemText(3, QCoreApplication::translate("Overtime_Emp", "03", nullptr));
        start_h->setItemText(4, QCoreApplication::translate("Overtime_Emp", "04", nullptr));
        start_h->setItemText(5, QCoreApplication::translate("Overtime_Emp", "05", nullptr));
        start_h->setItemText(6, QCoreApplication::translate("Overtime_Emp", "06", nullptr));
        start_h->setItemText(7, QCoreApplication::translate("Overtime_Emp", "07", nullptr));
        start_h->setItemText(8, QCoreApplication::translate("Overtime_Emp", "08", nullptr));
        start_h->setItemText(9, QCoreApplication::translate("Overtime_Emp", "09", nullptr));
        start_h->setItemText(10, QCoreApplication::translate("Overtime_Emp", "10", nullptr));
        start_h->setItemText(11, QCoreApplication::translate("Overtime_Emp", "11", nullptr));
        start_h->setItemText(12, QCoreApplication::translate("Overtime_Emp", "12", nullptr));
        start_h->setItemText(13, QCoreApplication::translate("Overtime_Emp", "13", nullptr));
        start_h->setItemText(14, QCoreApplication::translate("Overtime_Emp", "14", nullptr));
        start_h->setItemText(15, QCoreApplication::translate("Overtime_Emp", "15", nullptr));
        start_h->setItemText(16, QCoreApplication::translate("Overtime_Emp", "16", nullptr));
        start_h->setItemText(17, QCoreApplication::translate("Overtime_Emp", "17", nullptr));
        start_h->setItemText(18, QCoreApplication::translate("Overtime_Emp", "18", nullptr));
        start_h->setItemText(19, QCoreApplication::translate("Overtime_Emp", "19", nullptr));
        start_h->setItemText(20, QCoreApplication::translate("Overtime_Emp", "20", nullptr));
        start_h->setItemText(21, QCoreApplication::translate("Overtime_Emp", "21", nullptr));
        start_h->setItemText(22, QCoreApplication::translate("Overtime_Emp", "22", nullptr));
        start_h->setItemText(23, QCoreApplication::translate("Overtime_Emp", "23", nullptr));

        label_5->setText(QCoreApplication::translate("Overtime_Emp", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        end_h->setItemText(0, QCoreApplication::translate("Overtime_Emp", "00", nullptr));
        end_h->setItemText(1, QCoreApplication::translate("Overtime_Emp", "01", nullptr));
        end_h->setItemText(2, QCoreApplication::translate("Overtime_Emp", "02", nullptr));
        end_h->setItemText(3, QCoreApplication::translate("Overtime_Emp", "03", nullptr));
        end_h->setItemText(4, QCoreApplication::translate("Overtime_Emp", "04", nullptr));
        end_h->setItemText(5, QCoreApplication::translate("Overtime_Emp", "05", nullptr));
        end_h->setItemText(6, QCoreApplication::translate("Overtime_Emp", "06", nullptr));
        end_h->setItemText(7, QCoreApplication::translate("Overtime_Emp", "07", nullptr));
        end_h->setItemText(8, QCoreApplication::translate("Overtime_Emp", "08", nullptr));
        end_h->setItemText(9, QCoreApplication::translate("Overtime_Emp", "09", nullptr));
        end_h->setItemText(10, QCoreApplication::translate("Overtime_Emp", "10", nullptr));
        end_h->setItemText(11, QCoreApplication::translate("Overtime_Emp", "11", nullptr));
        end_h->setItemText(12, QCoreApplication::translate("Overtime_Emp", "12", nullptr));
        end_h->setItemText(13, QCoreApplication::translate("Overtime_Emp", "13", nullptr));
        end_h->setItemText(14, QCoreApplication::translate("Overtime_Emp", "14", nullptr));
        end_h->setItemText(15, QCoreApplication::translate("Overtime_Emp", "15", nullptr));
        end_h->setItemText(16, QCoreApplication::translate("Overtime_Emp", "16", nullptr));
        end_h->setItemText(17, QCoreApplication::translate("Overtime_Emp", "17", nullptr));
        end_h->setItemText(18, QCoreApplication::translate("Overtime_Emp", "18", nullptr));
        end_h->setItemText(19, QCoreApplication::translate("Overtime_Emp", "19", nullptr));
        end_h->setItemText(20, QCoreApplication::translate("Overtime_Emp", "20", nullptr));
        end_h->setItemText(21, QCoreApplication::translate("Overtime_Emp", "21", nullptr));
        end_h->setItemText(22, QCoreApplication::translate("Overtime_Emp", "22", nullptr));
        end_h->setItemText(23, QCoreApplication::translate("Overtime_Emp", "23", nullptr));

        end_m->setItemText(0, QCoreApplication::translate("Overtime_Emp", "00", nullptr));
        end_m->setItemText(1, QCoreApplication::translate("Overtime_Emp", "30", nullptr));

        handapply->setText(QCoreApplication::translate("Overtime_Emp", "\346\217\220\344\272\244", nullptr));
        cancelapply->setText(QCoreApplication::translate("Overtime_Emp", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("Overtime_Emp", "\346\216\222\347\217\255\347\224\263\350\257\267\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Overtime_Emp: public Ui_Overtime_Emp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERTIME_EMP_H
