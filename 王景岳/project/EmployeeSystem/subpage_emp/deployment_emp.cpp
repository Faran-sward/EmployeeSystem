#include "deployment_emp.h"
#include "ui_deployment_emp.h"
#include <qdatetime.h>
#include <QCollator>

Deployment_Emp::Deployment_Emp(QString employeeID,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deployment_Emp)
{
    ui->setupUi(this);
    this->employeeID = employeeID;
    getName();//把名字得到
    changeComboBoxInitiate();//ComboBox的内容初始化

    ui->widget_6->hide();
    QIcon icon(":/images/down.png");
    ui->ApplyPresentButton->setIcon(icon);
    ui->ApplyPresentButton->setIconSize(ui->ApplyPresentButton->size());  // 将图片大小设置为按钮部件的大小

    ui->deployment->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//使得表格能够适应大小

    jobRecord();
    deploymentRecord();

    applyButtonAnimation();
    applyAnimation();
    submitApply();
}

Deployment_Emp::~Deployment_Emp()
{
    delete ui;
}

//得到名字
void Deployment_Emp::getName(){

    QString jsonString = "{\"EmployeeID\":\"" + employeeID + "\"}";
    QString url = "http://8.130.119.222:1240/api/HLControllers/GetAllBasicInfo/" +QString::fromUtf8(jsonString.toUtf8().toPercentEncoding());
    //qDebug() <<url;

    // 创建网络访问管理器和请求对象
    QNetworkAccessManager* networkManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));

    // 发送 GET 请求
    QNetworkReply *reply = networkManager->get(request);

    // 响应成功时处理返回数据
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObj = jsonDoc.object();
            QJsonObject basicInfoObj = jsonObj["BasicInfo"].toObject();
            name = basicInfoObj["Name"].toString();
        } else {
            qDebug() << "请求失败" << reply->errorString();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

//职务信息查询
void Deployment_Emp::jobRecord()
{
    QString ID = employeeID;
    QString jsonString = "{\"EmployeeID\":\"" + ID + "\"}";
    QString url = "http://8.130.119.222:1240/api/HLControllers/GetPostInfo/" +QString::fromUtf8(jsonString.toUtf8().toPercentEncoding());
    //qDebug()<<url;

    // 创建网络访问管理器和请求对象
    QNetworkAccessManager* networkManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));

    // 发送 GET 请求
    QNetworkReply *reply = networkManager->get(request);

    ui->textEdit->setReadOnly(true); // 设置为不可写入
    ui->textEdit->setFontPointSize(16); // 设置文字大小为16号

    // 响应成功时处理返回数据
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonArray jsonArray = jsonResponse.array();

            if (!jsonArray.isEmpty()) {
                QJsonValue postTitleValue = jsonArray.at(0).toObject().value("PostTitle");
                if (postTitleValue.isString()) {
                    QString postTitle = postTitleValue.toString();
                    ui->textEdit->setText(postTitle);
                }
            } else {
                ui->textEdit->setText("没有岗位信息");
            }
        } else {
            ui->textEdit->setText("请求错误");
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

//调配记录查询
void Deployment_Emp::deploymentRecord()
{
    QString ID = employeeID;
    QString jsonString = "{\"EmployeeID\":\"" + ID + "\"}";
    QString url = "http://8.130.119.222:1240/api/BusinessInfo/Get/" +QString::fromUtf8(jsonString.toUtf8().toPercentEncoding());
    qDebug()<<url;

    // 创建网络访问管理器和请求对象
    QNetworkAccessManager* networkManager = new QNetworkAccessManager();
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

            // 清空表格
            ui->deployment->clear();

            // 设置表格的行数
            int rowCount = jsonArray.size();
            ui->deployment->setRowCount(rowCount);

            // 设置表格的列数和水平表头标签
            int columnCount = 7;
            ui->deployment->setColumnCount(columnCount);
            ui->deployment->setHorizontalHeaderLabels({"员工号", "外派号", "外派目的公司", "外派目的任职", "BusinessPostName", "起始时间", "结束时间"});

            // 向表格添加数据
            for (int i = 0; i < rowCount; i++) {

                QJsonObject jsonObject = jsonArray[i].toObject();
                QString employeeID = jsonObject.value("EmployeeID").toString();
                QString businessID = jsonObject.value("BusinessID").toString();
                QString enterpriseName = jsonObject.value("BusinessEnterpriseName").toString();
                QString departmentName = jsonObject.value("BusinessDepartmentName").toString();
                QString postName = jsonObject.value("BusinessPostName").toString();
                QString startTime = jsonObject.value("StartTime").toString();
                QString endTime = jsonObject.value("EndTime").toString();

                // 在每个单元格中设置表格项
                QTableWidgetItem* itemEmployeeID = new QTableWidgetItem(employeeID);
                QTableWidgetItem* itemBusinessID = new QTableWidgetItem(businessID);
                QTableWidgetItem* itemEnterpriseName = new QTableWidgetItem(enterpriseName);
                QTableWidgetItem* itemDepartmentName = new QTableWidgetItem(departmentName);
                QTableWidgetItem* itemPostName = new QTableWidgetItem(postName);
                QTableWidgetItem* itemStartTime = new QTableWidgetItem(startTime);
                QTableWidgetItem* itemEndTime = new QTableWidgetItem(endTime);

                ui->deployment->setItem(i, 0, itemEmployeeID);
                ui->deployment->setItem(i, 1, itemBusinessID);
                ui->deployment->setItem(i, 2, itemEnterpriseName);
                ui->deployment->setItem(i, 3, itemDepartmentName);
                ui->deployment->setItem(i, 4, itemPostName);
                ui->deployment->setItem(i, 5, itemStartTime);
                ui->deployment->setItem(i, 6, itemEndTime);
            }

            ui->deployment->show();
        } else {
            qDebug()<<"deployment失败";
            // 请求失败
            ui->deployment->setRowCount(1);
            QTableWidgetItem* itemError = new QTableWidgetItem(reply->errorString());
            ui->deployment->setItem(0, 0, itemError);
            ui->deployment->show();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

void Deployment_Emp::changeComboBoxInitiate(){

    QString url = "http://8.130.119.222:1240/api/HLControllers/GetAllPostInfo";

    QNetworkAccessManager *manager=new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));

    QNetworkReply *reply = manager->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();

            // 解析返回的JSON数据
            QJsonDocument jsonData = QJsonDocument::fromJson(data);
            if (jsonData.isArray()) {
                QJsonArray jsonArray = jsonData.array();

                QStringList jobs;
                for (int i = 0; i < jsonArray.size();i++) {
                    QJsonObject jsonObj = jsonArray[i].toObject();
                    QString postTitle = jsonObj["PostTitle"].toString();

                    jobs.append(postTitle); // 添加选项
                }
                ui->changecombox->clear();
                ui->changecombox->addItems(jobs);
            }
        }

        // 请求结束后释放reply对象
        reply->deleteLater();
    });
}

