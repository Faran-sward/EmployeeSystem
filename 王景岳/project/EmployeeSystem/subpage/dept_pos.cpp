#include "dept_pos.h"
#include "ui_dept_pos.h"

Dept_Pos::Dept_Pos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dept_Pos)
{
    ui->setupUi(this);
    int width=ui->tabWidget->width()-2;
    ui->auth_table->setColumnCount(4);
    ui->auth_table->setColumnWidth(0, width * 0.25);
    ui->auth_table->setColumnWidth(1, width * 0.25);
    ui->auth_table->setColumnWidth(2, width * 0.25);
    ui->auth_table->setColumnWidth(3, width * 0.25);
    ui->post_table->setColumnCount(5);
    ui->post_table->setColumnWidth(0, width * 0.20);
    ui->post_table->setColumnWidth(1, width * 0.20);
    ui->post_table->setColumnWidth(2, width * 0.20);
    ui->post_table->setColumnWidth(3, width * 0.20);
    ui->post_table->setColumnWidth(4, width * 0.20);
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

    ui->addButton->setStyleSheet("background-color:rgb(65,105,225);color:rgb(255, 255, 255);font:8pt;");
    ui->addButton->setIcon(QIcon(":/images/icons8-plus-50.png"));
    ui->addButton->setIconSize(QSize(15,15));

    url=QUrl(QString("http://121.41.120.170:5555/api/Dept/Get?building=")+QString("办公楼1"));
    request.setUrl(url);
    connect(&manager,&QNetworkAccessManager::finished,this,&Dept_Pos::GetDept);
    connect(ui->application, SIGNAL(closeSignal()), this, SLOT(slotCountMessage()));
    manager.get(request);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotCountMessage()));
    timer->start(1000);
    ui->auth_table->installEventFilter(this);
    ui->post_table->installEventFilter(this);
    ui->staff_table->installEventFilter(this);
}

void Dept_Pos::getScrollValue()
{
    QScrollBar *vScrollbar = ui->comboBox->view()->verticalScrollBar();
    nVSliderValue_0 = vScrollbar->sliderPosition();
}

void Dept_Pos::setScrollValue()
{
    QScrollBar *vScrollbar = ui->comboBox->view()->verticalScrollBar();
    if(ui->comboBox->currentIndex()==0){
        ui->comboBox->setCurrentIndex(-1);
        vScrollbar->setSliderPosition(nVSliderValue_0);
        ui->comboBox->setCurrentIndex(0);
    }
    vScrollbar->setSliderPosition(nVSliderValue_0);
}

void Dept_Pos::GetDept(QNetworkReply *reply)
{
    QByteArray array = reply->readAll();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(array,&error);
    if(error.error !=QJsonParseError::NoError)
    {
        qDebug("json error");
        return ;
    }
    getScrollValue();
    if (!doc.isNull() &&error.error == QJsonParseError::NoError)
    {
        //qDebug() << "文件解析成功\n";
        int dept_ind=-1;
        if (doc.isArray())
        {
            QJsonArray array = doc.array();  // 转数组
            if(thearray!=NULL){
                delete thearray;
            }
            thearray=new QJsonArray(array);
            int nSize = array.size();
            ui->comboBox->clear();
            for (int i = 0; i < nSize; i++)
            {
                ui->comboBox->addItem(array.at(i).toObject().value("name").toString());
                if(array.at(i).toObject().value("name").toString()==deptname){
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
        }
    }
    setScrollValue();
}

void Dept_Pos::slotCountMessage()
{
    //qDebug()<<"进行一次刷新";
    manager.get(request);
}

Dept_Pos::~Dept_Pos()
{
    delete ui;
}

void Dept_Pos::on_comboBox_currentIndexChanged(int index)
{
    if(index==-1){
        notchange=true;
        return;
    }
    if(thearray!=NULL){
        ui->num_lab->setText(QString("部门编号：")+thearray->at(index).toObject().value("id").toString());
        ui->name_lab->setText(QString("部门名称：")+thearray->at(index).toObject().value("name").toString());
        ui->build_lab->setText(QString("所在楼：")+thearray->at(index).toObject().value("buliding").toString());
        ui->floor_lab->setText(QString("所在楼层：")+thearray->at(index).toObject().value("layer").toString());
    }
    if(index==0&&notchange){
        notchange=false;
        return;
    }
    deptname=ui->comboBox->itemText(index);
    qDebug()<<"当前选中"<<ui->comboBox->itemText(index);
}

bool Dept_Pos::eventFilter(QObject * watched, QEvent * event)
{
    if(watched==ui->auth_table){
        if(event->type() == QEvent::Resize){
            int width=ui->tabWidget->width()-2;
            ui->auth_table->setColumnWidth(0, width * 0.25);
            ui->auth_table->setColumnWidth(1, width * 0.25);
            ui->auth_table->setColumnWidth(2, width * 0.25);
            ui->auth_table->setColumnWidth(3, width * 0.25);
        }
    }
    else if(watched==ui->post_table){
        if(event->type() == QEvent::Resize){
            int width=ui->tabWidget->width()-2;
            ui->post_table->setColumnWidth(0, width * 0.20);
            ui->post_table->setColumnWidth(1, width * 0.20);
            ui->post_table->setColumnWidth(2, width * 0.20);
            ui->post_table->setColumnWidth(3, width * 0.20);
            ui->post_table->setColumnWidth(4, width * 0.20);
        }
    }
    else if(watched==ui->staff_table){
        if(event->type() == QEvent::Resize){
            int width=ui->tabWidget->width()-2;
            ui->staff_table->setColumnWidth(0, width * 0.25);
            ui->staff_table->setColumnWidth(1, width * 0.25);
            ui->staff_table->setColumnWidth(2, width * 0.25);
            ui->staff_table->setColumnWidth(3, width * 0.25);
        }
    }
}

void Dept_Pos::on_addButton_clicked()
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
