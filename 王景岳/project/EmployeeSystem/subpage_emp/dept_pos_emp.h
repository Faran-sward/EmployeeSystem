#ifndef DEPT_POS_EMP_H
#define DEPT_POS_EMP_H

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
#include <QScrollBar>

namespace Ui {
class Dept_Pos_Emp;
}

class Dept_Pos_Emp : public QWidget
{
    Q_OBJECT

public:
    explicit Dept_Pos_Emp(QWidget *parent = nullptr);
    ~Dept_Pos_Emp();

private:
    Ui::Dept_Pos_Emp *ui;
    QString deptname="";
    QNetworkAccessManager manager;
    QNetworkRequest request;
    QUrl url = QUrl("");
    void GetDept(QNetworkReply *reply);
    QJsonArray* thearray=NULL;
    int nVSliderValue_0 = 0;
    void getScrollValue();
    void setScrollValue();
    bool notchange=false;

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private slots:
    void slotCountMessage();       //定时触发的槽函数
    void on_comboBox_currentIndexChanged(int index);
};

#endif // DEPT_POS_EMP_H
