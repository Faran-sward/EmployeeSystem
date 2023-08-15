/********************************************************************************
** Form generated from reading UI file 'vacation_emp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VACATION_EMP_H
#define UI_VACATION_EMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Vacation_Emp
{
public:
    QLabel *label;

    void setupUi(QWidget *Vacation_Emp)
    {
        if (Vacation_Emp->objectName().isEmpty())
            Vacation_Emp->setObjectName(QString::fromUtf8("Vacation_Emp"));
        Vacation_Emp->resize(400, 300);
        label = new QLabel(Vacation_Emp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 110, 69, 19));

        retranslateUi(Vacation_Emp);

        QMetaObject::connectSlotsByName(Vacation_Emp);
    } // setupUi

    void retranslateUi(QWidget *Vacation_Emp)
    {
        Vacation_Emp->setWindowTitle(QCoreApplication::translate("Vacation_Emp", "Form", nullptr));
        label->setText(QCoreApplication::translate("Vacation_Emp", "\344\274\221\345\201\207\347\224\263\350\257\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Vacation_Emp: public Ui_Vacation_Emp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VACATION_EMP_H
