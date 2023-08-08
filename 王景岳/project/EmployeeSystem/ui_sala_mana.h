/********************************************************************************
** Form generated from reading UI file 'sala_mana.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALA_MANA_H
#define UI_SALA_MANA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sala_Mana
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QComboBox *year_combo;
    QSpacerItem *horizontalSpacer;
    QComboBox *month_combo;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Sala_Mana)
    {
        if (Sala_Mana->objectName().isEmpty())
            Sala_Mana->setObjectName(QString::fromUtf8("Sala_Mana"));
        Sala_Mana->resize(686, 539);
        verticalLayout = new QVBoxLayout(Sala_Mana);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, 10, 30, 0);
        widget = new QWidget(Sala_Mana);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        year_combo = new QComboBox(widget);
        year_combo->setObjectName(QString::fromUtf8("year_combo"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(year_combo->sizePolicy().hasHeightForWidth());
        year_combo->setSizePolicy(sizePolicy);
        year_combo->setMinimumSize(QSize(171, 21));

        horizontalLayout->addWidget(year_combo);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        month_combo = new QComboBox(widget);
        month_combo->setObjectName(QString::fromUtf8("month_combo"));
        sizePolicy.setHeightForWidth(month_combo->sizePolicy().hasHeightForWidth());
        month_combo->setSizePolicy(sizePolicy);
        month_combo->setMinimumSize(QSize(171, 21));

        horizontalLayout->addWidget(month_combo);

        horizontalSpacer_2 = new QSpacerItem(201, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        tableWidget = new QTableWidget(Sala_Mana);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(Sala_Mana);

        QMetaObject::connectSlotsByName(Sala_Mana);
    } // setupUi

    void retranslateUi(QWidget *Sala_Mana)
    {
        Sala_Mana->setWindowTitle(QCoreApplication::translate("Sala_Mana", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Sala_Mana", "\345\221\230\345\267\245\345\267\245\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Sala_Mana", "\345\221\230\345\267\245\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Sala_Mana", "\345\272\225\350\226\252", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Sala_Mana", "\345\245\226\351\207\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Sala_Mana", "\347\273\251\346\225\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Sala_Mana", "\346\200\273\345\267\245\350\265\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Sala_Mana", "\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sala_Mana: public Ui_Sala_Mana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALA_MANA_H
