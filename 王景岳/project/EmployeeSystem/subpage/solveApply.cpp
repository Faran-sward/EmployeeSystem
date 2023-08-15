#include "solveApply.h"
#include "ui_solveApply.h"

SolveApply::SolveApply(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SolveApply)
{
    ui->setupUi(this);
}

SolveApply::~SolveApply()
{
    delete ui;
}
