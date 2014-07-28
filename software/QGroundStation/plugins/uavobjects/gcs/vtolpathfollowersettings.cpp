/**
 ******************************************************************************
 *
 * @file       vtolpathfollowersettings.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: vtolpathfollowersettings.xml.
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

#include "vtolpathfollowersettings.h"
#include "uavobjectfield.h"

const QString VtolPathFollowerSettings::NAME = QString("VtolPathFollowerSettings");
const QString VtolPathFollowerSettings::DESCRIPTION = QString("Settings for the @ref VtolPathFollowerModule");
const QString VtolPathFollowerSettings::CATEGORY = QString("Control");

/**
 * Constructor
 */
VtolPathFollowerSettings::VtolPathFollowerSettings(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList HorizontalPosPIElemNames;
    HorizontalPosPIElemNames.append("Kp");
    HorizontalPosPIElemNames.append("Ki");
    HorizontalPosPIElemNames.append("ILimit");
    fields.append( new UAVObjectField(QString("HorizontalPosPI"), QString("(m/s)/m"), UAVObjectField::FLOAT32, HorizontalPosPIElemNames, QStringList(), QString("")));
    QStringList HorizontalVelPIDElemNames;
    HorizontalVelPIDElemNames.append("Kp");
    HorizontalVelPIDElemNames.append("Ki");
    HorizontalVelPIDElemNames.append("Kd");
    HorizontalVelPIDElemNames.append("ILimit");
    fields.append( new UAVObjectField(QString("HorizontalVelPID"), QString("deg/(m/s)"), UAVObjectField::FLOAT32, HorizontalVelPIDElemNames, QStringList(), QString("")));
    QStringList VerticalPosPIElemNames;
    VerticalPosPIElemNames.append("Kp");
    VerticalPosPIElemNames.append("Ki");
    VerticalPosPIElemNames.append("ILimit");
    fields.append( new UAVObjectField(QString("VerticalPosPI"), QString(""), UAVObjectField::FLOAT32, VerticalPosPIElemNames, QStringList(), QString("")));
    QStringList VerticalVelPIDElemNames;
    VerticalVelPIDElemNames.append("Kp");
    VerticalVelPIDElemNames.append("Ki");
    VerticalVelPIDElemNames.append("Kd");
    VerticalVelPIDElemNames.append("ILimit");
    fields.append( new UAVObjectField(QString("VerticalVelPID"), QString(""), UAVObjectField::FLOAT32, VerticalVelPIDElemNames, QStringList(), QString("")));
    QStringList VelocityFeedforwardElemNames;
    VelocityFeedforwardElemNames.append("0");
    fields.append( new UAVObjectField(QString("VelocityFeedforward"), QString("deg/(m/s)"), UAVObjectField::FLOAT32, VelocityFeedforwardElemNames, QStringList(), QString("")));
    QStringList MaxRollPitchElemNames;
    MaxRollPitchElemNames.append("0");
    fields.append( new UAVObjectField(QString("MaxRollPitch"), QString("deg"), UAVObjectField::FLOAT32, MaxRollPitchElemNames, QStringList(), QString("")));
    QStringList UpdatePeriodElemNames;
    UpdatePeriodElemNames.append("0");
    fields.append( new UAVObjectField(QString("UpdatePeriod"), QString("ms"), UAVObjectField::INT32, UpdatePeriodElemNames, QStringList(), QString("")));
    QStringList HorizontalVelMaxElemNames;
    HorizontalVelMaxElemNames.append("0");
    fields.append( new UAVObjectField(QString("HorizontalVelMax"), QString("m/s"), UAVObjectField::UINT16, HorizontalVelMaxElemNames, QStringList(), QString("")));
    QStringList VerticalVelMaxElemNames;
    VerticalVelMaxElemNames.append("0");
    fields.append( new UAVObjectField(QString("VerticalVelMax"), QString("m/s"), UAVObjectField::UINT16, VerticalVelMaxElemNames, QStringList(), QString("")));
    QStringList GuidanceModeElemNames;
    GuidanceModeElemNames.append("0");
    QStringList GuidanceModeEnumOptions;
    GuidanceModeEnumOptions.append("DUAL_LOOP");
    GuidanceModeEnumOptions.append("VELOCITY_CONTROL");
    fields.append( new UAVObjectField(QString("GuidanceMode"), QString(""), UAVObjectField::ENUM, GuidanceModeElemNames, GuidanceModeEnumOptions, QString("")));
    QStringList ThrustControlElemNames;
    ThrustControlElemNames.append("0");
    QStringList ThrustControlEnumOptions;
    ThrustControlEnumOptions.append("FALSE");
    ThrustControlEnumOptions.append("TRUE");
    fields.append( new UAVObjectField(QString("ThrustControl"), QString(""), UAVObjectField::ENUM, ThrustControlElemNames, ThrustControlEnumOptions, QString("")));
    QStringList VelocitySourceElemNames;
    VelocitySourceElemNames.append("0");
    QStringList VelocitySourceEnumOptions;
    VelocitySourceEnumOptions.append("STATE_ESTIMATION");
    VelocitySourceEnumOptions.append("GPS_VELNED");
    VelocitySourceEnumOptions.append("GPS_GROUNDSPEED");
    fields.append( new UAVObjectField(QString("VelocitySource"), QString(""), UAVObjectField::ENUM, VelocitySourceElemNames, VelocitySourceEnumOptions, QString("")));

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
UAVObject::Metadata VtolPathFollowerSettings::getDefaultMetadata()
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
void VtolPathFollowerSettings::setDefaultFieldValues()
{
    data.HorizontalPosPI[0] = 0.25;
    data.HorizontalPosPI[1] = 0.02;
    data.HorizontalPosPI[2] = 1;
    data.HorizontalVelPID[0] = 8;
    data.HorizontalVelPID[1] = 0.5;
    data.HorizontalVelPID[2] = 0.002;
    data.HorizontalVelPID[3] = 4;
    data.VerticalPosPI[0] = 0.4;
    data.VerticalPosPI[1] = 0.02;
    data.VerticalPosPI[2] = 1;
    data.VerticalVelPID[0] = 0.1;
    data.VerticalVelPID[1] = 0.01;
    data.VerticalVelPID[2] = 0;
    data.VerticalVelPID[3] = 1;
    data.VelocityFeedforward = 2;
    data.MaxRollPitch = 20;
    data.UpdatePeriod = 50;
    data.HorizontalVelMax = 2;
    data.VerticalVelMax = 1;
    data.GuidanceMode = 0;
    data.ThrustControl = 0;
    data.VelocitySource = 0;

}

/**
 * Get the object data fields
 */
VtolPathFollowerSettings::DataFields VtolPathFollowerSettings::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void VtolPathFollowerSettings::setData(const DataFields& data)
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

void VtolPathFollowerSettings::emitNotifications()
{
            //if (data.HorizontalPosPI[0] != oldData.HorizontalPosPI[0])
            emit HorizontalPosPI_KpChanged(data.HorizontalPosPI[0]);
        //if (data.HorizontalPosPI[1] != oldData.HorizontalPosPI[1])
            emit HorizontalPosPI_KiChanged(data.HorizontalPosPI[1]);
        //if (data.HorizontalPosPI[2] != oldData.HorizontalPosPI[2])
            emit HorizontalPosPI_ILimitChanged(data.HorizontalPosPI[2]);
        //if (data.HorizontalVelPID[0] != oldData.HorizontalVelPID[0])
            emit HorizontalVelPID_KpChanged(data.HorizontalVelPID[0]);
        //if (data.HorizontalVelPID[1] != oldData.HorizontalVelPID[1])
            emit HorizontalVelPID_KiChanged(data.HorizontalVelPID[1]);
        //if (data.HorizontalVelPID[2] != oldData.HorizontalVelPID[2])
            emit HorizontalVelPID_KdChanged(data.HorizontalVelPID[2]);
        //if (data.HorizontalVelPID[3] != oldData.HorizontalVelPID[3])
            emit HorizontalVelPID_ILimitChanged(data.HorizontalVelPID[3]);
        //if (data.VerticalPosPI[0] != oldData.VerticalPosPI[0])
            emit VerticalPosPI_KpChanged(data.VerticalPosPI[0]);
        //if (data.VerticalPosPI[1] != oldData.VerticalPosPI[1])
            emit VerticalPosPI_KiChanged(data.VerticalPosPI[1]);
        //if (data.VerticalPosPI[2] != oldData.VerticalPosPI[2])
            emit VerticalPosPI_ILimitChanged(data.VerticalPosPI[2]);
        //if (data.VerticalVelPID[0] != oldData.VerticalVelPID[0])
            emit VerticalVelPID_KpChanged(data.VerticalVelPID[0]);
        //if (data.VerticalVelPID[1] != oldData.VerticalVelPID[1])
            emit VerticalVelPID_KiChanged(data.VerticalVelPID[1]);
        //if (data.VerticalVelPID[2] != oldData.VerticalVelPID[2])
            emit VerticalVelPID_KdChanged(data.VerticalVelPID[2]);
        //if (data.VerticalVelPID[3] != oldData.VerticalVelPID[3])
            emit VerticalVelPID_ILimitChanged(data.VerticalVelPID[3]);
        //if (data.VelocityFeedforward != oldData.VelocityFeedforward)
            emit VelocityFeedforwardChanged(data.VelocityFeedforward);
        //if (data.MaxRollPitch != oldData.MaxRollPitch)
            emit MaxRollPitchChanged(data.MaxRollPitch);
        //if (data.UpdatePeriod != oldData.UpdatePeriod)
            emit UpdatePeriodChanged(data.UpdatePeriod);
        //if (data.HorizontalVelMax != oldData.HorizontalVelMax)
            emit HorizontalVelMaxChanged(data.HorizontalVelMax);
        //if (data.VerticalVelMax != oldData.VerticalVelMax)
            emit VerticalVelMaxChanged(data.VerticalVelMax);
        //if (data.GuidanceMode != oldData.GuidanceMode)
            emit GuidanceModeChanged(data.GuidanceMode);
        //if (data.ThrustControl != oldData.ThrustControl)
            emit ThrustControlChanged(data.ThrustControl);
        //if (data.VelocitySource != oldData.VelocitySource)
            emit VelocitySourceChanged(data.VelocitySource);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *VtolPathFollowerSettings::clone(quint32 instID)
{
    VtolPathFollowerSettings *obj = new VtolPathFollowerSettings();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *VtolPathFollowerSettings::dirtyClone()
{
    VtolPathFollowerSettings *obj = new VtolPathFollowerSettings();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
VtolPathFollowerSettings *VtolPathFollowerSettings::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<VtolPathFollowerSettings *>(objMngr->getObject(VtolPathFollowerSettings::OBJID, instID));
}

float VtolPathFollowerSettings::getHorizontalPosPI(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.HorizontalPosPI[index];
}
void VtolPathFollowerSettings::setHorizontalPosPI(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.HorizontalPosPI[index] != value;
   data.HorizontalPosPI[index] = value;
   mutex->unlock();
   if (changed) emit HorizontalPosPIChanged(index,value);
}

float VtolPathFollowerSettings::getHorizontalPosPI_Kp() const
{
   QMutexLocker locker(mutex);
   return data.HorizontalPosPI[0];
}
void VtolPathFollowerSettings::setHorizontalPosPI_Kp(float value)
{
   mutex->lock();
   bool changed = data.HorizontalPosPI[0] != value;
   data.HorizontalPosPI[0] = value;
   mutex->unlock();
   if (changed) emit HorizontalPosPI_KpChanged(value);
}

float VtolPathFollowerSettings::getHorizontalPosPI_Ki() const
{
   QMutexLocker locker(mutex);
   return data.HorizontalPosPI[1];
}
void VtolPathFollowerSettings::setHorizontalPosPI_Ki(float value)
{
   mutex->lock();
   bool changed = data.HorizontalPosPI[1] != value;
   data.HorizontalPosPI[1] = value;
   mutex->unlock();
   if (changed) emit HorizontalPosPI_KiChanged(value);
}

float VtolPathFollowerSettings::getHorizontalPosPI_ILimit() const
{
   QMutexLocker locker(mutex);
   return data.HorizontalPosPI[2];
}
void VtolPathFollowerSettings::setHorizontalPosPI_ILimit(float value)
{
   mutex->lock();
   bool changed = data.HorizontalPosPI[2] != value;
   data.HorizontalPosPI[2] = value;
   mutex->unlock();
   if (changed) emit HorizontalPosPI_ILimitChanged(value);
}

float VtolPathFollowerSettings::getHorizontalVelPID(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.HorizontalVelPID[index];
}
void VtolPathFollowerSettings::setHorizontalVelPID(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.HorizontalVelPID[index] != value;
   data.HorizontalVelPID[index] = value;
   mutex->unlock();
   if (changed) emit HorizontalVelPIDChanged(index,value);
}

float VtolPathFollowerSettings::getHorizontalVelPID_Kp() const
{
   QMutexLocker locker(mutex);
   return data.HorizontalVelPID[0];
}
void VtolPathFollowerSettings::setHorizontalVelPID_Kp(float value)
{
   mutex->lock();
   bool changed = data.HorizontalVelPID[0] != value;
   data.HorizontalVelPID[0] = value;
   mutex->unlock();
   if (changed) emit HorizontalVelPID_KpChanged(value);
}

float VtolPathFollowerSettings::getHorizontalVelPID_Ki() const
{
   QMutexLocker locker(mutex);
   return data.HorizontalVelPID[1];
}
void VtolPathFollowerSettings::setHorizontalVelPID_Ki(float value)
{
   mutex->lock();
   bool changed = data.HorizontalVelPID[1] != value;
   data.HorizontalVelPID[1] = value;
   mutex->unlock();
   if (changed) emit HorizontalVelPID_KiChanged(value);
}

float VtolPathFollowerSettings::getHorizontalVelPID_Kd() const
{
   QMutexLocker locker(mutex);
   return data.HorizontalVelPID[2];
}
void VtolPathFollowerSettings::setHorizontalVelPID_Kd(float value)
{
   mutex->lock();
   bool changed = data.HorizontalVelPID[2] != value;
   data.HorizontalVelPID[2] = value;
   mutex->unlock();
   if (changed) emit HorizontalVelPID_KdChanged(value);
}

float VtolPathFollowerSettings::getHorizontalVelPID_ILimit() const
{
   QMutexLocker locker(mutex);
   return data.HorizontalVelPID[3];
}
void VtolPathFollowerSettings::setHorizontalVelPID_ILimit(float value)
{
   mutex->lock();
   bool changed = data.HorizontalVelPID[3] != value;
   data.HorizontalVelPID[3] = value;
   mutex->unlock();
   if (changed) emit HorizontalVelPID_ILimitChanged(value);
}

float VtolPathFollowerSettings::getVerticalPosPI(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.VerticalPosPI[index];
}
void VtolPathFollowerSettings::setVerticalPosPI(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.VerticalPosPI[index] != value;
   data.VerticalPosPI[index] = value;
   mutex->unlock();
   if (changed) emit VerticalPosPIChanged(index,value);
}

float VtolPathFollowerSettings::getVerticalPosPI_Kp() const
{
   QMutexLocker locker(mutex);
   return data.VerticalPosPI[0];
}
void VtolPathFollowerSettings::setVerticalPosPI_Kp(float value)
{
   mutex->lock();
   bool changed = data.VerticalPosPI[0] != value;
   data.VerticalPosPI[0] = value;
   mutex->unlock();
   if (changed) emit VerticalPosPI_KpChanged(value);
}

float VtolPathFollowerSettings::getVerticalPosPI_Ki() const
{
   QMutexLocker locker(mutex);
   return data.VerticalPosPI[1];
}
void VtolPathFollowerSettings::setVerticalPosPI_Ki(float value)
{
   mutex->lock();
   bool changed = data.VerticalPosPI[1] != value;
   data.VerticalPosPI[1] = value;
   mutex->unlock();
   if (changed) emit VerticalPosPI_KiChanged(value);
}

float VtolPathFollowerSettings::getVerticalPosPI_ILimit() const
{
   QMutexLocker locker(mutex);
   return data.VerticalPosPI[2];
}
void VtolPathFollowerSettings::setVerticalPosPI_ILimit(float value)
{
   mutex->lock();
   bool changed = data.VerticalPosPI[2] != value;
   data.VerticalPosPI[2] = value;
   mutex->unlock();
   if (changed) emit VerticalPosPI_ILimitChanged(value);
}

float VtolPathFollowerSettings::getVerticalVelPID(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.VerticalVelPID[index];
}
void VtolPathFollowerSettings::setVerticalVelPID(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.VerticalVelPID[index] != value;
   data.VerticalVelPID[index] = value;
   mutex->unlock();
   if (changed) emit VerticalVelPIDChanged(index,value);
}

float VtolPathFollowerSettings::getVerticalVelPID_Kp() const
{
   QMutexLocker locker(mutex);
   return data.VerticalVelPID[0];
}
void VtolPathFollowerSettings::setVerticalVelPID_Kp(float value)
{
   mutex->lock();
   bool changed = data.VerticalVelPID[0] != value;
   data.VerticalVelPID[0] = value;
   mutex->unlock();
   if (changed) emit VerticalVelPID_KpChanged(value);
}

float VtolPathFollowerSettings::getVerticalVelPID_Ki() const
{
   QMutexLocker locker(mutex);
   return data.VerticalVelPID[1];
}
void VtolPathFollowerSettings::setVerticalVelPID_Ki(float value)
{
   mutex->lock();
   bool changed = data.VerticalVelPID[1] != value;
   data.VerticalVelPID[1] = value;
   mutex->unlock();
   if (changed) emit VerticalVelPID_KiChanged(value);
}

float VtolPathFollowerSettings::getVerticalVelPID_Kd() const
{
   QMutexLocker locker(mutex);
   return data.VerticalVelPID[2];
}
void VtolPathFollowerSettings::setVerticalVelPID_Kd(float value)
{
   mutex->lock();
   bool changed = data.VerticalVelPID[2] != value;
   data.VerticalVelPID[2] = value;
   mutex->unlock();
   if (changed) emit VerticalVelPID_KdChanged(value);
}

float VtolPathFollowerSettings::getVerticalVelPID_ILimit() const
{
   QMutexLocker locker(mutex);
   return data.VerticalVelPID[3];
}
void VtolPathFollowerSettings::setVerticalVelPID_ILimit(float value)
{
   mutex->lock();
   bool changed = data.VerticalVelPID[3] != value;
   data.VerticalVelPID[3] = value;
   mutex->unlock();
   if (changed) emit VerticalVelPID_ILimitChanged(value);
}

float VtolPathFollowerSettings::getVelocityFeedforward() const
{
   QMutexLocker locker(mutex);
   return data.VelocityFeedforward;
}
void VtolPathFollowerSettings::setVelocityFeedforward(float value)
{
   mutex->lock();
   bool changed = data.VelocityFeedforward != value;
   data.VelocityFeedforward = value;
   mutex->unlock();
   if (changed) emit VelocityFeedforwardChanged(value);
}

float VtolPathFollowerSettings::getMaxRollPitch() const
{
   QMutexLocker locker(mutex);
   return data.MaxRollPitch;
}
void VtolPathFollowerSettings::setMaxRollPitch(float value)
{
   mutex->lock();
   bool changed = data.MaxRollPitch != value;
   data.MaxRollPitch = value;
   mutex->unlock();
   if (changed) emit MaxRollPitchChanged(value);
}

qint32 VtolPathFollowerSettings::getUpdatePeriod() const
{
   QMutexLocker locker(mutex);
   return data.UpdatePeriod;
}
void VtolPathFollowerSettings::setUpdatePeriod(qint32 value)
{
   mutex->lock();
   bool changed = data.UpdatePeriod != value;
   data.UpdatePeriod = value;
   mutex->unlock();
   if (changed) emit UpdatePeriodChanged(value);
}

quint16 VtolPathFollowerSettings::getHorizontalVelMax() const
{
   QMutexLocker locker(mutex);
   return data.HorizontalVelMax;
}
void VtolPathFollowerSettings::setHorizontalVelMax(quint16 value)
{
   mutex->lock();
   bool changed = data.HorizontalVelMax != value;
   data.HorizontalVelMax = value;
   mutex->unlock();
   if (changed) emit HorizontalVelMaxChanged(value);
}

quint16 VtolPathFollowerSettings::getVerticalVelMax() const
{
   QMutexLocker locker(mutex);
   return data.VerticalVelMax;
}
void VtolPathFollowerSettings::setVerticalVelMax(quint16 value)
{
   mutex->lock();
   bool changed = data.VerticalVelMax != value;
   data.VerticalVelMax = value;
   mutex->unlock();
   if (changed) emit VerticalVelMaxChanged(value);
}

quint8 VtolPathFollowerSettings::getGuidanceMode() const
{
   QMutexLocker locker(mutex);
   return data.GuidanceMode;
}
void VtolPathFollowerSettings::setGuidanceMode(quint8 value)
{
   mutex->lock();
   bool changed = data.GuidanceMode != value;
   data.GuidanceMode = value;
   mutex->unlock();
   if (changed) emit GuidanceModeChanged(value);
}

quint8 VtolPathFollowerSettings::getThrustControl() const
{
   QMutexLocker locker(mutex);
   return data.ThrustControl;
}
void VtolPathFollowerSettings::setThrustControl(quint8 value)
{
   mutex->lock();
   bool changed = data.ThrustControl != value;
   data.ThrustControl = value;
   mutex->unlock();
   if (changed) emit ThrustControlChanged(value);
}

quint8 VtolPathFollowerSettings::getVelocitySource() const
{
   QMutexLocker locker(mutex);
   return data.VelocitySource;
}
void VtolPathFollowerSettings::setVelocitySource(quint8 value)
{
   mutex->lock();
   bool changed = data.VelocitySource != value;
   data.VelocitySource = value;
   mutex->unlock();
   if (changed) emit VelocitySourceChanged(value);
}


