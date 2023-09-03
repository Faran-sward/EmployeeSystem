/********************************************************************************
** Form generated from reading UI file 'myApply.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYAPPLY_H
#define UI_MYAPPLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyApply
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *maplyYear;
    QLabel *label;
    QComboBox *maplyMonth;
    QLabel *label_2;
    QComboBox *maplyDay;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *maplyGet;
    QWidget *outside;
    QGridLayout *gridLayout_2;
    QWidget *inside;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QTableWidget *maplySolving;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QTableWidget *maplySolved;

    void setupUi(QWidget *MyApply)
    {
        if (MyApply->objectName().isEmpty())
            MyApply->setObjectName(QString::fromUtf8("MyApply"));
        MyApply->resize(800, 600);
        verticalLayout = new QVBoxLayout(MyApply);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(50, 50, 50, 30);
        widget_2 = new QWidget(MyApply);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2 {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(585, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(MyApply);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("#widget {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 20, -1);
        horizontalSpacer_2 = new QSpacerItem(172, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        maplyYear = new QComboBox(widget);
        maplyYear->setObjectName(QString::fromUtf8("maplyYear"));

        horizontalLayout->addWidget(maplyYear);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        maplyMonth = new QComboBox(widget);
        maplyMonth->setObjectName(QString::fromUtf8("maplyMonth"));

        horizontalLayout->addWidget(maplyMonth);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        maplyDay = new QComboBox(widget);
        maplyDay->setObjectName(QString::fromUtf8("maplyDay"));

        horizontalLayout->addWidget(maplyDay);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(171, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        maplyGet = new QPushButton(widget);
        maplyGet->setObjectName(QString::fromUtf8("maplyGet"));
        maplyGet->setStyleSheet(QString::fromUtf8("#maplyGet{\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"	padding-left:20px;\n"
"	padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"#maplyGet:hover {\n"
" 	border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"#maplyGet:pressed {\n"
"	 border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout->addWidget(maplyGet);


        verticalLayout->addWidget(widget);

        outside = new QWidget(MyApply);
        outside->setObjectName(QString::fromUtf8("outside"));
        outside->setStyleSheet(QString::fromUtf8("#outside {\n"
"    background-color: #FFFFFF;\n"
"    border-radius: 10px;\n"
"}"));
        gridLayout_2 = new QGridLayout(outside);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 30, 5, 30);
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
        maplySolving = new QTableWidget(tab);
        maplySolving->setObjectName(QString::fromUtf8("maplySolving"));

        gridLayout_4->addWidget(maplySolving, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        maplySolved = new QTableWidget(tab_2);
        maplySolved->setObjectName(QString::fromUtf8("maplySolved"));

        gridLayout_5->addWidget(maplySolved, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(inside, 0, 0, 1, 1);


        verticalLayout->addWidget(outside);


        retranslateUi(MyApply);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyApply);
    } // setupUi

    void retranslateUi(QWidget *MyApply)
    {
        MyApply->setWindowTitle(QCoreApplication::translate("MyApply", "Widget", nullptr));
        label_4->setText(QCoreApplication::translate("MyApply", "\346\210\221\347\232\204\347\224\263\350\257\267\350\256\260\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("MyApply", "\345\271\264", nullptr));
        label_2->setText(QCoreApplication::translate("MyApply", "\346\234\210", nullptr));
        label_3->setText(QCoreApplication::translate("MyApply", "\346\227\245", nullptr));
        maplyGet->setText(QCoreApplication::translate("MyApply", "\347\255\233\351\200\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MyApply", "\345\244\204\347\220\206\344\270\255", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MyApply", "\345\267\262\345\244\204\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyApply: public Ui_MyApply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYAPPLY_H
