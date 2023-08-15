#include "myApply.h"
#include "ui_myApply.h"

MyApply::MyApply(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyApply)
{
    ui->setupUi(this);
}

MyApply::~MyApply()
{
    delete ui;
}
