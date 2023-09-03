#include "sala_info.h"
#include "ui_sala_info.h"

Sala_Info::Sala_Info(QString num,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sala_Info)
{
    mynum=num;
    ui->setupUi(this);
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setColumnWidth(0, width * 0.16);
    ui->tableWidget->setColumnWidth(1, width * 0.16);
    ui->tableWidget->setColumnWidth(2, width * 0.17);
    ui->tableWidget->setColumnWidth(3, width * 0.17);
    ui->tableWidget->setColumnWidth(4, width * 0.17);
    ui->tableWidget->setColumnWidth(5, width * 0.17);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->widget->setStyleSheet("#widget{background-color:rgb(255,255,255);}");

    url=QUrl("http://8.130.119.222:1751/api/Values/getPersonalSalary?EmployeeID="+mynum);
    request.setUrl(url);
    connect(&manager,&QNetworkAccessManager::finished,this,&Sala_Info::GetSala);
    manager.get(request);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotCountMessage()));
    timer->start(1000);
    ui->tableWidget->installEventFilter(this);
}

Sala_Info::~Sala_Info()
{
    delete ui;
}

void Sala_Info::resizeEvent(QResizeEvent *event)
{
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnWidth(0, width * 0.16);
    ui->tableWidget->setColumnWidth(1, width * 0.16);
    ui->tableWidget->setColumnWidth(2, width * 0.17);
    ui->tableWidget->setColumnWidth(3, width * 0.17);
    ui->tableWidget->setColumnWidth(4, width * 0.17);
    ui->tableWidget->setColumnWidth(5, width * 0.17);
}

void Sala_Info::getScrollValue()
{
    QScrollBar *vScrollbar = ui->tableWidget->verticalScrollBar();
    nVSliderValue = vScrollbar->sliderPosition();

    QScrollBar *hScrollbar = ui->tableWidget->horizontalScrollBar();
    nHSliderValue = hScrollbar->sliderPosition();
}

void Sala_Info::setScrollValue()
{
    QScrollBar *vScrollbar = ui->tableWidget->verticalScrollBar();
    vScrollbar->setSliderPosition(nVSliderValue);

    QScrollBar *hScrollbar = ui->tableWidget->horizontalScrollBar();
    hScrollbar->setSliderPosition(nHSliderValue);
}

void Sala_Info::GetSala(QNetworkReply *reply)
{
    getScrollValue();
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
        //qDebug() << "文件解析成功\n";
        QJsonValue arrValue = doc.object().value("requestResult");
        if (arrValue.isArray())
        {
            QJsonArray array = arrValue.toArray();  // 转数组
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
                QTableWidgetItem *item0 = new QTableWidgetItem(array.at(i).toObject().value("year").toString());
                QTableWidgetItem *item1 = new QTableWidgetItem(array.at(i).toObject().value("month").toString());
                QTableWidgetItem *item2 = new QTableWidgetItem(array.at(i).toObject().value("basicSalary").toVariant().toString());
                QTableWidgetItem *item3 = new QTableWidgetItem(array.at(i).toObject().value("bonus").toVariant().toString());
                QTableWidgetItem *item4 = new QTableWidgetItem(array.at(i).toObject().value("commission").toVariant().toString());
                QTableWidgetItem *item5 = new QTableWidgetItem(array.at(i).toObject().value("overallSalary").toVariant().toString());

                ui->tableWidget->setItem(rowIdx,0,item0);
                ui->tableWidget->setItem(rowIdx,1,item1);
                ui->tableWidget->setItem(rowIdx,2,item2);
                ui->tableWidget->setItem(rowIdx,3,item3);
                ui->tableWidget->setItem(rowIdx,4,item4);
                ui->tableWidget->setItem(rowIdx,5,item5);
            }
        }
    }
    setScrollValue();
}

void Sala_Info::slotCountMessage()
{
    //qDebug()<<"进行一次刷新";
    manager.get(request);
}
