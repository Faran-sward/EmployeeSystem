#ifndef OVERTIME_EMP_H
#define OVERTIME_EMP_H

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

namespace Ui {
class Overtime_Emp;
}

class Overtime_Emp : public QWidget
{
    Q_OBJECT

public:
    explicit Overtime_Emp(QWidget *parent = nullptr);
    ~Overtime_Emp();

    void show_overtime();

public slots:
    void on_request_clicked();
    void on_handapply_clicked();
    void on_cancelapply_clicked();

private:
    Ui::Overtime_Emp *ui;
    QStandardItemModel* work_model;
    bool flag = true;
};

#endif // OVERTIME_EMP_H
