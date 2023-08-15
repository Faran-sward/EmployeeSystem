#include "mycontract_info.h"
#include "ui_mycontract_info.h"

Mycontract_Info::Mycontract_Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mycontract_Info)
{
    ui->setupUi(this);
    //合同查看的查询按键
    connect(ui->testpush,SIGNAL(clicked(bool)),this,SLOT(Contractcheck()));
    ui->testpush->setStyleSheet("background-color:rgb(65,105,225);color:rgb(255, 255, 255);font:10pt;");
    ui->testpush->setIconSize(QSize(20,20));
}

void Mycontract_Info::Contractcheck(void)  //合同查看函数
{
    QUrl url("http://8.130.119.222:2580/api/WebDBtest/GetText2?Employee_ID=E0004&Contract_ID=99888");
    QNetworkRequest request;

    request.setUrl(url);
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()),&eventLoop, SLOT(quit()));
    eventLoop.exec(QEventLoop::ExcludeUserInputEvents);

    //对请求的返回异常进行处理
    if(reply->error() != QNetworkReply::NoError)
    {
        ui->textBrowser->insertPlainText("错误，请联系管理员");
    }

    //解析返回的Json结果
    QByteArray replyData = reply->readAll();
    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(replyData, &json_error));
    if(json_error.error != QJsonParseError::NoError)
    {
        ui->textBrowser->insertPlainText("错误，请联系管理员");
    }
    QJsonObject rootObj = jsonDoc.object();
    QString codeStr = rootObj.value("employeeID").toString();
    QString codeStr2 = rootObj.value("contractId").toString();
    QString codeStr3 = rootObj.value("contractType").toString();
    QString codeStr4 = rootObj.value("contractState").toString();
    QString codeStr5 = rootObj.value("effectiveDate").toString();
    QString codeStr6 = rootObj.value("inoperativeDate").toString();
    QString codeStr7 = rootObj.value("documentLink").toString();

    ui->textBrowser->setText("");
    ui->textBrowser_10->setText("");
    ui->textBrowser_11->setText("");
    ui->textBrowser_12->setText("");
    ui->textBrowser_13->setText("");
    ui->textBrowser_14->setText("");
    ui->textBrowser_15->setText("");

    ui->textBrowser->insertPlainText(codeStr);
    ui->textBrowser_10->insertPlainText(codeStr2);
    ui->textBrowser_11->insertPlainText(codeStr3);
    ui->textBrowser_12->insertPlainText(codeStr4);
    ui->textBrowser_13->insertPlainText(codeStr5);
    ui->textBrowser_14->insertPlainText(codeStr6);
    ui->textBrowser_15->insertPlainText(codeStr7);

}

Mycontract_Info::~Mycontract_Info()
{
    delete ui;
}
