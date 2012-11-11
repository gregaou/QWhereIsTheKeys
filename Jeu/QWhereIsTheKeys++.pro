#-------------------------------------------------
#
# Project created by QtCreator 2012-11-11T20:26:01
#
#-------------------------------------------------

QT       += core gui

TARGET = QWhereIsTheKeys++
TEMPLATE = app


SOURCES += sources/main.cpp\
        sources/qwitk.cpp \
        sources/profil.cpp \
    sources/vue_factory.cpp \
    sources/vue_accueil.cpp \
    sources/model_profil.cpp

HEADERS  += sources/headers/qwitk.h \
    sources/headers/vue.h \
    sources/headers/singleton.h \
    sources/headers/profil.h \
    sources/headers/vue_factory.h \
    sources/headers/vue_accueil.h \
    sources/headers/model_profil.h

FORMS    += ui/qwitk.ui \
    ui/vue_accueil.ui
