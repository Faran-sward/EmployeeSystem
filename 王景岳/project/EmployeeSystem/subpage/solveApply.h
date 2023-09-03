#ifndef SOLVEAPPLY_H
#define SOLVEAPPLY_H

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
class SolveApply;
}

class SolveApply : public QWidget
{
    Q_OBJECT

public:
    explicit SolveApply(QWidget *parent = nullptr);
    ~SolveApply();

    void onApproveClicked(int row);
    void onDisApproveClicked(int row);
    void initialize();
    void updateDayOptions();
    void sendGetRequest(QString url);

private:
    Ui::SolveApply *ui;
};



#endif // SOLVEAPPLY_H
