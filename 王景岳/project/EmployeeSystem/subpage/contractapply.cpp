#include "contractapply.h"
#include "ui_contractapply.h"

ContractApply::ContractApply(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContractApply)
{
    ui->setupUi(this);
}

ContractApply::~ContractApply()
{
    delete ui;
}
