QT += core network
QT -= gui

CONFIG += c++11

TARGET = university_networks_lab_2_getDNS
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    my_dns_one.cpp

HEADERS += \
    my_dns_one.h
