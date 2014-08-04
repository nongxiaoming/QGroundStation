TEMPLATE = lib 
TARGET = EmptyGadget

QT +=  core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../common.pri)

HEADERS += emptyplugin.h
HEADERS += emptygadget.h
HEADERS += emptygadgetwidget.h
HEADERS += emptygadgetfactory.h
SOURCES += emptyplugin.cpp
SOURCES += emptygadget.cpp
SOURCES += emptygadgetfactory.cpp
SOURCES += emptygadgetwidget.cpp

OTHER_FILES += EmptyGadget.pluginspec

#依赖的库文件
LIBS += -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(ExtensionSystem)

#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
