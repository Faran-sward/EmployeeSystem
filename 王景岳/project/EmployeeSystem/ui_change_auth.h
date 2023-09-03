/********************************************************************************
** Form generated from reading UI file 'change_auth.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_AUTH_H
#define UI_CHANGE_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Change_Auth
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *numLab;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *nameLab;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *buildLab;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *floorLab;
    QLineEdit *floorEdit;
    QPushButton *addButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addButton;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QLabel *errorText;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QWidget *Change_Auth)
    {
        if (Change_Auth->objectName().isEmpty())
            Change_Auth->setObjectName(QString::fromUtf8("Change_Auth"));
        Change_Auth->resize(432, 314);
        verticalLayout_2 = new QVBoxLayout(Change_Auth);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(Change_Auth);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(widget_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        widget = new QWidget(frame);
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

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


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

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


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

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


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


        gridLayout->addWidget(widget, 0, 0, 1, 5);

        addButton_2 = new QPushButton(frame);
        addButton_2->setObjectName(QString::fromUtf8("addButton_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addButton_2->sizePolicy().hasHeightForWidth());
        addButton_2->setSizePolicy(sizePolicy1);
        addButton_2->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(addButton_2, 4, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 4, 1, 1);

        addButton = new QPushButton(frame);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(addButton, 4, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(17, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 5, 1, 1, 3);

        errorText = new QLabel(frame);
        errorText->setObjectName(QString::fromUtf8("errorText"));

        gridLayout->addWidget(errorText, 2, 0, 1, 5);

        horizontalSpacer_4 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_4, 3, 2, 1, 1);


        horizontalLayout->addWidget(frame);


        verticalLayout_2->addWidget(widget_2);

        verticalSpacer_7 = new QSpacerItem(118, 46, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);


        retranslateUi(Change_Auth);

        QMetaObject::connectSlotsByName(Change_Auth);
    } // setupUi

    void retranslateUi(QWidget *Change_Auth)
    {
        Change_Auth->setWindowTitle(QCoreApplication::translate("Change_Auth", "Form", nullptr));
        numLab->setText(QCoreApplication::translate("Change_Auth", "\351\203\250\351\227\250\345\220\215\347\247\260\357\274\232", nullptr));
        nameLab->setText(QCoreApplication::translate("Change_Auth", "\345\262\227\344\275\215\347\274\226\345\217\267\357\274\232", nullptr));
        buildLab->setText(QCoreApplication::translate("Change_Auth", "\345\262\227\344\275\215\345\220\215\347\247\260\357\274\232", nullptr));
        floorLab->setText(QCoreApplication::translate("Change_Auth", "\351\242\204\346\234\237\350\247\204\346\250\241\357\274\232", nullptr));
        floorEdit->setPlaceholderText(QCoreApplication::translate("Change_Auth", "\350\257\267\350\276\223\345\205\245\346\226\260\347\232\204\351\242\204\346\234\237\350\247\204\346\250\241", nullptr));
        addButton_2->setText(QCoreApplication::translate("Change_Auth", "\345\217\226\346\266\210", nullptr));
        addButton->setText(QCoreApplication::translate("Change_Auth", "\345\217\230\346\233\264", nullptr));
        errorText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Change_Auth: public Ui_Change_Auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_AUTH_H
