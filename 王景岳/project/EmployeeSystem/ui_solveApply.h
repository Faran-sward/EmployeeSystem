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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SolveApply
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *unsolved;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QWidget *solved;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_2;

    void setupUi(QWidget *SolveApply)
    {
        if (SolveApply->objectName().isEmpty())
            SolveApply->setObjectName(QString::fromUtf8("SolveApply"));
        SolveApply->resize(800, 600);
        gridLayout = new QGridLayout(SolveApply);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(50, 50, 50, 50);
        tabWidget = new QTabWidget(SolveApply);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        unsolved = new QWidget();
        unsolved->setObjectName(QString::fromUtf8("unsolved"));
        gridLayout_2 = new QGridLayout(unsolved);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidget = new QTableWidget(unsolved);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        tabWidget->addTab(unsolved, QString());
        solved = new QWidget();
        solved->setObjectName(QString::fromUtf8("solved"));
        gridLayout_3 = new QGridLayout(solved);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableWidget_2 = new QTableWidget(solved);
        if (tableWidget_2->columnCount() < 6)
            tableWidget_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        if (tableWidget_2->rowCount() < 1)
            tableWidget_2->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem13);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        gridLayout_3->addWidget(tableWidget_2, 0, 0, 1, 1);

        tabWidget->addTab(solved, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(SolveApply);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SolveApply);
    } // setupUi

    void retranslateUi(QWidget *SolveApply)
    {
        SolveApply->setWindowTitle(QCoreApplication::translate("SolveApply", "Widget", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SolveApply", "\347\224\263\350\257\267\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SolveApply", "\347\224\263\350\257\267\344\272\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SolveApply", "\345\221\230\345\267\245\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SolveApply", "\347\224\263\350\257\267\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SolveApply", "\347\224\263\350\257\267\350\277\233\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SolveApply", "\345\217\227\347\220\206\344\272\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(unsolved), QCoreApplication::translate("SolveApply", "\345\276\205\345\244\204\347\220\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("SolveApply", "\347\224\263\350\257\267\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("SolveApply", "\347\224\263\350\257\267\344\272\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("SolveApply", "\345\221\230\345\267\245\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("SolveApply", "\347\224\263\350\257\267\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("SolveApply", "\347\224\263\350\257\267\350\277\233\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("SolveApply", "\345\217\227\347\220\206\344\272\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(solved), QCoreApplication::translate("SolveApply", "\345\267\262\345\244\204\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SolveApply: public Ui_SolveApply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLVEAPPLY_H
