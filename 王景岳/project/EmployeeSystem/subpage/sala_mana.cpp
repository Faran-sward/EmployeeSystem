#include "sala_mana.h"
#include "ui_sala_mana.h"

Sala_Mana::Sala_Mana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sala_Mana)
{
    ui->setupUi(this);
    for(int i=0;i<12;i++){
        ui->month_combo->addItem(QString::number(i+1)+QString("月"));
    }
    QDateTime time = QDateTime::currentDateTime();
    int year = time.date().year();
    int month = time.date().month();
    for(int i=2000;i<=year;i++){
        ui->year_combo->addItem(QString::number(i)+QString("年"));
    }
    ui->year_combo->setCurrentIndex(year-2000);
    ui->month_combo->setCurrentIndex(month-1);
    yearnow=year;
    monthnow=month;
    if(time.date().day()>21){
        monthnow=-1;
    }
    int width=ui->tableWidget->width();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setColumnWidth(0, width * 0.14);
    ui->tableWidget->setColumnWidth(1, width * 0.14);
    ui->tableWidget->setColumnWidth(2, width * 0.14);
    ui->tableWidget->setColumnWidth(3, width * 0.14);
    ui->tableWidget->setColumnWidth(4, width * 0.14);
    ui->tableWidget->setColumnWidth(5, width * 0.15);
    ui->tableWidget->setColumnWidth(6, width * 0.15);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->widget->setStyleSheet("#widget{background-color:rgb(255,255,255);}");
    connect(ui->application,SIGNAL(closeSignal()),this,SLOT(hideRight()));
    connect(ui->application,SIGNAL(changedSignal()),this,SLOT(slotCountMessage()));

    QString yea=ui->year_combo->currentText();
    yea.remove("年");
    QString mon=ui->month_combo->currentText();
    mon.remove("月");
    url=QUrl("http://8.130.119.222:1751/api/Values/getSalaryTable?year="+yea+"&month="+mon);
    request.setUrl(url);
    connect(&manager,&QNetworkAccessManager::finished,this,&Sala_Mana::GetSala);
    connect(ui->year_combo,SIGNAL(currentIndexChanged(int)),this,SLOT(slotCountMessage()));
    connect(ui->month_combo,SIGNAL(currentIndexChanged(int)),this,SLOT(slotCountMessage()));
    //connect(ui->application, SIGNAL(closeSignal()), this, SLOT(slotCountMessage()));
    manager.get(request);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotCountMessage()));
    timer->start(1000);
    ui->tableWidget->installEventFilter(this);
}

void Sala_Mana::getScrollValue()
{
    QScrollBar *vScrollbar = ui->tableWidget->verticalScrollBar();
    nVSliderValue = vScrollbar->sliderPosition();

    QScrollBar *hScrollbar = ui->tableWidget->horizontalScrollBar();
    nHSliderValue = hScrollbar->sliderPosition();
}

void Sala_Mana::setScrollValue()
{
    QScrollBar *vScrollbar = ui->tableWidget->verticalScrollBar();
    vScrollbar->setSliderPosition(nVSliderValue);

    QScrollBar *hScrollbar = ui->tableWidget->horizontalScrollBar();
    hScrollbar->setSliderPosition(nHSliderValue);
}

void Sala_Mana::GetSala(QNetworkReply *reply)
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
        for(int row = ui->tableWidget->rowCount() - 1;row >= 0; row--)
        {
            ui->tableWidget->removeRow(row);
        }
        QJsonValue arrValue = doc.object().value("requestResult");
        if (arrValue.isArray())
        {
            QJsonArray array = arrValue.toArray();  // 转数组
            int nSize = array.size();
            for (int i = 0; i < nSize; i++)
            {
                //qDebug() << "将一条记录插入表格";
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                int rowIdx = ui->tableWidget->rowCount()-1;
                //必须先设置item,然后再获取,因为默认是空的
                QTableWidgetItem *item0 = new QTableWidgetItem(array.at(i).toObject().value("employeeID").toString());
                QTableWidgetItem *item1 = new QTableWidgetItem(array.at(i).toObject().value("name").toString());
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
                if(ui->year_combo->currentText()==(QString::number(yearnow)+"年")&&ui->month_combo->currentText()==(QString::number(monthnow)+"月")){
                    QPushButton *btn = new QPushButton();
                    btn->setText(tr("变更"));
                    ui->tableWidget->setCellWidget(rowIdx,6,btn);
                    connect(btn, SIGNAL(clicked()), this, SLOT(onChangeClicked()));
                }
                else{
                    QTableWidgetItem *item6 = new QTableWidgetItem("不可变更");
                    ui->tableWidget->setItem(rowIdx,6,item6);
                }
            }
        }
    }
    setScrollValue();
}

void Sala_Mana::slotCountMessage()
{
    //qDebug()<<"进行一次刷新";
    QString yea=ui->year_combo->currentText();
    yea.remove("年");
    QString mon=ui->month_combo->currentText();
    mon.remove("月");
    request.setUrl(QUrl("http://8.130.119.222:1751/api/Values/getSalaryTable?year="+yea+"&month="+mon));
    manager.get(request);
}

Sala_Mana::~Sala_Mana()
{
    delete ui;
}

void Sala_Mana::onChangeClicked()
{
    QPushButton *btn = (QPushButton *)sender();
    int x = btn->mapToParent(QPoint(0,0)).x();
    int y = btn->mapToParent(QPoint(0,0)).y();
    QModelIndex index = ui->tableWidget->indexAt(QPoint(x,y));
    int row = index.row();
    if(flag){
        QPropertyAnimation* animation=new QPropertyAnimation(ui->application,"maximumWidth");
        animation->setStartValue(0);
        animation->setEndValue(400);
        animation->setDuration(600);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->start();
        flag=!flag;
    }
    ui->application->setInfo(ui->tableWidget->model()->index(row,0).data().toString(),ui->tableWidget->model()->index(row,2).data().toString(),ui->tableWidget->model()->index(row,3).data().toString(),ui->tableWidget->model()->index(row,4).data().toString());
}

void Sala_Mana::hideRight()
{
    if(!flag){
        QPropertyAnimation* animation=new QPropertyAnimation(ui->application,"maximumWidth");
        animation->setStartValue(400);
        animation->setEndValue(0);
        animation->setDuration(600);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->start();
        flag=!flag;
    }
}

bool Sala_Mana::eventFilter(QObject * watched, QEvent * event)
{
    if(watched==ui->tableWidget){
        if(event->type() == QEvent::Resize){
            int width=ui->tableWidget->width();
            ui->tableWidget->setColumnWidth(0, width * 0.14);
            ui->tableWidget->setColumnWidth(1, width * 0.14);
            ui->tableWidget->setColumnWidth(2, width * 0.14);
            ui->tableWidget->setColumnWidth(3, width * 0.14);
            ui->tableWidget->setColumnWidth(4, width * 0.14);
            ui->tableWidget->setColumnWidth(5, width * 0.15);
            ui->tableWidget->setColumnWidth(6, width * 0.15);
        }
    }
}
