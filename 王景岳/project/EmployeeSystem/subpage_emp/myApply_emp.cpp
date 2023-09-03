#include "myApply_emp.h"
#include "ui_myApply_emp.h"

MyApply_Emp::MyApply_Emp(QString employeeID,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyApply_Emp)
{
    ui->setupUi(this);
    this->employeeID = employeeID;

    //使得表格能够适应大小
    ui->maplySolving->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->maplySolved->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    initialize();
}

MyApply_Emp::~MyApply_Emp()
{
    delete ui;
}

void MyApply_Emp::sendGetRequest(QString url) {
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkAccessManager *manager=new QNetworkAccessManager();

    //qDebug()<<url;

    QNetworkReply *reply = manager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();

            // 解析返回的JSON数据
            QJsonDocument jsonData = QJsonDocument::fromJson(data);
            if (jsonData.isArray()) {
                QJsonArray jsonArray = jsonData.array();

                // 获取comboBox组件的选中项
                QString selectedYear = ui->maplyYear->currentText();
                QString selectedMonth = ui->maplyMonth->currentText();
                QString selectedDay = ui->maplyDay->currentText();

                ui->maplySolving->setColumnCount(7);
                // 设置表头
                ui->maplySolving->setHorizontalHeaderLabels(QStringList() << "申请号" << "申请人工号"<<"申请人"<<"申请时间"<<"审批人"<<"审批内容"<<"申请状态");

                ui->maplySolved->setColumnCount(7);
                ui->maplySolved->setHorizontalHeaderLabels(QStringList() << "申请号" << "申请人工号"<<"申请人"<<"申请时间"<<"审批人"<<"审批内容"<<"申请状态");
                int j=0;
                int k=0;
                // 进行筛选并添加到tableWidget中
                for (int i = 0; i < jsonArray.size();i++) {
                    QJsonObject jsonObj = jsonArray[i].toObject();
                    QString startTime = jsonObj["StartTime"].toString();
                    //QString applicantID = jsonObj["ApplicantID"].toString();
                    QString progress= jsonObj["Progress"].toString();
                    //qDebug()<<i<<progress;
                    // 判断筛选条件
                    if ((selectedYear.isEmpty() || startTime.contains(selectedYear))
                        && (selectedMonth.isEmpty() || startTime.contains(selectedMonth))
                        && (selectedDay.isEmpty() || startTime.contains(selectedDay))){

                        if(progress=="待审批"){
                            ui->maplySolving->setRowCount(j+1);
                            // 添加到tableWidget的审批中
                            ui->maplySolving->setItem(j, 0, new QTableWidgetItem(jsonObj["ApplyID"].toString()));
                            ui->maplySolving->setItem(j, 1, new QTableWidgetItem(jsonObj["ApplicantID"].toString()));
                            ui->maplySolving->setItem(j, 2, new QTableWidgetItem(jsonObj["ApplicantName"].toString()));
                            ui->maplySolving->setItem(j, 3, new QTableWidgetItem(startTime));
                            ui->maplySolving->setItem(j, 4, new QTableWidgetItem(jsonObj["CondutorName"].toString()));
                            ui->maplySolving->setItem(j, 5, new QTableWidgetItem(jsonObj["Content"].toString()));
                            ui->maplySolving->setItem(j, 6, new QTableWidgetItem(jsonObj["Progress"].toString()));
                            j++;
                        }
                        else{
                            ui->maplySolved->setRowCount(k+1);
                            // 添加到tableWidget的已审批
                            ui->maplySolved->setItem(k, 0, new QTableWidgetItem(jsonObj["ApplyID"].toString()));
                            ui->maplySolved->setItem(k, 1, new QTableWidgetItem(jsonObj["ApplicantID"].toString()));
                            ui->maplySolved->setItem(k, 2, new QTableWidgetItem(jsonObj["ApplicantName"].toString()));
                            ui->maplySolved->setItem(k, 3, new QTableWidgetItem(startTime));
                            ui->maplySolved->setItem(k, 4, new QTableWidgetItem(jsonObj["CondutorName"].toString()));
                            ui->maplySolved->setItem(k, 5, new QTableWidgetItem(jsonObj["Content"].toString()));
                            ui->maplySolved->setItem(k, 6, new QTableWidgetItem(jsonObj["Progress"].toString()));
                            k++;
                        }
                    }
                }
            }
        }

        // 请求结束后释放reply对象
        reply->deleteLater();
    });
}

// 定义函数用于动态初始化“Day”组件的选项
void MyApply_Emp::updateDayOptions() {
    // 获取选中的年份和月份
    QString selectedYear = ui->maplyYear->currentText();
    QString selectedMonth = ui->maplyMonth->currentText();

    // 基于年份和月份确定该月的天数
    int numOfDays;
    if (selectedMonth == "2") {
        bool isLeapYear = (selectedYear.toInt() % 4 == 0 && selectedYear.toInt() % 100 != 0) || (selectedYear.toInt() % 400 == 0);
        numOfDays = isLeapYear ? 29 : 28;
    } else if (selectedMonth == "4" || selectedMonth == "6" || selectedMonth == "9" || selectedMonth == "11") {
        numOfDays = 30;
    } else {
        numOfDays = 31;
    }

    // 更新“Day”组件的选项
    QStringList days;
    days.append(""); // 添加一个空选项

    for (int i = 1; i <= numOfDays; i++) {
        QString day = QString("%1").arg(i, 2, 10, QLatin1Char('0'));
        days.append(day);
    }
    ui->maplyDay->clear();
    ui->maplyDay->addItems(days);
}

// 初始化函数
void MyApply_Emp::initialize() {
    //QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    // 设置comboBox的选项
    QStringList years = {"", "22", "23"};
    ui->maplyYear->addItems(years);

    QStringList months = {"", "1", "2", "3", "4", "5", "6",
                          "7", "8", "9", "10", "11", "12"};
    ui->maplyMonth->addItems(months);

    QStringList days = {"", "01", "02", "03", "04", "05", "06",
                        "07", "08", "09", "10", "11", "12",
                        "13", "14", "15", "16", "17", "18",
                        "19", "20", "21", "22", "23", "24",
                        "25", "26", "27", "28", "29", "30", "31"};
    ui->maplyDay->addItems(days);

    // 绑定“Year”和“Month”的选项更改事件
    connect(ui->maplyYear, &QComboBox::currentTextChanged, this, &MyApply_Emp::updateDayOptions);
    connect(ui->maplyMonth, &QComboBox::currentTextChanged, this, &MyApply_Emp::updateDayOptions);

    // 绑定按钮的点击事件，发送GET请求
    connect(ui->maplyGet, &QPushButton::clicked, [=]() {
        // 清空tableWidget
        ui->maplySolving->clearContents();
        ui->maplySolving->setRowCount(0);


        QString jsonString =  "{\"EmployeeID\":\"" + employeeID + "\"}";
        QString url = "http://8.130.119.222:1240/api/HLControllers/GetApplyResult/" +QString::fromUtf8(jsonString.toUtf8().toPercentEncoding());
        // 发送GET请求，并传入后端的API地址
        sendGetRequest(url);
    });
}
