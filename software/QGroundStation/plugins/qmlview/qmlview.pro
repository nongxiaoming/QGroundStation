TEMPLATE = lib
TARGET = QMLView
QT += svg
QT += opengl
QT += qml quick

include(../../common.pri)

HEADERS += \
    qmlviewplugin.h \
    qmlviewgadget.h \
    qmlviewgadgetwidget.h \
    qmlviewgadgetfactory.h \
    qmlviewgadgetconfiguration.h \
    qmlviewgadgetoptionspage.h


SOURCES += \
    qmlviewplugin.cpp \
    qmlviewgadget.cpp \
    qmlviewgadgetfactory.cpp \
    qmlviewgadgetwidget.cpp \
    qmlviewgadgetconfiguration.cpp \
    qmlviewgadgetoptionspage.cpp

OTHER_FILES += QMLView.pluginspec

FORMS += qmlviewgadgetoptionspage.ui

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
        -l$$qtLibraryName(Core)\
        -l$$qtLibraryName(ExtensionSystem)\
        -l$$qtLibraryName(Utils)\
        -l$$qtLibraryName(UAVObjects)


#指定生成的plugin保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
