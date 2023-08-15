#include "allcontract_info.h"
#include "ui_allcontract_info.h"

Allcontract_Info::Allcontract_Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Allcontract_Info)
{
    ui->setupUi(this);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(25);
    ui->addButton->setStyleSheet("background-color:rgb(65,105,225);color:rgb(255, 255, 255);font:10pt;");
    ui->addButton->setIcon(QIcon(":/images/icons8-plus-50.png"));
    ui->addButton->setIconSize(QSize(20,20));
    //ui->addButton->setButtonStyle(Qt::ToolButtonTextBesideIcon);

    //合同上传的上传返回按键
    connect(ui->addButton,&QPushButton::clicked,this,&Allcontract_Info::ToContractReg);
    connect(&Add_contract,&Add_contract::ToContractInfo,this,&Allcontract_Info::ToContractInfo);

    QStringList headText;
    headText << "合同编号" << "员工编号" << "合同类型" << "合同状态"<<"生效日期"<<"失效日期"<<"合同链接";
        ui->tableWidget->setHorizontalHeaderLabels(headText);
}

//合同上传的页面切换
void Allcontract_Info::ToContractReg()
{
    this->hide();
    Add_contract.show();
}

void Allcontract_Info::ToContractInfo()
{
    this->show();
    Add_contract.close();
}


Allcontract_Info::~Allcontract_Info()
{
    delete ui;
}
