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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deployment_Emp
{
public:
    QGridLayout *gridLayout;
    QWidget *Deployment;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_16;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_19;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *dplmtChange;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *dplmtLeave;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_18;
    QTableView *deployment;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *dplmtDeployment;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Deployment_Emp)
    {
        if (Deployment_Emp->objectName().isEmpty())
            Deployment_Emp->setObjectName(QString::fromUtf8("Deployment_Emp"));
        Deployment_Emp->resize(800, 600);
        gridLayout = new QGridLayout(Deployment_Emp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(50, 50, 50, 50);
        Deployment = new QWidget(Deployment_Emp);
        Deployment->setObjectName(QString::fromUtf8("Deployment"));
        verticalLayout = new QVBoxLayout(Deployment);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_16);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Deployment);
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
        label_8 = new QLabel(Deployment);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(36, 20));
        label_8->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_16->addWidget(label_8);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_19);


        verticalLayout->addLayout(horizontalLayout_16);

        textBrowser = new QTextBrowser(Deployment);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(467, 35));
        textBrowser->setMaximumSize(QSize(16777215, 35));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_16 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_16);

        dplmtChange = new QPushButton(Deployment);
        dplmtChange->setObjectName(QString::fromUtf8("dplmtChange"));
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

        dplmtLeave = new QPushButton(Deployment);
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


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_9 = new QLabel(Deployment);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_17->addWidget(label_9);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_18);


        verticalLayout->addLayout(horizontalLayout_17);

        deployment = new QTableView(Deployment);
        deployment->setObjectName(QString::fromUtf8("deployment"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deployment->sizePolicy().hasHeightForWidth());
        deployment->setSizePolicy(sizePolicy);
        deployment->setMinimumSize(QSize(427, 192));

        verticalLayout->addWidget(deployment);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_14);

        dplmtDeployment = new QPushButton(Deployment);
        dplmtDeployment->setObjectName(QString::fromUtf8("dplmtDeployment"));
        dplmtDeployment->setStyleSheet(QString::fromUtf8("#dplmtDeployment {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#dplmtDeployment:hover {\n"
" 	border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"#dplmtDeployment:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_15->addWidget(dplmtDeployment);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_15);


        verticalLayout->addLayout(horizontalLayout_15);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(Deployment, 0, 0, 1, 1);


        retranslateUi(Deployment_Emp);

        QMetaObject::connectSlotsByName(Deployment_Emp);
    } // setupUi

    void retranslateUi(QWidget *Deployment_Emp)
    {
        Deployment_Emp->setWindowTitle(QCoreApplication::translate("Deployment_Emp", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Deployment_Emp", "\350\201\214\345\212\241\345\222\214\350\260\203\351\205\215\350\256\260\345\275\225", nullptr));
        label_8->setText(QCoreApplication::translate("Deployment_Emp", "\345\275\223\345\211\215\350\201\214\345\212\241", nullptr));
        dplmtChange->setText(QCoreApplication::translate("Deployment_Emp", "\345\217\230\345\212\250\347\224\263\350\257\267", nullptr));
        dplmtLeave->setText(QCoreApplication::translate("Deployment_Emp", "\347\246\273\350\201\214\347\224\263\350\257\267", nullptr));
        label_9->setText(QCoreApplication::translate("Deployment_Emp", "\350\260\203\351\205\215\350\256\260\345\275\225", nullptr));
        dplmtDeployment->setText(QCoreApplication::translate("Deployment_Emp", "\350\260\203\351\205\215\347\224\263\350\257\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deployment_Emp: public Ui_Deployment_Emp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPLOYMENT_EMP_H
