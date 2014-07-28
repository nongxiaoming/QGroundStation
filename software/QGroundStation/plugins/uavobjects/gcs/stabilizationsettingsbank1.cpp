/**
 ******************************************************************************
 *
 * @file       stabilizationsettingsbank1.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: stabilizationsettingsbank1.xml.
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

#include "stabilizationsettingsbank1.h"
#include "uavobjectfield.h"

const QString StabilizationSettingsBank1::NAME = QString("StabilizationSettingsBank1");
const QString StabilizationSettingsBank1::DESCRIPTION = QString("Currently selected PID bank");
const QString StabilizationSettingsBank1::CATEGORY = QString("Control");

/**
 * Constructor
 */
StabilizationSettingsBank1::StabilizationSettingsBank1(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList ManualRateElemNames;
    ManualRateElemNames.append("Roll");
    ManualRateElemNames.append("Pitch");
    ManualRateElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("ManualRate"), QString("degrees/sec"), UAVObjectField::FLOAT32, ManualRateElemNames, QStringList(), QString("%BE:0:500; %BE:0:500; %BE:0:500")));
    QStringList MaximumRateElemNames;
    MaximumRateElemNames.append("Roll");
    MaximumRateElemNames.append("Pitch");
    MaximumRateElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("MaximumRate"), QString("degrees/sec"), UAVObjectField::FLOAT32, MaximumRateElemNames, QStringList(), QString("%BE:0:500; %BE:0:500; %BE:0:500")));
    QStringList RollRatePIDElemNames;
    RollRatePIDElemNames.append("Kp");
    RollRatePIDElemNames.append("Ki");
    RollRatePIDElemNames.append("Kd");
    RollRatePIDElemNames.append("ILimit");
    fields.append( new UAVObjectField(QString("RollRatePID"), QString(""), UAVObjectField::FLOAT32, RollRatePIDElemNames, QStringList(), QString("%BE:0:0.01; %BE:0:0.01; ; ")));
    QStringList PitchRatePIDElemNames;
    PitchRatePIDElemNames.append("Kp");
    PitchRatePIDElemNames.append("Ki");
    PitchRatePIDElemNames.append("Kd");
    PitchRatePIDElemNames.append("ILimit");
    fields.append( new UAVObjectField(QString("PitchRatePID"), QString(""), UAVObjectField::FLOAT32, PitchRatePIDElemNames, QStringList(), QString("%BE:0:0.01; %BE:0:0.01; ; ")));
    QStringList YawRatePIDElemNames;
    YawRatePIDElemNames.append("Kp");
    YawRatePIDElemNames.append("Ki");
    YawRatePIDElemNames.append("Kd");
    YawRatePIDElemNames.append("ILimit");
    fields.append( new UAVObjectField(QString("YawRatePID"), QString(""), UAVObjectField::FLOAT32, YawRatePIDElemNames, QStringList(), QString("%BE:0:0.01; %BE:0:0.01 ; ; ")));
    QStringList RollPIElemNames;
    RollPIElemNames.append("Kp");
    RollPIElemNames.append("Ki");
    RollPIElemNames.append("ILimit");
    fields.append( new UAVObjectField(QString("RollPI"), QString(""), UAVObjectField::FLOAT32, RollPIElemNames, QStringList(), QString("%BE:0:10; %BE:0:10; ")));
    QStringList PitchPIElemNames;
    PitchPIElemNames.append("Kp");
    PitchPIElemNames.append("Ki");
    PitchPIElemNames.append("ILimit");
    fields.append( new UAVObjectField(QString("PitchPI"), QString(""), UAVObjectField::FLOAT32, PitchPIElemNames, QStringList(), QString("%BE:0:10; %BE:0:10; ")));
    QStringList YawPIElemNames;
    YawPIElemNames.append("Kp");
    YawPIElemNames.append("Ki");
    YawPIElemNames.append("ILimit");
    fields.append( new UAVObjectField(QString("YawPI"), QString(""), UAVObjectField::FLOAT32, YawPIElemNames, QStringList(), QString("%BE:0:10; %BE:0:10; ")));
    QStringList RollMaxElemNames;
    RollMaxElemNames.append("0");
    fields.append( new UAVObjectField(QString("RollMax"), QString("degrees"), UAVObjectField::UINT8, RollMaxElemNames, QStringList(), QString("%BE:0:180")));
    QStringList PitchMaxElemNames;
    PitchMaxElemNames.append("0");
    fields.append( new UAVObjectField(QString("PitchMax"), QString("degrees"), UAVObjectField::UINT8, PitchMaxElemNames, QStringList(), QString("%BE:0:180")));
    QStringList YawMaxElemNames;
    YawMaxElemNames.append("0");
    fields.append( new UAVObjectField(QString("YawMax"), QString("degrees"), UAVObjectField::UINT8, YawMaxElemNames, QStringList(), QString("%BE:0:180")));

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
UAVObject::Metadata StabilizationSettingsBank1::getDefaultMetadata()
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
void StabilizationSettingsBank1::setDefaultFieldValues()
{
    data.ManualRate[0] = 150;
    data.ManualRate[1] = 150;
    data.ManualRate[2] = 175;
    data.MaximumRate[0] = 300;
    data.MaximumRate[1] = 300;
    data.MaximumRate[2] = 300;
    data.RollRatePID[0] = 0.003;
    data.RollRatePID[1] = 0.003;
    data.RollRatePID[2] = 2e-05;
    data.RollRatePID[3] = 0.3;
    data.PitchRatePID[0] = 0.003;
    data.PitchRatePID[1] = 0.003;
    data.PitchRatePID[2] = 2e-05;
    data.PitchRatePID[3] = 0.3;
    data.YawRatePID[0] = 0.0035;
    data.YawRatePID[1] = 0.0035;
    data.YawRatePID[2] = 0;
    data.YawRatePID[3] = 0.3;
    data.RollPI[0] = 2.5;
    data.RollPI[1] = 0;
    data.RollPI[2] = 50;
    data.PitchPI[0] = 2.5;
    data.PitchPI[1] = 0;
    data.PitchPI[2] = 50;
    data.YawPI[0] = 2.5;
    data.YawPI[1] = 0;
    data.YawPI[2] = 50;
    data.RollMax = 42;
    data.PitchMax = 42;
    data.YawMax = 42;

}

