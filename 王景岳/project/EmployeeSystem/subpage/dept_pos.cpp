#include "dept_pos.h"
#include "ui_dept_pos.h"

Dept_Pos::Dept_Pos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dept_Pos)
{
    ui->setupUi(this);
    int width=ui->tabWidget->width()-2;
    ui->auth_table->setColumnCount(3);
    ui->auth_table->setColumnWidth(0, width * 0.33);
    ui->auth_table->setColumnWidth(1, width * 0.33);
    ui->auth_table->setColumnWidth(2, width * 0.34);
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

    ui->addButton->setStyleSheet("background-color:rgb(65,105,225);color:rgb(255, 255, 255);font:8pt;");
    ui->addButton->setIcon(QIcon(":/images/icons8-plus-50.png"));
    ui->addButton->setIconSize(QSize(15,15));

    url=QUrl(QString("http://121.41.120.170:5555/api/Dept/Get?building=")+QString("办公楼1"));
    request.setUrl(url);
    connect(&manager,&QNetworkAccessManager::finished,this,&Dept_Pos::GetDept);
    manager.get(request);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotCountMessage()));
    timer->start(1000);
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
}

void Dept_Pos::slotCountMessage()
{
    qDebug()<<"进行一次刷新";
    manager.get(request);
}

Dept_Pos::~Dept_Pos()
{
    delete ui;
}

void Dept_Pos::on_comboBox_currentIndexChanged(int index)
{
    if(index==-1){
        return;
    }
    if(thearray!=NULL){
        ui->num_lab->setText(QString("部门编号：")+thearray->at(index).toObject().value("id").toString());
        ui->name_lab->setText(QString("部门名称：")+thearray->at(index).toObject().value("name").toString());
        ui->build_lab->setText(QString("所在楼：")+thearray->at(index).toObject().value("buliding").toString());
        ui->floor_lab->setText(QString("所在楼层：")+thearray->at(index).toObject().value("layer").toString());
    }
    if(index==0){
        return;
    }
    deptname=ui->comboBox->itemText(index);
    qDebug()<<"当前选中"<<ui->comboBox->itemText(index);
}

void Dept_Pos::resizeEvent(QResizeEvent *event)
{
    int width=ui->tabWidget->width()-2;
    ui->auth_table->setColumnWidth(0, width * 0.33);
    ui->auth_table->setColumnWidth(1, width * 0.33);
    ui->auth_table->setColumnWidth(2, width * 0.34);
    ui->post_table->setColumnWidth(0, width * 0.20);
    ui->post_table->setColumnWidth(1, width * 0.20);
    ui->post_table->setColumnWidth(2, width * 0.20);
    ui->post_table->setColumnWidth(3, width * 0.20);
    ui->post_table->setColumnWidth(4, width * 0.20);
    ui->staff_table->setColumnWidth(0, width * 0.25);
    ui->staff_table->setColumnWidth(1, width * 0.25);
    ui->staff_table->setColumnWidth(2, width * 0.25);
    ui->staff_table->setColumnWidth(3, width * 0.25);
}
