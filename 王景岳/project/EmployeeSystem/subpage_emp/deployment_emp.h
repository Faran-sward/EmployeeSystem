#ifndef DEPLOYMENT_EMP_H
#define DEPLOYMENT_EMP_H

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

#include <QStandardItemModel>
#include <QPropertyAnimation>

namespace Ui {
class Deployment_Emp;
}

class Deployment_Emp : public QWidget
{
    Q_OBJECT

public:
    explicit Deployment_Emp(QString employeeID,QWidget *parent = nullptr);
    ~Deployment_Emp();

    void jobRecord();
    void deploymentRecord();

    void changeComboBoxInitiate();
    void applyAnimation();
    void submitApply();
    void applyAddInfomation();

    void applyButtonAnimation();

    void getApplyID();
    void getName();


private:
    Ui::Deployment_Emp *ui;
    bool flagApplyPresentButton = true;
    QString applyID;
    QString employeeID;
    QString name;
    QString applyTime;
};
#endif // DEPLOYMENT_EMP_H
