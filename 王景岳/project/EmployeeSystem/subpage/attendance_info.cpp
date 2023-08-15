#include "attendance_info.h"
#include "ui_attendance_info.h"

Attendance_Info::Attendance_Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Attendance_Info)
{
    ui->setupUi(this);
}

Attendance_Info::~Attendance_Info()
{
    delete ui;
}
