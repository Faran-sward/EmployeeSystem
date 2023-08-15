#ifndef DEPLOYMENT_H
#define DEPLOYMENT_H

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
class Deployment;
}

class Deployment : public QWidget
{
    Q_OBJECT

public:
    explicit Deployment(QWidget *parent = nullptr);
    ~Deployment();

    void deploymentRecord(const QString& employeeID);
    QNetworkAccessManager* networkManager;

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Deployment *ui;
};


#endif // DEPLOYMENT_H
