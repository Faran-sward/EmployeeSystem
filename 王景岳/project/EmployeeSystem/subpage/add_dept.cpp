#include "add_dept.h"
#include "ui_add_dept.h"

Add_dept::Add_dept(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_dept)
{
    ui->setupUi(this);
    ui->addButton->setStyleSheet("background-color:rgb(65,105,225);color:rgb(255, 255, 255);font:10pt;");
    ui->widget_2->setStyleSheet("QWidget#widget_2{background-color:transparent;}");
    ui->frame->setStyleSheet("QFrame#frame{background-color:#aaff7f;border:none;border-radius:15px;}");
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
    ui->errorText->setStyleSheet("border: none;color:rgb(86, 144, 130);");
    ui->errorText->setText("正在创建中，请稍等");
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);

    QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
    QString strUrl="http://8.130.119.222:1751/api/Values/newBuildDept?DepartmentID="+ui->numEdit->text()+"&DepartmentTitle="+ui->nameEdit->text()+"&Building="+ui->buildEdit->text()+"&layer="+ui->floorEdit->text();
    request.setUrl(QUrl(strUrl));
    naManager->get(request);
}

void Add_dept::requestFinished(QNetworkReply *reply)
{
    /*
     * 类似创建账号，接收网络请求结果
     */
    QString ResultJson;
    QByteArray bytes = reply->readAll();
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(statusCode.isValid())
    {
        qDebug() << "status code=" << statusCode.toInt();
    }
    QNetworkReply::NetworkError err = reply->error();
    if(err != QNetworkReply::NoError)
    {
        qDebug() << "Failed: " << reply->errorString();
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("创建失败，请检查网络！");
        return;
    }
    else
    {
        qDebug() << "ResultJson  is  " <<  QString::fromStdString(bytes.toStdString());
        ResultJson =  QString::fromStdString(bytes.toStdString());
        if(bytes.toStdString()=="{\"backCode\":1}"){
            qDebug() << ui->nameEdit->text()<<"已创建成功";
            ui->errorText->setStyleSheet("border: none;color:rgb(86, 144, 130);");
            ui->errorText->setText("部门" + ui->numEdit->text()+"已创建成功");
            emit closeSignal();
        }
        else{
            ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
            ui->errorText->setText("该部门已创建，部门创建失败！");
            return;
        }
    }
}
