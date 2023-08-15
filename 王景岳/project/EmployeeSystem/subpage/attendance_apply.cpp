#include "attendance_apply.h"
#include "ui_attendance_apply.h"

Attendance_Apply::Attendance_Apply(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Attendance_Apply)
{
    ui->setupUi(this);
}

Attendance_Apply::~Attendance_Apply()
{
    delete ui;
}
