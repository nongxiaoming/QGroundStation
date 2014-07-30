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
          declarative\
          network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QGroundStation
TEMPLATE = app

win32 {
    RC_FILE = openpilotgcs.rc
    target.path = /bin
    INSTALLS += target
} else:macx {
    LIBS += -framework CoreFoundation
    ICON = openpilotgcs.icns
    QMAKE_INFO_PLIST = Info.plist
    FILETYPES.files = profile.icns prifile.icns
    FILETYPES.path = Contents/Resources
    QMAKE_BUNDLE_DATA += FILETYPES
} else {
    target.path  = /bin
    INSTALLS    += target
}

OTHER_FILES += openpilotgcs.rc

RESOURCES += \
    appresources.qrc

#源文件
SOURCES += main.cpp\
        mainwindow.cpp\
        gcssplashscreen.cpp\
       qtsingleapplication/qtsingleapplication.cpp\
       qtsingleapplication/qtlocalpeer.cpp\
       qtlockedfile/qtlockedfile.cpp
#头文件
HEADERS  += mainwindow.h\
         gcssplashscreen.h\
         qtsingleapplication/qtsingleapplication.h\
         qtsingleapplication/qtlocalpeer.h\
         qtlockedfile/qtlockedfile.h


unix:SOURCES += qtlockedfile/qtlockedfile_unix.cpp
win32:SOURCES += qtlockedfile/qtlockedfile_win.cpp

win32:contains(TEMPLATE, lib):contains(CONFIG, shared) {
    DEFINES += QT_QTLOCKEDFILE_EXPORT=__declspec(dllexport)
    DEFINES += QT_QTSINGLEAPPLICATION_EXPORT=__declspec(dllexport)
}
#界面文件
FORMS    += mainwindow.ui
#包含的目录
INCLUDEPATH +=.

#用到的lib
LIBS +=-l$$qtLibraryName(QChart)\
       -l$$qtLibraryName(PFDGadget)\
       -l$$qtLibraryName(Core)\
       -l$$qtLibraryName(DialGadget)\
       -l$$qtLibraryName(VersionInfo)\
       -l$$qtLibraryName(ExtensionSystem)\
       -l$$qtLibraryName(Utils)

#指定生成的app保存目录
DESTDIR=$${PROJECT_BINDIR}
