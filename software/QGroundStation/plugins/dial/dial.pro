TEMPLATE = lib
TARGET = DialGadget
QT += svg
QT += opengl

include(../../common.pri)

HEADERS += dialplugin.h
HEADERS += dialgadget.h
HEADERS += dialgadgetwidget.h
HEADERS += dialgadgetfactory.h
HEADERS += dialgadgetconfiguration.h
HEADERS += dialgadgetoptionspage.h
SOURCES += dialplugin.cpp
SOURCES += dialgadget.cpp
SOURCES += dialgadgetfactory.cpp
SOURCES += dialgadgetwidget.cpp
SOURCES += dialgadgetconfiguration.cpp
SOURCES += dialgadgetoptionspage.cpp
OTHER_FILES += DialGadget.pluginspec
FORMS += dialgadgetoptionspage.ui
RESOURCES += dial.qrc

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)

#指定生成的plugin保存目录
DESTDIR=$$PROJECT_PLUGINSDIR
