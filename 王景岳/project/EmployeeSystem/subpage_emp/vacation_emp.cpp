#include "vacation_emp.h"
#include "ui_vacation_emp.h"

Vacation_Emp::Vacation_Emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Vacation_Emp)
{
    ui->setupUi(this);
}

Vacation_Emp::~Vacation_Emp()
{
    delete ui;
}
