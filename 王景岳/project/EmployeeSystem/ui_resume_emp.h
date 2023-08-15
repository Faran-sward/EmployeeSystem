/********************************************************************************
** Form generated from reading UI file 'resume_emp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESUME_EMP_H
#define UI_RESUME_EMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Resume_Emp
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Resume_Emp)
    {
        if (Resume_Emp->objectName().isEmpty())
            Resume_Emp->setObjectName(QString::fromUtf8("Resume_Emp"));
        Resume_Emp->resize(800, 600);
        gridLayout = new QGridLayout(Resume_Emp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(50, 50, 50, 50);
        graphicsView = new QGraphicsView(Resume_Emp);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(Resume_Emp);

        QMetaObject::connectSlotsByName(Resume_Emp);
    } // setupUi

    void retranslateUi(QWidget *Resume_Emp)
    {
        Resume_Emp->setWindowTitle(QCoreApplication::translate("Resume_Emp", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Resume_Emp: public Ui_Resume_Emp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESUME_EMP_H
