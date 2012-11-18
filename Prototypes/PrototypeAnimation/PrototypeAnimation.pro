#-------------------------------------------------
#
# Project created by QtCreator 2012-11-16T09:05:58
#
#-------------------------------------------------

QT       += core gui

TARGET = PrototypeAnimation
TEMPLATE = app


SOURCES += main.cpp\
    carre.cpp \
    vue_jeu.cpp \
    objet_jeu.cpp \
    mainwindow.cpp \
    objetjeufactory.cpp

HEADERS  += \
    carre.h \
    vue_jeu.h \
    objet_jeu.h \
    mainwindow.h \
    singleton.h \
    objetjeufactory.h

FORMS    += \
    vue_jeu.ui \
    mainwindow.ui

RESOURCES += \
    ressources.qrc
