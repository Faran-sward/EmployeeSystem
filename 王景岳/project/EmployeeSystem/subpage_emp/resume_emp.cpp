#include "resume_emp.h"
#include "ui_resume_emp.h"

Resume_Emp::Resume_Emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Resume_Emp)
{
    ui->setupUi(this);
}

Resume_Emp::~Resume_Emp()
{
    delete ui;
}
