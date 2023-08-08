#ifndef MY_PRE_H
#define MY_PRE_H

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
class My_Pre;
}

class My_Pre : public QWidget
{
    Q_OBJECT

public:
    explicit My_Pre(QWidget *parent = nullptr);
    ~My_Pre();

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    Ui::My_Pre *ui;
};

#endif // MY_PRE_H
