#ifndef MYCONTRACT_INFO_H
#define MYCONTRACT_INFO_H

#include <QWidget>
#include <QButtonGroup>
#include <QThread>
#include <QTimer>

/*changed*/
#include<QMouseEvent>
#include<QMessageBox>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>
#include <QTabWidget>
#include <QTabBar>

namespace Ui {
class Mycontract_Info;
}

class Mycontract_Info : public QWidget
{
    Q_OBJECT

public:
    explicit Mycontract_Info(QWidget *parent = nullptr);
    ~Mycontract_Info();

public slots:
    void Contractcheck(void);          //合同查看所用

private:
    Ui::Mycontract_Info *ui;
};

#endif // MYCONTRACT_INFO_H
