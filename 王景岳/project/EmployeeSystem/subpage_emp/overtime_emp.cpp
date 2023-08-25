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
    line_header<<"序号"<<"申请人"<<"起始时间"<<"结束时间"<<"状态";
    work_model->setHorizontalHeaderLabels(line_header);
    work_model->setRowCount(15);

    ui->work_table->setModel(work_model);

    ui->work_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->work_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->work_table->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->work_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->refresh->setFlat(false);
    ui->request->setFlat(false);
    ui->work_table->setAlternatingRowColors(true);
    ui->work_table->verticalHeader()->setVisible(false);
    ui->startEdit->setPlaceholderText("例:2023-01-01");
    ui->endEdit->setPlaceholderText("例:2023-01-01");
}

void Overtime_Emp::on_request_clicked(){
    ui->personEdit->setText("徐辰");
    ui->numEdit->setText("2150264");
    if(!flag){
        QPropertyAnimation* animation=new QPropertyAnimation(ui->application,"maximumWidth");
        animation->setStartValue(400);
        animation->setEndValue(0);
        animation->setDuration(800);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->start();
        flag=!flag;
    }
    else{
        QPropertyAnimation* animation=new QPropertyAnimation(ui->application,"maximumWidth");
        animation->setStartValue(0);
        animation->setEndValue(400);
        animation->setDuration(800);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->start();
        flag=!flag;
    }
}

void Overtime_Emp::on_handapply_clicked(){

    if(ui->personEdit->text()==""||ui->numEdit->text()==""||ui->startEdit->text()==""||ui->endEdit->text()==""){
        QMessageBox::warning(this,"提示","请填写完整信息");
    }
    else{
        QMessageBox::information(this,"提示","提交成功");
        if(!flag){
            QPropertyAnimation* animation=new QPropertyAnimation(ui->application,"maximumWidth");
            animation->setStartValue(400);
            animation->setEndValue(0);
            animation->setDuration(800);
            animation->setEasingCurve(QEasingCurve::InOutQuad);
            animation->start();
            flag=!flag;
        }
        int row = ui->work_table->model()->rowCount();
        for(int i=0; i<row; i++){
            if(work_model->item(i,0) == nullptr){
                work_model->setItem(i,0,new QStandardItem(QString::number(i+1,10)));
                QString start_time = ui->startEdit->text()+":"+ui->start_h->currentText()+":"+ui->start_m->currentText();
                QString end_time=ui->endEdit->text()+":"+ui->end_h->currentText()+":"+ui->end_m->currentText();
                work_model->setItem(i,1,new QStandardItem(ui->personEdit->text()));
                work_model->setItem(i,2,new QStandardItem(start_time));
                work_model->setItem(i,3,new QStandardItem(end_time));
                work_model->setItem(i,4,new QStandardItem("未通过"));
                work_model->item(i,4)->setForeground(QBrush(QColor(255, 0, 0)));
                work_model->item(i,0)->setTextAlignment(Qt::AlignCenter);
                work_model->item(i,1)->setTextAlignment(Qt::AlignCenter);
                work_model->item(i,2)->setTextAlignment(Qt::AlignCenter);
                work_model->item(i,3)->setTextAlignment(Qt::AlignCenter);
                work_model->item(i,4)->setTextAlignment(Qt::AlignCenter);
                break;
            }
        }
        ui->personEdit->clear();
        ui->numEdit->clear();
        ui->startEdit->clear();
        ui->endEdit->clear();
        ui->work_table->setModel(work_model);
    }

}

void Overtime_Emp::on_cancelapply_clicked(){
    if(!flag){
        QPropertyAnimation* animation=new QPropertyAnimation(ui->application,"maximumWidth");
        animation->setStartValue(400);
        animation->setEndValue(0);
        animation->setDuration(800);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->start();
        flag=!flag;
    }
}
