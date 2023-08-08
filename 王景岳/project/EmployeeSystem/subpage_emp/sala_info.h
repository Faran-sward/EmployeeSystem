#ifndef SALA_INFO_H
#define SALA_INFO_H

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
class Sala_Info;
}

class Sala_Info : public QWidget
{
    Q_OBJECT

public:
    explicit Sala_Info(QWidget *parent = nullptr);
    ~Sala_Info();

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Sala_Info *ui;
};

#endif // SALA_INFO_H
