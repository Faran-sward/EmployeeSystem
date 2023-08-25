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
    QStringList line_header;
    line_header <<"序号"<<"起始时间"<<"结束时间"<<"考勤类型"<<"操作";
    ui->att_table->setRowCount(15);
    ui->att_table->setColumnCount(line_header.size());
    ui->att_table->setHorizontalHeaderLabels(line_header);

    QTableWidgetItem *check_1 = new QTableWidgetItem();
    check_1->setCheckState(Qt::Unchecked);
    QTableWidgetItem *check_2 = new QTableWidgetItem();
    check_2->setCheckState(Qt::Unchecked);

    ui->att_table->setItem(0,0,new QTableWidgetItem("1"));
    ui->att_table->setItem(0,1,new QTableWidgetItem("2023-07-19 08:05:00"));
    ui->att_table->setItem(0,2,new QTableWidgetItem("2023-07-19 17:06:00"));
    ui->att_table->setItem(0,3,new QTableWidgetItem("正常"));
    QTableWidgetItem *item_1=ui->att_table->item(0,3);
    item_1->setForeground(QColor(85,170,0));
    ui->att_table->setItem(0,4,check_1);
    ui->att_table->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->att_table->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->att_table->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->att_table->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    ui->att_table->setItem(1,0,new QTableWidgetItem("2"));
    ui->att_table->setItem(1,1,new QTableWidgetItem("2023-07-20 08:05:00"));
    ui->att_table->setItem(1,2,new QTableWidgetItem("2023-07-20 17:07:00"));
    ui->att_table->setItem(1,3,new QTableWidgetItem("加班"));
    QTableWidgetItem *item_2=ui->att_table->item(1,3);
    item_2->setForeground(QColor(255,0,0));
    ui->att_table->setItem(1,4,check_2);
    ui->att_table->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->att_table->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->att_table->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->att_table->item(1,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    ui->att_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->att_table->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->att_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->att_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->att_table->setAlternatingRowColors(true);
    ui->att_table->verticalHeader()->setVisible(false);
    ui->att_table->setShowGrid(false);

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
        sch_model->item(0,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        sch_model->item(1,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }

    ui->sch_table->setModel(sch_model);
    ui->sch_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->sch_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->sch_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MyAttendance::on_pushButton_clicked(){

    if(!flag){
        QPropertyAnimation* animation=new QPropertyAnimation(ui->sch_table,"maximumHeight");
        animation->setStartValue(200);
        animation->setEndValue(0);
        animation->setDuration(800);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->start();
        ui->pushButton->setText("显示排班");
        flag=!flag;
    }
    else{
        QPropertyAnimation* animation=new QPropertyAnimation(ui->sch_table,"maximumHeight");
        animation->setStartValue(0);
        animation->setEndValue(200);
        animation->setDuration(800);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->start();
        ui->pushButton->setText("隐藏排班");
        flag=!flag;
    }
}

void MyAttendance::on_signin_clicked(){
    QMessageBox::information(this,"提示","签到成功");
}
