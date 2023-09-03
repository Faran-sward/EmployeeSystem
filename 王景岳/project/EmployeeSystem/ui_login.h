/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *loginButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *userPict;
    QLineEdit *numEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passPict;
    QLineEdit *passEdit;
    QPushButton *eyePict;
    QWidget *widget_3;
    QPushButton *minButton;
    QPushButton *closeButton;
    QLabel *mainPict;
    QLabel *errorText;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        Login->setMinimumSize(QSize(400, 300));
        Login->setMaximumSize(QSize(400, 300));
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(140, 255, 101, 31));
        widget = new QWidget(Login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 140, 232, 32));
        widget->setMinimumSize(QSize(232, 32));
        widget->setMaximumSize(QSize(232, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        userPict = new QLabel(widget);
        userPict->setObjectName(QString::fromUtf8("userPict"));
        userPict->setMinimumSize(QSize(30, 30));
        userPict->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(userPict);

        numEdit = new QLineEdit(widget);
        numEdit->setObjectName(QString::fromUtf8("numEdit"));
        numEdit->setMinimumSize(QSize(200, 30));

        horizontalLayout->addWidget(numEdit);

        widget_2 = new QWidget(Login);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(80, 190, 232, 32));
        widget_2->setMinimumSize(QSize(232, 32));
        widget_2->setMaximumSize(QSize(232, 32));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        passPict = new QLabel(widget_2);
        passPict->setObjectName(QString::fromUtf8("passPict"));
        passPict->setMinimumSize(QSize(30, 30));
        passPict->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(passPict);

        passEdit = new QLineEdit(widget_2);
        passEdit->setObjectName(QString::fromUtf8("passEdit"));
        passEdit->setMinimumSize(QSize(170, 30));
        passEdit->setMaximumSize(QSize(170, 30));

        horizontalLayout_2->addWidget(passEdit);

        eyePict = new QPushButton(widget_2);
        eyePict->setObjectName(QString::fromUtf8("eyePict"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(eyePict->sizePolicy().hasHeightForWidth());
        eyePict->setSizePolicy(sizePolicy);
        eyePict->setMinimumSize(QSize(30, 30));
        eyePict->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(eyePict);

        widget_3 = new QWidget(Login);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 400, 120));
        widget_3->setMinimumSize(QSize(400, 120));
        widget_3->setMaximumSize(QSize(400, 120));
        widget_3->setStyleSheet(QString::fromUtf8(""));
        minButton = new QPushButton(widget_3);
        minButton->setObjectName(QString::fromUtf8("minButton"));
        minButton->setGeometry(QRect(360, 0, 20, 20));
        minButton->setMinimumSize(QSize(20, 20));
        minButton->setMaximumSize(QSize(20, 20));
        closeButton = new QPushButton(widget_3);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(380, 0, 20, 20));
        closeButton->setMinimumSize(QSize(20, 20));
        closeButton->setMaximumSize(QSize(20, 20));
        mainPict = new QLabel(widget_3);
        mainPict->setObjectName(QString::fromUtf8("mainPict"));
        mainPict->setGeometry(QRect(140, 0, 120, 120));
        mainPict->setMinimumSize(QSize(120, 120));
        mainPict->setMaximumSize(QSize(120, 120));
        errorText = new QLabel(Login);
        errorText->setObjectName(QString::fromUtf8("errorText"));
        errorText->setGeometry(QRect(80, 230, 201, 16));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        userPict->setText(QString());
        numEdit->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\267\245\345\217\267", nullptr));
        passPict->setText(QString());
        passEdit->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        eyePict->setText(QString());
        minButton->setText(QString());
        closeButton->setText(QString());
        mainPict->setText(QString());
        errorText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
