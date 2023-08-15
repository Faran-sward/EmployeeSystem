#include "overtime_emp.h"
#include "ui_overtime_emp.h"

Overtime_Emp::Overtime_Emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Overtime_Emp)
{
    ui->setupUi(this);
}

Overtime_Emp::~Overtime_Emp()
{
    delete ui;
}

void Overtime_Emp::show_overtime(){

    work_model=new QStandardItemModel();
    QStringList line_header;
    line_header<<"申请时间"<<"起始时间"<<"结束时间"<<"状态";
    work_model->setHorizontalHeaderLabels(line_header);
    work_model->setRowCount(15);

    ui->work_table->setModel(work_model);

    ui->work_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->work_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->work_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->refresh->setFlat(false);
    ui->request->setFlat(false);
    ui->work_table->setAlternatingRowColors(true);
}
