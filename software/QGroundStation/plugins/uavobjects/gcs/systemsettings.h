/**
 ******************************************************************************
 *
 * @file       systemsettings.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: systemsettings.xml. 
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
#ifndef SYSTEMSETTINGS_H
#define SYSTEMSETTINGS_H

#include "uavobjects/uavdataobject.h"
#include "uavobjects/uavobjectmanager.h"

class UAVOBJECTS_EXPORT SystemSettings: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(quint32 GUIConfigData_0 READ getGUIConfigData_0 WRITE setGUIConfigData_0 NOTIFY GUIConfigData_0Changed);
    Q_PROPERTY(quint32 GUIConfigData_1 READ getGUIConfigData_1 WRITE setGUIConfigData_1 NOTIFY GUIConfigData_1Changed);
    Q_PROPERTY(quint32 GUIConfigData_2 READ getGUIConfigData_2 WRITE setGUIConfigData_2 NOTIFY GUIConfigData_2Changed);
    Q_PROPERTY(quint32 GUIConfigData_3 READ getGUIConfigData_3 WRITE setGUIConfigData_3 NOTIFY GUIConfigData_3Changed);
    Q_PROPERTY(float AirSpeedMax READ getAirSpeedMax WRITE setAirSpeedMax NOTIFY AirSpeedMaxChanged);
    Q_PROPERTY(float AirSpeedMin READ getAirSpeedMin WRITE setAirSpeedMin NOTIFY AirSpeedMinChanged);
    Q_PROPERTY(quint8 AirframeType READ getAirframeType WRITE setAirframeType NOTIFY AirframeTypeChanged);
    Q_PROPERTY(quint8 ThrustControl READ getThrustControl WRITE setThrustControl NOTIFY ThrustControlChanged);


public:
    // Field structure
    typedef struct {
        quint32 GUIConfigData[4];
        float AirSpeedMax;
        float AirSpeedMin;
        quint8 AirframeType;
        quint8 ThrustControl;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field GUIConfigData information
    /* Number of elements for field GUIConfigData */
    static const quint32 GUICONFIGDATA_NUMELEM = 4;
    // Field AirSpeedMax information
    // Field AirSpeedMin information
    // Field AirframeType information
    /* Enumeration options for field AirframeType */
    typedef enum { AIRFRAMETYPE_FIXEDWING=0, AIRFRAMETYPE_FIXEDWINGELEVON=1, AIRFRAMETYPE_FIXEDWINGVTAIL=2, AIRFRAMETYPE_VTOL=3, AIRFRAMETYPE_HELICP=4, AIRFRAMETYPE_QUADX=5, AIRFRAMETYPE_QUADP=6, AIRFRAMETYPE_HEXA=7, AIRFRAMETYPE_OCTO=8, AIRFRAMETYPE_CUSTOM=9, AIRFRAMETYPE_HEXAX=10, AIRFRAMETYPE_OCTOV=11, AIRFRAMETYPE_OCTOCOAXP=12, AIRFRAMETYPE_OCTOCOAXX=13, AIRFRAMETYPE_HEXACOAX=14, AIRFRAMETYPE_TRI=15, AIRFRAMETYPE_GROUNDVEHICLECAR=16, AIRFRAMETYPE_GROUNDVEHICLEDIFFERENTIAL=17, AIRFRAMETYPE_GROUNDVEHICLEMOTORCYCLE=18 } AirframeTypeOptions;
    // Field ThrustControl information
    /* Enumeration options for field ThrustControl */
    typedef enum { THRUSTCONTROL_THROTTLE=0, THRUSTCONTROL_COLLECTIVE=1, THRUSTCONTROL_NONE=2 } ThrustControlOptions;

  
    // Constants
    static const quint32 OBJID = 0x45E67EAA;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 1;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    SystemSettings();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static SystemSettings* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE quint32 getGUIConfigData(quint32 index) const;
    Q_INVOKABLE quint32 getGUIConfigData_0() const;
    Q_INVOKABLE quint32 getGUIConfigData_1() const;
    Q_INVOKABLE quint32 getGUIConfigData_2() const;
    Q_INVOKABLE quint32 getGUIConfigData_3() const;
    Q_INVOKABLE float getAirSpeedMax() const;
    Q_INVOKABLE float getAirSpeedMin() const;
    Q_INVOKABLE quint8 getAirframeType() const;
    Q_INVOKABLE quint8 getThrustControl() const;


public slots:
    void setGUIConfigData(quint32 index, quint32 value);
    void setGUIConfigData_0(quint32 value);
    void setGUIConfigData_1(quint32 value);
    void setGUIConfigData_2(quint32 value);
    void setGUIConfigData_3(quint32 value);
    void setAirSpeedMax(float value);
    void setAirSpeedMin(float value);
    void setAirframeType(quint8 value);
    void setThrustControl(quint8 value);


signals:
    void GUIConfigDataChanged(quint32 index, quint32 value);
    void GUIConfigData_0Changed(quint32 value);
    void GUIConfigData_1Changed(quint32 value);
    void GUIConfigData_2Changed(quint32 value);
    void GUIConfigData_3Changed(quint32 value);
    void AirSpeedMaxChanged(float value);
    void AirSpeedMinChanged(float value);
    void AirframeTypeChanged(quint8 value);
    void ThrustControlChanged(quint8 value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // SYSTEMSETTINGS_H
