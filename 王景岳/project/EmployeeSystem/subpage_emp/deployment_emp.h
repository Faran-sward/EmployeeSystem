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

namespace Ui {
class Deployment_Emp;
}

class Deployment_Emp : public QWidget
{
    Q_OBJECT

public:
    explicit Deployment_Emp(QWidget *parent = nullptr);
    ~Deployment_Emp();

    void deploymentRecord(const QString& employeeID);

private:
    Ui::Deployment_Emp *ui;
    QNetworkAccessManager* networkManager;
};
#endif // DEPLOYMENT_EMP_H
