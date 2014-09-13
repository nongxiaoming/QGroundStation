TEMPLATE = lib
TARGET = Telemetry
DEFINES += TELEMETRY_LIBRARY

QT += svg

include(../../common.pri)

HEADERS += telemetry_global.h \
    telemetryplugin.h \
    monitorwidget.h \
    monitorgadgetconfiguration.h \
    monitorgadget.h \
    monitorgadgetfactory.h \
    monitorgadgetoptionspage.h

SOURCES += telemetryplugin.cpp \
    monitorwidget.cpp \
    monitorgadgetconfiguration.cpp \
    monitorgadget.cpp \
    monitorgadgetfactory.cpp \
    monitorgadgetoptionspage.cpp

OTHER_FILES += Telemetry.pluginspec

RESOURCES += telemetry.qrc

#依赖的库文件
LIBS *= -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(UAVObjectUtil)\
        -l$$qtLibraryName(UAVTalk)\
        -l$$qtLibraryName(VersionInfo)

#指定生成的plugin保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
