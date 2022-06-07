QT += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        Bullet.cpp \
        Playerone.cpp \
        Playertwo.cpp \
        baseitem.cpp \
        gamemenu.cpp \
        main.cpp \
        pvcmode.cpp \
        pvpmode.cpp \
        shield.cpp

HEADERS += \
    Bullet.h \
    Playerone.h \
    Playertwo.h \
    baseitem.h \
    gamemenu.h \
    pvcmode.h \
    pvpmode.h \
    shield.h

RESOURCES += \
    image.qrc

DISTFILES +=

