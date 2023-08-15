#ifndef MYAPPLY_H
#define MYAPPLY_H

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

namespace Ui {
class MyApply;
}

class MyApply : public QWidget
{
    Q_OBJECT

public:
    explicit MyApply(QWidget *parent = nullptr);
    ~MyApply();

private:
    Ui::MyApply *ui;
};


#endif // MYAPPLY_H
