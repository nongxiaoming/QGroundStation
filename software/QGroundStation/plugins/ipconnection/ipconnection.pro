TEMPLATE = lib
TARGET = IPconnection
include(../../common.pri)

QT +=  core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += ipconnectionplugin.h \
    ipconnection_global.h \
    ipconnectionconfiguration.h \
    ipconnectionoptionspage.h \
    ipconnection_internal.h
SOURCES += ipconnectionplugin.cpp \
    ipconnectionconfiguration.cpp \
    ipconnectionoptionspage.cpp
FORMS += ipconnectionoptionspage.ui
RESOURCES += 
DEFINES += IPconnection_LIBRARY
OTHER_FILES += IPconnection.pluginspec

#依赖的库文件
LIBS += -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)


#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
