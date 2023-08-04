#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EmployeeSystemFrontends.h"

class EmployeeSystemFrontends : public QMainWindow
{
    Q_OBJECT

public:
    EmployeeSystemFrontends(QWidget *parent = nullptr);
    ~EmployeeSystemFrontends();

private:
    Ui::EmployeeSystemFrontendsClass ui;
};
