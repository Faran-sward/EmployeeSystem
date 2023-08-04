/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "navlistview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *btnMenu_Close;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu_Min;
    QWidget *widgetLeft;
    QHBoxLayout *horizontalLayout;
    NavListView *navListView;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QWidget *page_2;
    QLabel *label_2;
    QWidget *page_3;
    QLabel *label_3;
    QWidget *page_4;
    QLabel *label_4;
    QWidget *page_5;
    QStackedWidget *page5_stack;
    QWidget *page_7;
    QLabel *label_8;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QTableView *deployment;
    QPushButton *pushButton_3;
    QWidget *page_9;
    QLabel *label_6;
    QWidget *page_10;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetTitle = new QWidget(centralwidget);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        widgetTitle->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(widgetTitle);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QString::fromUtf8("labIco"));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
        labTitle->setSizePolicy(sizePolicy1);
        labTitle->setStyleSheet(QString::fromUtf8(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(labTitle);

        widgetTop = new QWidget(widgetTitle);
        widgetTop->setObjectName(QString::fromUtf8("widgetTop"));
        horizontalLayout_2 = new QHBoxLayout(widgetTop);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(widgetTop);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy2);
        toolButton->setCheckable(true);
        toolButton->setAutoExclusive(true);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton->setAutoRaise(false);

        horizontalLayout_2->addWidget(toolButton);

        toolButton_2 = new QToolButton(widgetTop);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        sizePolicy2.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy2);
        toolButton_2->setCheckable(true);
        toolButton_2->setAutoExclusive(true);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextOnly);

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(widgetTop);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        sizePolicy2.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy2);
        toolButton_3->setCheckable(true);
        toolButton_3->setChecked(false);
        toolButton_3->setAutoExclusive(true);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextOnly);

        horizontalLayout_2->addWidget(toolButton_3);


        horizontalLayout_3->addWidget(widgetTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QString::fromUtf8("widgetMenu"));
        gridLayout_2 = new QGridLayout(widgetMenu);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 3);

        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QString::fromUtf8("btnMenu_Close"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy3);
        btnMenu_Close->setMinimumSize(QSize(30, 30));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Close, 0, 3, 1, 1);

        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QString::fromUtf8("btnMenu_Max"));
        sizePolicy3.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy3);
        btnMenu_Max->setMinimumSize(QSize(30, 30));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Max, 0, 2, 1, 1);

        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QString::fromUtf8("btnMenu_Min"));
        sizePolicy3.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy3);
        btnMenu_Min->setMinimumSize(QSize(30, 30));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Min, 0, 1, 1, 1);


        horizontalLayout_3->addWidget(widgetMenu);


        verticalLayout->addWidget(widgetTitle);

        widgetLeft = new QWidget(centralwidget);
        widgetLeft->setObjectName(QString::fromUtf8("widgetLeft"));
        horizontalLayout = new QHBoxLayout(widgetLeft);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        navListView = new NavListView(widgetLeft);
        navListView->setObjectName(QString::fromUtf8("navListView"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(navListView->sizePolicy().hasHeightForWidth());
        navListView->setSizePolicy(sizePolicy4);
        navListView->setSeparateVisible(false);
        navListView->setSeparateHeight(1);

        horizontalLayout->addWidget(navListView);

        stackedWidget = new QStackedWidget(widgetLeft);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy5);
        stackedWidget->setMinimumSize(QSize(0, 0));
        stackedWidget->setBaseSize(QSize(0, 0));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 190, 40, 12));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 150, 40, 12));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 150, 40, 12));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_4 = new QLabel(page_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 190, 40, 12));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page5_stack = new QStackedWidget(page_5);
        page5_stack->setObjectName(QString::fromUtf8("page5_stack"));
        page5_stack->setGeometry(QRect(-1, 19, 541, 471));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        label_8 = new QLabel(page_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 20, 51, 16));
        textBrowser = new QTextBrowser(page_7);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(40, 40, 451, 31));
        pushButton = new QPushButton(page_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 90, 80, 18));
        pushButton_2 = new QPushButton(page_7);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 90, 80, 18));
        label_9 = new QLabel(page_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 130, 51, 16));
        deployment = new QTableView(page_7);
        deployment->setObjectName(QString::fromUtf8("deployment"));
        deployment->setGeometry(QRect(45, 150, 471, 192));
        pushButton_3 = new QPushButton(page_7);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 360, 80, 18));
        page5_stack->addWidget(page_7);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        label_6 = new QLabel(page_9);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 140, 40, 12));
        page5_stack->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        label_7 = new QLabel(page_10);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 120, 40, 12));
        page5_stack->addWidget(page_10);
        stackedWidget->addWidget(page_5);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(widgetLeft);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);
        page5_stack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labIco->setText(QString());
        labTitle->setText(QString());
        toolButton->setText(QCoreApplication::translate("MainWindow", "\345\205\254\345\217\270\347\256\200\344\273\213", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "\351\200\232\347\237\245\344\277\241\346\201\257", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
#if QT_CONFIG(tooltip)
        btnMenu_Close->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMenu_Close->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
#if QT_CONFIG(tooltip)
        btnMenu_Max->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\250\345\261\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMenu_Max->setText(QCoreApplication::translate("MainWindow", "\342\226\241", nullptr));
#if QT_CONFIG(tooltip)
        btnMenu_Min->setToolTip(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMenu_Min->setText(QCoreApplication::translate("MainWindow", "\357\274\215", nullptr));
        navListView->setItems(QCoreApplication::translate("MainWindow", "\344\270\273\347\225\214\351\235\242||0||,\345\234\260\345\233\276\347\233\221\346\216\247|\344\270\273\347\225\214\351\235\242|||,\350\247\206\351\242\221\347\233\221\346\216\247|\344\270\273\347\225\214\351\235\242|||0xf03d,\350\256\276\345\244\207\347\233\221\346\216\247|\344\270\273\347\225\214\351\235\242|||0xf108,\347\263\273\347\273\237\350\256\276\347\275\256||0||,\351\230\262\345\214\272\344\277\241\346\201\257|\347\263\273\347\273\237\350\256\276\347\275\256|||0xf0e8,\344\275\215\347\275\256\350\260\203\346\225\264|\347\263\273\347\273\237\350\256\276\347\275\256|||0xf060,\345\234\260\345\233\276\347\274\226\350\276\221|\347\263\273\347\273\237\350\256\276\347\275\256|||0xf03e", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "page0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "page1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "page2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "page3", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\350\201\214\345\212\241", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\217\230\345\212\250\347\224\263\350\257\267", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\347\246\273\350\201\214\347\224\263\350\257\267", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\350\260\203\351\205\215\350\256\260\345\275\225", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\350\260\203\351\205\215\347\224\263\350\257\267", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "pge4-2", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "page4-3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
