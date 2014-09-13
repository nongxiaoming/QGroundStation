TEMPLATE = lib
TARGET = GpsDisplayGadget
QT += svg
QT += serialport

include(../../common.pri)

HEADERS += gpsdisplayplugin.h
HEADERS += gpsconstellationwidget.h
HEADERS += gpsparser.h
HEADERS += telemetryparser.h
HEADERS += gpssnrwidget.h
HEADERS += buffer.h
HEADERS += nmeaparser.h
HEADERS += gpsdisplaygadget.h
HEADERS += gpsdisplaywidget.h
HEADERS += gpsdisplaygadgetfactory.h
HEADERS += gpsdisplaygadgetconfiguration.h
HEADERS += gpsdisplaygadgetoptionspage.h
SOURCES += gpsdisplayplugin.cpp
SOURCES += gpsconstellationwidget.cpp
SOURCES += gpsparser.cpp
SOURCES += telemetryparser.cpp
SOURCES += gpssnrwidget.cpp
SOURCES += buffer.cpp
SOURCES += nmeaparser.cpp
SOURCES += gpsdisplaygadget.cpp
SOURCES += gpsdisplaygadgetfactory.cpp
SOURCES += gpsdisplaywidget.cpp
SOURCES += gpsdisplaygadgetconfiguration.cpp
SOURCES += gpsdisplaygadgetoptionspage.cpp
OTHER_FILES += GpsDisplayGadget.pluginspec
FORMS += gpsdisplaygadgetoptionspage.ui
FORMS += gpsdisplaywidget.ui
RESOURCES += widgetresources.qrc

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(Qwt)\
        -l$$qtLibraryName(UAVObjects)


#指定生成的plugin保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
