/********************************************************************************
** Form generated from reading UI file 'sign.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_H
#define UI_SIGN_H

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

class Ui_Sign
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *numLab;
    QLineEdit *numEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passLab;
    QLineEdit *passEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *conLab;
    QLineEdit *conEdit;
    QSpacerItem *verticalSpacer_6;
    QLabel *errorText;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *Sign)
    {
        if (Sign->objectName().isEmpty())
            Sign->setObjectName(QString::fromUtf8("Sign"));
        Sign->resize(303, 238);
        gridLayout = new QGridLayout(Sign);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        numLab = new QLabel(Sign);
        numLab->setObjectName(QString::fromUtf8("numLab"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numLab->sizePolicy().hasHeightForWidth());
        numLab->setSizePolicy(sizePolicy);
        numLab->setMinimumSize(QSize(60, 21));

        horizontalLayout->addWidget(numLab);

        numEdit = new QLineEdit(Sign);
        numEdit->setObjectName(QString::fromUtf8("numEdit"));
        numEdit->setMinimumSize(QSize(141, 21));

        horizontalLayout->addWidget(numEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        passLab = new QLabel(Sign);
        passLab->setObjectName(QString::fromUtf8("passLab"));
        sizePolicy.setHeightForWidth(passLab->sizePolicy().hasHeightForWidth());
        passLab->setSizePolicy(sizePolicy);
        passLab->setMinimumSize(QSize(60, 21));

        horizontalLayout_2->addWidget(passLab);

        passEdit = new QLineEdit(Sign);
        passEdit->setObjectName(QString::fromUtf8("passEdit"));
        passEdit->setMinimumSize(QSize(141, 21));

        horizontalLayout_2->addWidget(passEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        conLab = new QLabel(Sign);
        conLab->setObjectName(QString::fromUtf8("conLab"));
        sizePolicy.setHeightForWidth(conLab->sizePolicy().hasHeightForWidth());
        conLab->setSizePolicy(sizePolicy);
        conLab->setMinimumSize(QSize(60, 21));

        horizontalLayout_3->addWidget(conLab);

        conEdit = new QLineEdit(Sign);
        conEdit->setObjectName(QString::fromUtf8("conEdit"));
        conEdit->setMinimumSize(QSize(141, 21));

        horizontalLayout_3->addWidget(conEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 3);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 1, 1, 1, 1);

        errorText = new QLabel(Sign);
        errorText->setObjectName(QString::fromUtf8("errorText"));

        gridLayout->addWidget(errorText, 2, 0, 1, 3);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_4, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        addButton = new QPushButton(Sign);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(addButton, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 71, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 5, 1, 1, 1);


        retranslateUi(Sign);

        QMetaObject::connectSlotsByName(Sign);
    } // setupUi

    void retranslateUi(QWidget *Sign)
    {
        Sign->setWindowTitle(QCoreApplication::translate("Sign", "Form", nullptr));
        numLab->setText(QCoreApplication::translate("Sign", "\345\267\245\345\217\267\357\274\232", nullptr));
        numEdit->setInputMask(QString());
        numEdit->setPlaceholderText(QCoreApplication::translate("Sign", "\350\257\267\350\276\223\345\205\245\345\267\245\345\217\267", nullptr));
        passLab->setText(QCoreApplication::translate("Sign", "\345\257\206\347\240\201\357\274\232", nullptr));
        passEdit->setPlaceholderText(QCoreApplication::translate("Sign", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        conLab->setText(QCoreApplication::translate("Sign", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        conEdit->setPlaceholderText(QCoreApplication::translate("Sign", "\350\257\267\345\206\215\350\276\223\345\205\245\344\270\200\351\201\215\345\257\206\347\240\201", nullptr));
        errorText->setText(QString());
        addButton->setText(QCoreApplication::translate("Sign", "\345\210\233\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sign: public Ui_Sign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_H