void Deployment_Emp::applyAnimation(){
    connect(ui->dplmtChange, &QPushButton::clicked, this, [=]() {

        QPropertyAnimation* animation = new QPropertyAnimation(ui->widget, "minimumWidth");
        animation->setStartValue(0);
        animation->setEndValue(250);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->setDuration(800);
        animation->start();

        ui->applyType->setText("变动申请");
        ui->changewidget->show();
        ui->resignationwidget->hide();
        applyAddInfomation();
    });
    connect(ui->dplmtLeave, &QPushButton::clicked, this, [=]() {

        QPropertyAnimation* animation = new QPropertyAnimation(ui->widget, "minimumWidth");
        animation->setStartValue(0);
        animation->setEndValue(250);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->setDuration(800);
        animation->start();

        ui->applyType->setText("离职申请");
        ui->changewidget->hide();
        ui->resignationwidget->show();
        applyAddInfomation();
    });
    connect(ui->cancelApply,&QPushButton::clicked,this,[=](){
        QPropertyAnimation* animation = new QPropertyAnimation(ui->widget, "minimumWidth");
        animation->setStartValue(250);
        animation->setEndValue(0);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->setDuration(800);
        animation->start();
    });
}

void Deployment_Emp::applyButtonAnimation(){

    connect(ui->ApplyPresentButton, &QPushButton::clicked, this, [=]() {
        if(flagApplyPresentButton == true){
            QPropertyAnimation* animation = new QPropertyAnimation(ui->ApplyButtonWidget, "minimumHeight");
            animation->setStartValue(0);
            animation->setEndValue(30);
            animation->setEasingCurve(QEasingCurve::InOutQuad);
            animation->setDuration(800);
            animation->start();
            QIcon icon(":/images/on.png");
            ui->ApplyPresentButton->setIcon(icon);
            ui->ApplyPresentButton->setIconSize(ui->ApplyPresentButton->size());  // 将图片大小设置为按钮部件的大小

            flagApplyPresentButton = false;
        }else{
            QPropertyAnimation* animation = new QPropertyAnimation(ui->ApplyButtonWidget, "minimumHeight");
            animation->setStartValue(30);
            animation->setEndValue(0);
            animation->setEasingCurve(QEasingCurve::InOutQuad);
            animation->setDuration(800);
            animation->start();
            QIcon icon(":/images/down.png");
            ui->ApplyPresentButton->setIcon(icon);
            ui->ApplyPresentButton->setIconSize(ui->ApplyPresentButton->size());  // 将图片大小设置为按钮部件的大小

            flagApplyPresentButton = true;
        }
    });

}