/**
 * Get the object data fields
 */
StabilizationSettingsBank1::DataFields StabilizationSettingsBank1::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void StabilizationSettingsBank1::setData(const DataFields& data)
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

void StabilizationSettingsBank1::emitNotifications()
{
            //if (data.ManualRate[0] != oldData.ManualRate[0])
            emit ManualRate_RollChanged(data.ManualRate[0]);
        //if (data.ManualRate[1] != oldData.ManualRate[1])
            emit ManualRate_PitchChanged(data.ManualRate[1]);
        //if (data.ManualRate[2] != oldData.ManualRate[2])
            emit ManualRate_YawChanged(data.ManualRate[2]);
        //if (data.MaximumRate[0] != oldData.MaximumRate[0])
            emit MaximumRate_RollChanged(data.MaximumRate[0]);
        //if (data.MaximumRate[1] != oldData.MaximumRate[1])
            emit MaximumRate_PitchChanged(data.MaximumRate[1]);
        //if (data.MaximumRate[2] != oldData.MaximumRate[2])
            emit MaximumRate_YawChanged(data.MaximumRate[2]);
        //if (data.RollRatePID[0] != oldData.RollRatePID[0])
            emit RollRatePID_KpChanged(data.RollRatePID[0]);
        //if (data.RollRatePID[1] != oldData.RollRatePID[1])
            emit RollRatePID_KiChanged(data.RollRatePID[1]);
        //if (data.RollRatePID[2] != oldData.RollRatePID[2])
            emit RollRatePID_KdChanged(data.RollRatePID[2]);
        //if (data.RollRatePID[3] != oldData.RollRatePID[3])
            emit RollRatePID_ILimitChanged(data.RollRatePID[3]);
        //if (data.PitchRatePID[0] != oldData.PitchRatePID[0])
            emit PitchRatePID_KpChanged(data.PitchRatePID[0]);
        //if (data.PitchRatePID[1] != oldData.PitchRatePID[1])
            emit PitchRatePID_KiChanged(data.PitchRatePID[1]);
        //if (data.PitchRatePID[2] != oldData.PitchRatePID[2])
            emit PitchRatePID_KdChanged(data.PitchRatePID[2]);
        //if (data.PitchRatePID[3] != oldData.PitchRatePID[3])
            emit PitchRatePID_ILimitChanged(data.PitchRatePID[3]);
        //if (data.YawRatePID[0] != oldData.YawRatePID[0])
            emit YawRatePID_KpChanged(data.YawRatePID[0]);
        //if (data.YawRatePID[1] != oldData.YawRatePID[1])
            emit YawRatePID_KiChanged(data.YawRatePID[1]);
        //if (data.YawRatePID[2] != oldData.YawRatePID[2])
            emit YawRatePID_KdChanged(data.YawRatePID[2]);
        //if (data.YawRatePID[3] != oldData.YawRatePID[3])
            emit YawRatePID_ILimitChanged(data.YawRatePID[3]);
        //if (data.RollPI[0] != oldData.RollPI[0])
            emit RollPI_KpChanged(data.RollPI[0]);
        //if (data.RollPI[1] != oldData.RollPI[1])
            emit RollPI_KiChanged(data.RollPI[1]);
        //if (data.RollPI[2] != oldData.RollPI[2])
            emit RollPI_ILimitChanged(data.RollPI[2]);
        //if (data.PitchPI[0] != oldData.PitchPI[0])
            emit PitchPI_KpChanged(data.PitchPI[0]);
        //if (data.PitchPI[1] != oldData.PitchPI[1])
            emit PitchPI_KiChanged(data.PitchPI[1]);
        //if (data.PitchPI[2] != oldData.PitchPI[2])
            emit PitchPI_ILimitChanged(data.PitchPI[2]);
        //if (data.YawPI[0] != oldData.YawPI[0])
            emit YawPI_KpChanged(data.YawPI[0]);
        //if (data.YawPI[1] != oldData.YawPI[1])
            emit YawPI_KiChanged(data.YawPI[1]);
        //if (data.YawPI[2] != oldData.YawPI[2])
            emit YawPI_ILimitChanged(data.YawPI[2]);
        //if (data.RollMax != oldData.RollMax)
            emit RollMaxChanged(data.RollMax);
        //if (data.PitchMax != oldData.PitchMax)
            emit PitchMaxChanged(data.PitchMax);
        //if (data.YawMax != oldData.YawMax)
            emit YawMaxChanged(data.YawMax);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *StabilizationSettingsBank1::clone(quint32 instID)
{
    StabilizationSettingsBank1 *obj = new StabilizationSettingsBank1();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *StabilizationSettingsBank1::dirtyClone()
{
    StabilizationSettingsBank1 *obj = new StabilizationSettingsBank1();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
StabilizationSettingsBank1 *StabilizationSettingsBank1::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<StabilizationSettingsBank1 *>(objMngr->getObject(StabilizationSettingsBank1::OBJID, instID));
}

float StabilizationSettingsBank1::getManualRate(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.ManualRate[index];
}
void StabilizationSettingsBank1::setManualRate(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.ManualRate[index] != value;
   data.ManualRate[index] = value;
   mutex->unlock();
   if (changed) emit ManualRateChanged(index,value);
}

float StabilizationSettingsBank1::getManualRate_Roll() const
{
   QMutexLocker locker(mutex);
   return data.ManualRate[0];
}
void StabilizationSettingsBank1::setManualRate_Roll(float value)
{
   mutex->lock();
   bool changed = data.ManualRate[0] != value;
   data.ManualRate[0] = value;
   mutex->unlock();
   if (changed) emit ManualRate_RollChanged(value);
}

float StabilizationSettingsBank1::getManualRate_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.ManualRate[1];
}
void StabilizationSettingsBank1::setManualRate_Pitch(float value)
{
   mutex->lock();
   bool changed = data.ManualRate[1] != value;
   data.ManualRate[1] = value;
   mutex->unlock();
   if (changed) emit ManualRate_PitchChanged(value);
}

float StabilizationSettingsBank1::getManualRate_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.ManualRate[2];
}
void StabilizationSettingsBank1::setManualRate_Yaw(float value)
{
   mutex->lock();
   bool changed = data.ManualRate[2] != value;
   data.ManualRate[2] = value;
   mutex->unlock();
   if (changed) emit ManualRate_YawChanged(value);
}

