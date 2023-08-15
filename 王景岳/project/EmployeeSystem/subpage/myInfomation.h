#ifndef MYINFOMATION_H
#define MYINFOMATION_H

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
class MyInfomation;
}

class Employee
{
public:
    QString ID_number;
    QString EmployeeID;
    QString Name;
    QString Sex;
    QString Birth;
    QString PhoneNumber;
    QString HomeAddress;
    QString WorkState;
    QString Salary;

    // 构造函数,将QJsonObject转换为Employee对象
    Employee(){
        ID_number = "";
        EmployeeID = "";
        Name ="";
        Sex = "";
        Birth = "";
        PhoneNumber = "";
        HomeAddress ="";
        WorkState = "";
    }
    Employee(const QJsonObject& obj)
    {
        ID_number = obj["ID_number"].toString();
        EmployeeID = obj["EmployeeID"].toString();
        Name = obj["Name"].toString();
        Sex = obj["Sex"].toString();
        Birth = obj["Birth"].toString();
        PhoneNumber = obj["PhoneNumber"].toString();
        HomeAddress = obj["HomeAddress"].toString();
        WorkState = obj["WorkState"].toString();
    }

    //根据接口，转换成json的函数
    QJsonObject toJson() const {
        QJsonObject json;
        json["ID_number"]=ID_number;
        json["EmployeeID"] = EmployeeID;
        json["Name"] = Name;
        json["Sex"] = Sex;
        json["Birth"] = Birth;
        json["PhoneNumber"] = PhoneNumber;
        json["HomeAddress"]=HomeAddress;
        json["WorkState"]=WorkState;
        return json;
    }

};

class MyInfomation : public QWidget
{
    Q_OBJECT

public:
    explicit MyInfomation(QWidget *parent = nullptr);
    ~MyInfomation();

    void basicInfomation(const QString& employeeID);
    void bscChangeInfo();
    void bscEnsure();
    void bscCancel();

private:
    Ui::MyInfomation *ui;
    QNetworkAccessManager* networkManager;
    Employee employee;
};

#endif // MYINFOMATION_H
