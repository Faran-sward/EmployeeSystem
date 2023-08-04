#include "mainwindow.h"
#include "ui_mainwindow.h"




//调配信息查询（-7.28）
// 发送请求并接收返回数据
void MainWindow::deploymentRecord(const QString& employeeID)
{
    QJsonObject json;
    json["EmployeeID"] = employeeID;
    QJsonDocument jsonDoc(json);
    QString url = "http://8.130.115.212:1234/api/BussinessInfo/Get/"+ QString::fromUtf8(jsonDoc.toJson(QJsonDocument::Compact));

    qDebug() <<url;

    // 请求的 URL{"EmployeeID":"E0001"}

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
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonArray jsonArray = jsonResponse.array();
            if (jsonArray.isEmpty()) {
                // 未找到相应信息
                qDebug() << "未查找到相应信息";
                return;
            }

            // 显示调配记录表格
            QStandardItemModel* model = new QStandardItemModel();
            model->setHorizontalHeaderLabels({"EmployeeID", "BusinessID", "BusinessEnterpriseName", "BusinessDepartmentName", "BusinessPostName", "StartTime", "EndTime"});
            ui->deployment->setModel(model);

            for (const QJsonValue& jsonValue : jsonArray) {
                QJsonObject jsonObject = jsonValue.toObject();
                QString employeeID = jsonObject.value("EmployeeID").toString();
                QString businessID = jsonObject.value("BusinessID").toString();
                QString enterpriseName = jsonObject.value("BusinessEnterpriseName").toString();
                QString departmentName = jsonObject.value("BusinessDepartmentName").toString();
                QString postName = jsonObject.value("BusinessPostName").toString();
                QString startTime = jsonObject.value("StartTime").toString();
                QString endTime = jsonObject.value("EndTime").toString();

                QList<QStandardItem*> rowData;
                rowData << new QStandardItem(employeeID);
                rowData << new QStandardItem(businessID);
                rowData << new QStandardItem(enterpriseName);
                rowData << new QStandardItem(departmentName);
                rowData << new QStandardItem(postName);
                rowData << new QStandardItem(startTime);
                rowData << new QStandardItem(endTime);
                model->appendRow(rowData);
            }
            ui->deployment->show();
        } else {
            // 请求失败
            qDebug() << "请求失败" << reply->errorString();
            QStandardItemModel* model = new QStandardItemModel();
            model->setHorizontalHeaderLabels({"请求错误"});
            ui->deployment->setModel(model);
            ui->deployment->show();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

//7.31
//基本信息呈现
void MainWindow::basicInfomation(const QString& employeeID){
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
                    Employee tempEmployee(obj);
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
void MainWindow::bscChangeInfo()
{
    // 设置文本框为只读模式
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
    connect(ui->bscEnsure, &QPushButton::clicked, this, &MainWindow::bscEnsure);

    // 关联"cancel"按钮的槽函数
    connect(ui->bscCancel, &QPushButton::clicked, this, &MainWindow::bscCancel);
}


void MainWindow::bscEnsure()
{
    Employee temp;
    temp = employee;


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
            // 保存修改后的信息到原始类employeeinfo中,连接到url才能修改成功
            employee.Name = ui->bscName->text();
            employee.EmployeeID = ui->bscId->text();
            employee.Birth=ui->bscBirth->text();
            employee.HomeAddress=ui->bscAddress->text();
            employee.ID_number=ui->bscIDNumber->text();
            employee.PhoneNumber=ui->bscTele->text();
            employee.Salary=ui->bscSalary->text();
            employee.Sex=ui->bscSex->text();
            employee.WorkState=ui->bscWorkstate->text();
        } else {
            // 请求失败
            qDebug() << "请求失败" << reply->errorString();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

void MainWindow::bscCancel()
{
    // 取消修改并恢复原始信息
    ui->bscName->setText(employee.Name);
    ui->bscId->setText(employee.Name);
    ui->bscWorkstate->setText(employee.Name);
    ui->bscIDNumber->setText(employee.Name);
    ui->bscSex->setText(employee.Name);
    ui->bscTele->setText(employee.Name);
    ui->bscBirth->setText(employee.Name);
    ui->bscAddress->setText(employee.Name);
    ui->bscSalary->setText(employee.Name);

    // 显示原始按钮
    ui->bscChangeInfo->show();

    // 移除新按钮
    ui->bscEnsure->hide();
    ui->bscCancel->hide();
}
