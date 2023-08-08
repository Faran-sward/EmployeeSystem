#include "sala_info.h"
#include "ui_sala_info.h"

Sala_Info::Sala_Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sala_Info)
{
    ui->setupUi(this);
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setColumnWidth(0, width * 0.16);
    ui->tableWidget->setColumnWidth(1, width * 0.16);
    ui->tableWidget->setColumnWidth(2, width * 0.17);
    ui->tableWidget->setColumnWidth(3, width * 0.17);
    ui->tableWidget->setColumnWidth(4, width * 0.17);
    ui->tableWidget->setColumnWidth(5, width * 0.17);
}

Sala_Info::~Sala_Info()
{
    delete ui;
}

void Sala_Info::resizeEvent(QResizeEvent *event)
{
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnWidth(0, width * 0.16);
    ui->tableWidget->setColumnWidth(1, width * 0.16);
    ui->tableWidget->setColumnWidth(2, width * 0.17);
    ui->tableWidget->setColumnWidth(3, width * 0.17);
    ui->tableWidget->setColumnWidth(4, width * 0.17);
    ui->tableWidget->setColumnWidth(5, width * 0.17);
}
