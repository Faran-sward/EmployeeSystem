#include "myInfomation.h"
#include "ui_myInfomation.h"
MyInfomation::MyInfomation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyInfomation)
{
    ui->setupUi(this);
    ui->bscEnsure->hide();
    ui->bscCancel->hide();
    connect(ui->bscChangeInfo, &QPushButton::clicked, this, &MyInfomation::bscChangeInfo);

    ui->bscIDNumber->setReadOnly(true);
    ui->bscSex->setReadOnly(true);
    ui->bscSalary->setReadOnly(true);
    ui->bscBirth->setReadOnly(true);

    ui->bscAddress->setReadOnly(true);
    ui->bscTele->setReadOnly(true);

    basicInfomation("E0001");
}

MyInfomation::~MyInfomation()
{
    delete ui;
}

void MyInfomation::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);
    raise();

    QPainter painter(this);
    painter.setPen(Qt::NoPen);

    QLinearGradient gradient(0, 0, width(), 0);

    gradient.setColorAt(0, QColor("#0072ff")); //  #0072ff
    gradient.setColorAt(1, QColor("#00c6ff")); // #00c6ff

    painter.setBrush(gradient);
    //painter.drawRect(0, 0, width(), height());

//    painter.drawRect(0, 0, 30,height());
//    painter.drawRect(50, 0, 70,height());
//    painter.drawRect(220, 0, 20,100);
//    painter.drawRect(270, 0, 50,height());
//    painter.drawRect(370, 0, 60,100);
//    painter.drawRect(450, 0, 20,100);
//    painter.drawRect(560, 0, 60,height());


}

//基本信息呈现
void MyInfomation::basicInfomation(const QString& employeeID){

    QString ID = employeeID;
    QString jsonString = "{\"EmployeeID\":\"" + ID + "\"}";
    QString url = "http://8.130.119.222:1234/api/FundamentalInfo/Get/" +QString::fromUtf8(jsonString.toUtf8().toPercentEncoding());
    //qDebug() <<url;

    // 创建网络访问管理器和请求对象
    networkManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));

    // 发送 GET 请求
    QNetworkReply *reply = networkManager->get(request);
    QNetworkReply *reply2 = networkManager->get(request);

    // 响应成功时处理返回数据
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
            QJsonArray jsonArray = jsonDoc.array();
            for (const QJsonValue& value : jsonArray)
            {
                if (value.isObject())
                {
                    QJsonObject obj = value.toObject();
                    Employee tempEmployee(obj);
                    this->employee=tempEmployee;
                    //呈现信息

                    ui->bscWorkstate->setText("●"+employee.WorkState);
                    if(employee.WorkState!= "异常"){
                        ui->bscWorkstate->setStyleSheet("QLabel { color: #009933; }");
                    }else{
                        ui->bscWorkstate->setStyleSheet("QLabel { color: #FF0055; }");
                    }


                    ui->bscName->setText(employee.Name);
                    ui->bscID->setText(employee.EmployeeID);

                    ui->bscIDNumber->setText(employee.ID_number);
                    ui->bscSex->setText(employee.Sex);
                    ui->bscTele->setText(employee.PhoneNumber);
                    ui->bscBirth->setText(employee.Birth);
                    ui->bscAddress->setText(employee.HomeAddress);
                    ui->bscSalary->setText(employee.Salary);
                }
            }
        } else {
            // 请求失败
            qDebug() << "请求失败" << reply->errorString();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}
//基本信息修改
void MyInfomation::bscChangeInfo()
{
    //对可修改和不可修改项进行处理
    ui->bscIDNumber->setDisabled(true);
    ui->bscSex->setDisabled(true);
    ui->bscSalary->setDisabled(true);
    ui->bscBirth->setDisabled(true);

    ui->bscAddress->setReadOnly(false);
    ui->bscTele->setReadOnly(false);

    // 隐藏原始按钮
    ui->bscChangeInfo->hide();
    //呈现新按钮
    ui->bscCancel->show();
    ui->bscEnsure->show();


    // 关联"ensure"按钮的槽函数
    connect(ui->bscEnsure, &QPushButton::clicked, this, &MyInfomation::bscEnsure);

    // 关联"cancel"按钮的槽函数
    connect(ui->bscCancel, &QPushButton::clicked, this, &MyInfomation::bscCancel);
}


void MyInfomation::bscEnsure()
{
    Employee temp;
    temp = employee;

    // 保存修改后的信息到原始类employeeinfo中
    employee.HomeAddress=ui->bscAddress->text();
    employee.PhoneNumber=ui->bscTele->text();


    // 显示原始按钮
    ui->bscChangeInfo->show();

    // 隐藏按钮
    ui->bscEnsure->hide();
    ui->bscCancel->hide();

    //修改了就要向后端传递信息
    QJsonObject search_json = temp.toJson();//更改前
    QJsonDocument searchJsonDoc(search_json);
    QJsonObject set_json = employee.toJson();//更改后
    QJsonDocument setJsonDoc(set_json);

    //QString url = "http://8.130.119.222:1234/api/FundamentalInfo/Update/"+QString::fromUtf8(setJsonDoc.toJson(QJsonDocument::Compact))+ QString::fromUtf8(searchJsonDoc.toJson(QJsonDocument::Compact));

    QString baseUrl = "http://8.130.119.222:1234/api/FundamentalInfo/Update/";
    QString setJson = QString::fromUtf8(setJsonDoc.toJson(QJsonDocument::Compact));
    QString searchJson = QString::fromUtf8(searchJsonDoc.toJson(QJsonDocument::Compact));

    // URL编码
    QString encodedSetJson = QUrl::toPercentEncoding(setJson);
    QString encodedSearchJson = QUrl::toPercentEncoding(searchJson);

    QString url = baseUrl + encodedSetJson + encodedSearchJson;

    //qDebug() << url;

    // 创建网络访问管理器和请求对象
    networkManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    //应该还是get请求
    QNetworkReply *reply = networkManager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [=]()  {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug()<<"修改人员信息成功";
            ui->bscTele->setText(employee.PhoneNumber);
            ui->bscAddress->setText(employee.HomeAddress);
        } else {
            // 请求失败
            qDebug() << "修改人员信息失败" << reply->errorString();
            employee = temp;
            ui->bscTele->setText(employee.PhoneNumber);
            ui->bscAddress->setText(employee.HomeAddress);
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });


    //对可修改和不可修改项进行处理
    ui->bscIDNumber->setDisabled(false);
    ui->bscSex->setDisabled(false);
    ui->bscSalary->setDisabled(false);
    ui->bscBirth->setDisabled(false);

    ui->bscAddress->setReadOnly(true);
    ui->bscTele->setReadOnly(true);
}

void MyInfomation::bscCancel()
{
    // 取消修改并恢复原始信息
    ui->bscTele->setText(employee.PhoneNumber);
    ui->bscAddress->setText(employee.HomeAddress);

    // 显示原始按钮
    ui->bscChangeInfo->show();

    // 移除新按钮
    ui->bscEnsure->hide();
    ui->bscCancel->hide();

    //对可修改和不可修改项进行处理
    ui->bscIDNumber->setDisabled(false);
    ui->bscSex->setDisabled(false);
    ui->bscSalary->setDisabled(false);
    ui->bscBirth->setDisabled(false);

    ui->bscAddress->setReadOnly(true);
    ui->bscTele->setReadOnly(true);
}
