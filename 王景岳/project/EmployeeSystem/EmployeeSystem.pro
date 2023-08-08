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
    subpage/add_dept.cpp \
    subpage/dept_info.cpp \
    subpage/dept_pos.cpp \
    subpage/pre_appr.cpp \
    subpage/sala_mana.cpp \
    subpage_emp/dept_pos_emp.cpp \
    subpage_emp/my_pre.cpp \
    subpage_emp/sala_info.cpp

HEADERS += \
    login.h \
    mainwindow.h \
    mainwindow_emp.h \
    sign.h \
    subpage/add_dept.h \
    subpage/dept_info.h \
    subpage/dept_pos.h \
    subpage/pre_appr.h \
    subpage/sala_mana.h \
    subpage_emp/dept_pos_emp.h \
    subpage_emp/my_pre.h \
    subpage_emp/sala_info.h

FORMS += \
    login.ui \
    mainwindow.ui \
    mainwindow_emp.ui \
    sign.ui \
    subpage/add_dept.ui \
    subpage/dept_info.ui \
    subpage/dept_pos.ui \
    subpage/pre_appr.ui \
    subpage/sala_mana.ui \
    subpage_emp/dept_pos_emp.ui \
    subpage_emp/my_pre.ui \
    subpage_emp/sala_info.ui

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
