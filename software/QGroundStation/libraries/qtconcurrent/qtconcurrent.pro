TEMPLATE = lib
TARGET = QtConcurrent
DEFINES += BUILD_QTCONCURRENT

include(../../common.pri)

HEADERS += \
    qtconcurrent_global.h \
    multitask.h \
    runextensions.h
#指定生成的lib保存目录
DESTDIR=$${PROJECT_LIBDIR}
