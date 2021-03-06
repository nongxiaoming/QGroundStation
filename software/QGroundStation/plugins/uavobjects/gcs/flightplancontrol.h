/**
 ******************************************************************************
 *
 * @file       flightplancontrol.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: flightplancontrol.xml. 
 *             This is an automatically generated file.
 *             DO NOT modify manually.
 *
 * @brief      The UAVUObjects GCS plugin 
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
#ifndef FLIGHTPLANCONTROL_H
#define FLIGHTPLANCONTROL_H

#include "uavobjects/uavdataobject.h"
#include "uavobjects/uavobjectmanager.h"

class UAVOBJECTS_EXPORT FlightPlanControl: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(quint8 Command READ getCommand WRITE setCommand NOTIFY CommandChanged);


public:
    // Field structure
    typedef struct {
        quint8 Command;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field Command information
    /* Enumeration options for field Command */
    typedef enum { COMMAND_START=0, COMMAND_STOP=1, COMMAND_KILL=2 } CommandOptions;

  
    // Constants
    static const quint32 OBJID = 0x53E3F180;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 0;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    FlightPlanControl();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static FlightPlanControl* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE quint8 getCommand() const;


public slots:
    void setCommand(quint8 value);


signals:
    void CommandChanged(quint8 value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // FLIGHTPLANCONTROL_H
