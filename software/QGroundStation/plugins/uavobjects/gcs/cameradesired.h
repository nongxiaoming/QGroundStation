/**
 ******************************************************************************
 *
 * @file       cameradesired.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: cameradesired.xml. 
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
#ifndef CAMERADESIRED_H
#define CAMERADESIRED_H

#include "uavdataobject.h"
#include "uavobjectmanager.h"

class UAVOBJECTS_EXPORT CameraDesired: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float RollOrServo1 READ getRollOrServo1 WRITE setRollOrServo1 NOTIFY RollOrServo1Changed);
    Q_PROPERTY(float PitchOrServo2 READ getPitchOrServo2 WRITE setPitchOrServo2 NOTIFY PitchOrServo2Changed);
    Q_PROPERTY(float Yaw READ getYaw WRITE setYaw NOTIFY YawChanged);


public:
    // Field structure
    typedef struct {
        float RollOrServo1;
        float PitchOrServo2;
        float Yaw;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field RollOrServo1 information
    // Field PitchOrServo2 information
    // Field Yaw information

  
    // Constants
    static const quint32 OBJID = 0x6440104E;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 0;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    CameraDesired();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static CameraDesired* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getRollOrServo1() const;
    Q_INVOKABLE float getPitchOrServo2() const;
    Q_INVOKABLE float getYaw() const;


public slots:
    void setRollOrServo1(float value);
    void setPitchOrServo2(float value);
    void setYaw(float value);


signals:
    void RollOrServo1Changed(float value);
    void PitchOrServo2Changed(float value);
    void YawChanged(float value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // CAMERADESIRED_H
