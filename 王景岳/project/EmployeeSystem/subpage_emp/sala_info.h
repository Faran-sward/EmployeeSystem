#ifndef SALA_INFO_H
#define SALA_INFO_H

#include <QWidget>
#include <QDesktopWidget>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QJsonObject>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <QMessageBox>
#include <QResizeEvent>
#include <QStandardItem>
#include <QScrollBar>
#include <QPropertyAnimation>

namespace Ui {
class Sala_Info;
}

class Sala_Info : public QWidget
{
    Q_OBJECT

public:
    explicit Sala_Info(QString num,QWidget *parent = nullptr);
    ~Sala_Info();

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Sala_Info *ui;
    QString mynum;
    QNetworkAccessManager manager;
    QStandardItemModel *model;
    QNetworkRequest request;
    QUrl url = QUrl("");
    void GetSala(QNetworkReply *reply);
    int nVSliderValue = 0;
    int nHSliderValue = 0;
    void getScrollValue();
    void setScrollValue();

private slots:
    void slotCountMessage();       //定时触发的槽函数
};

#endif // SALA_INFO_H
