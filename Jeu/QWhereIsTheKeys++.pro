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
    sources/model_profil.cpp \
    sources/vue_profil_nouveau.cpp \
    sources/vue_profil_charger.cpp \
    sources/vue_profil_supprimer.cpp \
    sources/delegate_profil_supprimer.cpp

HEADERS  += sources/headers/qwitk.h \
    sources/headers/vue.h \
    sources/headers/singleton.h \
    sources/headers/profil.h \
    sources/headers/vue_factory.h \
    sources/headers/vue_accueil.h \
    sources/headers/model_profil.h \
    sources/headers/vue_profil_nouveau.h \
    sources/headers/vue_profil_charger.h \
    sources/headers/vue_profil.h \
    sources/headers/vue_profil_supprimer.h \
    sources/headers/delegate_profil_supprimer.h

FORMS    += ui/qwitk.ui \
    ui/vue_accueil.ui \
    ui/vue_profil_nouveau.ui \
    ui/vue_profil_charger.ui \
    ui/vue_profil_supprimer.ui

RESOURCES += \
    ressources/ressources.qrc
