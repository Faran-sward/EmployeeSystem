#include "contractreg.h"
#include "ui_contractreg.h"



ContractReg::ContractReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContractReg)
{
    ui->setupUi(this);
    setWindowFlags (Qt::CustomizeWindowHint);
    connect(ui->ToContractInfoBtn,&QPushButton::clicked,this,&ContractReg::ToContractInfo);
    connect(ui->upload,SIGNAL(clicked(bool)),this,SLOT(contract_upload()));
}

ContractReg::~ContractReg()
{
    delete ui;
}



void ContractReg::on_lineEdit_editingFinished()
{
    new_employee_id=ui->lineEdit->text();
    if(new_employee_id.length()!=5)
    {
        ui->label_7->setText("工号有误，请重新输入");
    }
    else
    {
        ui->label_7->setText("");
    }
    return;
}

void ContractReg::on_lineEdit_2_editingFinished()
{
    new_contract_id=ui->lineEdit_2->text();
    if(new_contract_id.length()!=5)
    {
        ui->label_8->setText("合同号有误，请重新输入");
    }
    else
    {
        ui->label_8->setText("");
    }
    return;
}


void ContractReg::on_lineEdit_3_editingFinished()
{
    new_contract_type=ui->lineEdit_3->text();
}

void ContractReg::on_lineEdit_4_editingFinished()
{
    new_effective_date=ui->lineEdit_4->text();
}

void ContractReg::on_lineEdit_5_editingFinished()
{
    new_inoperative_date=ui->lineEdit_5->text();
}

void ContractReg::on_lineEdit_6_editingFinished()
{
    new_document_link=ui->lineEdit_6->text();
}

void ContractReg::encode_url(QString str, QByteArray &outArr)
{
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    if(codec->canEncode(str)) {
        QByteArray tmpArr;
        tmpArr = codec->fromUnicode(str);
        for(int i=0,size = tmpArr.length();i<size;i++){
            char ch = tmpArr.at(i);
            if(ch < 128 && ch > 0){
                outArr.append(ch);
            }else{
                uchar low = ch & 0xff;
                char c[3];
                sprintf(c,"%02X",low);
                outArr.append("%").append(c);
            }
        }
    }
}


void ContractReg::contract_upload(void)
{
    QByteArray type_urlb,state_urlb,link_urlb;
    QString type_url,state_url,link_url;
    QString str2="未生效" ;
    encode_url(new_contract_type,type_urlb);
    encode_url(str2,state_urlb);
    encode_url(new_document_link,link_urlb);

    type_url=QString(type_urlb);
    state_url=QString(state_urlb);
    link_url=QString(link_urlb);
    QString str="http://8.130.119.222:2580/api/WebDBtest/send_contract?"
                  "Employee_ID="+new_employee_id+"&Contract_ID="+new_contract_id+
                  "&Contract_Type="+type_url+"&Contract_State="+state_url+
                  "&Effective_Date="+new_effective_date+"&Inoperative_Date="+new_inoperative_date+
                  "&Document_Link="+link_url;
    qDebug()<<str;

    QNetworkRequest request;
    request.setUrl(str);
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()),&eventLoop, SLOT(quit()));
    eventLoop.exec(QEventLoop::ExcludeUserInputEvents);

    //对请求的返回异常进行处理
    if(reply->error() != QNetworkReply::NoError)
    {
        ui->label_12->setText("错误，请联系管理员");
    }

    //解析返回的Json结果
    QByteArray replyData = reply->readAll();
    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(replyData, &json_error));
    if(json_error.error != QJsonParseError::NoError)
    {
        ui->label_12->setText("错误，请联系管理员");
    }

}
