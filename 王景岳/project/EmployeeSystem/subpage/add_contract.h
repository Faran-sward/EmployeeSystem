#ifndef ADD_CONTRACT_H
#define ADD_CONTRACT_H

#include <QWidget>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <QString>
#include <QLayout>
#include <QCalendarWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTextCodec>
#include <QTabWidget>
#include <QTabBar>


namespace Ui {
class Add_contract;
}

class Add_contract : public QWidget
{
    Q_OBJECT

public:
    explicit Add_contract(QWidget *parent = nullptr);
    ~Add_contract();

signals:
    void ToContractInfo();

public:
    void ModifyId();
    void encode_url(QString str, QByteArray &outArr);

private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_4_editingFinished();

    void on_lineEdit_5_editingFinished();

    void on_lineEdit_6_editingFinished();

public slots:
    void contract_upload(void);



private:
    Ui::Add_contract *ui;
    QString new_employee_id,new_contract_id,new_contract_type
        ,new_effective_date,new_inoperative_date,new_document_link;
};

#endif // ADD_CONTRACT_H
