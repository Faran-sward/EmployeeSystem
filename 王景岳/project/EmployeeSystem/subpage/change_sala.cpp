#include "change_sala.h"
#include "ui_change_sala.h"

Change_Sala::Change_Sala(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change_Sala)
{
    ui->setupUi(this);
    ui->addButton->setStyleSheet("background-color:rgb(65,105,225);color:rgb(255, 255, 255);font:10pt;");
    ui->addButton_2->setStyleSheet("background-color:rgb(230,105,105);color:rgb(255, 255, 255);font:10pt;");
    ui->widget_2->setStyleSheet("QWidget#widget_2{background-color:transparent;}");
    ui->frame->setStyleSheet("QFrame#frame{background-color:#aaff7f;border:none;border-radius:15px;}");
    QRegExp regExp("[0-9]{1,10}");
    ui->nameEdit->setValidator(new QRegExpValidator(regExp, this));
    ui->buildEdit->setValidator(new QRegExpValidator(regExp, this));
    ui->floorEdit->setValidator(new QRegExpValidator(regExp, this));
}

Change_Sala::~Change_Sala()
{
    delete ui;
}

void Change_Sala::setInfo(QString num,QString basic,QString bonus,QString comm)
{
    numnow=num;
    ui->numLab->setText("员工工号："+num);
    ui->nameEdit->setText(basic);
    ui->buildEdit->setText(bonus);
    ui->floorEdit->setText(comm);
}

void Change_Sala::on_addButton_clicked()
{
    if(ui->nameEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：底薪不得为空！");
        return;
    }
    if(ui->buildEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：奖金不得为空！");
        return;
    }
    if(ui->floorEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：绩效不得为空！");
        return;
    }
    /*
     * 类似创建账号，发送网络请求
     */
    ui->errorText->setStyleSheet("border: none;color:rgb(86, 144, 130);");
    ui->errorText->setText("正在变更中，请稍等");
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);

    QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
    QString strUrl="http://8.130.119.222:1751/api/Values/ChangeSalary?EmployeeID="+numnow+"&BasicSalary="+ui->nameEdit->text()+"&Bonus="+ui->buildEdit->text()+"&Commission="+ui->floorEdit->text();
    request.setUrl(QUrl(strUrl));
    naManager->get(request);
}

void Change_Sala::on_addButton_2_clicked()
{
    emit closeSignal();
}

void Change_Sala::requestFinished(QNetworkReply *reply)
{
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
        ui->errorText->setText("变更失败，请检查网络！");
        return;
    }
    else
    {
        qDebug() << "ResultJson  is  " <<  QString::fromStdString(bytes.toStdString());
        ResultJson =  QString::fromStdString(bytes.toStdString());
        if(bytes.toStdString()=="{\"backCode\":1}"){
            qDebug() << ui->nameEdit->text()<<"已变更成功";
            ui->errorText->setStyleSheet("border: none;color:rgb(86, 144, 130);");
            ui->errorText->setText("员工" + numnow+"薪资信息已变更成功");
            emit changedSignal();
            emit closeSignal();
        }
        else{
            ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
            ui->errorText->setText("已不可变更，变更失败！");
            return;
        }
    }
}
