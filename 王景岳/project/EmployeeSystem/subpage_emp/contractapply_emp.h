#ifndef CONTRACTAPPLY_EMP_H
#define CONTRACTAPPLY_EMP_H

#include <QWidget>

namespace Ui {
class ContractApply_emp;
}

class ContractApply_emp : public QWidget
{
    Q_OBJECT

public:
    explicit ContractApply_emp(QWidget *parent = nullptr);
    ~ContractApply_emp();

private:
    Ui::ContractApply_emp *ui;
};

#endif // CONTRACTAPPLY_EMP_H
