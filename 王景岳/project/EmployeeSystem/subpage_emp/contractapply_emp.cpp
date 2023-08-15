#include "contractapply_emp.h"
#include "ui_contractapply_emp.h"

ContractApply_emp::ContractApply_emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContractApply_emp)
{
    ui->setupUi(this);
}

ContractApply_emp::~ContractApply_emp()
{
    delete ui;
}
