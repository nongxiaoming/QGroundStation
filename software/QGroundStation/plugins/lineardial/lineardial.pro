TEMPLATE = lib
TARGET = LineardialGadget
QT += svg
QT += opengl
include(../../common.pri)

HEADERS += lineardialplugin.h
HEADERS += lineardialgadget.h
HEADERS += lineardialgadgetwidget.h
HEADERS += lineardialgadgetfactory.h
HEADERS += lineardialgadgetconfiguration.h
HEADERS += lineardialgadgetoptionspage.h
SOURCES += lineardialplugin.cpp
SOURCES += lineardialgadget.cpp
SOURCES += lineardialgadgetfactory.cpp
SOURCES += lineardialgadgetwidget.cpp
SOURCES += lineardialgadgetconfiguration.cpp
SOURCES += lineardialgadgetoptionspage.cpp
OTHER_FILES += LineardialGadget.pluginspec
FORMS += lineardialgadgetoptionspage.ui
RESOURCES += lineardial.qrc

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)


#指定生成的plugin保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