float StabilizationSettingsBank1::getMaximumRate(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.MaximumRate[index];
}
void StabilizationSettingsBank1::setMaximumRate(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.MaximumRate[index] != value;
   data.MaximumRate[index] = value;
   mutex->unlock();
   if (changed) emit MaximumRateChanged(index,value);
}

float StabilizationSettingsBank1::getMaximumRate_Roll() const
{
   QMutexLocker locker(mutex);
   return data.MaximumRate[0];
}
void StabilizationSettingsBank1::setMaximumRate_Roll(float value)
{
   mutex->lock();
   bool changed = data.MaximumRate[0] != value;
   data.MaximumRate[0] = value;
   mutex->unlock();
   if (changed) emit MaximumRate_RollChanged(value);
}

float StabilizationSettingsBank1::getMaximumRate_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.MaximumRate[1];
}
void StabilizationSettingsBank1::setMaximumRate_Pitch(float value)
{
   mutex->lock();
   bool changed = data.MaximumRate[1] != value;
   data.MaximumRate[1] = value;
   mutex->unlock();
   if (changed) emit MaximumRate_PitchChanged(value);
}

float StabilizationSettingsBank1::getMaximumRate_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.MaximumRate[2];
}
void StabilizationSettingsBank1::setMaximumRate_Yaw(float value)
{
   mutex->lock();
   bool changed = data.MaximumRate[2] != value;
   data.MaximumRate[2] = value;
   mutex->unlock();
   if (changed) emit MaximumRate_YawChanged(value);
}

