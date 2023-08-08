#include "sala_mana.h"
#include "ui_sala_mana.h"

Sala_Mana::Sala_Mana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sala_Mana)
{
    ui->setupUi(this);
    for(int i=0;i<12;i++){
        ui->month_combo->addItem(QString::number(i+1)+QString("月"));
    }
    QDateTime time = QDateTime::currentDateTime();
    int year = time.date().year();
    int month = time.date().month();
    for(int i=2000;i<=year;i++){
        ui->year_combo->addItem(QString::number(i)+QString("年"));
    }
    ui->year_combo->setCurrentIndex(year-2000);

    ui->month_combo->setCurrentIndex(month-1);
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setColumnWidth(0, width * 0.14);
    ui->tableWidget->setColumnWidth(1, width * 0.14);
    ui->tableWidget->setColumnWidth(2, width * 0.14);
    ui->tableWidget->setColumnWidth(3, width * 0.14);
    ui->tableWidget->setColumnWidth(4, width * 0.14);
    ui->tableWidget->setColumnWidth(5, width * 0.15);
    ui->tableWidget->setColumnWidth(6, width * 0.15);
}

Sala_Mana::~Sala_Mana()
{
    delete ui;
}

void Sala_Mana::resizeEvent(QResizeEvent *event)
{
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnWidth(0, width * 0.14);
    ui->tableWidget->setColumnWidth(1, width * 0.14);
    ui->tableWidget->setColumnWidth(2, width * 0.14);
    ui->tableWidget->setColumnWidth(3, width * 0.14);
    ui->tableWidget->setColumnWidth(4, width * 0.14);
    ui->tableWidget->setColumnWidth(5, width * 0.15);
    ui->tableWidget->setColumnWidth(6, width * 0.15);
}
