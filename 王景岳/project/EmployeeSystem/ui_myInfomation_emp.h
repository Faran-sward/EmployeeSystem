/********************************************************************************
** Form generated from reading UI file 'myInfomation_emp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYINFOMATION_EMP_H
#define UI_MYINFOMATION_EMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyInfomation_Emp
{
public:
    QGridLayout *gridLayout;
    QWidget *bscwidget;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_20;
    QLineEdit *bscName;
    QSpacerItem *verticalSpacer_18;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_22;
    QLineEdit *bscId;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_26;
    QLineEdit *bscWorkstate;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_25;
    QLineEdit *bscIDNumber;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_27;
    QLineEdit *bscTele;
    QSpacerItem *verticalSpacer_14;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_21;
    QLineEdit *bscAddress;
    QSpacerItem *verticalSpacer_17;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *bscEnsure;
    QPushButton *bscChangeInfo;
    QPushButton *bscCancel;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_15;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_24;
    QLineEdit *bscSex;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_23;
    QLineEdit *bscSalary;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_20;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_19;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_29;
    QLineEdit *bscBirth;
    QSpacerItem *verticalSpacer_21;

    void setupUi(QWidget *MyInfomation_Emp)
    {
        if (MyInfomation_Emp->objectName().isEmpty())
            MyInfomation_Emp->setObjectName(QString::fromUtf8("MyInfomation_Emp"));
        MyInfomation_Emp->resize(800, 600);
        gridLayout = new QGridLayout(MyInfomation_Emp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bscwidget = new QWidget(MyInfomation_Emp);
        bscwidget->setObjectName(QString::fromUtf8("bscwidget"));
        bscwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_6 = new QGridLayout(bscwidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(20, 20, 20, 20);
        verticalSpacer_13 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_13, 0, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_6, 0, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_20 = new QLabel(bscwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setStyleSheet(QString::fromUtf8("font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';"));

        horizontalLayout_4->addWidget(label_20);

        bscName = new QLineEdit(bscwidget);
        bscName->setObjectName(QString::fromUtf8("bscName"));
        bscName->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bscName->sizePolicy().hasHeightForWidth());
        bscName->setSizePolicy(sizePolicy);
        bscName->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(bscName);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_18);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_22 = new QLabel(bscwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';"));

        horizontalLayout_5->addWidget(label_22);

        bscId = new QLineEdit(bscwidget);
        bscId->setObjectName(QString::fromUtf8("bscId"));
        bscId->setEnabled(true);
        sizePolicy.setHeightForWidth(bscId->sizePolicy().hasHeightForWidth());
        bscId->setSizePolicy(sizePolicy);
        bscId->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(bscId);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_26 = new QLabel(bscwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setStyleSheet(QString::fromUtf8("font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';"));

        horizontalLayout_6->addWidget(label_26);

        bscWorkstate = new QLineEdit(bscwidget);
        bscWorkstate->setObjectName(QString::fromUtf8("bscWorkstate"));
        bscWorkstate->setEnabled(true);
        sizePolicy.setHeightForWidth(bscWorkstate->sizePolicy().hasHeightForWidth());
        bscWorkstate->setSizePolicy(sizePolicy);
        bscWorkstate->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(bscWorkstate);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_25 = new QLabel(bscwidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';"));

        horizontalLayout_7->addWidget(label_25);

        bscIDNumber = new QLineEdit(bscwidget);
        bscIDNumber->setObjectName(QString::fromUtf8("bscIDNumber"));
        bscIDNumber->setEnabled(true);
        sizePolicy.setHeightForWidth(bscIDNumber->sizePolicy().hasHeightForWidth());
        bscIDNumber->setSizePolicy(sizePolicy);
        bscIDNumber->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(bscIDNumber);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_27 = new QLabel(bscwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setStyleSheet(QString::fromUtf8("font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';"));

        horizontalLayout_8->addWidget(label_27);

        bscTele = new QLineEdit(bscwidget);
        bscTele->setObjectName(QString::fromUtf8("bscTele"));
        bscTele->setEnabled(true);
        sizePolicy.setHeightForWidth(bscTele->sizePolicy().hasHeightForWidth());
        bscTele->setSizePolicy(sizePolicy);
        bscTele->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_8->addWidget(bscTele);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_14);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_21 = new QLabel(bscwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';"));

        horizontalLayout_9->addWidget(label_21);

        bscAddress = new QLineEdit(bscwidget);
        bscAddress->setObjectName(QString::fromUtf8("bscAddress"));
        bscAddress->setEnabled(true);
        sizePolicy.setHeightForWidth(bscAddress->sizePolicy().hasHeightForWidth());
        bscAddress->setSizePolicy(sizePolicy);
        bscAddress->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_9->addWidget(bscAddress);


        verticalLayout_2->addLayout(horizontalLayout_9);

        verticalSpacer_17 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_17);


        gridLayout_6->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_9, 1, 4, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_12, 2, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_5, 2, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        bscEnsure = new QPushButton(bscwidget);
        bscEnsure->setObjectName(QString::fromUtf8("bscEnsure"));
        sizePolicy.setHeightForWidth(bscEnsure->sizePolicy().hasHeightForWidth());
        bscEnsure->setSizePolicy(sizePolicy);
        bscEnsure->setMaximumSize(QSize(127, 18));
        bscEnsure->setStyleSheet(QString::fromUtf8("#bscEnsure {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#bscEnsure:hover {\n"
" 	border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"#bscEnsure:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_13->addWidget(bscEnsure);

        bscChangeInfo = new QPushButton(bscwidget);
        bscChangeInfo->setObjectName(QString::fromUtf8("bscChangeInfo"));
        sizePolicy.setHeightForWidth(bscChangeInfo->sizePolicy().hasHeightForWidth());
        bscChangeInfo->setSizePolicy(sizePolicy);
        bscChangeInfo->setMaximumSize(QSize(126, 18));
        bscChangeInfo->setStyleSheet(QString::fromUtf8("#bscChangeInfo {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#bscChangeInfo:hover {\n"
" 	border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"#bscChangeInfo:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_13->addWidget(bscChangeInfo);

        bscCancel = new QPushButton(bscwidget);
        bscCancel->setObjectName(QString::fromUtf8("bscCancel"));
        sizePolicy.setHeightForWidth(bscCancel->sizePolicy().hasHeightForWidth());
        bscCancel->setSizePolicy(sizePolicy);
        bscCancel->setMaximumSize(QSize(127, 18));
        bscCancel->setStyleSheet(QString::fromUtf8("#bscCancel {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#bscCancel:hover {\n"
" 	border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"#bscCancel:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_13->addWidget(bscCancel);


        gridLayout_6->addLayout(horizontalLayout_13, 3, 1, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 3, 4, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_4, 4, 1, 1, 1);

        verticalSpacer_15 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_15, 4, 3, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        graphicsView = new QGraphicsView(bscwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(91, 111));
        graphicsView->setMaximumSize(QSize(91, 111));

        gridLayout_5->addWidget(graphicsView, 1, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_24 = new QLabel(bscwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setStyleSheet(QString::fromUtf8("font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';"));

        horizontalLayout_10->addWidget(label_24);

        bscSex = new QLineEdit(bscwidget);
        bscSex->setObjectName(QString::fromUtf8("bscSex"));
        bscSex->setEnabled(true);
        sizePolicy.setHeightForWidth(bscSex->sizePolicy().hasHeightForWidth());
        bscSex->setSizePolicy(sizePolicy);
        bscSex->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_10->addWidget(bscSex);


        gridLayout_5->addLayout(horizontalLayout_10, 3, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 4, 1, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_23 = new QLabel(bscwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setStyleSheet(QString::fromUtf8("font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';"));

        horizontalLayout_12->addWidget(label_23);

        bscSalary = new QLineEdit(bscwidget);
        bscSalary->setObjectName(QString::fromUtf8("bscSalary"));
        bscSalary->setEnabled(true);
        sizePolicy.setHeightForWidth(bscSalary->sizePolicy().hasHeightForWidth());
        bscSalary->setSizePolicy(sizePolicy);
        bscSalary->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_12->addWidget(bscSalary);


        gridLayout_5->addLayout(horizontalLayout_12, 7, 0, 1, 3);

        horizontalSpacer_7 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        verticalSpacer_20 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_20, 6, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_7, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_19 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_19, 0, 1, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_29 = new QLabel(bscwidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setStyleSheet(QString::fromUtf8("font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';"));

        horizontalLayout_11->addWidget(label_29);

        bscBirth = new QLineEdit(bscwidget);
        bscBirth->setObjectName(QString::fromUtf8("bscBirth"));
        bscBirth->setEnabled(true);
        sizePolicy.setHeightForWidth(bscBirth->sizePolicy().hasHeightForWidth());
        bscBirth->setSizePolicy(sizePolicy);
        bscBirth->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_11->addWidget(bscBirth);


        gridLayout_5->addLayout(horizontalLayout_11, 5, 0, 1, 3);

        verticalSpacer_21 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_21, 8, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 3, 1, 1);


        gridLayout->addWidget(bscwidget, 0, 0, 1, 1);


        retranslateUi(MyInfomation_Emp);

        QMetaObject::connectSlotsByName(MyInfomation_Emp);
    } // setupUi

    void retranslateUi(QWidget *MyInfomation_Emp)
    {
        MyInfomation_Emp->setWindowTitle(QCoreApplication::translate("MyInfomation_Emp", "Widget", nullptr));
        label_20->setText(QCoreApplication::translate("MyInfomation_Emp", "\345\247\223    \345\220\215", nullptr));
        label_22->setText(QCoreApplication::translate("MyInfomation_Emp", "\345\267\245    \345\217\267", nullptr));
        label_26->setText(QCoreApplication::translate("MyInfomation_Emp", "\345\267\245\344\275\234\347\212\266\346\200\201", nullptr));
        label_25->setText(QCoreApplication::translate("MyInfomation_Emp", "\350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        label_27->setText(QCoreApplication::translate("MyInfomation_Emp", "\347\224\265\350\257\235\345\217\267\347\240\201", nullptr));
        label_21->setText(QCoreApplication::translate("MyInfomation_Emp", "\345\256\266\345\272\255\344\275\217\345\235\200", nullptr));
        bscEnsure->setText(QCoreApplication::translate("MyInfomation_Emp", "\347\241\256\350\256\244", nullptr));
        bscChangeInfo->setText(QCoreApplication::translate("MyInfomation_Emp", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        bscCancel->setText(QCoreApplication::translate("MyInfomation_Emp", "\345\217\226\346\266\210", nullptr));
        label_24->setText(QCoreApplication::translate("MyInfomation_Emp", "\346\200\247    \345\210\253", nullptr));
        label_23->setText(QCoreApplication::translate("MyInfomation_Emp", "\350\226\252    \350\265\204", nullptr));
        label_29->setText(QCoreApplication::translate("MyInfomation_Emp", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyInfomation_Emp: public Ui_MyInfomation_Emp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYINFOMATION_EMP_H
