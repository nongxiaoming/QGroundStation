TEMPLATE = lib
TARGET = MagicWaypoint 
QT += svg

include(../../common.pri)

HEADERS += magicwaypointgadget.h
HEADERS += magicwaypointgadgetwidget.h
HEADERS += magicwaypointgadgetfactory.h
HEADERS += magicwaypointplugin.h
HEADERS += positionfield.h

SOURCES += magicwaypointgadget.cpp
SOURCES += magicwaypointgadgetwidget.cpp
SOURCES += magicwaypointgadgetfactory.cpp
SOURCES += magicwaypointplugin.cpp
SOURCES += positionfield.cpp

OTHER_FILES += MagicWaypoint.pluginspec

FORMS += magicwaypoint.ui

RESOURCES += magicwaypoint.qrc

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)


#指定生成的plugin保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
