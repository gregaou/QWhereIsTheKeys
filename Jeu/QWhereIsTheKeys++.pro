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
    sources/vue_menu_jeu.cpp \
    sources/vue_nouveau_jeu.cpp \
    sources/model_jeu.cpp

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
    sources/headers/vue_menu_jeu.h \
    sources/headers/vue_nouveau_jeu.h \
    sources/headers/model_jeu.h

FORMS    += ui/qwitk.ui \
    ui/vue_accueil.ui \
    ui/vue_profil_nouveau.ui \
    ui/vue_profil_charger.ui \
    ui/vue_profil_supprimer.ui \
    ui/vue_menu_jeu.ui \
    ui/vue_nouveau_jeu.ui

RESOURCES += \
    ressources/ressources.qrc