float StabilizationSettingsBank1::getRollRatePID(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.RollRatePID[index];
}
void StabilizationSettingsBank1::setRollRatePID(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.RollRatePID[index] != value;
   data.RollRatePID[index] = value;
   mutex->unlock();
   if (changed) emit RollRatePIDChanged(index,value);
}

float StabilizationSettingsBank1::getRollRatePID_Kp() const
{
   QMutexLocker locker(mutex);
   return data.RollRatePID[0];
}
void StabilizationSettingsBank1::setRollRatePID_Kp(float value)
{
   mutex->lock();
   bool changed = data.RollRatePID[0] != value;
   data.RollRatePID[0] = value;
   mutex->unlock();
   if (changed) emit RollRatePID_KpChanged(value);
}

float StabilizationSettingsBank1::getRollRatePID_Ki() const
{
   QMutexLocker locker(mutex);
   return data.RollRatePID[1];
}
void StabilizationSettingsBank1::setRollRatePID_Ki(float value)
{
   mutex->lock();
   bool changed = data.RollRatePID[1] != value;
   data.RollRatePID[1] = value;
   mutex->unlock();
   if (changed) emit RollRatePID_KiChanged(value);
}

float StabilizationSettingsBank1::getRollRatePID_Kd() const
{
   QMutexLocker locker(mutex);
   return data.RollRatePID[2];
}
void StabilizationSettingsBank1::setRollRatePID_Kd(float value)
{
   mutex->lock();
   bool changed = data.RollRatePID[2] != value;
   data.RollRatePID[2] = value;
   mutex->unlock();
   if (changed) emit RollRatePID_KdChanged(value);
}

float StabilizationSettingsBank1::getRollRatePID_ILimit() const
{
   QMutexLocker locker(mutex);
   return data.RollRatePID[3];
}
void StabilizationSettingsBank1::setRollRatePID_ILimit(float value)
{
   mutex->lock();
   bool changed = data.RollRatePID[3] != value;
   data.RollRatePID[3] = value;
   mutex->unlock();
   if (changed) emit RollRatePID_ILimitChanged(value);
}

float StabilizationSettingsBank1::getPitchRatePID(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.PitchRatePID[index];
}
void StabilizationSettingsBank1::setPitchRatePID(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.PitchRatePID[index] != value;
   data.PitchRatePID[index] = value;
   mutex->unlock();
   if (changed) emit PitchRatePIDChanged(index,value);
}

float StabilizationSettingsBank1::getPitchRatePID_Kp() const
{
   QMutexLocker locker(mutex);
   return data.PitchRatePID[0];
}
void StabilizationSettingsBank1::setPitchRatePID_Kp(float value)
{
   mutex->lock();
   bool changed = data.PitchRatePID[0] != value;
   data.PitchRatePID[0] = value;
   mutex->unlock();
   if (changed) emit PitchRatePID_KpChanged(value);
}

float StabilizationSettingsBank1::getPitchRatePID_Ki() const
{
   QMutexLocker locker(mutex);
   return data.PitchRatePID[1];
}
void StabilizationSettingsBank1::setPitchRatePID_Ki(float value)
{
   mutex->lock();
   bool changed = data.PitchRatePID[1] != value;
   data.PitchRatePID[1] = value;
   mutex->unlock();
   if (changed) emit PitchRatePID_KiChanged(value);
}

