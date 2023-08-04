/********************************************************************************
** Form generated from reading UI file 'dept_pos.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPT_POS_H
#define UI_DEPT_POS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dept_Pos
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *name_lab;
    QLabel *num_lab;
    QLabel *build_lab;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *floor_lab;
    QSpacerItem *horizontalSpacer_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QTableWidget *auth_table;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *post_table;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *staff_table;

    void setupUi(QWidget *Dept_Pos)
    {
        if (Dept_Pos->objectName().isEmpty())
            Dept_Pos->setObjectName(QString::fromUtf8("Dept_Pos"));
        Dept_Pos->resize(686, 539);
        verticalLayout_2 = new QVBoxLayout(Dept_Pos);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(30, 10, 30, 0);
        horizontalSpacer_3 = new QSpacerItem(623, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_3);

        comboBox = new QComboBox(Dept_Pos);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(171, 21));

        verticalLayout_2->addWidget(comboBox);

        widget = new QWidget(Dept_Pos);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(7);
        gridLayout->setContentsMargins(0, 0, -1, 0);
        name_lab = new QLabel(widget);
        name_lab->setObjectName(QString::fromUtf8("name_lab"));
        sizePolicy.setHeightForWidth(name_lab->sizePolicy().hasHeightForWidth());
        name_lab->setSizePolicy(sizePolicy);
        name_lab->setMinimumSize(QSize(221, 21));

        gridLayout->addWidget(name_lab, 0, 3, 1, 2);

        num_lab = new QLabel(widget);
        num_lab->setObjectName(QString::fromUtf8("num_lab"));
        sizePolicy.setHeightForWidth(num_lab->sizePolicy().hasHeightForWidth());
        num_lab->setSizePolicy(sizePolicy);
        num_lab->setMinimumSize(QSize(151, 21));

        gridLayout->addWidget(num_lab, 0, 0, 1, 1);

        build_lab = new QLabel(widget);
        build_lab->setObjectName(QString::fromUtf8("build_lab"));
        sizePolicy.setHeightForWidth(build_lab->sizePolicy().hasHeightForWidth());
        build_lab->setSizePolicy(sizePolicy);
        build_lab->setMinimumSize(QSize(171, 21));

        gridLayout->addWidget(build_lab, 1, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(211, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 5, 1, 1);

        floor_lab = new QLabel(widget);
        floor_lab->setObjectName(QString::fromUtf8("floor_lab"));
        sizePolicy.setHeightForWidth(floor_lab->sizePolicy().hasHeightForWidth());
        floor_lab->setSizePolicy(sizePolicy);
        floor_lab->setMinimumSize(QSize(111, 21));

        gridLayout->addWidget(floor_lab, 1, 3, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 5, 1, 1);


        verticalLayout_2->addWidget(widget);

        tabWidget = new QTabWidget(Dept_Pos);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        auth_table = new QTableWidget(tab);
        if (auth_table->columnCount() < 3)
            auth_table->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        auth_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        auth_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        auth_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        auth_table->setObjectName(QString::fromUtf8("auth_table"));

        horizontalLayout->addWidget(auth_table);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        post_table = new QTableWidget(tab_2);
        if (post_table->columnCount() < 4)
            post_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        post_table->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        post_table->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        post_table->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        post_table->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        post_table->setObjectName(QString::fromUtf8("post_table"));

        horizontalLayout_2->addWidget(post_table);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_3 = new QHBoxLayout(tab_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        staff_table = new QTableWidget(tab_3);
        if (staff_table->columnCount() < 4)
            staff_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        staff_table->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        staff_table->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        staff_table->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        staff_table->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        staff_table->setObjectName(QString::fromUtf8("staff_table"));

        horizontalLayout_3->addWidget(staff_table);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(Dept_Pos);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dept_Pos);
    } // setupUi

    void retranslateUi(QWidget *Dept_Pos)
    {
        Dept_Pos->setWindowTitle(QCoreApplication::translate("Dept_Pos", "Form", nullptr));
        name_lab->setText(QCoreApplication::translate("Dept_Pos", "\351\203\250\351\227\250\345\220\215\347\247\260\357\274\232", nullptr));
        num_lab->setText(QCoreApplication::translate("Dept_Pos", "\351\203\250\351\227\250\347\274\226\345\217\267\357\274\232", nullptr));
        build_lab->setText(QCoreApplication::translate("Dept_Pos", "\346\211\200\345\234\250\346\245\274\357\274\232", nullptr));
        floor_lab->setText(QCoreApplication::translate("Dept_Pos", "\346\211\200\345\234\250\346\245\274\345\261\202\357\274\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem = auth_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Dept_Pos", "\350\201\214\344\275\215\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = auth_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Dept_Pos", "\345\275\223\345\211\215\350\247\204\346\250\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = auth_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Dept_Pos", "\351\242\204\350\256\241\350\247\204\346\250\241", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Dept_Pos", "\347\274\226\345\210\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = post_table->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Dept_Pos", "\350\201\214\344\275\215\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = post_table->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Dept_Pos", "\350\201\214\344\275\215\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = post_table->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Dept_Pos", "\350\201\214\344\275\215\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = post_table->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Dept_Pos", "\350\201\214\344\275\215\347\255\211\347\272\247", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Dept_Pos", "\345\262\227\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = staff_table->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Dept_Pos", "\345\221\230\345\267\245\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = staff_table->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Dept_Pos", "\345\275\223\345\211\215\350\201\214\344\275\215\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = staff_table->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Dept_Pos", "\345\275\223\345\211\215\346\211\200\345\234\250\345\237\216\345\270\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = staff_table->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Dept_Pos", "\345\205\245\350\201\214\346\227\266\351\227\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Dept_Pos", "\345\221\230\345\267\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dept_Pos: public Ui_Dept_Pos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPT_POS_H
