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
    explicit MyApply(QString employrrID,QWidget *parent = nullptr);
    ~MyApply();

    void initialize();
    void updateDayOptions();
    void sendGetRequest(QString url);
    void onApproveClicked(int row);
    void onDisApproveClicked(int row);

private:
    Ui::MyApply *ui;
    QString employeeID;
};


#endif // MYAPPLY_H
