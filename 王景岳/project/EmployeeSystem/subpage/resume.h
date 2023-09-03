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

#include<QPropertyAnimation>
#include <QTableWidget>

namespace Ui {
class Resume;
}

class Resume : public QWidget
{
    Q_OBJECT

public:
    explicit Resume(QWidget *parent = nullptr);
    ~Resume();

    void fillComboBox();
    void presentDepartInfo();
    void presentEmployeeInfo();
    void onEmployeeCellClicked(int row, int column);


    void Leftmenu_Animation();
    void pdfToPic();
    void getResumePic();
    void maxResume();
    void returnToUi();
    void download();


private:
    Ui::Resume *ui;
    QString searchingID;


private slots:
    void treatCheckedCombo();
};


#endif // RESUME_H
