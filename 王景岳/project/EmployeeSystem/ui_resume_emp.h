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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Resume_Emp
{
public:
    QGridLayout *gridLayout_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_6;
    QWidget *resumePresent;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *maxUi;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *returnUi;
    QSpacerItem *horizontalSpacer_10;
    QWidget *resume;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *download;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *rsmDeptNo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *rsmDeptMem;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *rsmSearchID;
    QPushButton *search;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QTableWidget *employeeTable;

    void setupUi(QWidget *Resume_Emp)
    {
        if (Resume_Emp->objectName().isEmpty())
            Resume_Emp->setObjectName(QString::fromUtf8("Resume_Emp"));
        Resume_Emp->resize(800, 600);
        gridLayout_4 = new QGridLayout(Resume_Emp);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget_5 = new QWidget(Resume_Emp);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setStyleSheet(QString::fromUtf8("#widget_5 {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_6 = new QSpacerItem(585, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        gridLayout_4->addWidget(widget_5, 0, 0, 1, 1);

        resumePresent = new QWidget(Resume_Emp);
        resumePresent->setObjectName(QString::fromUtf8("resumePresent"));
        resumePresent->setMaximumSize(QSize(0, 16777215));
        resumePresent->setStyleSheet(QString::fromUtf8("#resumePresent {\n"
"    border-left: 2px solid #00408E;\n"
"    border-radius: 0px;\n"
"}"));
        verticalLayout = new QVBoxLayout(resumePresent);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        maxUi = new QPushButton(resumePresent);
        maxUi->setObjectName(QString::fromUtf8("maxUi"));
        maxUi->setMinimumSize(QSize(80, 18));
        maxUi->setMaximumSize(QSize(80, 18));
        maxUi->setStyleSheet(QString::fromUtf8("#maxUi{\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #6699FF;\n"
"    border: 2px solid #6699FF;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#maxUi:hover {\n"
" 	border: 2px solid #00408E;\n"
"    background-color: #00408E;\n"
"}\n"
"\n"
"#maxUi:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #00408E;\n"
"}"));

        horizontalLayout_5->addWidget(maxUi);

        horizontalSpacer_9 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        returnUi = new QPushButton(resumePresent);
        returnUi->setObjectName(QString::fromUtf8("returnUi"));
        returnUi->setMinimumSize(QSize(80, 18));
        returnUi->setMaximumSize(QSize(80, 18));
        returnUi->setStyleSheet(QString::fromUtf8("#returnUi {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #FF9999;\n"
"    border: 2px solid #FF9999;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#returnUi:hover {\n"
" 	border: 2px solid #FF6666;\n"
"    background-color: #FF6666;\n"
"}\n"
"\n"
"#returnUi:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #FF6666;\n"
"}"));

        horizontalLayout_5->addWidget(returnUi);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_5);

        resume = new QWidget(resumePresent);
        resume->setObjectName(QString::fromUtf8("resume"));
        resume->setMinimumSize(QSize(0, 231));
        gridLayout_2 = new QGridLayout(resume);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(10);
        gridLayout_2->setContentsMargins(4, 90, 0, 89);
        label = new QLabel(resume);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addWidget(resume);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        download = new QPushButton(resumePresent);
        download->setObjectName(QString::fromUtf8("download"));
        download->setMaximumSize(QSize(80, 18));
        download->setStyleSheet(QString::fromUtf8("#download {\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#download:hover {\n"
" 	border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"#download:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_3->addWidget(download);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_4->addWidget(resumePresent, 0, 1, 4, 1);

        widget = new QWidget(Resume_Emp);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("#widget {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(151, 22));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(331, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_4->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(Resume_Emp);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2 {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rsmDeptNo = new QLabel(widget_2);
        rsmDeptNo->setObjectName(QString::fromUtf8("rsmDeptNo"));
        rsmDeptNo->setMinimumSize(QSize(151, 16));

        horizontalLayout_2->addWidget(rsmDeptNo);

        horizontalSpacer_2 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        rsmDeptMem = new QLabel(widget_2);
        rsmDeptMem->setObjectName(QString::fromUtf8("rsmDeptMem"));
        rsmDeptMem->setMinimumSize(QSize(151, 16));

        horizontalLayout_2->addWidget(rsmDeptMem);

        horizontalSpacer_3 = new QSpacerItem(84, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_4->addWidget(widget_2, 2, 0, 1, 1);

        widget_3 = new QWidget(Resume_Emp);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("#widget_3 {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_4 = new QSpacerItem(129, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        rsmSearchID = new QLineEdit(widget_3);
        rsmSearchID->setObjectName(QString::fromUtf8("rsmSearchID"));
        rsmSearchID->setEnabled(true);
        rsmSearchID->setReadOnly(true);

        gridLayout->addWidget(rsmSearchID, 0, 1, 1, 1);

        search = new QPushButton(widget_3);
        search->setObjectName(QString::fromUtf8("search"));
        search->setStyleSheet(QString::fromUtf8("#search{\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#search:hover {\n"
" 	border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"#search:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        gridLayout->addWidget(search, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(129, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 3, 1, 1);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        widget_4->setMinimumSize(QSize(0, 211));
        widget_4->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        employeeTable = new QTableWidget(widget_4);
        employeeTable->setObjectName(QString::fromUtf8("employeeTable"));
        employeeTable->setEnabled(true);

        gridLayout_3->addWidget(employeeTable, 0, 1, 1, 1);


        gridLayout->addWidget(widget_4, 1, 0, 1, 4);


        gridLayout_4->addWidget(widget_3, 3, 0, 1, 1);


        retranslateUi(Resume_Emp);

        QMetaObject::connectSlotsByName(Resume_Emp);
    } // setupUi

    void retranslateUi(QWidget *Resume_Emp)
    {
        Resume_Emp->setWindowTitle(QCoreApplication::translate("Resume_Emp", "Widget", nullptr));
        label_4->setText(QCoreApplication::translate("Resume_Emp", "\347\256\200\345\216\206\346\237\245\350\257\242", nullptr));
        maxUi->setText(QCoreApplication::translate("Resume_Emp", "\346\237\245\347\234\213", nullptr));
        returnUi->setText(QCoreApplication::translate("Resume_Emp", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("Resume_Emp", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        download->setText(QCoreApplication::translate("Resume_Emp", "\344\270\213\350\275\275", nullptr));
        rsmDeptNo->setText(QCoreApplication::translate("Resume_Emp", "\351\203\250\351\227\250\347\274\226\345\217\267\357\274\232", nullptr));
        rsmDeptMem->setText(QCoreApplication::translate("Resume_Emp", "\351\203\250\351\227\250\344\272\272\346\225\260\357\274\232", nullptr));
        rsmSearchID->setPlaceholderText(QCoreApplication::translate("Resume_Emp", "\346\210\221\347\232\204\345\221\230\345\267\245\345\217\267", nullptr));
        search->setText(QCoreApplication::translate("Resume_Emp", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Resume_Emp: public Ui_Resume_Emp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESUME_EMP_H
