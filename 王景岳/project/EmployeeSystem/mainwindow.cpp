#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * 该窗口是boss登录后进入的主界面
 */
MainWindow::MainWindow(QString num,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::CustomizeWindowHint);
    ui->setupUi(this);

    jobnum=num;
    qDebug()<<"当前登录工号："<<jobnum;
    QImage image;
    image.load(":/images/head_icon.png");
    ui->labIco->setScaledContents(true);
    ui->labIco->setPixmap(QPixmap::fromImage(image));
    //设置左侧标签导航栏内容与样式
    QString str="组织规划||0||,部门信息|组织规划|||,部门管理|组织规划|||,编制申请审批|组织规划|||,薪资管理||0||,薪资变更|薪资管理|||,员工信息||0||,我的信息|员工信息|||,员工简历|员工信息|||,职务管理||0||,我的职务|职务管理|||,我的申请|职务管理|||,受理申请|职务管理|||,合同管理||0||,员工合同|合同管理|||,受理申请|合同管理|||,考勤管理||0||,考勤信息|考勤管理|||,排班管理|考勤管理|||,受理申请|考勤管理|||";

    ui->navListView->setItems(str);
    ui->navListView->setChildBgNormalColor(QColor(100,149,255));//
    ui->navListView->setChildTextNormalColor(QColor(255,255,255));//
    ui->navListView->setChildBgHoverColor(QColor(100,149,255,100));//
    ui->navListView->setChildTextHoverColor(QColor(0,0,0));//
    ui->navListView->setChildBgSelectedColor(QColor(100,149,255,200));
    ui->navListView->setChildTextSelectedColor(QColor(255,255,255));//
    ui->navListView->setTriangleColor(QColor(255,255,255));//
    ui->navListView->setLineColor(QColor(255,255,255));//
    ui->navListView->setParentBgNormalColor(QColor(65,105,225));//
    ui->navListView->setParentTextNormalColor(QColor(255,255,255));//
    ui->navListView->setParentBgHoverColor(QColor(65,105,225,100));//
    ui->navListView->setParentTextHoverColor(QColor(0,0,0));//
    ui->navListView->setParentBgSelectedColor(QColor(65,105,225,200));//
    ui->navListView->setParentTextSelectedColor(QColor(0,0,0));//
    ui->navListView->setStyleSheet("border: none;");
    ui->stackedWidget->setStyleSheet("#stackedWidget{background-color:rgb(240,240,240);}");
    /*changed*/
    //注册事件过滤器
    installEventFilter(this);
    //创建QNetworkAccessManager对象
    networkManager = new QNetworkAccessManager(this);
    //隐藏标题栏
    //setWindowFlags (Qt::CustomizeWindowHint);


    //将上方标签按钮加入按钮组
    topgroup->addButton(ui->toolButton,0);
    topgroup->addButton(ui->toolButton_2,1);
    //topgroup->addButton(ui->toolButton_3,2);
    ui->widgetTitle->setProperty("form", "title");
    ui->widgetLeft->setProperty("nav", "left");
    ui->widgetTop->setProperty("nav", "top");

    //将所有子页面生成并加入stackedWidget
    dept_pos=new Dept_Pos();
    ui->stackedWidget->addWidget(dept_pos);
    dept_info=new Dept_Info();
    ui->stackedWidget->addWidget(dept_info);
    pre_appr=new Pre_Appr();
    ui->stackedWidget->addWidget(pre_appr);
    sala_mana=new Sala_Mana();
    ui->stackedWidget->addWidget(sala_mana);

    myinfomation = new MyInfomation();
    ui->stackedWidget->addWidget(myinfomation);
    resume = new Resume();
    ui->stackedWidget->addWidget(resume);
    deployment = new Deployment();
    ui->stackedWidget->addWidget(deployment);
    myapply = new MyApply();
    ui->stackedWidget->addWidget(myapply);
    solveapply=new SolveApply();
    ui->stackedWidget->addWidget(solveapply);
    allcontractinfo=new Allcontract_Info();
    ui->stackedWidget->addWidget(allcontractinfo);
    contractapply=new ContractApply();
    ui->stackedWidget->addWidget(contractapply);

    attendance_info = new Attendance_Info();
    ui->stackedWidget->addWidget(attendance_info);
    schedule = new Schedule();
    ui->stackedWidget->addWidget(schedule);
    attendance_apply = new Attendance_Apply();
    ui->stackedWidget->addWidget(attendance_apply);
    /*
     * 加入新页面
     */

    connect(ui->navListView,SIGNAL(pressed(int,int)),this,SLOT(GetLeftPress(int,int)));
    connect(topgroup,SIGNAL(buttonClicked(int)),this,SLOT(GetTopPress(int)));
    connect(ui->toolButton_3,SIGNAL(pressed()),this,SLOT(this.on_toolButton_3_clicked()));
    ui->navListView->setCurrentRow(1);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateLeft()));
    timer->start(10);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent( QCloseEvent * event ){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "退出程序", "确定要退出吗?", QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            // 用户选择了退出，关闭程序
            event->accept();
        } else {
            // 用户选择了取消，忽略关闭事件
            event->ignore();
        }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event){
        {
            static bool isMousePressed = false;		//鼠标是否按下
            static QPoint mousePos;					//鼠标按下位置在窗体中的坐标

            QMouseEvent *ev = static_cast<QMouseEvent *>(event);

            //鼠标左键按下
            if (ev->type()==QEvent::MouseButtonPress)
            {
                if (ev->button()==Qt::LeftButton)
                {
                    isMousePressed = true;
                    mousePos = ev->globalPos() - pos();		//鼠标全局坐标-窗体左上顶点坐标
                }
                else
                {
                    exit(0);
                }

            }
            else if (ev->type() == QEvent::MouseButtonRelease)
            {
                isMousePressed = false;
                return true;
            }
            else if (ev->type() == QEvent::MouseMove)
            {
                if (isMousePressed && (ev->buttons() && Qt::LeftButton))
                {
                    if (!this->isMaximized()){ //窗口已经最大化则禁止拖动
                        this->move(ev->globalPos() - mousePos);
                        return true;
                    }
                }
            }
            return QWidget::eventFilter(watched, event);;
        }
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
    for(int i=0;i<parentIndex;i++){
        page+=parentlong[i];
    }
    page+=index;
    ui->stackedWidget->setCurrentIndex(page);
}

void MainWindow::GetTopPress(int index)
{
    ui->navListView->setCurrentRow(-1);
    indexnow=0;
    parentIndexnow=-1;
    int page=14+index;
    ui->stackedWidget->setCurrentIndex(page);
}

void MainWindow::on_toolButton_3_clicked()
{
    close();
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

void MainWindow::on_btnMenu_Close_clicked()
{
    close();
}

void MainWindow::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void MainWindow::on_btnMenu_Max_clicked()
{
    if (this->isMaximized())
    {
        this->showNormal();//还原事件
        ui->btnMenu_Max->setText("□");
        ui->btnMenu_Max->setToolTip(tr("最大化"));
    }
    else
    {
        this->showMaximized();//最大化事件
        ui->btnMenu_Max->setText("▣");
        ui->btnMenu_Max->setToolTip(tr("最大化还原"));
    }
}

