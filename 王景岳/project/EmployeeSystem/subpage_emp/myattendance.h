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

private:
    QStandardItemModel* att_model;
    QStandardItemModel* sch_model;

    Ui::MyAttendance *ui;
};

#endif // MYATTENDANCE_H
