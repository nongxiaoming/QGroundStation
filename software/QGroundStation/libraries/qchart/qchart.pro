TEMPLATE = lib
TARGET = QChart

include(../../common.pri)

QT += widgets

DEFINES += QChart

HEADERS = chart.h\
         channel.h\
        channeldata.h\
        chartdecorator.h\
        datacontainers.h\
        scalegrid.h\
        widgetwithbackground.h\
        functions.h

SOURCES = chart.cpp\
         chartdecorator.cpp\
         scalegrid.cpp\
         channel.cpp\
         widgetwithbackground.cpp\
         functions.cpp\
         ./standard/channeldecorator.cpp\
         ./standard/glassdecorator.cpp\
         ./standard/labelsdecorator.cpp\
         ./standard/legenddecorator.cpp\
         ./standard/scalegriddecorator.cpp
INCLUDEPATH += standard
#指定生成的lib保存目录
DESTDIR=$${PROJECT_LIBDIR}
