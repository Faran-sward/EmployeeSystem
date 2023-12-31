﻿#ifndef MAINWINDOW_EMP_H
#define MAINWINDOW_EMP_H

#include "qabstractbutton.h"
#include <QMainWindow>
#include <QButtonGroup>
#include <QThread>
#include <QTimer>
#include "subpage_emp/sala_info.h"
#include "subpage_emp/dept_pos_emp.h"
#include "subpage_emp/deployment_emp.h"
#include "subpage_emp/myInfomation_emp.h"
#include "subpage_emp/resume_emp.h"
#include "subpage_emp/myApply_emp.h"
#include "subpage_emp/mycontract_info.h"
#include "subpage_emp/contractapply_emp.h"
#include "subpage_emp/myattendance.h"
#include "subpage_emp/overtime_emp.h"
#include "subpage_emp/vacation_emp.h"

/*changed*/
#include<QMouseEvent>
#include<QMessageBox>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_Emp; }
QT_END_NAMESPACE

class MainWindow_Emp : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_Emp(QString num,QWidget *parent = nullptr);
    ~MainWindow_Emp();
    void closeEvent( QCloseEvent * event )override;

    void requestData(const QString& empID);
    void handleNetworkReply();


protected:
    bool eventFilter(QObject *watched, QEvent *event)override;

private:
    Ui::MainWindow_Emp *ui;
    QButtonGroup * topgroup = new QButtonGroup(this);
    int parentIndexnow=0,indexnow=0;
    int parentlong[6]={1,1,2,2,2,3};
    bool parentexpand[6]={1,1,1,1,1,1};
    QString jobnum;

    QNetworkAccessManager* networkManager;
    QStandardItemModel* model;

    Sala_Info* sala_info;
    Dept_Pos_Emp* dept_pos_emp;
    Deployment_Emp *deployment_emp;
    MyInfomation_Emp* myinfomation_emp;
    Resume_Emp* resume_emp;
    MyApply_Emp* myApply_emp;
    Mycontract_Info* mycontract_info;
    ContractApply_emp* contractapply_emp;
    MyAttendance* myattendance;
    Overtime_Emp* overtime_emp;
    Vacation_Emp* vacation_emp;
    /*
     * 加入新页面
     */

private slots:
    void GetLeftPress(int index, int parentIndex); //上方标签被点击后触发的槽函数
    void GetTopPress(int index); //左侧标签被点击后触发的槽函数
    void UpdateLeft(); //定时更新左侧导航目录的槽函数
    void on_toolButton_3_clicked();
    void on_btnMenu_Close_clicked();
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
};
#endif // MAINWINDOW_EMP_H
