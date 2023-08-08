#ifndef SALA_MANA_H
#define SALA_MANA_H

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
class Sala_Mana;
}

class Sala_Mana : public QWidget
{
    Q_OBJECT

public:
    explicit Sala_Mana(QWidget *parent = nullptr);
    ~Sala_Mana();

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Sala_Mana *ui;
};

#endif // SALA_MANA_H
