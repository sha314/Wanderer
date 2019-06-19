#-------------------------------------------------
#
# Project created by QtCreator 2019-06-09T23:20:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Wanderer
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
        copypasteoperation.cpp \
        fileconflict.cpp \
        form/columnviewform.cpp \
        form/iconviewform.cpp \
        form/listviewform.cpp \
        form/treeviewform.cpp \
        list_files_folders.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        copypasteoperation.h \
        fileconflict.h \
        form/columnviewform.h \
        form/iconviewform.h \
        form/listviewform.h \
        form/treeviewform.h \
        list_files_folders.h \
        mainwindow.h \
        src/view/viewmodes.h

FORMS += \
        copypasteoperation.ui \
        fileconflict.ui \
        form/columnviewform.ui \
        form/iconviewform.ui \
        form/listviewform.ui \
        form/treeviewform.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES +=

RESOURCES += \
    appicon.qrc \
    menu_bar_icons.qrc
