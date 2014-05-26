TEMPLATE = lib
TARGET = QScienceSpinBox

include(../../common.pri)

QT += widgets

DEFINES += QSCIENCESPINBOX

HEADERS = QScienceSpinBox.h

SOURCES = QScienceSpinBox.cpp

#指定生成的lib保存目录
DESTDIR=$${PROJECT_LIBDIR}
