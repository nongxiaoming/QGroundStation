TEMPLATE = lib
TARGET = Aggregation

include(../../common.pri)

DEFINES += AGGREGATION_LIBRARY

HEADERS = aggregate.h \
    aggregation_global.h

SOURCES = aggregate.cpp

#指定生成的lib保存目录
DESTDIR=$${PROJECT_LIBDIR}