float StabilizationSettingsBank1::getPitchRatePID_Kd() const
{
   QMutexLocker locker(mutex);
   return data.PitchRatePID[2];
}
void StabilizationSettingsBank1::setPitchRatePID_Kd(float value)
{
   mutex->lock();
   bool changed = data.PitchRatePID[2] != value;
   data.PitchRatePID[2] = value;
   mutex->unlock();
   if (changed) emit PitchRatePID_KdChanged(value);
}

float StabilizationSettingsBank1::getPitchRatePID_ILimit() const
{
   QMutexLocker locker(mutex);
   return data.PitchRatePID[3];
}
void StabilizationSettingsBank1::setPitchRatePID_ILimit(float value)
{
   mutex->lock();
   bool changed = data.PitchRatePID[3] != value;
   data.PitchRatePID[3] = value;
   mutex->unlock();
   if (changed) emit PitchRatePID_ILimitChanged(value);
}

float StabilizationSettingsBank1::getYawRatePID(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.YawRatePID[index];
}
void StabilizationSettingsBank1::setYawRatePID(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.YawRatePID[index] != value;
   data.YawRatePID[index] = value;
   mutex->unlock();
   if (changed) emit YawRatePIDChanged(index,value);
}

float StabilizationSettingsBank1::getYawRatePID_Kp() const
{
   QMutexLocker locker(mutex);
   return data.YawRatePID[0];
}
void StabilizationSettingsBank1::setYawRatePID_Kp(float value)
{
   mutex->lock();
   bool changed = data.YawRatePID[0] != value;
   data.YawRatePID[0] = value;
   mutex->unlock();
   if (changed) emit YawRatePID_KpChanged(value);
}

float StabilizationSettingsBank1::getYawRatePID_Ki() const
{
   QMutexLocker locker(mutex);
   return data.YawRatePID[1];
}
void StabilizationSettingsBank1::setYawRatePID_Ki(float value)
{
   mutex->lock();
   bool changed = data.YawRatePID[1] != value;
   data.YawRatePID[1] = value;
   mutex->unlock();
   if (changed) emit YawRatePID_KiChanged(value);
}

float StabilizationSettingsBank1::getYawRatePID_Kd() const
{
   QMutexLocker locker(mutex);
   return data.YawRatePID[2];
}
void StabilizationSettingsBank1::setYawRatePID_Kd(float value)
{
   mutex->lock();
   bool changed = data.YawRatePID[2] != value;
   data.YawRatePID[2] = value;
   mutex->unlock();
   if (changed) emit YawRatePID_KdChanged(value);
}

float StabilizationSettingsBank1::getYawRatePID_ILimit() const
{
   QMutexLocker locker(mutex);
   return data.YawRatePID[3];
}
void StabilizationSettingsBank1::setYawRatePID_ILimit(float value)
{
   mutex->lock();
   bool changed = data.YawRatePID[3] != value;
   data.YawRatePID[3] = value;
   mutex->unlock();
   if (changed) emit YawRatePID_ILimitChanged(value);
}

float StabilizationSettingsBank1::getRollPI(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.RollPI[index];
}
void StabilizationSettingsBank1::setRollPI(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.RollPI[index] != value;
   data.RollPI[index] = value;
   mutex->unlock();
   if (changed) emit RollPIChanged(index,value);
}

float StabilizationSettingsBank1::getRollPI_Kp() const
{
   QMutexLocker locker(mutex);
   return data.RollPI[0];
}
void StabilizationSettingsBank1::setRollPI_Kp(float value)
{
   mutex->lock();
   bool changed = data.RollPI[0] != value;
   data.RollPI[0] = value;
   mutex->unlock();
   if (changed) emit RollPI_KpChanged(value);
}

float StabilizationSettingsBank1::getRollPI_Ki() const
{
   QMutexLocker locker(mutex);
   return data.RollPI[1];
}
void StabilizationSettingsBank1::setRollPI_Ki(float value)
{
   mutex->lock();
   bool changed = data.RollPI[1] != value;
   data.RollPI[1] = value;
   mutex->unlock();
   if (changed) emit RollPI_KiChanged(value);
}

float StabilizationSettingsBank1::getRollPI_ILimit() const
{
   QMutexLocker locker(mutex);
   return data.RollPI[2];
}
void StabilizationSettingsBank1::setRollPI_ILimit(float value)
{
   mutex->lock();
   bool changed = data.RollPI[2] != value;
   data.RollPI[2] = value;
   mutex->unlock();
   if (changed) emit RollPI_ILimitChanged(value);
}

