#include "resume_emp.h"
#include "ui_resume_emp.h"

#include <QFileInfo>
#include <QFileDialog>

#include <QDesktopServices>
#include <QHeaderView>

Resume_Emp::Resume_Emp(QString employeeID,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Resume_Emp)
{
    ui->setupUi(this);
    ui->rsmSearchID->setText(employeeID);
    ui->rsmSearchID->setReadOnly(true);

    fillComboBox();
    //ui->comboBox->setCurrentIndex(-1);  // 将当前选中的项设置为 -1，即不选中任何项
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(treatCheckedCombo()));

    Leftmenu_Animation();

    maxResume();
    returnToUi();
    download();
}

Resume_Emp::~Resume_Emp()
{
    delete ui;
}

void Resume_Emp::fillComboBox() {

    QNetworkAccessManager* networkManager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl("http://8.130.119.222:1240/api/HLControllers/GetAllDeptName"));

    // 发送 GET 请求
    QNetworkReply *reply = networkManager->get(request);
    // 响应成功时处理返回数据
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 解析第一个GET请求的响应
            QByteArray response = reply->readAll();
            QJsonDocument json = QJsonDocument::fromJson(response);

            // 从响应中获取每个部门的"DepartmentTitle"
            QStringList departmentTitles;
            QJsonArray departmentArray = json.array();
            foreach (const QJsonValue& value, departmentArray) {
                QString departmentTitle = value.toObject()["DepartmentTitle"].toString();
                departmentTitles.append(departmentTitle);
            }

            // 将可选项添加到combobox中
            ui->comboBox->clear();
            ui->comboBox->addItems(departmentTitles);


        } else {
            // 请求失败
            qDebug() << "请求失败" << reply->errorString();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

void Resume_Emp::presentDepartInfo() {

    int index = ui->comboBox->currentIndex();
    // 获取选定的部门名称
    QString selectedDepartment = ui->comboBox->itemText(index);
    QNetworkAccessManager* networkManager = new QNetworkAccessManager();
    QNetworkRequest request;

    QString jsonString = "{\"DepartmentTitle\":\"" + selectedDepartment + "\"}";
    QString url = "http://8.130.119.222:1240/api/HLControllers/GetDepartmentInfo/" + QString::fromUtf8(jsonString.toUtf8().toPercentEncoding());
    //qDebug()<<url;
    request.setUrl(QUrl(url));

    // 发送 GET 请求
    QNetworkReply *reply = networkManager->get(request);
    // 响应成功时处理返回数据
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 解析GET请求的响应
            QByteArray response = reply->readAll();
            QJsonDocument json = QJsonDocument::fromJson(response);

            // 计算"CurrentScale"的总和
            double totalCurrentScale = 0;
            QJsonArray jsonArray = json.array();
            for (const auto& item : jsonArray) {
                double currentScale = item.toObject()["CurrentScale"].toDouble();
                totalCurrentScale += currentScale;
            }
            // 更新文本
            ui->rsmDeptNo->setText("部门编号："+jsonArray[0].toObject()["DepartmentID"].toString());
            ui->rsmDeptMem->setText("部门人数："+QString::number(totalCurrentScale));
        } else {
            // 请求失败
            qDebug() << "请求失败" << reply->errorString();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

void Resume_Emp::presentEmployeeInfo() {
    int index = ui->comboBox->currentIndex();
    // 获取选定的部门名称
    QString selectedDepartment = ui->comboBox->itemText(index);
    QNetworkAccessManager* networkManager2 = new QNetworkAccessManager();
    QNetworkRequest request;

    QString jsonString = "{\"DepartmentTitle\":\"" + selectedDepartment + "\"}";
    QString url = "http://8.130.119.222:1240/api/HLControllers/GetDeptEmpID/" + QString::fromUtf8(jsonString.toUtf8().toPercentEncoding());
    //qDebug() << url;
    request.setUrl(QUrl(url));

    // 发送 GET 请求
    QNetworkReply* reply = networkManager2->get(request);
    // 响应成功时处理返回数据
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 从响应中获取 EmployeeID 列表
            QByteArray response = reply->readAll();
            QJsonArray jsonArray = QJsonDocument::fromJson(response).array();
            ui->employeeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 使得表格能够适应大小

            // 设置表格的行数和列数
            int rowCount = (jsonArray.size() + 1) / 2;
            ui->employeeTable->setRowCount(rowCount);
            ui->employeeTable->setColumnCount(2);

            // 将 EmployeeID 填充到表格中
            int rowIndex = 0;
            int colIndex = 0;
            for (int i = 0; i < jsonArray.size(); i++) {
                QJsonObject jsonObj = jsonArray[i].toObject();
                QString employeeID = jsonObj["EmployeeID"].toString();

                QTableWidgetItem* item = new QTableWidgetItem();
                item->setData(Qt::DisplayRole, employeeID); // 设置单元格文本
                item->setTextAlignment(Qt::AlignCenter); // 文字居中对齐
                ui->employeeTable->setItem(rowIndex, colIndex, item);

                colIndex++;
                if (colIndex == 2) {
                    colIndex = 0;
                    rowIndex++;
                }
            }

            // 设置表头
            ui->employeeTable->setHorizontalHeaderLabels(QStringList() << "EmployeeID" << "EmployeeID");


        }
        else {
            // 请求失败
            qDebug() << "请求失败" << reply->errorString();
        }
        reply->deleteLater();
        networkManager2->deleteLater();
    });
}



