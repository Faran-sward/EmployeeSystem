#include "change_auth.h"
#include "ui_change_auth.h"

Change_Auth::Change_Auth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change_Auth)
{
    ui->setupUi(this);
    ui->addButton->setStyleSheet("background-color:rgb(65,105,225);color:rgb(255, 255, 255);font:10pt;");
    ui->addButton_2->setStyleSheet("background-color:rgb(230,105,105);color:rgb(255, 255, 255);font:10pt;");
    ui->widget_2->setStyleSheet("QWidget#widget_2{background-color:transparent;}");
    ui->frame->setStyleSheet("QFrame#frame{background-color:#aaff7f;border:none;border-radius:15px;}");
    QRegExp regExp("[0-9]{1,10}");
    ui->floorEdit->setValidator(new QRegExpValidator(regExp, this));
}

Change_Auth::~Change_Auth()
{
    delete ui;
}

void Change_Auth::setInfo(QString deid,QString dename,QString poid,QString poname,QString num)
{
    deptnumnow=deid;
    postnumnow=poid;
    ui->numLab->setText("部门名称："+dename);
    ui->nameLab->setText("岗位编号："+poid);
    ui->buildLab->setText("岗位名称："+poname);
    ui->floorEdit->setText(num);
}

void Change_Auth::on_addButton_clicked()
{
    if(ui->floorEdit->text().length()==0){
        ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
        ui->errorText->setText("错误：新的预计规模不得为空！");
        return;
    }
    ui->errorText->setStyleSheet("border: none;color:rgb(86, 144, 130);");
    ui->errorText->setText("正在变更中，请稍等");
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);

    QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
    QString strUrl="http://8.130.119.222:1751/api/Values/changeScale?DepartmentID="+deptnumnow+"&PostID="+postnumnow+"&EmulatedScale="+ui->floorEdit->text();
    request.setUrl(QUrl(strUrl));
    naManager->get(request);
}

void Change_Auth::on_addButton_2_clicked()
{
    emit closeSignal();
}

void Change_Auth::requestFinished(QNetworkReply *reply)
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
            qDebug() << "已变更成功";
            ui->errorText->setStyleSheet("border: none;color:rgb(86, 144, 130);");
            ui->errorText->setText(deptnumnow+"部门"+postnumnow+"岗位编制已变更成功");
            emit changedSignal();
            emit closeSignal();
        }
        else{
            ui->errorText->setStyleSheet("border: none;color:rgb(255, 0, 0);");
            ui->errorText->setText("变更失败！");
            return;
        }
    }
}