float StabilizationSettingsBank1::getPitchPI(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.PitchPI[index];
}
void StabilizationSettingsBank1::setPitchPI(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.PitchPI[index] != value;
   data.PitchPI[index] = value;
   mutex->unlock();
   if (changed) emit PitchPIChanged(index,value);
}

float StabilizationSettingsBank1::getPitchPI_Kp() const
{
   QMutexLocker locker(mutex);
   return data.PitchPI[0];
}
void StabilizationSettingsBank1::setPitchPI_Kp(float value)
{
   mutex->lock();
   bool changed = data.PitchPI[0] != value;
   data.PitchPI[0] = value;
   mutex->unlock();
   if (changed) emit PitchPI_KpChanged(value);
}

float StabilizationSettingsBank1::getPitchPI_Ki() const
{
   QMutexLocker locker(mutex);
   return data.PitchPI[1];
}
void StabilizationSettingsBank1::setPitchPI_Ki(float value)
{
   mutex->lock();
   bool changed = data.PitchPI[1] != value;
   data.PitchPI[1] = value;
   mutex->unlock();
   if (changed) emit PitchPI_KiChanged(value);
}

float StabilizationSettingsBank1::getPitchPI_ILimit() const
{
   QMutexLocker locker(mutex);
   return data.PitchPI[2];
}
void StabilizationSettingsBank1::setPitchPI_ILimit(float value)
{
   mutex->lock();
   bool changed = data.PitchPI[2] != value;
   data.PitchPI[2] = value;
   mutex->unlock();
   if (changed) emit PitchPI_ILimitChanged(value);
}

float StabilizationSettingsBank1::getYawPI(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.YawPI[index];
}
void StabilizationSettingsBank1::setYawPI(quint32 index, float value)
{
   mutex->lock();
   bool changed = data.YawPI[index] != value;
   data.YawPI[index] = value;
   mutex->unlock();
   if (changed) emit YawPIChanged(index,value);
}

float StabilizationSettingsBank1::getYawPI_Kp() const
{
   QMutexLocker locker(mutex);
   return data.YawPI[0];
}
void StabilizationSettingsBank1::setYawPI_Kp(float value)
{
   mutex->lock();
   bool changed = data.YawPI[0] != value;
   data.YawPI[0] = value;
   mutex->unlock();
   if (changed) emit YawPI_KpChanged(value);
}

float StabilizationSettingsBank1::getYawPI_Ki() const
{
   QMutexLocker locker(mutex);
   return data.YawPI[1];
}
void StabilizationSettingsBank1::setYawPI_Ki(float value)
{
   mutex->lock();
   bool changed = data.YawPI[1] != value;
   data.YawPI[1] = value;
   mutex->unlock();
   if (changed) emit YawPI_KiChanged(value);
}

float StabilizationSettingsBank1::getYawPI_ILimit() const
{
   QMutexLocker locker(mutex);
   return data.YawPI[2];
}
void StabilizationSettingsBank1::setYawPI_ILimit(float value)
{
   mutex->lock();
   bool changed = data.YawPI[2] != value;
   data.YawPI[2] = value;
   mutex->unlock();
   if (changed) emit YawPI_ILimitChanged(value);
}

quint8 StabilizationSettingsBank1::getRollMax() const
{
   QMutexLocker locker(mutex);
   return data.RollMax;
}
void StabilizationSettingsBank1::setRollMax(quint8 value)
{
   mutex->lock();
   bool changed = data.RollMax != value;
   data.RollMax = value;
   mutex->unlock();
   if (changed) emit RollMaxChanged(value);
}

quint8 StabilizationSettingsBank1::getPitchMax() const
{
   QMutexLocker locker(mutex);
   return data.PitchMax;
}
void StabilizationSettingsBank1::setPitchMax(quint8 value)
{
   mutex->lock();
   bool changed = data.PitchMax != value;
   data.PitchMax = value;
   mutex->unlock();
   if (changed) emit PitchMaxChanged(value);
}

quint8 StabilizationSettingsBank1::getYawMax() const
{
   QMutexLocker locker(mutex);
   return data.YawMax;
}
void StabilizationSettingsBank1::setYawMax(quint8 value)
{
   mutex->lock();
   bool changed = data.YawMax != value;
   data.YawMax = value;
   mutex->unlock();
   if (changed) emit YawMaxChanged(value);
}


