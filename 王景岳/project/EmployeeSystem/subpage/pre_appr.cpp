#include "pre_appr.h"
#include "ui_pre_appr.h"

Pre_Appr::Pre_Appr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pre_Appr)
{
    ui->setupUi(this);
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setColumnWidth(0, width * 0.25);
    ui->tableWidget->setColumnWidth(1, width * 0.25);
    ui->tableWidget->setColumnWidth(2, width * 0.25);
    ui->tableWidget->setColumnWidth(3, width * 0.25);
    ui->widget->setStyleSheet("#widget{background-color:rgb(255,255,255);}");
}

Pre_Appr::~Pre_Appr()
{
    delete ui;
}

void Pre_Appr::resizeEvent(QResizeEvent *event)
{
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnWidth(0, width * 0.25);
    ui->tableWidget->setColumnWidth(1, width * 0.25);
    ui->tableWidget->setColumnWidth(2, width * 0.25);
    ui->tableWidget->setColumnWidth(3, width * 0.25);
}
