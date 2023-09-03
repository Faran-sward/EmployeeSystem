#include "solveApply.h"
#include "ui_solveApply.h"

SolveApply::SolveApply(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SolveApply)
{
    ui->setupUi(this);
    ui->applySolving->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//使得表格能够适应大小
    ui->applySolved->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//使得表格能够适应大小
    initialize();
}

SolveApply::~SolveApply()
{
    delete ui;
}

void SolveApply::onApproveClicked(int row) {
    // 获取所点击按钮所在行的数据
    QString applyID = ui->applySolving->item(row, 0)->data(Qt::DisplayRole).toString();

    QString search_json =  "{\"ApplyID\":\"" + applyID + "\"}";
    QString set_json = "{\"Progress\":\"审批已通过\"}";
    QString url = "http://8.130.119.222:1240/api/ApplyInfo/Update/" +QString::fromUtf8(set_json.toUtf8().toPercentEncoding())+"/"+QString::fromUtf8(search_json.toUtf8().toPercentEncoding());
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
            sendGetRequest("http://8.130.119.222:1240/api/HLControllers/GetWaitApplyInfo");
            //qDebug()<<"OnApprove成功:"<<reply->errorString();
        } else {
            qDebug()<<"OnApproveError:"<<reply->errorString();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

void SolveApply::onDisApproveClicked(int row) {
    // 获取所点击按钮所在行的数据
    QString applyID = ui->applySolving->item(row, 0)->data(Qt::DisplayRole).toString();

    QString search_json =  "{\"ApplyID\":\"" + applyID + "\"}";
    QString set_json = "{\"Progress\":\"审批未通过\"}";
    QString url = "http://8.130.119.222:1240/api/ApplyInfo/Update/" +QString::fromUtf8(set_json.toUtf8().toPercentEncoding())+"/"+QString::fromUtf8(search_json.toUtf8().toPercentEncoding());
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
            sendGetRequest("http://8.130.119.222:1240/api/HLControllers/GetWaitApplyInfo");
        } else {
            qDebug()<<"OnApproveError:"<<reply->errorString();
        }
        reply->deleteLater();
        networkManager->deleteLater();
    });
}

