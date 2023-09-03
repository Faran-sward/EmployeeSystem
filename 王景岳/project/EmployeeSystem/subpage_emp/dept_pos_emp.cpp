#include "dept_pos_emp.h"
#include "ui_dept_pos_emp.h"

Dept_Pos_Emp::Dept_Pos_Emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dept_Pos_Emp)
{
    ui->setupUi(this);
    int width=ui->tabWidget->width()-2;
    ui->auth_table->setColumnCount(3);
    ui->auth_table->setColumnWidth(0, width * 0.33);
    ui->auth_table->setColumnWidth(1, width * 0.33);
    ui->auth_table->setColumnWidth(2, width * 0.34);
    ui->post_table->setColumnCount(4);
    ui->post_table->setColumnWidth(0, width * 0.25);
    ui->post_table->setColumnWidth(1, width * 0.25);
    ui->post_table->setColumnWidth(2, width * 0.25);
    ui->post_table->setColumnWidth(3, width * 0.25);
    ui->staff_table->setColumnCount(4);
    ui->staff_table->setColumnWidth(0, width * 0.25);
    ui->staff_table->setColumnWidth(1, width * 0.25);
    ui->staff_table->setColumnWidth(2, width * 0.25);
    ui->staff_table->setColumnWidth(3, width * 0.25);
    ui->widget->setStyleSheet("#widget{background-color:rgb(255,255,255);}");
    ui->widget_2->setStyleSheet("#widget_2{background-color:rgb(255,255,255);}");
    ui->tab->setStyleSheet("border: none;");
    ui->tab_2->setStyleSheet("border: none;");
    ui->tab_3->setStyleSheet("border: none;");

    ui->auth_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->auth_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->auth_table->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->auth_table->setAlternatingRowColors(true);
    ui->auth_table->verticalHeader()->setVisible(false);
    ui->auth_table->horizontalHeader()->setStretchLastSection(true);

    ui->post_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->post_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->post_table->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->post_table->setAlternatingRowColors(true);
    ui->post_table->verticalHeader()->setVisible(false);
    ui->post_table->horizontalHeader()->setStretchLastSection(true);

    ui->staff_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->staff_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->staff_table->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->staff_table->setAlternatingRowColors(true);
    ui->staff_table->verticalHeader()->setVisible(false);
    ui->staff_table->horizontalHeader()->setStretchLastSection(true);

    url=QUrl("http://8.130.119.222:1751/api/Values/GetAllDeptInfo");
    request.setUrl(url);
    connect(&manager,&QNetworkAccessManager::finished,this,&Dept_Pos_Emp::GetDept);
    manager.get(request);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotCountMessage()));
    timer->start(10000);
}

void Dept_Pos_Emp::getScrollValue()
{
    QScrollBar *vScrollbar = ui->comboBox->view()->verticalScrollBar();
    nVSliderValue_0 = vScrollbar->sliderPosition();
}

void Dept_Pos_Emp::setScrollValue()
{
    QScrollBar *vScrollbar = ui->comboBox->view()->verticalScrollBar();
    if(ui->comboBox->currentIndex()==0){
        ui->comboBox->setCurrentIndex(-1);
        vScrollbar->setSliderPosition(nVSliderValue_0);
        ui->comboBox->setCurrentIndex(0);
    }
    vScrollbar->setSliderPosition(nVSliderValue_0);
}

void Dept_Pos_Emp::GetDept(QNetworkReply *reply)
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
        int dept_ind=-1;
        QJsonValue arrValue = doc.object().value("infos");
        if (arrValue.isArray())
        {
            QJsonArray array = arrValue.toArray();  // 转数组
            int nSize = array.size();
            if(thearray!=NULL){
                delete thearray;
            }
            thearray=new QJsonArray(array);
            ui->comboBox->clear();
            for (int i = 0; i < nSize; i++)
            {
                ui->comboBox->addItem(array.at(i).toObject().value("departmentTitle").toString());
                if(array.at(i).toObject().value("departmentTitle").toString()==deptname){
                    dept_ind=i;
                }
            }
        }
        if(dept_ind!=-1){ //之前所选中的部门刷新后未被删除
            ui->comboBox->setCurrentIndex(dept_ind);
        }
        else{ //反之，自动跳转到首个部门
            ui->comboBox->setCurrentIndex(0);
            deptname=ui->comboBox->itemText(0);
            tableRefresh();
        }
        if(dept_ind==0){
            tableRefresh();
        }
    }
    setScrollValue();
}

