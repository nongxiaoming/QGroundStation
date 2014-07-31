/**
 ******************************************************************************
 *
 * @file       airspeedstate.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: airspeedstate.xml. 
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
#ifndef AIRSPEEDSTATE_H
#define AIRSPEEDSTATE_H

#include "uavobjects/uavdataobject.h"
#include "uavobjects/uavobjectmanager.h"

class UAVOBJECTS_EXPORT AirspeedState: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float CalibratedAirspeed READ getCalibratedAirspeed WRITE setCalibratedAirspeed NOTIFY CalibratedAirspeedChanged);
    Q_PROPERTY(float TrueAirspeed READ getTrueAirspeed WRITE setTrueAirspeed NOTIFY TrueAirspeedChanged);


public:
    // Field structure
    typedef struct {
        float CalibratedAirspeed;
        float TrueAirspeed;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field CalibratedAirspeed information
    // Field TrueAirspeed information

  
    // Constants
    static const quint32 OBJID = 0xC7009F28;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 0;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    AirspeedState();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static AirspeedState* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getCalibratedAirspeed() const;
    Q_INVOKABLE float getTrueAirspeed() const;


public slots:
    void setCalibratedAirspeed(float value);
    void setTrueAirspeed(float value);


signals:
    void CalibratedAirspeedChanged(float value);
    void TrueAirspeedChanged(float value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // AIRSPEEDSTATE_H
