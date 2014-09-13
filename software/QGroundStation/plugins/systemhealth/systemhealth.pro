TEMPLATE = lib
TARGET = SystemHealthGadget
QT += svg
include(../../common.pri)

HEADERS += systemhealthplugin.h
HEADERS += systemhealthgadget.h
HEADERS += systemhealthgadgetwidget.h
HEADERS += systemhealthgadgetfactory.h
HEADERS += systemhealthgadgetconfiguration.h
HEADERS += systemhealthgadgetoptionspage.h
SOURCES += systemhealthplugin.cpp
SOURCES += systemhealthgadget.cpp
SOURCES += systemhealthgadgetfactory.cpp
SOURCES += systemhealthgadgetwidget.cpp
SOURCES += systemhealthgadgetconfiguration.cpp
SOURCES += systemhealthgadgetoptionspage.cpp
OTHER_FILES += SystemHealthGadget.pluginspec
FORMS += systemhealthgadgetoptionspage.ui

RESOURCES += \
    systemhealth.qrc

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(UAVTalk)

#指定生成的lib保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
