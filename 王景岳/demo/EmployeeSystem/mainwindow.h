#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qabstractbutton.h"
#include <QMainWindow>
#include <QButtonGroup>
#include <QThread>
#include <QTimer>
#include "subpage/dept_info.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QButtonGroup * topgroup = new QButtonGroup(this);
    int parentIndexnow=0,indexnow=0;
    int parentlong[6]={2,2,3,2,3,2};
    bool parentexpand[6]={1,1,1,1,1,1};
    Dept_Info* dept_info;

private slots:
    void GetLeftPress(int index, int parentIndex); //上方标签被点击后触发的槽函数
    void GetTopPress(int index); //左侧标签被点击后触发的槽函数
    void UpdateLeft(); //定时更新左侧导航目录的槽函数

};
#endif // MAINWINDOW_H
