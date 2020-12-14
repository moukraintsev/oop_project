QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_film_window.cpp \
    add_series_window.cpp \
    film.cpp \
    main.cpp \
    mainwindow.cpp \
    series.cpp \
    show_film_window.cpp \
    show_not_viewed.cpp \
    show_series_window.cpp \
    video.cpp \
    videocollection.cpp

HEADERS += \
    add_film_window.h \
    add_series_window.h \
    film.h \
    mainwindow.h \
    series.h \
    show_film_window.h \
    show_not_viewed.h \
    show_series_window.h \
    video.h \
    videocollection.h

FORMS += \
    add_film_window.ui \
    add_series_window.ui \
    mainwindow.ui \
    show_film_window.ui \
    show_not_viewed.ui \
    show_series_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
