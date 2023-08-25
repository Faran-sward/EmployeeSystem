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

    url=QUrl(QString("http://121.41.120.170:5555/api/Dept/Get?building=")+QString("办公楼1"));
    request.setUrl(url);
    connect(&manager,&QNetworkAccessManager::finished,this,&Dept_Pos_Emp::GetDept);
    manager.get(request);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotCountMessage()));
    timer->start(1000);
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
        qDebug() << "文件解析成功\n";
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
        if(dept_ind!=-1){
            ui->comboBox->setCurrentIndex(dept_ind);
        }
        else{
            ui->comboBox->setCurrentIndex(0);
            deptname=ui->comboBox->itemText(0);
        }
    }
    setScrollValue();
}

void Dept_Pos_Emp::slotCountMessage()
{
    qDebug()<<"进行一次刷新";
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