void Dept_Pos_Emp::slotCountMessage()
{
    //qDebug()<<"进行一次刷新";
    manager.get(request);
}

Dept_Pos_Emp::~Dept_Pos_Emp()
{
    delete ui;
}

void Dept_Pos_Emp::on_comboBox_currentIndexChanged(int index)
{
    if(index==-1){
        notchange=true;
        return;
    }
    if(thearray!=NULL){
        ui->num_lab->setText(QString("部门编号：")+thearray->at(index).toObject().value("departmentID").toString());
        ui->name_lab->setText(QString("部门名称：")+thearray->at(index).toObject().value("departmentTitle").toString());
        ui->build_lab->setText(QString("所在楼：")+thearray->at(index).toObject().value("building").toString());
        ui->floor_lab->setText(QString("所在楼层：")+thearray->at(index).toObject().value("layer").toVariant().toString());
    }
    if(index==0&&notchange){
        notchange=false;
        return;
    }
    deptname=ui->comboBox->itemText(index);
    tableRefresh();
}

void Dept_Pos_Emp::resizeEvent(QResizeEvent *event)
{
    int width=ui->tabWidget->width()-2;
    ui->auth_table->setColumnWidth(0, width * 0.33);
    ui->auth_table->setColumnWidth(1, width * 0.33);
    ui->auth_table->setColumnWidth(2, width * 0.34);
    ui->post_table->setColumnWidth(0, width * 0.25);
    ui->post_table->setColumnWidth(1, width * 0.25);
    ui->post_table->setColumnWidth(2, width * 0.25);
    ui->post_table->setColumnWidth(3, width * 0.25);
    ui->staff_table->setColumnWidth(0, width * 0.25);
    ui->staff_table->setColumnWidth(1, width * 0.25);
    ui->staff_table->setColumnWidth(2, width * 0.25);
    ui->staff_table->setColumnWidth(3, width * 0.25);
}

