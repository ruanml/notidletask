# -------------------------------------------------
# Project created by QtCreator 2012-01-01T15:36:39
# -------------------------------------------------
TARGET = notidletask
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    linuxsystemidle.cpp \
    isystemidle.cpp \
    configuration.cpp
HEADERS += mainwindow.h \
    isystemidle.h \
    linuxsystemidle.h \
    configuration.h \
    main.h
FORMS += mainwindow.ui
QT += xml
LIBS += -lXss
