QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    sign.cpp \
    subpage/dept_info.cpp

HEADERS += \
    login.h \
    mainwindow.h \
    sign.h \
    subpage/dept_info.h

FORMS += \
    login.ui \
    mainwindow.ui \
    sign.ui \
    subpage/dept_info.ui

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

QT += network

DISTFILES += \
    images/icons8-closed-eye-100.png \
    images/icons8-eye-100.png \
    images/icons8-lock-60.png \
    images/icons8-user-60.png
