#ifndef CHANGE_AUTH_H
#define CHANGE_AUTH_H

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
class Change_Auth;
}

class Change_Auth : public QWidget
{
    Q_OBJECT

public:
    explicit Change_Auth(QWidget *parent = nullptr);
    ~Change_Auth();
    QString deptnumnow,postnumnow;
    void setInfo(QString deid,QString dename,QString poid,QString poname,QString num);

private:
    Ui::Change_Auth *ui;

private slots:
    void on_addButton_clicked();
    void on_addButton_2_clicked();
    void requestFinished(QNetworkReply *reply);      //用来接收网络访问结果的槽函数

signals:
    void closeSignal(); //取消后发送的信号，以便进行隐藏
    void changedSignal(); //变更后发送的信号，以便进行更新
};

#endif // CHANGE_AUTH_H
