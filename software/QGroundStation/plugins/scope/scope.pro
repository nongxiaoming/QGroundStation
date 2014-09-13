TEMPLATE = lib
TARGET = ScopeGadget

DEFINES += SCOPE_LIBRARY

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../common.pri)

HEADERS += \
    scopeplugin.h \
    plotdata.h \
    scope_global.h \
    scopegadgetoptionspage.h \
    scopegadgetconfiguration.h \
    scopegadget.h \
    scopegadgetwidget.h \
    scopegadgetfactory.h

SOURCES += \
    scopeplugin.cpp \
    plotdata.cpp \
    scopegadgetoptionspage.cpp \
    scopegadgetconfiguration.cpp \
    scopegadget.cpp \
    scopegadgetfactory.cpp \
    scopegadgetwidget.cpp

OTHER_FILES += ScopeGadget.pluginspec

FORMS += scopegadgetoptionspage.ui

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)\
        -l$$qtLibraryName(UAVTalk)\
        -l$$qtLibraryName(Qwt)

#指定生成的lib保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
