#include "dept_info.h"
#include "ui_dept_info.h"

Dept_Info::Dept_Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dept_Info)
{
    ui->setupUi(this);
    int width = qApp->desktop()->availableGeometry().width() - 200;
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setColumnWidth(0, width * 0.06);
    ui->tableWidget->setColumnWidth(1, width * 0.10);
    ui->tableWidget->setColumnWidth(2, width * 0.15);
    ui->tableWidget->setColumnWidth(3, width * 0.15);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << "部门编号" << "部门名称" << "所在楼" << "所在楼层";
    ui->tableWidget->setHorizontalHeaderLabels(headText);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    url=QUrl(QString("http://121.41.120.170:5555/api/Dept/Get?building=")+QString("办公楼1"));
    request.setUrl(url);
    connect(&manager,&QNetworkAccessManager::finished,this,&Dept_Info::GetDept);
    manager.get(request);
}

void Dept_Info::GetDept(QNetworkReply *reply)
{
    QByteArray array = reply->readAll();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(array,&error);
    if(error.error !=QJsonParseError::NoError)
    {
        qDebug("json error");
        return ;
    }
    if (!doc.isNull() &&error.error == QJsonParseError::NoError)
    {
        qDebug() << "文件解析成功\n";
        if (doc.isArray())
        {
            QJsonArray array = doc.array();  // 转数组
            int nSize = array.size();
            for (int i = 0; i < nSize; i++)
            {
                qDebug() << "将一条记录插入表格";
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                int rowIdx = ui->tableWidget->rowCount()-1;
                //必须先设置item,然后再获取,因为默认是空的
                QTableWidgetItem *item0 = new QTableWidgetItem(array.at(i).toObject().value("id").toString());
                QTableWidgetItem *item1 = new QTableWidgetItem(array.at(i).toObject().value("name").toString());
                QTableWidgetItem *item2 = new QTableWidgetItem(array.at(i).toObject().value("buliding").toString());
                QTableWidgetItem *item3 = new QTableWidgetItem(array.at(i).toObject().value("layer").toString());
                ui->tableWidget->setItem(rowIdx,0,item0);
                ui->tableWidget->setItem(rowIdx,1,item1);
                ui->tableWidget->setItem(rowIdx,2,item2);
                ui->tableWidget->setItem(rowIdx,3,item3);
            }
        }
    }
}

Dept_Info::~Dept_Info()
{
    delete ui;
}
