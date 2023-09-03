#include "dept_info.h"
#include "qeasingcurve.h"
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
    ui->addButton->setIconSize(QSize(20,20));
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
    ui->widget->setStyleSheet("#widget{background-color:rgb(255,255,255);}");

    url=QUrl("http://8.130.119.222:1751/api/Values/GetAllDeptInfo");
    request.setUrl(url);
    connect(&manager,&QNetworkAccessManager::finished,this,&Dept_Info::GetDept);
    connect(ui->application, SIGNAL(closeSignal()), this, SLOT(slotCountMessage()));
    manager.get(request);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotCountMessage()));
    timer->start(1000);
    ui->tableWidget->installEventFilter(this);
}

void Dept_Info::getScrollValue()
{
    QScrollBar *vScrollbar = ui->tableWidget->verticalScrollBar();
    nVSliderValue = vScrollbar->sliderPosition();

    QScrollBar *hScrollbar = ui->tableWidget->horizontalScrollBar();
    nHSliderValue = hScrollbar->sliderPosition();
}

void Dept_Info::setScrollValue()
{
    QScrollBar *vScrollbar = ui->tableWidget->verticalScrollBar();
    vScrollbar->setSliderPosition(nVSliderValue);

    QScrollBar *hScrollbar = ui->tableWidget->horizontalScrollBar();
    hScrollbar->setSliderPosition(nHSliderValue);
}

void Dept_Info::GetDept(QNetworkReply *reply)
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
        QJsonValue arrValue = doc.object().value("infos");
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
                QTableWidgetItem *item0 = new QTableWidgetItem(array.at(i).toObject().value("departmentID").toString());
                QTableWidgetItem *item1 = new QTableWidgetItem(array.at(i).toObject().value("departmentTitle").toString());
                QTableWidgetItem *item2 = new QTableWidgetItem(array.at(i).toObject().value("building").toString());
                QTableWidgetItem *item3 = new QTableWidgetItem(array.at(i).toObject().value("layer").toVariant().toString());
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
    setScrollValue();
}

void Dept_Info::slotCountMessage()
{
    //qDebug()<<"进行一次刷新";
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
    /*
     * 通过服务端对数据库进行修改
     */
    QNetworkRequest oNetRequest;
    QString strUrl="http://8.130.119.222:1751/api/Values/delDeptInfo?DepartmentID="+ui->tableWidget->model()->index(row,0).data().toString();
    oNetRequest.setUrl(QUrl(strUrl));

    QNetworkAccessManager oNetAccessManager;
    QNetworkReply* oNetReply = nullptr;
    QByteArray inputTmp;
    oNetReply = oNetAccessManager.get(oNetRequest);
    // 添加超时处理，10s超时
    QEventLoop eventloop;
    connect(oNetReply, SIGNAL(finished()), &eventloop, SLOT(quit()));
    QTimer::singleShot(10000, &eventloop, &QEventLoop::quit);
    eventloop.exec();
    QByteArray array;
    QString strResult;
    if(oNetReply->isFinished())
    {
        if(oNetReply->error() == QNetworkReply::NoError)//正常结束，读取响应数据
        {
            strResult = oNetReply->readAll();
            if(strResult=="{\"backCode\":1}"){
                qDebug() << "将"<<ui->tableWidget->model()->index(row,1).data().toString()<<"部门取消";
                ui->tableWidget->removeRow(row);
            }
            else{
                QErrorMessage *dialog = new QErrorMessage(this);
                dialog->setWindowTitle("错误信息提示框");
                dialog->showMessage("该部门已被删除！");
            }
        }
        else //异常结束，比如不存在的http服务器
        {
            QErrorMessage *dialog = new QErrorMessage(this);
            dialog->setWindowTitle("错误信息提示框");
            dialog->showMessage("网络错误，删除失败！");
        }
    }
    else //超时，网络原因导致删除失败
    {
        disconnect(oNetReply, &QNetworkReply::finished, &eventloop, &QEventLoop::quit);
        oNetReply->abort();
        qDebug()<<"timeout";
        QErrorMessage *dialog = new QErrorMessage(this);
        dialog->setWindowTitle("错误信息提示框");
        dialog->showMessage("网络错误，删除失败！");
    }

    oNetReply->deleteLater();

}

void Dept_Info::on_addButton_clicked()
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
    else{
        QPropertyAnimation* animation=new QPropertyAnimation(ui->application,"maximumWidth");
        animation->setStartValue(0);
        animation->setEndValue(400);
        animation->setDuration(600);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->start();
        flag=!flag;
    }
}

bool Dept_Info::eventFilter(QObject * watched, QEvent * event)
{
    if(watched==ui->tableWidget){
        if(event->type() == QEvent::Resize){
            int width = ui->tableWidget->width()-20;
            ui->tableWidget->setColumnWidth(0, width * 0.20);
            ui->tableWidget->setColumnWidth(1, width * 0.20);
            ui->tableWidget->setColumnWidth(2, width * 0.20);
            ui->tableWidget->setColumnWidth(3, width * 0.20);
            ui->tableWidget->setColumnWidth(4, width * 0.20);
        }
    }
}
