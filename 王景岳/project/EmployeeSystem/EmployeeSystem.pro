QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow_emp.cpp \
    sign.cpp \
    subpage/add_contract.cpp \
    subpage/add_dept.cpp \
    subpage/add_post.cpp \
    subpage/allcontract_info.cpp \
    subpage/attendance_apply.cpp \
    subpage/attendance_info.cpp \
    subpage/change_auth.cpp \
    subpage/change_sala.cpp \
    subpage/contractapply.cpp \
    subpage/deployment.cpp \
    subpage/dept_info.cpp \
    subpage/dept_pos.cpp \
    subpage/myApply.cpp \
    subpage/myInfomation.cpp \
    subpage/resume.cpp \
    subpage/sala_mana.cpp \
    subpage/schedule.cpp \
    subpage/solveApply.cpp \
    subpage_emp/contractapply_emp.cpp \
    subpage_emp/deployment_emp.cpp \
    subpage_emp/dept_pos_emp.cpp \
    subpage_emp/myApply_emp.cpp \
    subpage_emp/myInfomation_emp.cpp \
    subpage_emp/myattendance.cpp \
    subpage_emp/mycontract_info.cpp \
    subpage_emp/overtime_emp.cpp \
    subpage_emp/resume_emp.cpp \
    subpage_emp/sala_info.cpp \
    subpage_emp/vacation_emp.cpp

HEADERS += \
    login.h \
    mainwindow.h \
    mainwindow_emp.h \
    sign.h \
    subpage/add_contract.h \
    subpage/add_dept.h \
    subpage/add_post.h \
    subpage/allcontract_info.h \
    subpage/attendance_apply.h \
    subpage/attendance_info.h \
    subpage/change_auth.h \
    subpage/change_sala.h \
    subpage/contractapply.h \
    subpage/deployment.h \
    subpage/dept_info.h \
    subpage/dept_pos.h \
    subpage/myApply.h \
    subpage/myInfomation.h \
    subpage/resume.h \
    subpage/sala_mana.h \
    subpage/schedule.h \
    subpage/solveApply.h \
    subpage_emp/contractapply_emp.h \
    subpage_emp/deployment_emp.h \
    subpage_emp/dept_pos_emp.h \
    subpage_emp/myApply_emp.h \
    subpage_emp/myInfomation_emp.h \
    subpage_emp/myattendance.h \
    subpage_emp/mycontract_info.h \
    subpage_emp/overtime_emp.h \
    subpage_emp/resume_emp.h \
    subpage_emp/sala_info.h \
    subpage_emp/vacation_emp.h

FORMS += \
    login.ui \
    mainwindow.ui \
    mainwindow_emp.ui \
    sign.ui \
    subpage/add_contract.ui \
    subpage/add_dept.ui \
    subpage/add_post.ui \
    subpage/allcontract_info.ui \
    subpage/attendance_apply.ui \
    subpage/attendance_info.ui \
    subpage/change_auth.ui \
    subpage/change_sala.ui \
    subpage/contractapply.ui \
    subpage/deployment.ui \
    subpage/dept_info.ui \
    subpage/dept_pos.ui \
    subpage/myApply.ui \
    subpage/myInfomation.ui \
    subpage/resume.ui \
    subpage/sala_mana.ui \
    subpage/schedule.ui \
    subpage/solveApply.ui \
    subpage_emp/contractapply_emp.ui \
    subpage_emp/deployment_emp.ui \
    subpage_emp/dept_pos_emp.ui \
    subpage_emp/myApply_emp.ui \
    subpage_emp/myInfomation_emp.ui \
    subpage_emp/myattendance.ui \
    subpage_emp/mycontract_info.ui \
    subpage_emp/overtime_emp.ui \
    subpage_emp/resume_emp.ui \
    subpage_emp/sala_info.ui \
    subpage_emp/vacation_emp.ui

DESTDIR = $$PWD/quc
CONFIG(debug, debug|release){
LIBS += -L$$PWD/quc/ -lqucd
} else {
LIBS += -L$$PWD/quc/ -lquc
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    other/qss.qrc
