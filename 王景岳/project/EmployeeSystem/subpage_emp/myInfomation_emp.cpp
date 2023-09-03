#include "myInfomation_emp.h"
#include "ui_myInfomation_emp.h"

#include <QPropertyAnimation>

MyInfomation_Emp::MyInfomation_Emp(QString employeeID,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyInfomation_Emp)
{
    ui->setupUi(this);
    employee.EmployeeID = employeeID;

    ui->bscEnsure->hide();
    ui->bscCancel->hide();
    connect(ui->bscChangeInfo, &QPushButton::clicked, this, &MyInfomation_Emp::bscChangeInfo);

    ui->bscIDNumber->setReadOnly(true);
    ui->bscSex->setReadOnly(true);
    ui->bscBirth->setReadOnly(true);

    ui->bscAddress->setReadOnly(true);
    ui->bscTele->setReadOnly(true);

    ui->bscEducation->setReadOnly(true);
    ui->bscSalary->setReadOnly(true);

    applyAnimation();
    exitAnimation();

    basicInfomation();

    //if(employee.ImageURL=="有")
    picPresent();
}
MyInfomation_Emp::~MyInfomation_Emp()
{
    delete ui;
}

void MyInfomation_Emp::picPresent(){
    QNetworkRequest request;
    QString url = "http://8.130.119.222:1235/"+employee.EmployeeID+".jpg";
    request.setUrl(QUrl(url));

    // 发送请求并等待响应
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    // 检查请求是否成功
    if (reply->error() == QNetworkReply::NoError) {
        // 读取返回的图片数据
        QByteArray imageData = reply->readAll();

        // 创建一个图像对象
        QImage image;
        if (image.loadFromData(imageData)) {
            // 设置图像到 QLabel 中
            ui->bscPicture->setPixmap(QPixmap::fromImage(image));
            ui->bscPicture->setScaledContents(true); // 自动缩放图片以适应 QLabel
        }
    } else {
        // 请求失败就提示错误消息
        qDebug() << "Picture Load Error: " << reply->errorString();
    }

    // 清理资源
    reply->deleteLater();
}


