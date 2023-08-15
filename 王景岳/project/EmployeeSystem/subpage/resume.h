#ifndef RESUME_H
#define RESUME_H

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
class Resume;
}

class Resume : public QWidget
{
    Q_OBJECT

public:
    explicit Resume(QWidget *parent = nullptr);
    ~Resume();

private:
    Ui::Resume *ui;
};


#endif // RESUME_H
