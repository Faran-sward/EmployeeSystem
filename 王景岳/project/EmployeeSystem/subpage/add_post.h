#ifndef ADD_POST_H
#define ADD_POST_H

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
class Add_post;
}

class Add_post : public QWidget
{
    Q_OBJECT

public:
    explicit Add_post(QWidget *parent = nullptr);
    ~Add_post();

private:
    Ui::Add_post *ui;

private slots:
    void on_addButton_clicked();
    void requestFinished(QNetworkReply *reply);      //用来接收网络访问结果的槽函数

signals:
    void closeSignal(); //新建部门后发送的信号，以便进行刷新
};

#endif // ADD_POST_H
