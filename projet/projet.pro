#-------------------------------------------------
#
# Project created by QtCreator 2017-03-29T16:37:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    note.cpp \
    page.cpp \
    notebook.cpp

HEADERS  += mainwindow.h \
    note.h \
    page.h \
    notebook.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
