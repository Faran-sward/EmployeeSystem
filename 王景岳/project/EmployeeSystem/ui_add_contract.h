/********************************************************************************
** Form generated from reading UI file 'add_contract.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_CONTRACT_H
#define UI_ADD_CONTRACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add_contract
{
public:
    QPushButton *ToContractInfoBtn;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *upload;

    void setupUi(QWidget *Add_contract)
    {
        if (Add_contract->objectName().isEmpty())
            Add_contract->setObjectName(QString::fromUtf8("Add_contract"));
        Add_contract->resize(540, 470);
        ToContractInfoBtn = new QPushButton(Add_contract);
        ToContractInfoBtn->setObjectName(QString::fromUtf8("ToContractInfoBtn"));
        ToContractInfoBtn->setGeometry(QRect(390, 370, 131, 51));
        groupBox = new QGroupBox(Add_contract);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 491, 331));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 51, 41));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 30, 113, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 81, 41));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 80, 113, 41));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(120, 130, 113, 41));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(120, 180, 113, 41));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 130, 81, 41));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 180, 81, 41));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 230, 81, 41));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 230, 113, 41));
        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(120, 280, 226, 41));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 280, 81, 41));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(260, 38, 161, 31));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 90, 161, 31));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(260, 140, 161, 31));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(260, 190, 161, 31));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(260, 240, 161, 31));
        label_12 = new QLabel(Add_contract);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(160, 408, 211, 41));
        upload = new QPushButton(Add_contract);
        upload->setObjectName(QString::fromUtf8("upload"));
        upload->setGeometry(QRect(10, 370, 131, 51));

        retranslateUi(Add_contract);

        QMetaObject::connectSlotsByName(Add_contract);
    } // setupUi

    void retranslateUi(QWidget *Add_contract)
    {
        Add_contract->setWindowTitle(QCoreApplication::translate("Add_contract", "Form", nullptr));
        ToContractInfoBtn->setText(QCoreApplication::translate("Add_contract", "\350\277\224\345\233\236", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Add_contract", "\345\220\210\345\220\214", nullptr));
        label->setText(QCoreApplication::translate("Add_contract", "\345\267\245\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Add_contract", "\345\220\210\345\220\214\347\274\226\345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Add_contract", "\345\220\210\345\220\214\347\261\273\345\236\213\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Add_contract", "\347\224\237\346\225\210\346\227\266\351\227\264\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Add_contract", "\345\244\261\346\225\210\346\227\266\351\227\264\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Add_contract", "\345\220\210\345\220\214\351\223\276\346\216\245\357\274\232", nullptr));
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        upload->setText(QCoreApplication::translate("Add_contract", "\344\270\212\344\274\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_contract: public Ui_Add_contract {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_CONTRACT_H
