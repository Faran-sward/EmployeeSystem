#ifndef MYAPPLY_EMP_H
#define MYAPPLY_EMP_H

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
class MyApply_Emp;
}

class MyApply_Emp : public QWidget
{
    Q_OBJECT

public:
    explicit MyApply_Emp(QString  employeeID ,QWidget *parent = nullptr);
    ~MyApply_Emp();

    void initialize();
    void updateDayOptions();
    void sendGetRequest(QString url);
    void onApproveClicked(int row);
    void onDisApproveClicked(int row);

private:
    Ui::MyApply_Emp *ui;
    QString employeeID;
};


#endif // MYAPPLY_EMP_H
