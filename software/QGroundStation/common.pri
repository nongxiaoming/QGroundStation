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
# along with QGroundStation. If not, see <http://www.gnu.org/licenses/>.
# -------------------------------------------------

message(Qt version $$[QT_VERSION])

# Setup our supported build types. We do this once here and then use the defined config scopes
# to allow us to easily modify suported build types in one place instead of duplicated throughout
# the project file.

linux-g++ | linux-g++-64 {
    message(Linux build)
    CONFIG += LinuxBuild
}
win32-msvc* {
    message(Windows build)
    CONFIG += WindowsBuild
}
win32-g++ | win32-g++-64 {
    message(Windows build)
    CONFIG += WindowsBuild
}
macx-clang | macx-llvm {
    message(Mac build)
    CONFIG += MacBuild
}

#定义qtLibraryName替换宏
defineReplace(qtLibraryName) {
   unset(LIBRARY_NAME)
   LIBRARY_NAME = $$1
   CONFIG(debug, debug|release) {
      !debug_and_release|build_pass {
          mac:RET = $$member(LIBRARY_NAME, 0)_debug
              else:win32:RET = $$member(LIBRARY_NAME, 0)d
      }
   }
   isEmpty(RET):RET = $$LIBRARY_NAME
   return($$RET)
}


# 设置编译目录环境

BASEDIR = $${IN_PWD}
DebugBuild {
    DESTDIR = $${OUT_PWD}/debug
    BUILDDIR = $${OUT_PWD}/build-debug
    OUTDIR_NAME = debug
}
ReleaseBuild {
    DESTDIR = $${OUT_PWD}/release
    BUILDDIR = $${OUT_PWD}/build-release
    OUTDIR_NAME = release
}
OBJECTS_DIR = $${BUILDDIR}/obj
MOC_DIR = $${BUILDDIR}/moc
UI_DIR = $${BUILDDIR}/ui
RCC_DIR = $${BUILDDIR}/rcc

#设置可执行文件生成目录
PROJECT_BINDIR = $${PWD}/$${OUTDIR_NAME}/bin
#设置libraries生成目录
PROJECT_LIBRARYDIR = $${PWD}/$${OUTDIR_NAME}/libraries
#设置plugins生成目录
PROJECT_PLUGINSDIR = $${PWD}/$${OUTDIR_NAME}/plugins

#设置语言为C++
LANGUAGE = C++

#如果工程模板为lib,替换TARGET名称
equals(TEMPLATE,lib)
{
TARGET = $$qtLibraryName($$TARGET)
}
message(BASEDIR $$BASEDIR DESTDIR $$DESTDIR TARGET $$TARGET)

#包含的头文件目录
INCLUDEPATH += $${PWD}/libraries\
               $${PWD}/plugins
#SDL库目录
SDL_DIR = $${PWD}/thirdparty/SDL-1.2.15
#需要用到的库
LIBS +=-L$$PROJECT_LIBRARYDIR
LIBS +=-L$$PROJECT_PLUGINSDIR
