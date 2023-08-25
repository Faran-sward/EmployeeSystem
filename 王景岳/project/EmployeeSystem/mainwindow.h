#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qabstractbutton.h"
#include <QMainWindow>
#include <QButtonGroup>
#include <QThread>
#include <QTimer>
#include "subpage/dept_info.h"
#include "subpage/dept_pos.h"
#include "subpage/sala_mana.h"
#include "subpage/myInfomation.h"
#include "subpage/resume.h"
#include "subpage/deployment.h"
#include "subpage/myApply.h"
#include "subpage/solveApply.h"
#include "subpage/allcontract_info.h"
#include "subpage/contractapply.h"
#include "subpage/attendance_info.h"
#include "subpage/schedule.h"
#include "subpage/attendance_apply.h"

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
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString num,QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent( QCloseEvent * event )override;

    void requestData(const QString& empID);
    void handleNetworkReply();

protected:
    bool eventFilter(QObject *watched, QEvent *event)override;

private:
    Ui::MainWindow *ui;
    QButtonGroup * topgroup = new QButtonGroup(this);
    int parentIndexnow=0,indexnow=0;
    int parentlong[6]={2,1,2,3,2,3};
    bool parentexpand[6]={1,1,1,1,1,1};
    QString jobnum;

    QNetworkAccessManager* networkManager;
    QStandardItemModel* model;

    Dept_Info* dept_info;
    Dept_Pos* dept_pos;
    Sala_Mana* sala_mana;
    MyInfomation* myinfomation;
    Resume* resume;
    Deployment *deployment;
    MyApply *myapply;
    SolveApply * solveapply;
    Allcontract_Info* allcontractinfo;
    ContractApply* contractapply;
    Attendance_Info* attendance_info;
    Schedule* schedule;
    Attendance_Apply* attendance_apply;
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
#endif // MAINWINDOW_H
