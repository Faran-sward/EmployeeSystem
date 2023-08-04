#include "dept_info.h"
#include "ui_dept_info.h"
#include "add_dept.h"

Dept_Info::Dept_Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dept_Info)
{
    ui->setupUi(this);
    int width = ui->tableWidget->width()-20;
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(0, width * 0.20);
    ui->tableWidget->setColumnWidth(1, width * 0.20);
    ui->tableWidget->setColumnWidth(2, width * 0.20);
    ui->tableWidget->setColumnWidth(3, width * 0.20);
    ui->tableWidget->setColumnWidth(4, width * 0.20);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(25);
    ui->addButton->setStyleSheet("background-color:rgb(65,105,225);color:rgb(255, 255, 255);font:10pt;");
    ui->addButton->setIcon(QIcon(":/images/icons8-plus-50.png"));
    ui->addButton->setIconSize(QSize(15,15));
    //ui->addButton->setButtonStyle(Qt::ToolButtonTextBesideIcon);
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
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotCountMessage()));
    timer->start(10000);
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
            for(int row = ui->tableWidget->rowCount() - 1;row >= 0; row--)
            {
                ui->tableWidget->removeRow(row);
            }
            for (int i = 0; i < nSize; i++)
            {
                //qDebug() << "将一条记录插入表格";
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
                QPushButton *btn = new QPushButton();
                btn->setText(tr("取消"));
                ui->tableWidget->setCellWidget(rowIdx,4,btn);
                connect(btn, SIGNAL(clicked()), this, SLOT(onCancelClicked()));
            }
        }
    }
}

void Dept_Info::slotCountMessage()
{
    qDebug()<<"进行一次刷新";
    manager.get(request);
}

Dept_Info::~Dept_Info()
{
    delete ui;
}

void Dept_Info::onCancelClicked()
{
    QPushButton *btn = (QPushButton *)sender();
    int x = btn->mapToParent(QPoint(0,0)).x();
    int y = btn->mapToParent(QPoint(0,0)).y();
    QModelIndex index = ui->tableWidget->indexAt(QPoint(x,y));
    int row = index.row();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "取消部门", QString("确定要将")+ui->tableWidget->model()->index(row,1).data().toString()+"部门取消吗?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }
    qDebug() << "将"<<ui->tableWidget->model()->index(row,1).data().toString()<<"部门取消";
    /*
     * 通过服务端对数据库进行修改
     */
    ui->tableWidget->removeRow(row);
}

void Dept_Info::resizeEvent(QResizeEvent *event)
{
    int width = ui->tableWidget->width()-20;
    ui->tableWidget->setColumnWidth(0, width * 0.20);
    ui->tableWidget->setColumnWidth(1, width * 0.20);
    ui->tableWidget->setColumnWidth(2, width * 0.20);
    ui->tableWidget->setColumnWidth(3, width * 0.20);
    ui->tableWidget->setColumnWidth(4, width * 0.20);
}

void Dept_Info::on_addButton_clicked()
{
    Add_dept* a=new Add_dept();
    a->show();
    connect(a, SIGNAL(closeSignal()), this, SLOT(slotCountMessage()));
}
