#include "myattendance.h"
#include "ui_myattendance.h"

MyAttendance::MyAttendance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyAttendance)
{
    ui->setupUi(this);
}

MyAttendance::~MyAttendance()
{
    delete ui;
}

void MyAttendance::show_table(){
    // 输出考勤表
    att_model=new QStandardItemModel();
    QStringList line_header;
    line_header<<"起始时间"<<"结束时间"<<"考勤类型";
    att_model->setHorizontalHeaderLabels(line_header);
    att_model->setRowCount(10);

    QPushButton* feedback=new QPushButton();
    feedback->setText("申请核实");
    feedback->setEnabled(true);

    att_model->setItem(0,0,new QStandardItem("2023-07-19 08:05:00"));
    att_model->setItem(0,1,new QStandardItem("2023-07-19 17:06:00"));
    att_model->setItem(0,2,new QStandardItem("正常"));

    att_model->setItem(1,0,new QStandardItem("2023-07-20 08:05:00"));
    att_model->setItem(1,1,new QStandardItem("2023-07-19 17:07:00"));
    att_model->setItem(1,2,new QStandardItem("正常"));

    att_model->setItem(2,0,new QStandardItem("2023-07-21 08:05:00"));
    att_model->setItem(2,1,new QStandardItem("2023-07-19 19:08:00"));
    att_model->setItem(2,2,new QStandardItem("加班"));

    ui->att_table->setModel(att_model);

    ui->att_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->att_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->att_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->att_table->setAlternatingRowColors(true);

    // 输出排班表
    sch_model = new QStandardItemModel();
    QStringList line_header_;
    line_header_<<"周一"<<"周二"<<"周三"<<"周四"<<"周五"<<"周六"<<"周日";
    sch_model->setHorizontalHeaderLabels(line_header_);
    QStringList row_header;
    row_header<<"上午"<<"下午";
    sch_model->setVerticalHeaderLabels(row_header);

    QString data={"1111100"};

    for(int i=0; i<7; i++){
        if(data[i]=='0'){
            sch_model->setItem(0,i,new QStandardItem("×"));
            sch_model->setItem(1,i,new QStandardItem("×"));
        }
        else{
            sch_model->setItem(0,i,new QStandardItem("√"));
            sch_model->setItem(1,i,new QStandardItem("√"));
        }
    }

    ui->sch_table->setModel(sch_model);
    ui->sch_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->sch_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->sch_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
