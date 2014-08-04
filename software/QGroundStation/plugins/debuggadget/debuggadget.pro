TEMPLATE = lib 
TARGET = DebugGadget

QT +=  core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../common.pri)

HEADERS += debugplugin.h \
    debugengine.h
HEADERS += debuggadget.h
HEADERS += debuggadgetwidget.h
HEADERS += debuggadgetfactory.h
SOURCES += debugplugin.cpp \
    debugengine.cpp
SOURCES += debuggadget.cpp
SOURCES += debuggadgetfactory.cpp
SOURCES += debuggadgetwidget.cpp

OTHER_FILES += DebugGadget.pluginspec

FORMS += \
    debug.ui

#依赖的库文件
LIBS += -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(ExtensionSystem)

#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
