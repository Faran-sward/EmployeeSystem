#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置左侧标签导航栏内容与样式
    QString str="组织规划||0||,部门信息|组织规划|||,部门管理|组织规划|||,员工信息||0||,我的信息|员工信息|||,全体信息|员工信息|||,职务管理||0||,我的职务|职务管理|||,简历管理|职务管理|||,入职登记|职务管理|||,合同管理||0||,合同信息查看|合同管理|||,合同信息管理|合同管理|||,考勤管理||0||,考勤排班|考勤管理|||,我的日历|考勤管理|||,考勤数据修改|考勤管理|||,薪资管理||0||,我的薪水|薪资管理|||,薪水变更|薪资管理|||";
    ui->navListView->setItems(str);
    ui->navListView->setChildBgNormalColor(QColor(228,228,228));
    ui->navListView->setChildTextNormalColor(QColor(127,129,133));
    ui->navListView->setChildBgHoverColor(QColor(0,187,158));
    ui->navListView->setChildTextHoverColor(QColor(255,255,255));
    ui->navListView->setChildBgSelectedColor(QColor(255,255,255));
    ui->navListView->setChildTextSelectedColor(QColor(127,129,133));
    ui->navListView->setTriangleColor(QColor(127,129,133));
    ui->navListView->setLineColor(QColor(0,187,158));
    /*ui->navListView->setParentBgNormalColor(QColor(127,129,133));
    ui->navListView->setParentTextNormalColor(QColor(228,228,228));*/
    ui->navListView->setParentBgNormalColor(QColor(40,43,51));
    ui->navListView->setParentTextNormalColor(QColor(255,255,255));
    ui->navListView->setParentBgHoverColor(QColor(40,43,51));
    ui->navListView->setParentTextHoverColor(QColor(255,255,255));
    ui->navListView->setParentBgSelectedColor(QColor(40,43,51));
    ui->navListView->setParentTextSelectedColor(QColor(255,255,255));
    //将上方标签按钮加入按钮组
    topgroup->addButton(ui->toolButton,0);
    topgroup->addButton(ui->toolButton_2,1);
    topgroup->addButton(ui->toolButton_3,2);
    ui->widgetTitle->setProperty("form", "title");
    ui->widgetLeft->setProperty("nav", "left");
    ui->widgetTop->setProperty("nav", "top");
    //将所有子页面生成并加入stackedWidget
    dept_info=new Dept_Info;
    ui->stackedWidget->addWidget(dept_info);

    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->navListView,SIGNAL(pressed(int,int)),this,SLOT(GetLeftPress(int,int)));
    connect(topgroup,SIGNAL(buttonClicked(int)),this,SLOT(GetTopPress(int)));
    ui->navListView->setCurrentRow(1);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateLeft()));
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GetLeftPress(int index, int parentIndex)
{
    if(parentIndex == -1){ //当点击的是可展开标签时，更新记录的展开状态
        parentexpand[index]=1-parentexpand[index];
        return;
    }
    parentIndexnow=parentIndex;
    indexnow=index;
    topgroup->button(0)->setChecked(true);
    topgroup->setExclusive(false);
    topgroup->button(0)->setChecked(false);
    topgroup->setExclusive(true);
    int page=0;
    if(parentIndex<=2){
        page=parentIndex*2+index;
    }
    else if(parentIndex<=4){
        page=parentIndex*2+index+1;
    }
    else{
        page=parentIndex*2+index+2;
    }
    /*
     * 此处进行页面切换
     */
}

void MainWindow::GetTopPress(int index)
{
    ui->navListView->setCurrentRow(-1);
    indexnow=0;
    parentIndexnow=-1;
    int page=14+index;
    /*
     * 此处进行页面切换
     */
}

void MainWindow::UpdateLeft()
{
    if(parentexpand[parentIndexnow]){
        int row=0;
        for(int i=0;i<parentIndexnow;i++){
            row+=parentexpand[i]*parentlong[i]+1;
        }
        row+=indexnow+1;
        ui->navListView->setCurrentRow(row);
    }
}
