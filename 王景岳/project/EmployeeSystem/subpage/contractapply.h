#ifndef CONTRACTAPPLY_H
#define CONTRACTAPPLY_H

#include <QWidget>

namespace Ui {
class ContractApply;
}

class ContractApply : public QWidget
{
    Q_OBJECT

public:
    explicit ContractApply(QWidget *parent = nullptr);
    ~ContractApply();

private:
    Ui::ContractApply *ui;
};

#endif // CONTRACTAPPLY_H
