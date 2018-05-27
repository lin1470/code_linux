#-------------------------------------------------
#
# Project created by QtCreator 2016-12-03T16:13:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = one_card_system2
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    dialog.cpp \
    sure.cpp \
    warning.cpp

HEADERS  += widget.h \
    dialog.h \
    sure.h \
    warning.h

FORMS    += widget.ui \
    dialog.ui \
    sure.ui \
    warning.ui
