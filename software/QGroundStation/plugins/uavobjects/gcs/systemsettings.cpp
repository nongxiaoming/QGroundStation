/**
 ******************************************************************************
 *
 * @file       systemsettings.cpp
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

#include "systemsettings.h"
#include "uavobjectfield.h"

const QString SystemSettings::NAME = QString("SystemSettings");
const QString SystemSettings::DESCRIPTION = QString("Select airframe type.  Currently used by @ref ActuatorModule to choose mixing from @ref ActuatorDesired to @ref ActuatorCommand");
const QString SystemSettings::CATEGORY = QString("System");

/**
 * Constructor
 */
SystemSettings::SystemSettings(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList GUIConfigDataElemNames;
    GUIConfigDataElemNames.append("0");
    GUIConfigDataElemNames.append("1");
    GUIConfigDataElemNames.append("2");
    GUIConfigDataElemNames.append("3");
    fields.append( new UAVObjectField(QString("GUIConfigData"), QString("bits"), UAVObjectField::UINT32, GUIConfigDataElemNames, QStringList(), QString("")));
    QStringList AirSpeedMaxElemNames;
    AirSpeedMaxElemNames.append("0");
    fields.append( new UAVObjectField(QString("AirSpeedMax"), QString("m/s"), UAVObjectField::FLOAT32, AirSpeedMaxElemNames, QStringList(), QString("")));
    QStringList AirSpeedMinElemNames;
    AirSpeedMinElemNames.append("0");
    fields.append( new UAVObjectField(QString("AirSpeedMin"), QString("m/s"), UAVObjectField::FLOAT32, AirSpeedMinElemNames, QStringList(), QString("")));
    QStringList AirframeTypeElemNames;
    AirframeTypeElemNames.append("0");
    QStringList AirframeTypeEnumOptions;
    AirframeTypeEnumOptions.append("FixedWing");
    AirframeTypeEnumOptions.append("FixedWingElevon");
    AirframeTypeEnumOptions.append("FixedWingVtail");
    AirframeTypeEnumOptions.append("VTOL");
    AirframeTypeEnumOptions.append("HeliCP");
    AirframeTypeEnumOptions.append("QuadX");
    AirframeTypeEnumOptions.append("QuadP");
    AirframeTypeEnumOptions.append("Hexa");
    AirframeTypeEnumOptions.append("Octo");
    AirframeTypeEnumOptions.append("Custom");
    AirframeTypeEnumOptions.append("HexaX");
    AirframeTypeEnumOptions.append("OctoV");
    AirframeTypeEnumOptions.append("OctoCoaxP");
    AirframeTypeEnumOptions.append("OctoCoaxX");
    AirframeTypeEnumOptions.append("HexaCoax");
    AirframeTypeEnumOptions.append("Tri");
    AirframeTypeEnumOptions.append("GroundVehicleCar");
    AirframeTypeEnumOptions.append("GroundVehicleDifferential");
    AirframeTypeEnumOptions.append("GroundVehicleMotorcycle");
    fields.append( new UAVObjectField(QString("AirframeType"), QString(""), UAVObjectField::ENUM, AirframeTypeElemNames, AirframeTypeEnumOptions, QString("")));
    QStringList ThrustControlElemNames;
    ThrustControlElemNames.append("0");
    QStringList ThrustControlEnumOptions;
    ThrustControlEnumOptions.append("Throttle");
    ThrustControlEnumOptions.append("Collective");
    ThrustControlEnumOptions.append("None");
    fields.append( new UAVObjectField(QString("ThrustControl"), QString(""), UAVObjectField::ENUM, ThrustControlElemNames, ThrustControlEnumOptions, QString("")));

    // Initialize object
    initializeFields(fields, (quint8 *)&data, NUMBYTES);
    // Set the default field values
    setDefaultFieldValues();
    // Set the object description
    setDescription(DESCRIPTION);

    // Set the Category of this object type
    setCategory(CATEGORY);

    connect(this, SIGNAL(objectUpdated(UAVObject *)), SLOT(emitNotifications()));
}

/**
 * Get the default metadata for this object
 */
UAVObject::Metadata SystemSettings::getDefaultMetadata()
{
    UAVObject::Metadata metadata;
    metadata.flags =
        ACCESS_READWRITE << UAVOBJ_ACCESS_SHIFT |
        ACCESS_READWRITE << UAVOBJ_GCS_ACCESS_SHIFT |
        1 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
        1 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
        UPDATEMODE_ONCHANGE << UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT |
        UPDATEMODE_ONCHANGE << UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT |
        UPDATEMODE_MANUAL << UAVOBJ_LOGGING_UPDATE_MODE_SHIFT;
    metadata.flightTelemetryUpdatePeriod = 0;
    metadata.gcsTelemetryUpdatePeriod = 0;
    metadata.loggingUpdatePeriod = 0;
    return metadata;
}

/**
 * Initialize object fields with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void SystemSettings::setDefaultFieldValues()
{
    data.GUIConfigData[0] = 0;
    data.GUIConfigData[1] = 0;
    data.GUIConfigData[2] = 0;
    data.GUIConfigData[3] = 0;
    data.AirSpeedMax = 30;
    data.AirSpeedMin = 10;
    data.AirframeType = 5;
    data.ThrustControl = 0;

}

/**
 * Get the object data fields
 */
