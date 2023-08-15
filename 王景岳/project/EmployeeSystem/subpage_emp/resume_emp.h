#ifndef RESUME_EMP_H
#define RESUME_EMP_H

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
class Resume_Emp;
}

class Resume_Emp : public QWidget
{
    Q_OBJECT

public:
    explicit Resume_Emp(QWidget *parent = nullptr);
    ~Resume_Emp();

private:
    Ui::Resume_Emp *ui;
};


#endif // RESUME_EMP_H
