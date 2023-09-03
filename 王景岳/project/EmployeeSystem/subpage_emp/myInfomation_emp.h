#ifndef MYINFOMATION_EMP_H
#define MYINFOMATION_EMP_H

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
class MyInfomation_Emp;
}

class Employee_Emp
{
public:
    QString ID_number;
    QString EmployeeID;
    QString Name;
    QString Sex;
    QString Birth;
    QString PhoneNumber;
    QString HomeAddress;
    QString ImageURL;
    QString WorkState;



    // 构造函数,将QJsonObject转换为Employee对象
    Employee_Emp(){
        ID_number = "";
        EmployeeID = "";
        Name ="";
        Sex = "";
        Birth = "";
        PhoneNumber = "";
        HomeAddress ="";
        ImageURL="";
        WorkState = "";
    }
    Employee_Emp(const QJsonObject& obj)
    {
        ID_number = obj["ID_number"].toString();
        EmployeeID = obj["EmployeeID"].toString();
        Name = obj["Name"].toString();
        Sex = obj["Sex"].toString();
        Birth = obj["Birth"].toString();
        PhoneNumber = obj["PhoneNumber"].toString();
        HomeAddress = obj["HomeAddress"].toString();
        ImageURL = obj["ImageURL"].toString();
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
        json["ImageURL"]=ImageURL;
        json["WorkState"]=WorkState;
        return json;
    }

};

class ResumeInfo_Emp {
public:
    QString idNumber;
    QString educationNo;
    QString educationType;
    QString institutionName;
    QString jobTitle;
    QString startTime;
    QString endTime;
    QString degree;
};

class SalaryInfo_Emp{
public:
    QString EmployeeID;
    QString PayDate;
    QString Bonus;
    QString Commission;
    QString OverallSalary;
};

class MyInfomation_Emp : public QWidget
{
    Q_OBJECT

public:
    explicit MyInfomation_Emp(QString employeeID,QWidget *parent = nullptr);
    ~MyInfomation_Emp();

    void basicInfomation();
    void dealBasicInfo(QJsonObject jsonObj);
    void dealEduInfo(QJsonObject jsonObj);
    void dealSalaryInfo(QJsonObject jsonObj);

    void bscChangeInfo();
    void bscEnsure();
    void bscCancel();

    void picPresent();
    void applyAnimation();
    void exitAnimation();

private:
    Ui::MyInfomation_Emp *ui;
    Employee_Emp employee;
    Employee_Emp temp;
};

#endif // MYINFOMATION_EMP_H