void Deployment_Emp::getApplyID()
{
    QString url = "http://8.130.119.222:1240/api/HLControllers/GetNewApplyID";

    // 创建网络访问管理器和请求对象
    QNetworkAccessManager* networkManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));

    // 发送 GET 请求
    QNetworkReply *reply = networkManager->get(request);

    // 等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString newApplyID = "-1"; // 默认为-1，表示获取失败

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonResponse.object();

        if (jsonObject.contains("NewApplyID")) {
            newApplyID = jsonObject.value("NewApplyID").toString();
        }
    }

    ui->applyNumber->setText("申请号 ： " + newApplyID);
    reply->deleteLater();
}

//在ui文件中呈现信息，并关键信息都保存到变量中
void Deployment_Emp::applyAddInfomation(){

    getApplyID();//要等它结束才能继续进行
    ui->applyPerson->setText("申请人 ： " + employeeID);
    QString timeString = "申请时间 ：";
    QDateTime currentDateTime = QDateTime::currentDateTime();
    applyTime = currentDateTime.toString("dd-M'月'-yy");
    timeString += applyTime;
    ui->applytime->setText(timeString);

    applyID = ui->applyNumber->text().remove("申请号 ： ");
    //qDebug()<<"applyID"<<applyID;
}

void Deployment_Emp::submitApply(){
    connect(ui->submitApply, &QPushButton::clicked, this, [=]() {
        QString jsonString1 = "{\"ApplyID\":\"" + applyID + "\",";
        QString jsonString2 = "\"ApplicantID\":\"" + employeeID + "\",";
        QString jsonString3 = "\"ApplicantName\":\"" + name + "\",";
        QString jsonString4 = "\"StartTime\":\"" + applyTime + "\",";
        QString jsonString5 = "\"CondutorName\":\"暂无\",";
        QString jsonString6;
        if(ui->applyType->text()=="离职申请"){
            jsonString6 = "\"Content\":\"" + ui->resignationlabel->text() + "\",";
        }else{
            jsonString6 = "\"Content\":\"" + ui->changelabel->text()+"，目标职位："+ui->changecombox->currentText() + "\",";
        }
        QString jsonString7 = "\"Progress\":\"待审批\"}";
        QString jsonString = jsonString1+jsonString2+jsonString3+jsonString4+jsonString5+jsonString6+jsonString7;

        QString url = "http://8.130.119.222:1240/api/ApplyInfo/Insert/" +QString::fromUtf8(jsonString.toUtf8().toPercentEncoding());
        //qDebug()<<url;

        // 创建网络访问管理器和请求对象
        QNetworkAccessManager* networkManager = new QNetworkAccessManager();
        QNetworkRequest request;
        request.setUrl(QUrl(url));

        // 发送 GET 请求
        QNetworkReply *reply = networkManager->get(request);

        // 响应成功时处理返回数据
        QObject::connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                //窗口弹回去
                QPropertyAnimation* animation = new QPropertyAnimation(ui->widget, "minimumWidth");
                animation->setStartValue(250);
                animation->setEndValue(0);
                animation->setEasingCurve(QEasingCurve::InOutQuad);
                animation->setDuration(800);
                animation->start();

                // 显示标签
                ui->applyIfSucceed->setText("申请成功");
                ui->widget_6->show();

                // 创建一个定时器
                QTimer *timer = new QTimer(this);
                // 设置定时器触发的时间间隔为3秒
                timer->setInterval(3000); // 单位为毫秒

                // 连接定时器的timeout()信号到槽函数
                connect(timer, &QTimer::timeout, this, [=]() {
                    // 隐藏标签
                    ui->widget_6->hide();

                    // 在需要的情况下，可以删除定时器
                    timer->deleteLater();
                });

                // 启动定时器
                timer->start();

            } else {
                //窗口弹回去
                QPropertyAnimation* animation = new QPropertyAnimation(ui->widget, "minimumWidth");
                animation->setStartValue(250);
                animation->setEndValue(0);
                animation->setEasingCurve(QEasingCurve::InOutQuad);
                animation->setDuration(800);
                animation->start();

                // 显示标签
                ui->applyIfSucceed->setText("申请失败");
                ui->widget_6->show();

                // 创建一个定时器
                QTimer *timer = new QTimer(this);
                // 设置定时器触发的时间间隔为3秒
                timer->setInterval(3000); // 单位为毫秒

                // 连接定时器的timeout()信号到槽函数
                connect(timer, &QTimer::timeout, this, [=]() {
                    // 隐藏标签
                    ui->widget_6->hide();

                    // 在需要的情况下，可以删除定时器
                    timer->deleteLater();
                });

                // 启动定时器
                timer->start();
            }
            reply->deleteLater();
            networkManager->deleteLater();
        });
    });
}
