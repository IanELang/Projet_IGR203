#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T15:19:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cornell
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    notebook.cpp \
    page.cpp \
    note.cpp

HEADERS  += mainwindow.h \
    notebook.h \
    page.h \
    note.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources/user.qrc
