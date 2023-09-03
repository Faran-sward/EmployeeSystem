#ifndef CHANGE_SALA_H
#define CHANGE_SALA_H

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
class Change_Sala;
}

class Change_Sala : public QWidget
{
    Q_OBJECT

public:
    explicit Change_Sala(QWidget *parent = nullptr);
    ~Change_Sala();
    QString numnow;
    void setInfo(QString num,QString basic,QString bonus,QString comm);

private:
    Ui::Change_Sala *ui;

private slots:
    void on_addButton_clicked();
    void on_addButton_2_clicked();
    void requestFinished(QNetworkReply *reply);      //用来接收网络访问结果的槽函数

signals:
    void closeSignal(); //取消后发送的信号，以便进行隐藏
    void changedSignal(); //变更后发送的信号，以便进行更新
};

#endif // CHANGE_SALA_H
