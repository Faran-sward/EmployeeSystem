/********************************************************************************
** Form generated from reading UI file 'resume.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESUME_H
#define UI_RESUME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Resume
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *formal;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QWidget *informal;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_6;
    QGraphicsView *graphicsView_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *Resume)
    {
        if (Resume->objectName().isEmpty())
            Resume->setObjectName(QString::fromUtf8("Resume"));
        Resume->resize(800, 600);
        gridLayout = new QGridLayout(Resume);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(50, 50, 50, 50);
        tabWidget = new QTabWidget(Resume);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        formal = new QWidget();
        formal->setObjectName(QString::fromUtf8("formal"));
        gridLayout_2 = new QGridLayout(formal);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        lineEdit = new QLineEdit(formal);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(formal);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"    padding-left:20px;\n"
"    padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(formal);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(formal);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"    padding-left:20px;\n"
"    padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(formal, QString());
        informal = new QWidget();
        informal->setObjectName(QString::fromUtf8("informal"));
        gridLayout_3 = new QGridLayout(informal);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        lineEdit_2 = new QLineEdit(informal);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        pushButton_2 = new QPushButton(informal);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"    padding-left:20px;\n"
"    padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        graphicsView_2 = new QGraphicsView(informal);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        verticalLayout_2->addWidget(graphicsView_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        pushButton_4 = new QPushButton(informal);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    font: 25 10pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"    color: rgb(255,255,255);\n"
"    padding-left:20px;\n"
"    padding-right:20px;\n"
"    background-color: #2F80ED;\n"
"    border: 2px solid #2F80ED;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #1652AB;\n"
"    background-color: #1652AB;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 2px solid #FFFFFF;\n"
"    background-color: #1652AB;\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_4);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(informal, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Resume);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Resume);
    } // setupUi

    void retranslateUi(QWidget *Resume)
    {
        Resume->setWindowTitle(QCoreApplication::translate("Resume", "Widget", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QCoreApplication::translate("Resume", "\346\237\245\350\257\242", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Resume", "\345\257\274\345\207\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(formal), QCoreApplication::translate("Resume", "\346\255\243\345\274\217\345\221\230\345\267\245", nullptr));
        lineEdit_2->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("Resume", "\346\237\245\350\257\242", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Resume", "\346\211\271\345\207\206\345\205\245\350\201\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(informal), QCoreApplication::translate("Resume", "\345\276\205\345\205\245\350\201\214\345\221\230\345\267\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Resume: public Ui_Resume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESUME_H
