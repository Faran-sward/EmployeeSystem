#include "add_dept.h"
#include "ui_add_dept.h"

Add_dept::Add_dept(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_dept)
{
    ui->setupUi(this);
    ui->addButton->setStyleSheet("background-color:rgb(65,105,225);color:rgb(255, 255, 255);font:10pt;");
}

Add_dept::~Add_dept()
{
    delete ui;
}

void Add_dept::on_addButton_clicked()
{
    if(ui->numEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：部门编号不得为空！");
        return;
    }
    if(ui->nameEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：部门名称不得为空！");
        return;
    }
    if(ui->buildEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：所在楼不得为空！");
        return;
    }
    if(ui->floorEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：所在楼层不得为空！");
        return;
    }
    /*
     * 类似创建账号，发送网络请求
     */
}

void Add_dept::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
    event->accept();
}

void Add_dept::requestFinished(QNetworkReply *reply)
{
    /*
     * 类似创建账号，接收网络请求结果
     */
}