void Dept_Pos_Emp::tableRefresh()
{
    //下面更新编制表、职位表、员工表的内容
    QNetworkRequest requeste;
    QString strUrle="http://8.130.119.222:1751/api/Values/getCertainOrgInfo?DepartmentTitle="+deptname;
    requeste.setUrl(QUrl(strUrle));

    QNetworkAccessManager naManagere;
    QNetworkReply* netReplye = nullptr;
    netReplye = naManagere.get(requeste);
    QEventLoop eventloope;
    connect(netReplye, SIGNAL(finished()), &eventloope, SLOT(quit()));
    QTimer::singleShot(10000, &eventloope, &QEventLoop::quit);
    eventloope.exec();
    if(netReplye->isFinished())
    {
        if(netReplye->error() == QNetworkReply::NoError)//正常结束，读取响应数据
        {
            QByteArray array = netReplye->readAll();
            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(array,&error);
            if(error.error !=QJsonParseError::NoError)
            {
                qDebug("json error");
                return ;
            }
            if (!doc.isNull() &&error.error == QJsonParseError::NoError)
            {
                for(int row = ui->auth_table->rowCount() - 1;row >= 0; row--)
                {
                    ui->auth_table->removeRow(row);
                }
                QJsonValue arrValue = doc.object().value("requestResult");
                if (arrValue.isArray())
                {
                    QJsonArray array = arrValue.toArray();  // 转数组
                    int nSize = array.size();
                    for (int i = 0; i < nSize; i++)
                    {
                        ui->auth_table->insertRow(ui->auth_table->rowCount());
                        int rowIdx = ui->auth_table->rowCount()-1;
                        //必须先设置item,然后再获取,因为默认是空的
                        QTableWidgetItem *item0 = new QTableWidgetItem(array.at(i).toObject().value("postID").toString());
                        QTableWidgetItem *item1 = new QTableWidgetItem(array.at(i).toObject().value("currentScale").toVariant().toString());
                        QTableWidgetItem *item2 = new QTableWidgetItem(array.at(i).toObject().value("emulatedScale").toVariant().toString());
                        ui->auth_table->setItem(rowIdx,0,item0);
                        ui->auth_table->setItem(rowIdx,1,item1);
                        ui->auth_table->setItem(rowIdx,2,item2);
                    }
                }
            }
        }
    }
    netReplye->deleteLater();

    QNetworkRequest requestp;
    QString strUrlp="http://8.130.119.222:1751/api/Values/getCertainPositionInfo?DepartmentTitle="+deptname;
    requestp.setUrl(QUrl(strUrlp));
    QNetworkAccessManager naManagerp;
    QNetworkReply* netReplyp = nullptr;
    netReplyp = naManagerp.get(requestp);
    QEventLoop eventloopp;
    connect(netReplyp, SIGNAL(finished()), &eventloopp, SLOT(quit()));
    QTimer::singleShot(10000, &eventloopp, &QEventLoop::quit);
    eventloopp.exec();
    if(netReplyp->isFinished())
    {
        if(netReplyp->error() == QNetworkReply::NoError)//正常结束，读取响应数据
        {
            QByteArray array = netReplyp->readAll();
            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(array,&error);
            if(error.error !=QJsonParseError::NoError)
            {
                qDebug("json error");
                return ;
            }
            if (!doc.isNull() &&error.error == QJsonParseError::NoError)
            {
                for(int row = ui->post_table->rowCount() - 1;row >= 0; row--)
                {
                    ui->post_table->removeRow(row);
                }
                QJsonValue arrValue = doc.object().value("requestResult");
                if (arrValue.isArray())
                {
                    QJsonArray array = arrValue.toArray();  // 转数组
                    int nSize = array.size();
                    for (int i = 0; i < nSize; i++)
                    {
                        ui->post_table->insertRow(ui->post_table->rowCount());
                        int rowIdx = ui->post_table->rowCount()-1;
                        //必须先设置item,然后再获取,因为默认是空的
                        QTableWidgetItem *item0 = new QTableWidgetItem(array.at(i).toObject().value("postID").toString());
                        QTableWidgetItem *item1 = new QTableWidgetItem(array.at(i).toObject().value("postTitle").toString());
                        QTableWidgetItem *item2 = new QTableWidgetItem(array.at(i).toObject().value("postType").toString());
                        QTableWidgetItem *item3 = new QTableWidgetItem(array.at(i).toObject().value("postLevel").toString());
                        ui->post_table->setItem(rowIdx,0,item0);
                        ui->post_table->setItem(rowIdx,1,item1);
                        ui->post_table->setItem(rowIdx,2,item2);
                        ui->post_table->setItem(rowIdx,3,item3);
                    }
                }
            }
        }
    }
    netReplyp->deleteLater();

    QNetworkRequest requests;
    QString strUrls="http://8.130.119.222:1751/api/Values/getCertainEmployeeInfo?DepartmentTitle="+deptname;
    requests.setUrl(QUrl(strUrls));
    QNetworkAccessManager naManagers;
    QNetworkReply* netReplys = nullptr;
    netReplys = naManagers.get(requests);
    QEventLoop eventloops;
    connect(netReplys, SIGNAL(finished()), &eventloops, SLOT(quit()));
    QTimer::singleShot(10000, &eventloops, &QEventLoop::quit);
    eventloops.exec();
    if(netReplys->isFinished())
    {
        if(netReplys->error() == QNetworkReply::NoError)//正常结束，读取响应数据
        {
            QByteArray array = netReplys->readAll();
            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(array,&error);
            if(error.error !=QJsonParseError::NoError)
            {
                qDebug("json error");
                return ;
            }
            if (!doc.isNull() &&error.error == QJsonParseError::NoError)
            {
                for(int row = ui->staff_table->rowCount() - 1;row >= 0; row--)
                {
                    ui->staff_table->removeRow(row);
                }
                QJsonValue arrValue = doc.object().value("requestResult");
                if (arrValue.isArray())
                {
                    QJsonArray array = arrValue.toArray();  // 转数组
                    int nSize = array.size();
                    for (int i = 0; i < nSize; i++)
                    {
                        ui->staff_table->insertRow(ui->staff_table->rowCount());
                        int rowIdx = ui->staff_table->rowCount()-1;
                        //必须先设置item,然后再获取,因为默认是空的
                        QTableWidgetItem *item0 = new QTableWidgetItem(array.at(i).toObject().value("employeeID").toString());
                        QTableWidgetItem *item1 = new QTableWidgetItem(array.at(i).toObject().value("currentPostID").toString());
                        QTableWidgetItem *item2 = new QTableWidgetItem(array.at(i).toObject().value("currentCity").toString());
                        QTableWidgetItem *item3 = new QTableWidgetItem(array.at(i).toObject().value("startWorkingDate").toString());
                        ui->staff_table->setItem(rowIdx,0,item0);
                        ui->staff_table->setItem(rowIdx,1,item1);
                        ui->staff_table->setItem(rowIdx,2,item2);
                        ui->staff_table->setItem(rowIdx,3,item3);
                    }
                }
            }
        }
    }
    netReplyp->deleteLater();
}
