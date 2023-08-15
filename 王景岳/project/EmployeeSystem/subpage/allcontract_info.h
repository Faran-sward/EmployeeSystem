#ifndef ALLCONTRACT_INFO_H
#define ALLCONTRACT_INFO_H

#include <QWidget>
#include <QResizeEvent>
#include"add_contract.h"

namespace Ui {
class Allcontract_Info;
}

class Allcontract_Info : public QWidget
{
    Q_OBJECT

public:
    explicit Allcontract_Info(QWidget *parent = nullptr);
    ~Allcontract_Info();



public:
    Add_contract Add_contract;
    void ToContractReg();
    void ToContractInfo();

private:
    Ui::Allcontract_Info *ui;
};

#endif // ALLCONTRACT_INFO_H
