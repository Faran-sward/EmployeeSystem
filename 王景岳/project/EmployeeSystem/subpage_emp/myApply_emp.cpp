#include "myApply_emp.h"
#include "ui_myApply_emp.h"

MyApply_Emp::MyApply_Emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyApply_Emp)
{
    ui->setupUi(this);
}

MyApply_Emp::~MyApply_Emp()
{
    delete ui;
}
