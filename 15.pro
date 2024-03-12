#-------------------------------------------------
#
# Project created by QtCreator 2022-05-13T03:18:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 15
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    settings.cpp \
    object.cpp \
    brush.cpp \
    color.cpp \
    pen.cpp \
    tochka.cpp \
    brush_style_dialog.cpp \
    pen_style_dialog.cpp \
    width_dialog.cpp \
    poly_dialog.cpp \
    dialog.cpp \
    my_widget.cpp \
    arc.cpp \
    ellipse.cpp \
    line.cpp \
    lom.cpp \
    pixel.cpp \
    poly.cpp \
    rectangle.cpp \
    color_dialog.cpp

HEADERS += \
        mainwindow.h \
    settings.h \
    object.h \
    brush.h \
    color.h \
    pen.h \
    tochka.h \
    brush_style_dialog.h \
    pen_style_dialog.h \
    width_dialog.h \
    poly_dialog.h \
    dialog.h \
    my_widget.h \
    arc.h \
    ellipse.h \
    line.h \
    lom.h \
    pixel.h \
    poly.h \
    rectangle.h \
    color_dialog.h

FORMS += \
        mainwindow.ui \
    settings.ui \
    brush_style_dialog.ui \
    pen_style_dialog.ui \
    width_dialog.ui \
    poly_dialog.ui \
    dialog.ui \
    color_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