void SolveApply::sendGetRequest(QString url) {
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkAccessManager *manager=new QNetworkAccessManager();

    QNetworkReply *reply = manager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();


            // 解析返回的JSON数据
            QJsonDocument jsonData = QJsonDocument::fromJson(data);
            if (jsonData.isArray()) {
                QJsonArray jsonArray = jsonData.array();

                // 获取comboBox组件的选中项
                QString selectedYear = ui->applyYear->currentText();
                QString selectedMonth = ui->applyMonth->currentText();
                QString selectedDay = ui->applyDay->currentText();



                ui->applySolving->setColumnCount(8);
                // 设置表头
                ui->applySolving->setHorizontalHeaderLabels(QStringList() << "申请号" << "申请人工号"<<"申请人"<<"申请时间"<<"审批人"<<"审批内容"<<"申请状态"<<"操作");

                ui->applySolved->setColumnCount(7);
                // 设置表头
                ui->applySolved->setHorizontalHeaderLabels(QStringList() << "申请号" << "申请人工号"<<"申请人"<<"申请时间"<<"审批人"<<"审批内容"<<"申请状态");
                int j =0 ;
                int k= 0 ;
                // 进行筛选并添加到tableWidget中
                for (int i = 0; i < jsonArray.size(); i++) {
                    QJsonObject jsonObj = jsonArray[i].toObject();
                    QString startTime = jsonObj["StartTime"].toString();
                    QString applicantID = jsonObj["ApplicantID"].toString();
                    QString progress = jsonObj["Progress"].toString();

                    // 判断筛选条件
                    if ((selectedYear.isEmpty() || startTime.contains(selectedYear))
                        && (selectedMonth.isEmpty() || startTime.contains(selectedMonth))
                        && (selectedDay.isEmpty() || startTime.contains(selectedDay))
                        &&(ui->employeeID->text()==""||applicantID==ui->employeeID->text())) {
                        if(progress == "待审批"){
                            ui->applySolving->setRowCount(j+1);
                            // 添加到tableWidget中
                            ui->applySolving->setItem(j, 0, new QTableWidgetItem(jsonObj["ApplyID"].toString()));
                            ui->applySolving->setItem(j, 1, new QTableWidgetItem(jsonObj["ApplicantID"].toString()));
                            ui->applySolving->setItem(j, 2, new QTableWidgetItem(jsonObj["ApplicantName"].toString()));
                            ui->applySolving->setItem(j, 3, new QTableWidgetItem(startTime));
                            ui->applySolving->setItem(j, 4, new QTableWidgetItem(jsonObj["CondutorName"].toString()));
                            ui->applySolving->setItem(j, 5, new QTableWidgetItem(jsonObj["Content"].toString()));
                            ui->applySolving->setItem(j, 6, new QTableWidgetItem(jsonObj["Progress"].toString()));
                            QPushButton *btn_1 = new QPushButton();
                            btn_1->setText(tr("通过"));
                            QPushButton *btn_2 = new QPushButton();
                            btn_2->setText(tr("驳回"));

                            QWidget *tmp_widget = new QWidget();
                            QHBoxLayout *tmp_layout = new QHBoxLayout(tmp_widget);
                            tmp_layout->addWidget(btn_1);
                            tmp_layout->addWidget(btn_2);
                            tmp_layout->setMargin(0);
                            ui->applySolving->setCellWidget(j,7,tmp_widget);

                            connect(btn_1, &QPushButton::clicked, this, [=]() {
                                onApproveClicked(j);
                            });
                            connect(btn_2, &QPushButton::clicked, this, [=]() {
                                onDisApproveClicked(j);
                            });
                            j++;
                        }
                        else{
                            ui->applySolved->setRowCount(k+1);
                            // 添加到tableWidget中
                            ui->applySolved->setItem(k, 0, new QTableWidgetItem(jsonObj["ApplyID"].toString()));
                            ui->applySolved->setItem(k, 1, new QTableWidgetItem(jsonObj["ApplicantID"].toString()));
                            ui->applySolved->setItem(k, 2, new QTableWidgetItem(jsonObj["ApplicantName"].toString()));
                            ui->applySolved->setItem(k, 3, new QTableWidgetItem(startTime));
                            ui->applySolved->setItem(k, 4, new QTableWidgetItem(jsonObj["CondutorName"].toString()));
                            ui->applySolved->setItem(k, 5, new QTableWidgetItem(jsonObj["Content"].toString()));
                            ui->applySolved->setItem(k, 6, new QTableWidgetItem(jsonObj["Progress"].toString()));
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
void SolveApply::updateDayOptions() {
    // 获取选中的年份和月份
    QString selectedYear = ui->applyYear->currentText();
    QString selectedMonth = ui->applyMonth->currentText();

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
    ui->applyDay->clear();
    ui->applyDay->addItems(days);
}

// 初始化函数
void SolveApply::initialize() {
    //QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    // 设置comboBox的选项
    QStringList years = {"", "22", "23"};
    ui->applyYear->addItems(years);

    QStringList months = {"", "1", "2", "3", "4", "5", "6",
                          "7", "8", "9", "10", "11", "12"};
    ui->applyMonth->addItems(months);

    QStringList days = {"", "01", "02", "03", "04", "05", "06",
                        "07", "08", "09", "10", "11", "12",
                        "13", "14", "15", "16", "17", "18",
                        "19", "20", "21", "22", "23", "24",
                        "25", "26", "27", "28", "29", "30", "31"};
    ui->applyDay->addItems(days);

    // 绑定“Year”和“Month”的选项更改事件
    connect(ui->applyYear, &QComboBox::currentTextChanged, this, &SolveApply::updateDayOptions);
    connect(ui->applyMonth, &QComboBox::currentTextChanged, this, &SolveApply::updateDayOptions);

    // 绑定按钮的点击事件，发送GET请求
    connect(ui->getApply, &QPushButton::clicked, [=]() {
        // 清空tableWidget
        ui->applySolving->clearContents();
        ui->applySolving->setRowCount(0);

        // 发送GET请求，并传入后端的API地址
        sendGetRequest("http://8.130.119.222:1240/api/HLControllers/GetWaitApplyInfo");
    });
}
