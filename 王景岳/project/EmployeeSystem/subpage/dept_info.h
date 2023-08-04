#ifndef DEPT_INFO_H
#define DEPT_INFO_H

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
class Dept_Info;
}

class Dept_Info : public QWidget
{
    Q_OBJECT

public:
    explicit Dept_Info(QWidget *parent = nullptr);
    ~Dept_Info();

private:
    Ui::Dept_Info *ui;
    QNetworkAccessManager manager;
    QNetworkRequest request;
    QUrl url = QUrl("");
    void GetDept(QNetworkReply *reply);

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private slots:
    void slotCountMessage();       //定时触发的槽函数
    void onCancelClicked();        //取消按钮被点击触发的槽函数
    void on_addButton_clicked();
};

#endif // DEPT_INFO_H
