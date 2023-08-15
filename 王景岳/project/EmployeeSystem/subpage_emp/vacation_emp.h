#ifndef VACATION_EMP_H
#define VACATION_EMP_H

#include <QWidget>

namespace Ui {
class Vacation_Emp;
}

class Vacation_Emp : public QWidget
{
    Q_OBJECT

public:
    explicit Vacation_Emp(QWidget *parent = nullptr);
    ~Vacation_Emp();

private:
    Ui::Vacation_Emp *ui;
};

#endif // VACATION_EMP_H
