TEMPLATE = lib

TARGET = LoggingGadget
DEFINES += LOGGING_LIBRARY
QT += svg

include(../../common.pri)

HEADERS += loggingplugin.h \
    logginggadgetwidget.h \
    logginggadget.h \
    logginggadgetfactory.h

SOURCES += loggingplugin.cpp \
    logginggadgetwidget.cpp \
    logginggadget.cpp \
    logginggadgetfactory.cpp

OTHER_FILES += LoggingGadget.pluginspec

FORMS += logging.ui

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(UAVTalk)\
        -l$$qtLibraryName(ScopeGadget)

#指定生成的plugin保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
