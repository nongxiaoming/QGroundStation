/**
 ******************************************************************************
 *
 * @file       gyrosensor.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: gyrosensor.xml. 
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
#ifndef GYROSENSOR_H
#define GYROSENSOR_H

#include "uavobjects/uavdataobject.h"
#include "uavobjects/uavobjectmanager.h"

class UAVOBJECTS_EXPORT GyroSensor: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float x READ getx WRITE setx NOTIFY xChanged);
    Q_PROPERTY(float y READ gety WRITE sety NOTIFY yChanged);
    Q_PROPERTY(float z READ getz WRITE setz NOTIFY zChanged);
    Q_PROPERTY(float temperature READ gettemperature WRITE settemperature NOTIFY temperatureChanged);


public:
    // Field structure
    typedef struct {
        float x;
        float y;
        float z;
        float temperature;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field x information
    // Field y information
    // Field z information
    // Field temperature information

  
    // Constants
    static const quint32 OBJID = 0xA63680C6;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 0;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    GyroSensor();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static GyroSensor* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getx() const;
    Q_INVOKABLE float gety() const;
    Q_INVOKABLE float getz() const;
    Q_INVOKABLE float gettemperature() const;


public slots:
    void setx(float value);
    void sety(float value);
    void setz(float value);
    void settemperature(float value);


signals:
    void xChanged(float value);
    void yChanged(float value);
    void zChanged(float value);
    void temperatureChanged(float value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // GYROSENSOR_H
