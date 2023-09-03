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
    emit needSignal();
}

void Add_post::requestFinished(QNetworkReply *reply)
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
        ResultJson =  QString::fromStdString(bytes.toStdString());
        if(bytes.toStdString()=="{\"backCode\":1}"){
            qDebug() << ui->nameEdit->text()<<"已创建成功";
            ui->errorText->setStyleSheet("border: none;color:rgb(86, 144, 130);");
            ui->errorText->setText("职位" + ui->numEdit->text()+"已创建成功");
            emit closeSignal();
        }
        else{
            ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
            ui->errorText->setText("该职位已创建，部门创建失败！");
            return;
        }
    }
}

void Add_post::getName(QString name)
{
    /*
     * 类似创建账号，发送网络请求
     */
    ui->errorText->setStyleSheet("border: none;color:rgb(86, 144, 130);");
    ui->errorText->setText("正在创建中，请稍等");
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);

    QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
    QString strUrl="http://8.130.119.222:1751/api/Values/newBuildPost?DepartmentID="+name+"&PostID="+ui->numEdit->text()+"&PostTitle="+ui->nameEdit->text()+"&PostType="+ui->buildEdit->text()+"&PostLevel="+ui->floorEdit->text();
    request.setUrl(QUrl(strUrl));
    naManager->get(request);
}
