#ifndef ADD_DEPT_H
#define ADD_DEPT_H

#include <QWidget>
#include <QDesktopWidget>
#include <QRegExpValidator>
#include <QMouseEvent>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QJsonObject>
#include <QDebug>
#include <QCloseEvent>

namespace Ui {
class Add_dept;
}

class Add_dept : public QWidget
{
    Q_OBJECT

public:
    explicit Add_dept(QWidget *parent = nullptr);
    ~Add_dept();

private:
    Ui::Add_dept *ui;

private slots:
    void on_addButton_clicked();
    void requestFinished(QNetworkReply *reply);      //用来接收网络访问结果的槽函数

signals:
    void closeSignal(); //新建部门后发送的信号，以便进行刷新
};

#endif // ADD_DEPT_H
