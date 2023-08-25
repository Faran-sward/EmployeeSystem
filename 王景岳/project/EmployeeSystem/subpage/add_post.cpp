#include "add_post.h"
#include "ui_add_post.h"

Add_post::Add_post(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_post)
{
    ui->setupUi(this);
    ui->addButton->setStyleSheet("background-color:rgb(65,105,225);color:rgb(255, 255, 255);font:10pt;");
    ui->widget_2->setStyleSheet("QWidget#widget_2{background-color:transparent;}");
    ui->frame->setStyleSheet("QFrame#frame{background-color:#aaff7f;border:none;border-radius:15px;}");

}

Add_post::~Add_post()
{
    delete ui;
}

void Add_post::on_addButton_clicked()
{
    if(ui->numEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：职位编号不得为空！");
        return;
    }
    if(ui->nameEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：职位名称不得为空！");
        return;
    }
    if(ui->buildEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：职位类型不得为空！");
        return;
    }
    if(ui->floorEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：职位等级不得为空！");
        return;
    }
    /*
     * 类似创建账号，发送网络请求
     */
    emit closeSignal();
}

void Add_post::requestFinished(QNetworkReply *reply)
{
    /*
     * 类似创建账号，接收网络请求结果
     */
}
