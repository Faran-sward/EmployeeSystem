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
#include <QStandardItem>
#include <QScrollBar>
#include <QPropertyAnimation>
#include <QMessageBox>
#include <QErrorMessage>

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
    bool eventFilter(QObject * watched, QEvent * event);

private:
    Ui::Sala_Mana *ui;
    QNetworkAccessManager manager;
    QStandardItemModel *model;
    QNetworkRequest request;
    QUrl url = QUrl("");
    void GetSala(QNetworkReply *reply);
    int nVSliderValue = 0;
    int nHSliderValue = 0;
    void getScrollValue();
    void setScrollValue();
    bool flag = true;
    int yearnow;
    int monthnow;

private slots:
    void slotCountMessage();       //定时触发的槽函数
    void onChangeClicked();        //变更按钮被点击触发的槽函数
    void hideRight();
};

#endif // SALA_MANA_H
