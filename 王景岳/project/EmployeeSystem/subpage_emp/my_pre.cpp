#include "my_pre.h"
#include "ui_my_pre.h"

My_Pre::My_Pre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::My_Pre)
{
    ui->setupUi(this);
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(0, width * 0.20);
    ui->tableWidget->setColumnWidth(1, width * 0.20);
    ui->tableWidget->setColumnWidth(2, width * 0.20);
    ui->tableWidget->setColumnWidth(3, width * 0.20);
    ui->tableWidget->setColumnWidth(4, width * 0.20);
}

My_Pre::~My_Pre()
{
    delete ui;
}

void My_Pre::resizeEvent(QResizeEvent *event)
{
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnWidth(0, width * 0.20);
    ui->tableWidget->setColumnWidth(1, width * 0.20);
    ui->tableWidget->setColumnWidth(2, width * 0.20);
    ui->tableWidget->setColumnWidth(3, width * 0.20);
    ui->tableWidget->setColumnWidth(4, width * 0.20);
}
