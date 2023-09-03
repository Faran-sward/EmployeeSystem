/********************************************************************************
** Form generated from reading UI file 'deployment_emp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPLOYMENT_EMP_H
#define UI_DEPLOYMENT_EMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deployment_Emp
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_13;
    QWidget *Deployment_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_19;
    QWidget *ee;
    QGridLayout *gridLayout_2;
    QPushButton *ApplyPresentButton;
    QWidget *ApplyButtonWidget;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *dplmtChange;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *dplmtLeave;
    QSpacerItem *horizontalSpacer_17;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_18;
    QTableWidget *deployment;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLabel *applyType;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *applyNumber;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *applyPerson;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *applytime;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QWidget *applycontent;
    QVBoxLayout *verticalLayout_2;
    QWidget *resignationwidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *resignationlabel;
    QSpacerItem *horizontalSpacer_11;
    QWidget *changewidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *changelabel;
    QComboBox *changecombox;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *submitApply;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *cancelApply;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_13;
    QWidget *widget_9;
    QGridLayout *gridLayout_3;
    QLabel *applyIfSucceed;
    QSpacerItem *horizontalSpacer_14;

    void setupUi(QWidget *Deployment_Emp)
    {
        if (Deployment_Emp->objectName().isEmpty())
            Deployment_Emp->setObjectName(QString::fromUtf8("Deployment_Emp"));
        Deployment_Emp->resize(800, 600);
        gridLayout = new QGridLayout(Deployment_Emp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_3 = new QWidget(Deployment_Emp);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("#widget_3{\n"
"background-color:#00408E;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(widget_3);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(20, 20, 20, 0);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));
        horizontalLayout_13 = new QHBoxLayout(widget_4);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, 0, -1, 0);
        Deployment_3 = new QWidget(widget_4);
        Deployment_3->setObjectName(QString::fromUtf8("Deployment_3"));
        Deployment_3->setStyleSheet(QString::fromUtf8("#Deployment_3 {\n"
"    background-color: #FFFFFF;\n"
"    border: 0px solid #CCCCCC;\n"
"    border-radius: 10px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(Deployment_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, -1, 20);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Deployment_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(121, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_8 = new QLabel(Deployment_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(36, 20));
        label_8->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_16->addWidget(label_8);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_19);


        verticalLayout->addLayout(horizontalLayout_16);

        ee = new QWidget(Deployment_3);
        ee->setObjectName(QString::fromUtf8("ee"));
        gridLayout_2 = new QGridLayout(ee);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(-1, 0, -1, 0);
        ApplyPresentButton = new QPushButton(ee);
        ApplyPresentButton->setObjectName(QString::fromUtf8("ApplyPresentButton"));
        ApplyPresentButton->setMinimumSize(QSize(31, 31));
        ApplyPresentButton->setMaximumSize(QSize(31, 31));
        ApplyPresentButton->setStyleSheet(QString::fromUtf8("#ApplyPresentButton{\n"
"    background-color: #6699FF;\n"
"    border: 2px solid #6699FF;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#ApplyPresentButton:hover {\n"
" 	border: 2px solid #00408E;\n"
"	background-color: #00408E;\n"
"}\n"
"\n"
"#ApplyPresentButton:pressed {\n"
"	 border: 2px solid #00408E;\n"
"	 background-color: #00408E;\n"
"}"));

        gridLayout_2->addWidget(ApplyPresentButton, 0, 1, 1, 1);

        ApplyButtonWidget = new QWidget(ee);
        ApplyButtonWidget->setObjectName(QString::fromUtf8("ApplyButtonWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ApplyButtonWidget->sizePolicy().hasHeightForWidth());
        ApplyButtonWidget->setSizePolicy(sizePolicy);
        ApplyButtonWidget->setMaximumSize(QSize(16777215, 0));
        horizontalLayout_14 = new QHBoxLayout(ApplyButtonWidget);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_16 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_16);

        dplmtChange = new QPushButton(ApplyButtonWidget);
        dplmtChange->setObjectName(QString::fromUtf8("dplmtChange"));
        dplmtChange->setMaximumSize(QSize(16777215, 25));
        dplmtChange->setStyleSheet(QString::fromUtf8("#dplmtChange {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#dplmtChange:hover {\n"
" 	border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"#dplmtChange:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_14->addWidget(dplmtChange);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_12);

        dplmtLeave = new QPushButton(ApplyButtonWidget);
        dplmtLeave->setObjectName(QString::fromUtf8("dplmtLeave"));
        dplmtLeave->setStyleSheet(QString::fromUtf8("#dplmtLeave {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#dplmtLeave:hover {\n"
" 	border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"#dplmtLeave:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_14->addWidget(dplmtLeave);

        horizontalSpacer_17 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_17);


        gridLayout_2->addWidget(ApplyButtonWidget, 1, 0, 1, 2);

        textEdit = new QTextEdit(ee);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(0, 35));
        textEdit->setMaximumSize(QSize(16777215, 35));

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);

        ApplyPresentButton->raise();
        textEdit->raise();
        ApplyButtonWidget->raise();

        verticalLayout->addWidget(ee);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_9 = new QLabel(Deployment_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_17->addWidget(label_9);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_18);


        verticalLayout->addLayout(horizontalLayout_17);

        deployment = new QTableWidget(Deployment_3);
        deployment->setObjectName(QString::fromUtf8("deployment"));
        sizePolicy.setHeightForWidth(deployment->sizePolicy().hasHeightForWidth());
        deployment->setSizePolicy(sizePolicy);
        deployment->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(deployment);


        horizontalLayout_13->addWidget(Deployment_3);

        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(0, 16777215));
        widget->setStyleSheet(QString::fromUtf8("#widget {\n"
"    border-left: 2px solid #00408E;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2 {\n"
"    background-color: #00408E;\n"
"    border-radius: 10px;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(widget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(25, 22));
        label_2->setStyleSheet(QString::fromUtf8("#label_2 {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"}"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/deployment1.png")));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_2);

        applyType = new QLabel(widget_2);
        applyType->setObjectName(QString::fromUtf8("applyType"));
        applyType->setFont(font);
        applyType->setStyleSheet(QString::fromUtf8("#applyType{\n"
"background-color: transparent;\n"
"color: white;\n"
"}"));

        horizontalLayout_5->addWidget(applyType);

        horizontalSpacer_2 = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_7->addWidget(widget_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_9 = new QHBoxLayout(widget_5);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        applyNumber = new QLabel(widget_5);
        applyNumber->setObjectName(QString::fromUtf8("applyNumber"));

        horizontalLayout_9->addWidget(applyNumber);

        horizontalSpacer_3 = new QSpacerItem(176, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(widget_5);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_10 = new QHBoxLayout(widget_6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        applyPerson = new QLabel(widget_6);
        applyPerson->setObjectName(QString::fromUtf8("applyPerson"));

        horizontalLayout_10->addWidget(applyPerson);

        horizontalSpacer_4 = new QSpacerItem(176, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(widget_6);


        verticalLayout_7->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        applytime = new QLabel(widget);
        applytime->setObjectName(QString::fromUtf8("applytime"));
        applytime->setMinimumSize(QSize(130, 0));

        horizontalLayout_2->addWidget(applytime);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_7->addLayout(horizontalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_7 = new QWidget(widget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_11 = new QHBoxLayout(widget_7);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_5 = new QLabel(widget_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_11->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(176, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);


        verticalLayout_5->addWidget(widget_7);

        applycontent = new QWidget(widget);
        applycontent->setObjectName(QString::fromUtf8("applycontent"));
        applycontent->setMinimumSize(QSize(0, 151));
        verticalLayout_2 = new QVBoxLayout(applycontent);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        resignationwidget = new QWidget(applycontent);
        resignationwidget->setObjectName(QString::fromUtf8("resignationwidget"));
        horizontalLayout_6 = new QHBoxLayout(resignationwidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        resignationlabel = new QLabel(resignationwidget);
        resignationlabel->setObjectName(QString::fromUtf8("resignationlabel"));
        resignationlabel->setMinimumSize(QSize(51, 16));

        horizontalLayout_6->addWidget(resignationlabel);

        horizontalSpacer_11 = new QSpacerItem(97, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);


        verticalLayout_2->addWidget(resignationwidget);

        changewidget = new QWidget(applycontent);
        changewidget->setObjectName(QString::fromUtf8("changewidget"));
        horizontalLayout_7 = new QHBoxLayout(changewidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        changelabel = new QLabel(changewidget);
        changelabel->setObjectName(QString::fromUtf8("changelabel"));
        changelabel->setMinimumSize(QSize(51, 16));

        horizontalLayout_7->addWidget(changelabel);

        changecombox = new QComboBox(changewidget);
        changecombox->setObjectName(QString::fromUtf8("changecombox"));
        changecombox->setMinimumSize(QSize(121, 22));

        horizontalLayout_7->addWidget(changecombox);


        verticalLayout_2->addWidget(changewidget);


        verticalLayout_5->addWidget(applycontent);


        verticalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        submitApply = new QPushButton(widget);
        submitApply->setObjectName(QString::fromUtf8("submitApply"));
        submitApply->setStyleSheet(QString::fromUtf8("#submitApply{\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #6699FF;\n"
"    border: 2px solid #6699FF;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#submitApply:hover {\n"
" 	border: 2px solid #00408E;\n"
"    background-color: #00408E;\n"
"}\n"
"\n"
"#submitApply:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #00408E;\n"
"}"));

        horizontalLayout_3->addWidget(submitApply);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        cancelApply = new QPushButton(widget);
        cancelApply->setObjectName(QString::fromUtf8("cancelApply"));
        cancelApply->setStyleSheet(QString::fromUtf8("#cancelApply {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #FF9999;\n"
"    border: 2px solid #FF9999;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#cancelApply:hover {\n"
" 	border: 2px solid #FF6666;\n"
"    background-color: #FF6666;\n"
"}\n"
"\n"
"#cancelApply:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #FF6666;\n"
"}"));

        horizontalLayout_4->addWidget(cancelApply);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_7->addLayout(verticalLayout_6);


        horizontalLayout_13->addWidget(widget);


        verticalLayout_4->addWidget(widget_4);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setMinimumSize(QSize(0, 71));
        widget_8->setMaximumSize(QSize(16777215, 16777215));
        widget_8->setStyleSheet(QString::fromUtf8("#widget_5{background-color: #00408E;}"));
        horizontalLayout_8 = new QHBoxLayout(widget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_13 = new QSpacerItem(317, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);

        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setMinimumSize(QSize(100, 0));
        widget_9->setMaximumSize(QSize(16777215, 40));
        widget_9->setStyleSheet(QString::fromUtf8("#widget_6 {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}\n"
""));
        gridLayout_3 = new QGridLayout(widget_9);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        applyIfSucceed = new QLabel(widget_9);
        applyIfSucceed->setObjectName(QString::fromUtf8("applyIfSucceed"));
        applyIfSucceed->setFont(font);
        applyIfSucceed->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(applyIfSucceed, 0, 0, 1, 1);


        horizontalLayout_8->addWidget(widget_9);

        horizontalSpacer_14 = new QSpacerItem(317, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_14);


        verticalLayout_4->addWidget(widget_8);


        gridLayout->addWidget(widget_3, 0, 0, 1, 1);


        retranslateUi(Deployment_Emp);

        QMetaObject::connectSlotsByName(Deployment_Emp);
    } // setupUi

    void retranslateUi(QWidget *Deployment_Emp)
    {
        Deployment_Emp->setWindowTitle(QCoreApplication::translate("Deployment_Emp", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Deployment_Emp", "\350\201\214\345\212\241\345\222\214\350\260\203\351\205\215\350\256\260\345\275\225", nullptr));
        label_8->setText(QCoreApplication::translate("Deployment_Emp", "\345\275\223\345\211\215\350\201\214\345\212\241", nullptr));
        ApplyPresentButton->setText(QString());
        dplmtChange->setText(QCoreApplication::translate("Deployment_Emp", "\345\217\230\345\212\250\347\224\263\350\257\267", nullptr));
        dplmtLeave->setText(QCoreApplication::translate("Deployment_Emp", "\347\246\273\350\201\214\347\224\263\350\257\267", nullptr));
        label_9->setText(QCoreApplication::translate("Deployment_Emp", "\350\260\203\351\205\215\350\256\260\345\275\225", nullptr));
        label_2->setText(QString());
        applyType->setText(QCoreApplication::translate("Deployment_Emp", "\347\224\263\350\257\267\347\247\215\347\261\273", nullptr));
        applyNumber->setText(QCoreApplication::translate("Deployment_Emp", "\347\224\263\350\257\267\345\217\267", nullptr));
        applyPerson->setText(QCoreApplication::translate("Deployment_Emp", "\347\224\263\350\257\267\344\272\272", nullptr));
        applytime->setText(QCoreApplication::translate("Deployment_Emp", "\347\224\263\350\257\267\346\227\266\351\227\264", nullptr));
        label_5->setText(QCoreApplication::translate("Deployment_Emp", "\347\224\263\350\257\267\345\206\205\345\256\271", nullptr));
        resignationlabel->setText(QCoreApplication::translate("Deployment_Emp", "\347\246\273\350\201\214\347\224\263\350\257\267", nullptr));
        changelabel->setText(QCoreApplication::translate("Deployment_Emp", "\345\217\230\345\212\250\347\224\263\350\257\267", nullptr));
        submitApply->setText(QCoreApplication::translate("Deployment_Emp", "\346\217\220\344\272\244\347\224\263\350\257\267", nullptr));
        cancelApply->setText(QCoreApplication::translate("Deployment_Emp", "\345\217\226\346\266\210", nullptr));
        applyIfSucceed->setText(QCoreApplication::translate("Deployment_Emp", "\346\217\220\347\244\272\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deployment_Emp: public Ui_Deployment_Emp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPLOYMENT_EMP_H