SystemSettings::DataFields SystemSettings::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void SystemSettings::setData(const DataFields& data)
{
    QMutexLocker locker(mutex);
    // Get metadata
    Metadata mdata = getMetadata();
    // Update object if the access mode permits
    if (UAVObject::GetGcsAccess(mdata) == ACCESS_READWRITE) {
        this->data = data;
        emit objectUpdatedAuto(this); // trigger object updated event
        emit objectUpdated(this);
    }
}

void SystemSettings::emitNotifications()
{
            //if (data.GUIConfigData[0] != oldData.GUIConfigData[0])
            emit GUIConfigData_0Changed(data.GUIConfigData[0]);
        //if (data.GUIConfigData[1] != oldData.GUIConfigData[1])
            emit GUIConfigData_1Changed(data.GUIConfigData[1]);
        //if (data.GUIConfigData[2] != oldData.GUIConfigData[2])
            emit GUIConfigData_2Changed(data.GUIConfigData[2]);
        //if (data.GUIConfigData[3] != oldData.GUIConfigData[3])
            emit GUIConfigData_3Changed(data.GUIConfigData[3]);
        //if (data.AirSpeedMax != oldData.AirSpeedMax)
            emit AirSpeedMaxChanged(data.AirSpeedMax);
        //if (data.AirSpeedMin != oldData.AirSpeedMin)
            emit AirSpeedMinChanged(data.AirSpeedMin);
        //if (data.AirframeType != oldData.AirframeType)
            emit AirframeTypeChanged(data.AirframeType);
        //if (data.ThrustControl != oldData.ThrustControl)
            emit ThrustControlChanged(data.ThrustControl);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *SystemSettings::clone(quint32 instID)
{
    SystemSettings *obj = new SystemSettings();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *SystemSettings::dirtyClone()
{
    SystemSettings *obj = new SystemSettings();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
SystemSettings *SystemSettings::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<SystemSettings *>(objMngr->getObject(SystemSettings::OBJID, instID));
}

quint32 SystemSettings::getGUIConfigData(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.GUIConfigData[index];
}
void SystemSettings::setGUIConfigData(quint32 index, quint32 value)
{
   mutex->lock();
   bool changed = data.GUIConfigData[index] != value;
   data.GUIConfigData[index] = value;
   mutex->unlock();
   if (changed) emit GUIConfigDataChanged(index,value);
}

quint32 SystemSettings::getGUIConfigData_0() const
{
   QMutexLocker locker(mutex);
   return data.GUIConfigData[0];
}
void SystemSettings::setGUIConfigData_0(quint32 value)
{
   mutex->lock();
   bool changed = data.GUIConfigData[0] != value;
   data.GUIConfigData[0] = value;
   mutex->unlock();
   if (changed) emit GUIConfigData_0Changed(value);
}

quint32 SystemSettings::getGUIConfigData_1() const
{
   QMutexLocker locker(mutex);
   return data.GUIConfigData[1];
}
void SystemSettings::setGUIConfigData_1(quint32 value)
{
   mutex->lock();
   bool changed = data.GUIConfigData[1] != value;
   data.GUIConfigData[1] = value;
   mutex->unlock();
   if (changed) emit GUIConfigData_1Changed(value);
}

quint32 SystemSettings::getGUIConfigData_2() const
{
   QMutexLocker locker(mutex);
   return data.GUIConfigData[2];
}
void SystemSettings::setGUIConfigData_2(quint32 value)
{
   mutex->lock();
   bool changed = data.GUIConfigData[2] != value;
   data.GUIConfigData[2] = value;
   mutex->unlock();
   if (changed) emit GUIConfigData_2Changed(value);
}

quint32 SystemSettings::getGUIConfigData_3() const
{
   QMutexLocker locker(mutex);
   return data.GUIConfigData[3];
}
void SystemSettings::setGUIConfigData_3(quint32 value)
{
   mutex->lock();
   bool changed = data.GUIConfigData[3] != value;
   data.GUIConfigData[3] = value;
   mutex->unlock();
   if (changed) emit GUIConfigData_3Changed(value);
}

float SystemSettings::getAirSpeedMax() const
{
   QMutexLocker locker(mutex);
   return data.AirSpeedMax;
}
void SystemSettings::setAirSpeedMax(float value)
{
   mutex->lock();
   bool changed = data.AirSpeedMax != value;
   data.AirSpeedMax = value;
   mutex->unlock();
   if (changed) emit AirSpeedMaxChanged(value);
}

float SystemSettings::getAirSpeedMin() const
{
   QMutexLocker locker(mutex);
   return data.AirSpeedMin;
}
void SystemSettings::setAirSpeedMin(float value)
{
   mutex->lock();
   bool changed = data.AirSpeedMin != value;
   data.AirSpeedMin = value;
   mutex->unlock();
   if (changed) emit AirSpeedMinChanged(value);
}

quint8 SystemSettings::getAirframeType() const
{
   QMutexLocker locker(mutex);
   return data.AirframeType;
}
void SystemSettings::setAirframeType(quint8 value)
{
   mutex->lock();
   bool changed = data.AirframeType != value;
   data.AirframeType = value;
   mutex->unlock();
   if (changed) emit AirframeTypeChanged(value);
}

quint8 SystemSettings::getThrustControl() const
{
   QMutexLocker locker(mutex);
   return data.ThrustControl;
}
void SystemSettings::setThrustControl(quint8 value)
{
   mutex->lock();
   bool changed = data.ThrustControl != value;
   data.ThrustControl = value;
   mutex->unlock();
   if (changed) emit ThrustControlChanged(value);
}


