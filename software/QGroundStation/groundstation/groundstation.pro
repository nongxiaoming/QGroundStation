# -------------------------------------------------
# QGroundStation - a Groundstation for coper
# Maintainer:
# nongxiaoming <nongxiaoming@gmail.com>
# (c) 2014 QGroundStation Developers
# This file is part of the QGroundStation project
# QGroundStation is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# QGroundStation is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with QGroundControl. If not, see <http://www.gnu.org/licenses/>.
# -------------------------------------------------

include(../common.pri)
# Qt configuration
CONFIG += qt \
    thread

QT       += core gui\
         opengl \
          svg \
           xml \
          webkit \
          sql \
          declarative

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QGroundStation
TEMPLATE = app

include(libraries.pri)
#源文件
SOURCES += main.cpp\
        mainwindow.cpp
#头文件
HEADERS  += mainwindow.h
#界面文件
FORMS    += mainwindow.ui
#包含的目录
INCLUDEPATH +=.
