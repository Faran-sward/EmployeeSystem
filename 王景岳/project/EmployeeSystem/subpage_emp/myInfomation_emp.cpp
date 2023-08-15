#include "myInfomation_emp.h"
#include "ui_myInfomation_emp.h"

MyInfomation_Emp::MyInfomation_Emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyInfomation_Emp)
{
    ui->setupUi(this);
    ui->bscEnsure->hide();
    ui->bscCancel->hide();
    connect(ui->bscChangeInfo, &QPushButton::clicked, this, &MyInfomation_Emp::bscChangeInfo);

    ui->bscName->setReadOnly(true);
    ui->bscId->setReadOnly(true);
    ui->bscWorkstate->setReadOnly(true);
    ui->bscIDNumber->setReadOnly(true);
    ui->bscSex->setReadOnly(true);
    ui->bscTele->setReadOnly(true);
    ui->bscBirth->setReadOnly(true);
    ui->bscAddress->setReadOnly(true);
    ui->bscSalary->setReadOnly(true);
}
MyInfomation_Emp::~MyInfomation_Emp()
{
    delete ui;
}

//基本信息呈现
void MyInfomation_Emp::basicInfomation(const QString& employeeID){
    QJsonObject json;
    json["EmployeeID"] = employeeID;
    QJsonDocument jsonDoc(json);
    QString url = "http://8.130.115.212:1234/api/FundamentalInfo/Get/"+ QString::fromUtf8(jsonDoc.toJson(QJsonDocument::Compact));

    qDebug() <<url;

    // 创建网络访问管理器和请求对象
    networkManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));

    // 发送 GET 请求
    QNetworkReply *reply = networkManager->get(request);

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
                    Employee_Emp tempEmployee(obj);
                    //呈现信息
                    ui->bscName->setText(employee.Name);
                    ui->bscId->setText(employee.EmployeeID);
                    ui->bscWorkstate->setText(employee.WorkState);
                    ui->bscIDNumber->setText(employee.ID_number);
                    ui->bscSex->setText(employee.Sex);
                    ui->bscTele->setText(employee.PhoneNumber);
                    ui->bscBirth->setText(employee.Birth);
                    ui->bscAddress->setText(employee.HomeAddress);
                    ui->bscSalary->setText(employee.Salary);
                    this->employee=tempEmployee;
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
void MyInfomation_Emp::bscChangeInfo()
{
    // 设置文本框为可写模式
    ui->bscName->setReadOnly(false);
    ui->bscId->setReadOnly(false);
    ui->bscWorkstate->setReadOnly(false);
    ui->bscIDNumber->setReadOnly(false);
    ui->bscSex->setReadOnly(false);
    ui->bscTele->setReadOnly(false);
    ui->bscBirth->setReadOnly(false);
    ui->bscAddress->setReadOnly(false);
    ui->bscSalary->setReadOnly(false);

    // 隐藏原始按钮
    ui->bscChangeInfo->hide();
    //呈现新按钮
    ui->bscCancel->show();
    ui->bscEnsure->show();


    // 关联"ensure"按钮的槽函数
    connect(ui->bscEnsure, &QPushButton::clicked, this, &MyInfomation_Emp::bscEnsure);

    // 关联"cancel"按钮的槽函数
    connect(ui->bscCancel, &QPushButton::clicked, this, &MyInfomation_Emp::bscCancel);
}


void MyInfomation_Emp::bscEnsure()
{
    Employee_Emp temp;
    temp = employee;

    // 保存修改后的信息到原始类employeeinfo中
    employee.Name = ui->bscName->text();
    employee.EmployeeID = ui->bscId->text();
    employee.Birth=ui->bscBirth->text();
    employee.HomeAddress=ui->bscAddress->text();
    employee.ID_number=ui->bscIDNumber->text();
    employee.PhoneNumber=ui->bscTele->text();
    employee.Salary=ui->bscSalary->text();
    employee.Sex=ui->bscSex->text();
    employee.WorkState=ui->bscWorkstate->text();

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

    QString url = "http://8.130.115.212:1234/api/FundamentalInfo/Update/"+QString::fromUtf8(setJsonDoc.toJson(QJsonDocument::Compact))+ QString::fromUtf8(searchJsonDoc.toJson(QJsonDocument::Compact));
    qDebug() <<url;

    // 创建网络访问管理器和请求对象
    networkManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    //应该还是get请求
    QNetworkReply *reply = networkManager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [=]()  {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug()<<"修改人员信息成功";
        } else {
            // 请求失败
            qDebug() << "修改人员信息失败" << reply->errorString();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

void MyInfomation_Emp::bscCancel()
{
    // 取消修改并恢复原始信息
    ui->bscName->setText(employee.Name);
    ui->bscId->setText(employee.EmployeeID);
    ui->bscWorkstate->setText(employee.WorkState);
    ui->bscIDNumber->setText(employee.ID_number);
    ui->bscSex->setText(employee.Sex);
    ui->bscTele->setText(employee.PhoneNumber);
    ui->bscBirth->setText(employee.Birth);
    ui->bscAddress->setText(employee.HomeAddress);
    ui->bscSalary->setText(employee.Salary);

    // 显示原始按钮
    ui->bscChangeInfo->show();

    // 移除新按钮
    ui->bscEnsure->hide();
    ui->bscCancel->hide();
}
