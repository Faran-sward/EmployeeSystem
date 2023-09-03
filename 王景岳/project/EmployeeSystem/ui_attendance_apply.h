/********************************************************************************
** Form generated from reading UI file 'attendance_apply.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDANCE_APPLY_H
#define UI_ATTENDANCE_APPLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Attendance_Apply
{
public:
    QLabel *label;

    void setupUi(QWidget *Attendance_Apply)
    {
        if (Attendance_Apply->objectName().isEmpty())
            Attendance_Apply->setObjectName(QString::fromUtf8("Attendance_Apply"));
        Attendance_Apply->resize(400, 300);
        label = new QLabel(Attendance_Apply);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 120, 69, 19));

        retranslateUi(Attendance_Apply);

        QMetaObject::connectSlotsByName(Attendance_Apply);
    } // setupUi

    void retranslateUi(QWidget *Attendance_Apply)
    {
        Attendance_Apply->setWindowTitle(QCoreApplication::translate("Attendance_Apply", "Form", nullptr));
        label->setText(QCoreApplication::translate("Attendance_Apply", "\350\200\203\345\213\244\347\224\263\350\257\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Attendance_Apply: public Ui_Attendance_Apply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDANCE_APPLY_H
