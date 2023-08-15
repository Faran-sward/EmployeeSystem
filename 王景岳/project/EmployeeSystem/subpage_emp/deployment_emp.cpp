#include "deployment_emp.h"
#include "ui_deployment_emp.h"

Deployment_Emp::Deployment_Emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deployment_Emp)
{
    ui->setupUi(this);
}

Deployment_Emp::~Deployment_Emp()
{
    delete ui;
}

//调配信息查询
// 发送请求并接收返回数据
void Deployment_Emp::deploymentRecord(const QString& employeeID)
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
            model->setHorizontalHeaderLabels({"员工号", "外派号", "外派目的公司", "外派目的任职", "BusinessPostName", "起始时间", "结束时间"});
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
