#ifndef ATTENDANCE_APPLY_H
#define ATTENDANCE_APPLY_H

#include <QWidget>

namespace Ui {
class Attendance_Apply;
}

class Attendance_Apply : public QWidget
{
    Q_OBJECT

public:
    explicit Attendance_Apply(QWidget *parent = nullptr);
    ~Attendance_Apply();

private:
    Ui::Attendance_Apply *ui;
};

#endif // ATTENDANCE_APPLY_H
