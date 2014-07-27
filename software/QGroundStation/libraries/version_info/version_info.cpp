/**
 ******************************************************************************
 * @file       version_info.cpp.template
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2013.
 * @addtogroup VersionInfo
 * @{
 * @brief      The template file used to generate the real source file called
 *             build/openpilotgcs-synthetics/version_info.cpp
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#include "version_info.h"

VersionInfo::VersionInfo()
{
}

QString VersionInfo::origin()
{
    return "https://nongxiaoming:7819570535@git.oschina.net/nongxiaoming/OpenPilot.git";
}

QString VersionInfo::revision()
{
    return "master:4389f767-dirty 20140702 21:27";
}

QString VersionInfo::hash()
{
    return "4389f767f3e6b0e3be8938d58fc1f7c71f5559a5";
}

QString VersionInfo::uavoHash()
{
    return "346a11134f4ff07312aeb45b77dfaf5cfdeac004";
}

QString VersionInfo::uavoHashArray()
{
    return "{ 0x34,0x6a,0x11,0x13,0x4f,0x4f,0xf0,0x73,0x12,0xae,0xb4,0x5b,0x77,0xdf,0xaf,0x5c,0xfd,0xea,0xc0,0x04 }";
}

QString VersionInfo::label()
{
    return "20140702-4389f767-dirty";
}

QString VersionInfo::tag()
{
    return "";
}

QString VersionInfo::tagOrBranch()
{
    return "master";
}

QString VersionInfo::tagOrHash8()
{
    return "4389f767";
}

QString VersionInfo::hash8()
{
    return "4389f767";
}

QString VersionInfo::fwTag()
{
    return "master-dirty";
}

QString VersionInfo::unixTime()
{
    return "1404336478";
}

QString VersionInfo::dateTime()
{
    return "20140702 21:27";
}

QString VersionInfo::date()
{
    return "20140702";
}

QString VersionInfo::day()
{
    return "02";
}

QString VersionInfo::month()
{
    return "07";
}

QString VersionInfo::year()
{
    return "2014";
}

QString VersionInfo::hour()
{
    return "21";
}

QString VersionInfo::minute()
{
    return "27";
}

QString VersionInfo::dirty()
{
    return "-dirty";
}
