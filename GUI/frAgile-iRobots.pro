#-------------------------------------------------
#
# Project created by QtCreator 2016-11-05T13:32:24
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = frAgile-iRobots
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    customer.cpp

HEADERS  += mainwindow.h \
    customer.h

FORMS    += mainwindow.ui
