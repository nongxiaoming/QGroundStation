TEMPLATE = lib
TARGET = ConsoleGadget

QT +=  core gui Qxt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../common.pri)

HEADERS += consoleplugin.h \
    texteditloggerengine.h
HEADERS += consolegadget.h
HEADERS += consolegadgetwidget.h
HEADERS += consolegadgetfactory.h
SOURCES += consoleplugin.cpp \
    texteditloggerengine.cpp
SOURCES += consolegadget.cpp
SOURCES += consolegadgetfactory.cpp
SOURCES += consolegadgetwidget.cpp
OTHER_FILES += ConsoleGadget.pluginspec

#依赖的库文件
LIBS += -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(ExtensionSystem)

#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
