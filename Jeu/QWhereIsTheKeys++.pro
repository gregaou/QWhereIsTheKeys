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
    sources/model_jeu.cpp \
    sources/vue_jeu.cpp \
    sources/objet_jeu.cpp \
    sources/oj_heros.cpp \
    sources/objet_jeu_mobile.cpp \
    sources/oj_plateforme.cpp \
    sources/vue_jeu_charger.cpp \
    sources/vue_jeu_menu.cpp \
    sources/vue_jeu_nouveau.cpp \
    sources/collision_oj_heros.cpp \
    sources/niveau.cpp \
    sources/model_niveau.cpp

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
    sources/headers/model_jeu.h \
    sources/headers/vue_jeu.h \
    sources/headers/objet_jeu.h \
    sources/headers/oj_heros.h \
    sources/headers/objet_jeu_mobile.h \
    sources/headers/oj_plateforme.h \
    sources/headers/vue_jeu_charger.h \
    sources/headers/vue_jeu_menu.h \
    sources/headers/vue_jeu_nouveau.h \
    sources/headers/collision_oj.h \
    sources/headers/collision_oj_heros.h \
    sources/headers/model_niveau.h \
    sources/headers/niveau.h

FORMS    += ui/qwitk.ui \
    ui/vue_accueil.ui \
    ui/vue_profil_nouveau.ui \
    ui/vue_profil_charger.ui \
    ui/vue_profil_supprimer.ui \
    ui/vue_jeu.ui \
    ui/vue_jeu_charger.ui \
    ui/vue_jeu_menu.ui \
    ui/vue_jeu_nouveau.ui

RESOURCES += \
    ressources/ressources.qrc
