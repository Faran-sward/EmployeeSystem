/********************************************************************************
** Form generated from reading UI file 'solveApply.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLVEAPPLY_H
#define UI_SOLVEAPPLY_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SolveApply
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *applyYear;
    QLabel *label_2;
    QComboBox *applyMonth;
    QLabel *label_3;
    QComboBox *applyDay;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *employeeID;
    QPushButton *getApply;
    QWidget *outside;
    QGridLayout *gridLayout_2;
    QWidget *inside;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QTableWidget *applySolving;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QTableWidget *applySolved;

    void setupUi(QWidget *SolveApply)
    {
        if (SolveApply->objectName().isEmpty())
            SolveApply->setObjectName(QString::fromUtf8("SolveApply"));
        SolveApply->resize(800, 600);
        verticalLayout = new QVBoxLayout(SolveApply);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(50, 50, 50, 30);
        widget_4 = new QWidget(SolveApply);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("#widget_4 {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(16);
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        horizontalSpacer_6 = new QSpacerItem(585, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(widget_4);

        widget_2 = new QWidget(SolveApply);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2 {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(221, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        applyYear = new QComboBox(widget_2);
        applyYear->setObjectName(QString::fromUtf8("applyYear"));

        horizontalLayout->addWidget(applyYear);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        applyMonth = new QComboBox(widget_2);
        applyMonth->setObjectName(QString::fromUtf8("applyMonth"));

        horizontalLayout->addWidget(applyMonth);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        applyDay = new QComboBox(widget_2);
        applyDay->setObjectName(QString::fromUtf8("applyDay"));

        horizontalLayout->addWidget(applyDay);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(220, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(SolveApply);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("#widget_3 {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 20, -1);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        employeeID = new QLineEdit(widget_3);
        employeeID->setObjectName(QString::fromUtf8("employeeID"));

        horizontalLayout_3->addWidget(employeeID);

        getApply = new QPushButton(widget_3);
        getApply->setObjectName(QString::fromUtf8("getApply"));
        getApply->setStyleSheet(QString::fromUtf8("#getApply{\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#getApply:hover {\n"
" 	border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"#getApply:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_3->addWidget(getApply);


        verticalLayout->addWidget(widget_3);

        outside = new QWidget(SolveApply);
        outside->setObjectName(QString::fromUtf8("outside"));
        outside->setStyleSheet(QString::fromUtf8("#outside {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        gridLayout_2 = new QGridLayout(outside);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 10, 5, 0);
        inside = new QWidget(outside);
        inside->setObjectName(QString::fromUtf8("inside"));
        inside->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(inside);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(inside);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        applySolving = new QTableWidget(tab);
        applySolving->setObjectName(QString::fromUtf8("applySolving"));

        gridLayout_4->addWidget(applySolving, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        applySolved = new QTableWidget(tab_2);
        applySolved->setObjectName(QString::fromUtf8("applySolved"));

        gridLayout_5->addWidget(applySolved, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(inside, 0, 0, 1, 1);


        verticalLayout->addWidget(outside);


        retranslateUi(SolveApply);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SolveApply);
    } // setupUi

    void retranslateUi(QWidget *SolveApply)
    {
        SolveApply->setWindowTitle(QCoreApplication::translate("SolveApply", "Widget", nullptr));
        label_5->setText(QCoreApplication::translate("SolveApply", "\347\224\263\350\257\267\345\244\204\347\220\206", nullptr));
        label_2->setText(QCoreApplication::translate("SolveApply", "\345\271\264", nullptr));
        label_3->setText(QCoreApplication::translate("SolveApply", "\346\234\210", nullptr));
        label_4->setText(QCoreApplication::translate("SolveApply", "\346\227\245", nullptr));
        employeeID->setPlaceholderText(QCoreApplication::translate("SolveApply", "\345\221\230\345\267\245\345\217\267", nullptr));
        getApply->setText(QCoreApplication::translate("SolveApply", "\347\255\233\351\200\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SolveApply", "\345\244\204\347\220\206\344\270\255", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SolveApply", "\345\267\262\345\244\204\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SolveApply: public Ui_SolveApply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLVEAPPLY_H
