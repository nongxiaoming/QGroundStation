TEMPLATE = lib
TARGET = ModelViewGadget

QT += opengl

include(../../common.pri)

INCLUDEPATH += ../../libs/glc_lib
HEADERS += modelviewplugin.h \
    modelviewgadgetconfiguration.h \
    modelviewgadget.h \
    modelviewgadgetwidget.h \
    modelviewgadgetfactory.h \
    modelviewgadgetoptionspage.h
SOURCES += modelviewplugin.cpp \
    modelviewgadgetconfiguration.cpp \
    modelviewgadget.cpp \
    modelviewgadgetfactory.cpp \
    modelviewgadgetwidget.cpp \
    modelviewgadgetoptionspage.cpp
OTHER_FILES += ModelViewGadget.pluginspec
FORMS += modelviewoptionspage.ui

RESOURCES += \
    modelview.qrc

#依赖的库文件
LIBS += -l$$qtLibraryName(Aggregation)\
      -l$$qtLibraryName(Core)\
      -l$$qtLibraryName(ExtensionSystem)\
      -l$$qtLibraryName(Utils)\
      -l$$qtLibraryName(UAVObjects)\
      -l$$qtLibraryName(GLC_lib)

#指定生成的lib保存目录
DESTDIR=$${PROJECT_PLUGINSDIR}
