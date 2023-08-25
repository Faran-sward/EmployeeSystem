#ifndef MYATTENDANCE_H
#define MYATTENDANCE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>
#include <QPushButton>
#include <QTableWidget>
#include <QPropertyAnimation>
#include <QMessageBox>
#include <QDateTime>

namespace Ui {
class MyAttendance;
}

class MyAttendance : public QWidget
{
    Q_OBJECT

public:
    explicit MyAttendance(QWidget *parent = nullptr);
    ~MyAttendance();

    void show_table();

public slots:
    void on_pushButton_clicked();
    void on_signin_clicked();

private:
    QStandardItemModel* sch_model;
    bool flag = true;

    Ui::MyAttendance *ui;
};

#endif // MYATTENDANCE_H
