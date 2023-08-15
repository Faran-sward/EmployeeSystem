#ifndef ATTENDANCE_INFO_H
#define ATTENDANCE_INFO_H

#include <QWidget>

namespace Ui {
class Attendance_Info;
}

class Attendance_Info : public QWidget
{
    Q_OBJECT

public:
    explicit Attendance_Info(QWidget *parent = nullptr);
    ~Attendance_Info();

private:
    Ui::Attendance_Info *ui;
};

#endif // ATTENDANCE_INFO_H