//基本信息呈现
void MyInfomation_Emp::basicInfomation(){

    QString ID = employee.EmployeeID;
    QString jsonString = "{\"EmployeeID\":\"" + ID + "\"}";
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
            dealBasicInfo(jsonObj);
            dealEduInfo(jsonObj);
            dealSalaryInfo(jsonObj);
        } else {
            // 请求失败
            qDebug() << "请求失败" << reply->errorString();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

void MyInfomation_Emp::dealBasicInfo(QJsonObject jsonObj){
    QJsonObject basicInfoObj = jsonObj["BasicInfo"].toObject();

    Employee_Emp tempEmployee(basicInfoObj);
    this->employee = tempEmployee;

    // 呈现信息
    ui->bscWorkstate->setText("●" + employee.WorkState);
    if (employee.WorkState != "异常") {
        ui->bscWorkstate->setStyleSheet("QLabel { color: #009933; }");
    } else {
            ui->bscWorkstate->setStyleSheet("QLabel { color: #FF0055; }");
        }

    ui->bscName->setText(employee.Name);
    ui->bscID->setText(employee.EmployeeID);
    ui->bscIDNumber->setText(employee.ID_number);
    ui->bscSex->setText(employee.Sex);
    ui->bscTele->setText(employee.PhoneNumber);
    ui->bscBirth->setText(employee.Birth);
    ui->bscAddress->setText(employee.HomeAddress);
}

void MyInfomation_Emp::dealEduInfo(QJsonObject jsonObj){
    // 提取"ResumeInfo"
    QJsonArray resumeInfoArray = jsonObj.value("ResumeInfo").toArray();

    // 找到距离当前时间最短的"Degree"对应的内容
    QString shortestDegree;
    int shortestDistance = INT_MAX; // 初始化为最大值，确保第一个值一定小于最短距离
    for(auto it = resumeInfoArray.begin(); it != resumeInfoArray.end(); ++it) {
        QJsonObject resumeInfoObj = it->toObject();
        QString degree = resumeInfoObj.value("Degree").toString();
        QString endTimeStr = resumeInfoObj.value("EndTime").toString();

        // 计算距离当前时间最短的项
        QDateTime endTime = QDateTime::fromString(endTimeStr, "dd-M月-yy");
        int daysToCurrent = endTime.daysTo(QDateTime::currentDateTime());

        if(daysToCurrent < shortestDistance) {
            shortestDegree = degree;
            shortestDistance = daysToCurrent;
        }
    }
    ui->bscEducation->setText(shortestDegree);


    // 存储"ResumeInfo"的对象数组
    QVector<ResumeInfo_Emp> resumeInfos;

    // 创建一个竖直布局
    QVBoxLayout* layout = new QVBoxLayout(ui->widget_4);

    // 遍历"ResumeInfo"，将每个项存储到类的对象数组里
    for(auto it = resumeInfoArray.begin(); it != resumeInfoArray.end(); ++it) {
        QJsonObject resumeInfoObj = it->toObject();

        // 创建新的ResumeInfo对象
        ResumeInfo_Emp resumeInfo;

        // 从Json对象中提取数据并存储到ResumeInfo对象中
        resumeInfo.idNumber = resumeInfoObj.value("ID_number").toString();
        resumeInfo.educationNo = resumeInfoObj.value("EducationNo").toString();
        resumeInfo.educationType = resumeInfoObj.value("EducationType").toString();
        resumeInfo.institutionName = resumeInfoObj.value("InstitutionName").toString();
        resumeInfo.jobTitle = resumeInfoObj.value("JobTitle").toString();
        resumeInfo.startTime = resumeInfoObj.value("StartTime").toString();
        resumeInfo.endTime = resumeInfoObj.value("EndTime").toString();
        resumeInfo.degree = resumeInfoObj.value("Degree").toString();

        // 将ResumeInfo对象添加到数组中
        resumeInfos.append(resumeInfo);




        QLabel* label = new QLabel(ui->widget_4);
        QString eduDetailInfo;
        eduDetailInfo = "\n编号："+resumeInfo.educationNo+"\n"+
                        "起始时间："+resumeInfo.startTime+"\n"+
                        "结束时间："+resumeInfo.endTime+"\n"+
                        "教育程度："+resumeInfo.degree+"\n";
        label->setText(eduDetailInfo);

        // 将 QLabel 添加到布局中
        layout->addWidget(label);


        // 设置布局的对齐方式为顶部对齐
        layout->setAlignment(Qt::AlignTop);


    }
    // 设置 widget_4 的布局
    ui->widget_4->setLayout(layout);
}

void MyInfomation_Emp::dealSalaryInfo(QJsonObject jsonObj){
    // 提取"SalaryInfo"
    QJsonArray salaryinfoArray = jsonObj.value("SalaryInfo").toArray();

    // 找到距离当前时间最短的"OverallSalary"对应的内容
    QString shortestSalary;
    int shortestDistance = INT_MAX; // 初始化为最大值，确保第一个值一定小于最短距离
    for(auto it = salaryinfoArray.begin(); it != salaryinfoArray.end(); ++it) {
        QJsonObject salaryInfoObj = it->toObject();
        QString OverallSalary = QString::number(salaryInfoObj.value("OverallSalary").toDouble());
        QString endTimeStr = salaryInfoObj.value("PayDate").toString();

        // 计算距离当前时间最短的项
        QDateTime endTime = QDateTime::fromString(endTimeStr, "dd-M月-yy");
        int daysToCurrent = endTime.daysTo(QDateTime::currentDateTime());

        if(daysToCurrent < shortestDistance) {
            shortestSalary = OverallSalary;
            shortestDistance = daysToCurrent;
        }
    }
    ui->bscSalary->setText(shortestSalary);


    // 存储"ResumeInfo"的对象数组
    QVector<SalaryInfo_Emp> salaryInfos;

    // 创建一个竖直布局
    QVBoxLayout* layout = new QVBoxLayout(ui->widget_5);

    // 遍历"ResumeInfo"，将每个项存储到类的对象数组里
    for(auto it = salaryinfoArray.begin(); it != salaryinfoArray.end(); ++it) {
        QJsonObject salaryInfoObj = it->toObject();

        // 创建新的ResumeInfo对象
        SalaryInfo_Emp salaryInfo;

        // 从Json对象中提取数据并存储到ResumeInfo对象中
        salaryInfo.PayDate = salaryInfoObj.value("PayDate").toString();
        salaryInfo.Bonus = QString::number(salaryInfoObj.value("Bonus").toDouble());
        salaryInfo.Commission = QString::number(salaryInfoObj.value("Commission").toDouble());
        salaryInfo.OverallSalary = QString::number(salaryInfoObj.value("OverallSalary").toDouble());

        // 将ResumeInfo对象添加到数组中
        salaryInfos.append(salaryInfo);




        QLabel* label = new QLabel(ui->widget_5);
        QString eduDetailInfo;
        eduDetailInfo = "\n结算日期："+salaryInfo.PayDate+"\n"+
                        "奖金："+salaryInfo.Bonus+"\n"+
                        "回扣："+salaryInfo.Commission+"\n"+
                        "总工资："+salaryInfo.OverallSalary+"\n";
        label->setText(eduDetailInfo);

        // 将 QLabel 添加到布局中
        layout->addWidget(label);

        // 设置布局的对齐方式为顶部对齐
        layout->setAlignment(Qt::AlignTop);
    }
    // 设置 widget_5 的布局
    ui->widget_5->setLayout(layout);
}

//基本信息修改
void MyInfomation_Emp::bscChangeInfo()
{
    //对可修改和不可修改项进行处理
    ui->bscIDNumber->setDisabled(true);
    ui->bscSex->setDisabled(true);
    ui->bscSalary->setDisabled(true);
    ui->bscBirth->setDisabled(true);
    ui->bscEducation->setDisabled(true);

    ui->bscAddress->setReadOnly(false);
    ui->bscTele->setReadOnly(false);

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
    temp = employee;

    // 保存修改后的信息到原始类employeeinfo中
    employee.HomeAddress=ui->bscAddress->text();
    employee.PhoneNumber=ui->bscTele->text();


    // 显示原始按钮
    ui->bscChangeInfo->show();

    // 隐藏按钮
    ui->bscEnsure->hide();
    ui->bscCancel->hide();


    QString setJson1 = "{\"HomeAddress\":\"" + employee.HomeAddress + "\",";
    QString setJson2 = "\"PhoneNumber\":\"" + employee.PhoneNumber + "\"}";
    QString setJson = setJson1+setJson2;
    QString searchJson = "{\"EmployeeID\":\"" + employee.EmployeeID + "\"}";
    QString url = "http://8.130.119.222:1240/api/FundamentalInfo/Update/" +QString::fromUtf8(setJson.toUtf8().toPercentEncoding())+"/"+QString::fromUtf8(searchJson.toUtf8().toPercentEncoding());

    //qDebug() << url;

    // 创建网络访问管理器和请求对象
    QNetworkAccessManager* networkManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    //还是get请求
    QNetworkReply *reply = networkManager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [=]()  {
        if (reply->error() == QNetworkReply::NoError) {
            //qDebug()<<"修改人员信息成功";
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
    ui->bscEducation->setDisabled(false);

    ui->bscAddress->setReadOnly(true);
    ui->bscTele->setReadOnly(true);
}

void MyInfomation_Emp::bscCancel()
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
    ui->bscEducation->setDisabled(false);

    ui->bscAddress->setReadOnly(true);
    ui->bscTele->setReadOnly(true);
}

//窗口动画
void MyInfomation_Emp::applyAnimation(){
    connect(ui->eduDetail, &QPushButton::clicked, this, [=]() {
        QPropertyAnimation* animation = new QPropertyAnimation(ui->bscotherwidget, "minimumWidth");
        animation->setStartValue(0);
        animation->setEndValue(200);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->setDuration(800);
        animation->start();

        ui->otherTitle->setText("教育履历");
        ui->widget_4->show();
        ui->widget_5->hide();
    });
    connect(ui->salaryDetail, &QPushButton::clicked, this, [=]() {
        QPropertyAnimation* animation = new QPropertyAnimation(ui->bscotherwidget, "minimumWidth");
        animation->setStartValue(0);
        animation->setEndValue(200);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->setDuration(800);
        animation->start();

        ui->otherTitle->setText("薪资信息");
        ui->widget_4->hide();
        ui->widget_5->show();
    });
}
//退出键对应的动画
void MyInfomation_Emp::exitAnimation(){
    connect(ui->otherWidgetHide, &QPushButton::clicked, this, [=]() {
        QPropertyAnimation* animation = new QPropertyAnimation(ui->bscotherwidget, "minimumWidth");
        animation->setStartValue(200);
        animation->setEndValue(0);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->setDuration(800);
        animation->start();
    });
}
