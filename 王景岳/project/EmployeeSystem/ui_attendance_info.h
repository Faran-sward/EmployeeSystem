/********************************************************************************
** Form generated from reading UI file 'attendance_info.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDANCE_INFO_H
#define UI_ATTENDANCE_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Attendance_Info
{
public:
    QLabel *label;

    void setupUi(QWidget *Attendance_Info)
    {
        if (Attendance_Info->objectName().isEmpty())
            Attendance_Info->setObjectName(QString::fromUtf8("Attendance_Info"));
        Attendance_Info->resize(400, 300);
        label = new QLabel(Attendance_Info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 100, 69, 19));

        retranslateUi(Attendance_Info);

        QMetaObject::connectSlotsByName(Attendance_Info);
    } // setupUi

    void retranslateUi(QWidget *Attendance_Info)
    {
        Attendance_Info->setWindowTitle(QCoreApplication::translate("Attendance_Info", "Form", nullptr));
        label->setText(QCoreApplication::translate("Attendance_Info", "\350\200\203\345\213\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Attendance_Info: public Ui_Attendance_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDANCE_INFO_H
