#ifndef PRE_APPR_H
#define PRE_APPR_H

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
class Pre_Appr;
}

class Pre_Appr : public QWidget
{
    Q_OBJECT

public:
    explicit Pre_Appr(QWidget *parent = nullptr);
    ~Pre_Appr();

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Pre_Appr *ui;
};

#endif // PRE_APPR_H
