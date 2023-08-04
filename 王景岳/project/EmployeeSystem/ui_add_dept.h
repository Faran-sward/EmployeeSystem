/********************************************************************************
** Form generated from reading UI file 'add_dept.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_DEPT_H
#define UI_ADD_DEPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add_dept
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *numLab;
    QLineEdit *numEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *nameLab;
    QLineEdit *nameEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *buildLab;
    QLineEdit *buildEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *floorLab;
    QLineEdit *floorEdit;
    QSpacerItem *verticalSpacer_6;
    QLabel *errorText;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *Add_dept)
    {
        if (Add_dept->objectName().isEmpty())
            Add_dept->setObjectName(QString::fromUtf8("Add_dept"));
        Add_dept->resize(362, 274);
        gridLayout = new QGridLayout(Add_dept);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        widget = new QWidget(Add_dept);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        numLab = new QLabel(widget);
        numLab->setObjectName(QString::fromUtf8("numLab"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numLab->sizePolicy().hasHeightForWidth());
        numLab->setSizePolicy(sizePolicy);
        numLab->setMinimumSize(QSize(60, 21));

        horizontalLayout_4->addWidget(numLab);

        numEdit = new QLineEdit(widget);
        numEdit->setObjectName(QString::fromUtf8("numEdit"));
        numEdit->setMinimumSize(QSize(141, 21));

        horizontalLayout_4->addWidget(numEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        nameLab = new QLabel(widget);
        nameLab->setObjectName(QString::fromUtf8("nameLab"));
        sizePolicy.setHeightForWidth(nameLab->sizePolicy().hasHeightForWidth());
        nameLab->setSizePolicy(sizePolicy);
        nameLab->setMinimumSize(QSize(60, 21));

        horizontalLayout_5->addWidget(nameLab);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setMinimumSize(QSize(141, 21));

        horizontalLayout_5->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        buildLab = new QLabel(widget);
        buildLab->setObjectName(QString::fromUtf8("buildLab"));
        sizePolicy.setHeightForWidth(buildLab->sizePolicy().hasHeightForWidth());
        buildLab->setSizePolicy(sizePolicy);
        buildLab->setMinimumSize(QSize(60, 21));

        horizontalLayout_6->addWidget(buildLab);

        buildEdit = new QLineEdit(widget);
        buildEdit->setObjectName(QString::fromUtf8("buildEdit"));
        buildEdit->setMinimumSize(QSize(141, 21));

        horizontalLayout_6->addWidget(buildEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        floorLab = new QLabel(widget);
        floorLab->setObjectName(QString::fromUtf8("floorLab"));
        sizePolicy.setHeightForWidth(floorLab->sizePolicy().hasHeightForWidth());
        floorLab->setSizePolicy(sizePolicy);
        floorLab->setMinimumSize(QSize(60, 21));

        horizontalLayout_7->addWidget(floorLab);

        floorEdit = new QLineEdit(widget);
        floorEdit->setObjectName(QString::fromUtf8("floorEdit"));
        floorEdit->setMinimumSize(QSize(141, 21));

        horizontalLayout_7->addWidget(floorEdit);


        verticalLayout->addLayout(horizontalLayout_7);


        gridLayout->addWidget(widget, 0, 0, 1, 3);

        verticalSpacer_6 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 1, 1, 1, 1);

        errorText = new QLabel(Add_dept);
        errorText->setObjectName(QString::fromUtf8("errorText"));

        gridLayout->addWidget(errorText, 2, 0, 1, 3);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_4, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        addButton = new QPushButton(Add_dept);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(addButton, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 5, 1, 1, 1);


        retranslateUi(Add_dept);

        QMetaObject::connectSlotsByName(Add_dept);
    } // setupUi

    void retranslateUi(QWidget *Add_dept)
    {
        Add_dept->setWindowTitle(QCoreApplication::translate("Add_dept", "Form", nullptr));
        numLab->setText(QCoreApplication::translate("Add_dept", "\351\203\250\351\227\250\347\274\226\345\217\267\357\274\232", nullptr));
        numEdit->setInputMask(QString());
        numEdit->setPlaceholderText(QCoreApplication::translate("Add_dept", "\350\257\267\350\276\223\345\205\245\351\203\250\351\227\250\347\274\226\345\217\267", nullptr));
        nameLab->setText(QCoreApplication::translate("Add_dept", "\351\203\250\351\227\250\345\220\215\347\247\260\357\274\232", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("Add_dept", "\350\257\267\350\276\223\345\205\245\351\203\250\351\227\250\345\220\215\347\247\260", nullptr));
        buildLab->setText(QCoreApplication::translate("Add_dept", "\346\211\200\345\234\250\346\245\274\357\274\232", nullptr));
        buildEdit->setPlaceholderText(QCoreApplication::translate("Add_dept", "\350\257\267\350\276\223\345\205\245\346\211\200\345\234\250\346\245\274", nullptr));
        floorLab->setText(QCoreApplication::translate("Add_dept", "\346\211\200\345\234\250\346\245\274\345\261\202\357\274\232", nullptr));
        floorEdit->setPlaceholderText(QCoreApplication::translate("Add_dept", "\350\257\267\350\276\223\345\205\245\346\211\200\345\234\250\346\245\274\345\261\202", nullptr));
        errorText->setText(QString());
        addButton->setText(QCoreApplication::translate("Add_dept", "\345\210\233\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_dept: public Ui_Add_dept {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_DEPT_H