void Resume_Emp::treatCheckedCombo(){
    //呈现部门信息
    presentDepartInfo();

    //呈现员工信息，选中员工获得员工号，可进一步进行查询
    presentEmployeeInfo();
}

void Resume_Emp::Leftmenu_Animation(){
    connect(ui->search, &QPushButton::clicked, this, [=]() {

        searchingID = ui->rsmSearchID->text();//把选中的值赋给searchingID
        pdfToPic();

        QPropertyAnimation* animation = new QPropertyAnimation(ui->resumePresent, "minimumWidth");
        animation->setStartValue(0);
        animation->setEndValue(200);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->setDuration(800);
        animation->start();
        getResumePic() ;
    });
}

void Resume_Emp::pdfToPic(){

    QNetworkAccessManager* networkManager = new QNetworkAccessManager();
    QNetworkRequest request;

    QString jsonString = "{\"EmployeeID\":\"" + searchingID + "\"}";
    QString url = "http://8.130.119.222:1240/api/PicturePDF/ChangePdfToImage/" + QString::fromUtf8(jsonString.toUtf8().toPercentEncoding());
    //qDebug()<<url;
    request.setUrl(QUrl(url));

    // 发送 GET 请求
    QNetworkReply *reply = networkManager->get(request);
    // 响应成功时处理返回数据
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            //无操作
        } else {
            // 请求失败
            qDebug() << "请求失败" << reply->errorString();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

void Resume_Emp::getResumePic() {
    QString url = "http://8.130.119.222:1239/"; // 图片的基本URL

    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);

    int number = 0;
    // 发送网络请求获取图片
    QNetworkRequest request(QUrl(url + searchingID + "-"+QString::number(number)+".png"));
    networkManager->get(request);

    connect(networkManager, &QNetworkAccessManager::finished, this, [=](QNetworkReply* reply) {
        if(reply->error() == QNetworkReply::NoError) {
            // 将获取的图片数据转换成QPixmap
            QByteArray imageData = reply->readAll();
            QPixmap pixmap;
            pixmap.loadFromData(imageData);

            // 创建并设置显示图片的 QLabel
            ui->label->setPixmap(pixmap);
            ui->label->setScaledContents(true); // 自动缩放图片以适应 QLabel

        } else {
            // 请求失败
            qDebug() << "请求图片失败" << reply->errorString();
        }

        // 清理资源
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

void Resume_Emp::maxResume(){
    //唤起新的窗口，展示简历
    connect(ui->maxUi,&QPushButton::clicked,this,[=](){
        QString url = "http://8.130.119.222:1238/"+searchingID+".pdf";
        QDesktopServices::openUrl(QUrl(url));
    });
}

void Resume_Emp::returnToUi(){
    connect(ui->returnUi, &QPushButton::clicked, this, [=]() {
        QPropertyAnimation* animation = new QPropertyAnimation(ui->resumePresent, "minimumWidth");
        animation->setStartValue(ui->resumePresent->minimumWidth());
        animation->setEndValue(0);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->setDuration(800);
        animation->start();
    });
}

void Resume_Emp::download() {
    connect(ui->download, &QPushButton::clicked, this, [=]() {
        QString url = "http://8.130.119.222:1238/"+searchingID+".pdf";
        QUrl fileUrl(url);

        QString fileName = QFileInfo(fileUrl.path()).fileName();

        QFileDialog dialog(nullptr, "选择保存位置");
        dialog.setAcceptMode(QFileDialog::AcceptSave);
        dialog.selectFile(fileName);

        if (dialog.exec() == QDialog::Accepted) {
            QString savePath = dialog.selectedFiles().first();

            QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);
            QNetworkRequest request;
            request.setUrl(fileUrl);

            QNetworkReply* reply = networkManager->get(request);
            connect(reply, &QNetworkReply::finished, [=]() {
                if (reply->error() == QNetworkReply::NoError) {
                    QFile file(savePath);
                    if (file.open(QIODevice::WriteOnly)) {
                        file.write(reply->readAll());
                        file.close();
                        qDebug() << "文件下载完成：" << savePath;
                    } else {
                        qDebug() << "文件保存失败：" << savePath;
                    }
                } else {
                    qDebug() << "文件下载失败：" << reply->errorString();
                }

                // 清理资源
                reply->deleteLater();
                networkManager->deleteLater();
            });
        }
    });
}
