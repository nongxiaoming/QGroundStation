/**
 ******************************************************************************
 *
 * @file       camerastabsettings.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: camerastabsettings.xml.
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

#include "camerastabsettings.h"
#include "uavobjectfield.h"

const QString CameraStabSettings::NAME = QString("CameraStabSettings");
const QString CameraStabSettings::DESCRIPTION = QString("Settings for the @ref CameraStab mmodule");
const QString CameraStabSettings::CATEGORY = QString("Control");

/**
 * Constructor
 */
CameraStabSettings::CameraStabSettings(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField *> fields;
    QStringList MaxAxisLockRateElemNames;
    MaxAxisLockRateElemNames.append("0");
    fields.append( new UAVObjectField(QString("MaxAxisLockRate"), QString("deg/s"), UAVObjectField::FLOAT32, MaxAxisLockRateElemNames, QStringList(), QString("")));
    QStringList MaxAccelElemNames;
    MaxAccelElemNames.append("0");
    fields.append( new UAVObjectField(QString("MaxAccel"), QString("units/sec"), UAVObjectField::UINT16, MaxAccelElemNames, QStringList(), QString("")));
    QStringList InputElemNames;
    InputElemNames.append("Roll");
    InputElemNames.append("Pitch");
    InputElemNames.append("Yaw");
    QStringList InputEnumOptions;
    InputEnumOptions.append("Accessory0");
    InputEnumOptions.append("Accessory1");
    InputEnumOptions.append("Accessory2");
    InputEnumOptions.append("Accessory3");
    InputEnumOptions.append("Accessory4");
    InputEnumOptions.append("Accessory5");
    InputEnumOptions.append("None");
    fields.append( new UAVObjectField(QString("Input"), QString("channel"), UAVObjectField::ENUM, InputElemNames, InputEnumOptions, QString("")));
    QStringList InputRangeElemNames;
    InputRangeElemNames.append("Roll");
    InputRangeElemNames.append("Pitch");
    InputRangeElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("InputRange"), QString("deg"), UAVObjectField::UINT8, InputRangeElemNames, QStringList(), QString("")));
    QStringList InputRateElemNames;
    InputRateElemNames.append("Roll");
    InputRateElemNames.append("Pitch");
    InputRateElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("InputRate"), QString("deg/s"), UAVObjectField::UINT8, InputRateElemNames, QStringList(), QString("")));
    QStringList StabilizationModeElemNames;
    StabilizationModeElemNames.append("Roll");
    StabilizationModeElemNames.append("Pitch");
    StabilizationModeElemNames.append("Yaw");
    QStringList StabilizationModeEnumOptions;
    StabilizationModeEnumOptions.append("Attitude");
    StabilizationModeEnumOptions.append("AxisLock");
    fields.append( new UAVObjectField(QString("StabilizationMode"), QString(""), UAVObjectField::ENUM, StabilizationModeElemNames, StabilizationModeEnumOptions, QString("")));
    QStringList OutputRangeElemNames;
    OutputRangeElemNames.append("Roll");
    OutputRangeElemNames.append("Pitch");
    OutputRangeElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("OutputRange"), QString("deg"), UAVObjectField::UINT8, OutputRangeElemNames, QStringList(), QString("")));
    QStringList ResponseTimeElemNames;
    ResponseTimeElemNames.append("Roll");
    ResponseTimeElemNames.append("Pitch");
    ResponseTimeElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("ResponseTime"), QString("ms"), UAVObjectField::UINT8, ResponseTimeElemNames, QStringList(), QString("")));
    QStringList GimbalTypeElemNames;
    GimbalTypeElemNames.append("0");
    QStringList GimbalTypeEnumOptions;
    GimbalTypeEnumOptions.append("Generic");
    GimbalTypeEnumOptions.append("Yaw-Roll-Pitch");
    GimbalTypeEnumOptions.append("Yaw-Pitch-Roll");
    GimbalTypeEnumOptions.append("Roll-Pitch-Mixed");
    fields.append( new UAVObjectField(QString("GimbalType"), QString(""), UAVObjectField::ENUM, GimbalTypeElemNames, GimbalTypeEnumOptions, QString("")));
    QStringList FeedForwardElemNames;
    FeedForwardElemNames.append("Roll");
    FeedForwardElemNames.append("Pitch");
    FeedForwardElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("FeedForward"), QString(""), UAVObjectField::UINT8, FeedForwardElemNames, QStringList(), QString("")));
    QStringList AccelTimeElemNames;
    AccelTimeElemNames.append("Roll");
    AccelTimeElemNames.append("Pitch");
    AccelTimeElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("AccelTime"), QString("ms"), UAVObjectField::UINT8, AccelTimeElemNames, QStringList(), QString("")));
    QStringList DecelTimeElemNames;
    DecelTimeElemNames.append("Roll");
    DecelTimeElemNames.append("Pitch");
    DecelTimeElemNames.append("Yaw");
    fields.append( new UAVObjectField(QString("DecelTime"), QString("ms"), UAVObjectField::UINT8, DecelTimeElemNames, QStringList(), QString("")));
    QStringList Servo1PitchReverseElemNames;
    Servo1PitchReverseElemNames.append("0");
    QStringList Servo1PitchReverseEnumOptions;
    Servo1PitchReverseEnumOptions.append("FALSE");
    Servo1PitchReverseEnumOptions.append("TRUE");
    fields.append( new UAVObjectField(QString("Servo1PitchReverse"), QString(""), UAVObjectField::ENUM, Servo1PitchReverseElemNames, Servo1PitchReverseEnumOptions, QString("")));
    QStringList Servo2PitchReverseElemNames;
    Servo2PitchReverseElemNames.append("0");
    QStringList Servo2PitchReverseEnumOptions;
    Servo2PitchReverseEnumOptions.append("FALSE");
    Servo2PitchReverseEnumOptions.append("TRUE");
    fields.append( new UAVObjectField(QString("Servo2PitchReverse"), QString(""), UAVObjectField::ENUM, Servo2PitchReverseElemNames, Servo2PitchReverseEnumOptions, QString("")));

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
UAVObject::Metadata CameraStabSettings::getDefaultMetadata()
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
void CameraStabSettings::setDefaultFieldValues()
{
    data.MaxAxisLockRate = 1;
    data.MaxAccel = 500;
    data.Input[0] = 6;
    data.Input[1] = 6;
    data.Input[2] = 6;
    data.InputRange[0] = 20;
    data.InputRange[1] = 20;
    data.InputRange[2] = 20;
    data.InputRate[0] = 50;
    data.InputRate[1] = 50;
    data.InputRate[2] = 50;
    data.StabilizationMode[0] = 0;
    data.StabilizationMode[1] = 0;
    data.StabilizationMode[2] = 0;
    data.OutputRange[0] = 20;
    data.OutputRange[1] = 20;
    data.OutputRange[2] = 20;
    data.ResponseTime[0] = 0;
    data.ResponseTime[1] = 0;
    data.ResponseTime[2] = 0;
    data.GimbalType = 0;
    data.FeedForward[0] = 0;
    data.FeedForward[1] = 0;
    data.FeedForward[2] = 0;
    data.AccelTime[0] = 5;
    data.AccelTime[1] = 5;
    data.AccelTime[2] = 5;
    data.DecelTime[0] = 5;
    data.DecelTime[1] = 5;
    data.DecelTime[2] = 5;
    data.Servo1PitchReverse = 0;
    data.Servo2PitchReverse = 0;

}

/**
 * Get the object data fields
 */
CameraStabSettings::DataFields CameraStabSettings::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void CameraStabSettings::setData(const DataFields& data)
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

void CameraStabSettings::emitNotifications()
{
            //if (data.MaxAxisLockRate != oldData.MaxAxisLockRate)
            emit MaxAxisLockRateChanged(data.MaxAxisLockRate);
        //if (data.MaxAccel != oldData.MaxAccel)
            emit MaxAccelChanged(data.MaxAccel);
        //if (data.Input[0] != oldData.Input[0])
            emit Input_RollChanged(data.Input[0]);
        //if (data.Input[1] != oldData.Input[1])
            emit Input_PitchChanged(data.Input[1]);
        //if (data.Input[2] != oldData.Input[2])
            emit Input_YawChanged(data.Input[2]);
        //if (data.InputRange[0] != oldData.InputRange[0])
            emit InputRange_RollChanged(data.InputRange[0]);
        //if (data.InputRange[1] != oldData.InputRange[1])
            emit InputRange_PitchChanged(data.InputRange[1]);
        //if (data.InputRange[2] != oldData.InputRange[2])
            emit InputRange_YawChanged(data.InputRange[2]);
        //if (data.InputRate[0] != oldData.InputRate[0])
            emit InputRate_RollChanged(data.InputRate[0]);
        //if (data.InputRate[1] != oldData.InputRate[1])
            emit InputRate_PitchChanged(data.InputRate[1]);
        //if (data.InputRate[2] != oldData.InputRate[2])
            emit InputRate_YawChanged(data.InputRate[2]);
        //if (data.StabilizationMode[0] != oldData.StabilizationMode[0])
            emit StabilizationMode_RollChanged(data.StabilizationMode[0]);
        //if (data.StabilizationMode[1] != oldData.StabilizationMode[1])
            emit StabilizationMode_PitchChanged(data.StabilizationMode[1]);
        //if (data.StabilizationMode[2] != oldData.StabilizationMode[2])
            emit StabilizationMode_YawChanged(data.StabilizationMode[2]);
        //if (data.OutputRange[0] != oldData.OutputRange[0])
            emit OutputRange_RollChanged(data.OutputRange[0]);
        //if (data.OutputRange[1] != oldData.OutputRange[1])
            emit OutputRange_PitchChanged(data.OutputRange[1]);
        //if (data.OutputRange[2] != oldData.OutputRange[2])
            emit OutputRange_YawChanged(data.OutputRange[2]);
        //if (data.ResponseTime[0] != oldData.ResponseTime[0])
            emit ResponseTime_RollChanged(data.ResponseTime[0]);
        //if (data.ResponseTime[1] != oldData.ResponseTime[1])
            emit ResponseTime_PitchChanged(data.ResponseTime[1]);
        //if (data.ResponseTime[2] != oldData.ResponseTime[2])
            emit ResponseTime_YawChanged(data.ResponseTime[2]);
        //if (data.GimbalType != oldData.GimbalType)
            emit GimbalTypeChanged(data.GimbalType);
        //if (data.FeedForward[0] != oldData.FeedForward[0])
            emit FeedForward_RollChanged(data.FeedForward[0]);
        //if (data.FeedForward[1] != oldData.FeedForward[1])
            emit FeedForward_PitchChanged(data.FeedForward[1]);
        //if (data.FeedForward[2] != oldData.FeedForward[2])
            emit FeedForward_YawChanged(data.FeedForward[2]);
        //if (data.AccelTime[0] != oldData.AccelTime[0])
            emit AccelTime_RollChanged(data.AccelTime[0]);
        //if (data.AccelTime[1] != oldData.AccelTime[1])
            emit AccelTime_PitchChanged(data.AccelTime[1]);
        //if (data.AccelTime[2] != oldData.AccelTime[2])
            emit AccelTime_YawChanged(data.AccelTime[2]);
        //if (data.DecelTime[0] != oldData.DecelTime[0])
            emit DecelTime_RollChanged(data.DecelTime[0]);
        //if (data.DecelTime[1] != oldData.DecelTime[1])
            emit DecelTime_PitchChanged(data.DecelTime[1]);
        //if (data.DecelTime[2] != oldData.DecelTime[2])
            emit DecelTime_YawChanged(data.DecelTime[2]);
        //if (data.Servo1PitchReverse != oldData.Servo1PitchReverse)
            emit Servo1PitchReverseChanged(data.Servo1PitchReverse);
        //if (data.Servo2PitchReverse != oldData.Servo2PitchReverse)
            emit Servo2PitchReverseChanged(data.Servo2PitchReverse);

}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject *CameraStabSettings::clone(quint32 instID)
{
    CameraStabSettings *obj = new CameraStabSettings();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Create a clone of this object only to be used to retrieve defaults
 */
UAVDataObject *CameraStabSettings::dirtyClone()
{
    CameraStabSettings *obj = new CameraStabSettings();
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
CameraStabSettings *CameraStabSettings::GetInstance(UAVObjectManager *objMngr, quint32 instID)
{
    return dynamic_cast<CameraStabSettings *>(objMngr->getObject(CameraStabSettings::OBJID, instID));
}

float CameraStabSettings::getMaxAxisLockRate() const
{
   QMutexLocker locker(mutex);
   return data.MaxAxisLockRate;
}
void CameraStabSettings::setMaxAxisLockRate(float value)
{
   mutex->lock();
   bool changed = data.MaxAxisLockRate != value;
   data.MaxAxisLockRate = value;
   mutex->unlock();
   if (changed) emit MaxAxisLockRateChanged(value);
}

quint16 CameraStabSettings::getMaxAccel() const
{
   QMutexLocker locker(mutex);
   return data.MaxAccel;
}
void CameraStabSettings::setMaxAccel(quint16 value)
{
   mutex->lock();
   bool changed = data.MaxAccel != value;
   data.MaxAccel = value;
   mutex->unlock();
   if (changed) emit MaxAccelChanged(value);
}

quint8 CameraStabSettings::getInput(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.Input[index];
}
void CameraStabSettings::setInput(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.Input[index] != value;
   data.Input[index] = value;
   mutex->unlock();
   if (changed) emit InputChanged(index,value);
}

quint8 CameraStabSettings::getInput_Roll() const
{
   QMutexLocker locker(mutex);
   return data.Input[0];
}
void CameraStabSettings::setInput_Roll(quint8 value)
{
   mutex->lock();
   bool changed = data.Input[0] != value;
   data.Input[0] = value;
   mutex->unlock();
   if (changed) emit Input_RollChanged(value);
}

quint8 CameraStabSettings::getInput_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.Input[1];
}
void CameraStabSettings::setInput_Pitch(quint8 value)
{
   mutex->lock();
   bool changed = data.Input[1] != value;
   data.Input[1] = value;
   mutex->unlock();
   if (changed) emit Input_PitchChanged(value);
}

quint8 CameraStabSettings::getInput_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.Input[2];
}
void CameraStabSettings::setInput_Yaw(quint8 value)
{
   mutex->lock();
   bool changed = data.Input[2] != value;
   data.Input[2] = value;
   mutex->unlock();
   if (changed) emit Input_YawChanged(value);
}

quint8 CameraStabSettings::getInputRange(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.InputRange[index];
}
void CameraStabSettings::setInputRange(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.InputRange[index] != value;
   data.InputRange[index] = value;
   mutex->unlock();
   if (changed) emit InputRangeChanged(index,value);
}

quint8 CameraStabSettings::getInputRange_Roll() const
{
   QMutexLocker locker(mutex);
   return data.InputRange[0];
}
void CameraStabSettings::setInputRange_Roll(quint8 value)
{
   mutex->lock();
   bool changed = data.InputRange[0] != value;
   data.InputRange[0] = value;
   mutex->unlock();
   if (changed) emit InputRange_RollChanged(value);
}

quint8 CameraStabSettings::getInputRange_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.InputRange[1];
}
void CameraStabSettings::setInputRange_Pitch(quint8 value)
{
   mutex->lock();
   bool changed = data.InputRange[1] != value;
   data.InputRange[1] = value;
   mutex->unlock();
   if (changed) emit InputRange_PitchChanged(value);
}

quint8 CameraStabSettings::getInputRange_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.InputRange[2];
}
void CameraStabSettings::setInputRange_Yaw(quint8 value)
{
   mutex->lock();
   bool changed = data.InputRange[2] != value;
   data.InputRange[2] = value;
   mutex->unlock();
   if (changed) emit InputRange_YawChanged(value);
}

quint8 CameraStabSettings::getInputRate(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.InputRate[index];
}
void CameraStabSettings::setInputRate(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.InputRate[index] != value;
   data.InputRate[index] = value;
   mutex->unlock();
   if (changed) emit InputRateChanged(index,value);
}

quint8 CameraStabSettings::getInputRate_Roll() const
{
   QMutexLocker locker(mutex);
   return data.InputRate[0];
}
void CameraStabSettings::setInputRate_Roll(quint8 value)
{
   mutex->lock();
   bool changed = data.InputRate[0] != value;
   data.InputRate[0] = value;
   mutex->unlock();
   if (changed) emit InputRate_RollChanged(value);
}

quint8 CameraStabSettings::getInputRate_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.InputRate[1];
}
void CameraStabSettings::setInputRate_Pitch(quint8 value)
{
   mutex->lock();
   bool changed = data.InputRate[1] != value;
   data.InputRate[1] = value;
   mutex->unlock();
   if (changed) emit InputRate_PitchChanged(value);
}

quint8 CameraStabSettings::getInputRate_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.InputRate[2];
}
void CameraStabSettings::setInputRate_Yaw(quint8 value)
{
   mutex->lock();
   bool changed = data.InputRate[2] != value;
   data.InputRate[2] = value;
   mutex->unlock();
   if (changed) emit InputRate_YawChanged(value);
}

quint8 CameraStabSettings::getStabilizationMode(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.StabilizationMode[index];
}
void CameraStabSettings::setStabilizationMode(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.StabilizationMode[index] != value;
   data.StabilizationMode[index] = value;
   mutex->unlock();
   if (changed) emit StabilizationModeChanged(index,value);
}

quint8 CameraStabSettings::getStabilizationMode_Roll() const
{
   QMutexLocker locker(mutex);
   return data.StabilizationMode[0];
}
void CameraStabSettings::setStabilizationMode_Roll(quint8 value)
{
   mutex->lock();
   bool changed = data.StabilizationMode[0] != value;
   data.StabilizationMode[0] = value;
   mutex->unlock();
   if (changed) emit StabilizationMode_RollChanged(value);
}

quint8 CameraStabSettings::getStabilizationMode_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.StabilizationMode[1];
}
void CameraStabSettings::setStabilizationMode_Pitch(quint8 value)
{
   mutex->lock();
   bool changed = data.StabilizationMode[1] != value;
   data.StabilizationMode[1] = value;
   mutex->unlock();
   if (changed) emit StabilizationMode_PitchChanged(value);
}

quint8 CameraStabSettings::getStabilizationMode_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.StabilizationMode[2];
}
void CameraStabSettings::setStabilizationMode_Yaw(quint8 value)
{
   mutex->lock();
   bool changed = data.StabilizationMode[2] != value;
   data.StabilizationMode[2] = value;
   mutex->unlock();
   if (changed) emit StabilizationMode_YawChanged(value);
}

quint8 CameraStabSettings::getOutputRange(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.OutputRange[index];
}
void CameraStabSettings::setOutputRange(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.OutputRange[index] != value;
   data.OutputRange[index] = value;
   mutex->unlock();
   if (changed) emit OutputRangeChanged(index,value);
}

quint8 CameraStabSettings::getOutputRange_Roll() const
{
   QMutexLocker locker(mutex);
   return data.OutputRange[0];
}
void CameraStabSettings::setOutputRange_Roll(quint8 value)
{
   mutex->lock();
   bool changed = data.OutputRange[0] != value;
   data.OutputRange[0] = value;
   mutex->unlock();
   if (changed) emit OutputRange_RollChanged(value);
}

quint8 CameraStabSettings::getOutputRange_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.OutputRange[1];
}
void CameraStabSettings::setOutputRange_Pitch(quint8 value)
{
   mutex->lock();
   bool changed = data.OutputRange[1] != value;
   data.OutputRange[1] = value;
   mutex->unlock();
   if (changed) emit OutputRange_PitchChanged(value);
}

quint8 CameraStabSettings::getOutputRange_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.OutputRange[2];
}
void CameraStabSettings::setOutputRange_Yaw(quint8 value)
{
   mutex->lock();
   bool changed = data.OutputRange[2] != value;
   data.OutputRange[2] = value;
   mutex->unlock();
   if (changed) emit OutputRange_YawChanged(value);
}

quint8 CameraStabSettings::getResponseTime(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.ResponseTime[index];
}
void CameraStabSettings::setResponseTime(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.ResponseTime[index] != value;
   data.ResponseTime[index] = value;
   mutex->unlock();
   if (changed) emit ResponseTimeChanged(index,value);
}

quint8 CameraStabSettings::getResponseTime_Roll() const
{
   QMutexLocker locker(mutex);
   return data.ResponseTime[0];
}
void CameraStabSettings::setResponseTime_Roll(quint8 value)
{
   mutex->lock();
   bool changed = data.ResponseTime[0] != value;
   data.ResponseTime[0] = value;
   mutex->unlock();
   if (changed) emit ResponseTime_RollChanged(value);
}

quint8 CameraStabSettings::getResponseTime_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.ResponseTime[1];
}
void CameraStabSettings::setResponseTime_Pitch(quint8 value)
{
   mutex->lock();
   bool changed = data.ResponseTime[1] != value;
   data.ResponseTime[1] = value;
   mutex->unlock();
   if (changed) emit ResponseTime_PitchChanged(value);
}

quint8 CameraStabSettings::getResponseTime_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.ResponseTime[2];
}
void CameraStabSettings::setResponseTime_Yaw(quint8 value)
{
   mutex->lock();
   bool changed = data.ResponseTime[2] != value;
   data.ResponseTime[2] = value;
   mutex->unlock();
   if (changed) emit ResponseTime_YawChanged(value);
}

quint8 CameraStabSettings::getGimbalType() const
{
   QMutexLocker locker(mutex);
   return data.GimbalType;
}
void CameraStabSettings::setGimbalType(quint8 value)
{
   mutex->lock();
   bool changed = data.GimbalType != value;
   data.GimbalType = value;
   mutex->unlock();
   if (changed) emit GimbalTypeChanged(value);
}

quint8 CameraStabSettings::getFeedForward(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.FeedForward[index];
}
void CameraStabSettings::setFeedForward(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.FeedForward[index] != value;
   data.FeedForward[index] = value;
   mutex->unlock();
   if (changed) emit FeedForwardChanged(index,value);
}

quint8 CameraStabSettings::getFeedForward_Roll() const
{
   QMutexLocker locker(mutex);
   return data.FeedForward[0];
}
void CameraStabSettings::setFeedForward_Roll(quint8 value)
{
   mutex->lock();
   bool changed = data.FeedForward[0] != value;
   data.FeedForward[0] = value;
   mutex->unlock();
   if (changed) emit FeedForward_RollChanged(value);
}

quint8 CameraStabSettings::getFeedForward_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.FeedForward[1];
}
void CameraStabSettings::setFeedForward_Pitch(quint8 value)
{
   mutex->lock();
   bool changed = data.FeedForward[1] != value;
   data.FeedForward[1] = value;
   mutex->unlock();
   if (changed) emit FeedForward_PitchChanged(value);
}

quint8 CameraStabSettings::getFeedForward_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.FeedForward[2];
}
void CameraStabSettings::setFeedForward_Yaw(quint8 value)
{
   mutex->lock();
   bool changed = data.FeedForward[2] != value;
   data.FeedForward[2] = value;
   mutex->unlock();
   if (changed) emit FeedForward_YawChanged(value);
}

quint8 CameraStabSettings::getAccelTime(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.AccelTime[index];
}
void CameraStabSettings::setAccelTime(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.AccelTime[index] != value;
   data.AccelTime[index] = value;
   mutex->unlock();
   if (changed) emit AccelTimeChanged(index,value);
}

quint8 CameraStabSettings::getAccelTime_Roll() const
{
   QMutexLocker locker(mutex);
   return data.AccelTime[0];
}
void CameraStabSettings::setAccelTime_Roll(quint8 value)
{
   mutex->lock();
   bool changed = data.AccelTime[0] != value;
   data.AccelTime[0] = value;
   mutex->unlock();
   if (changed) emit AccelTime_RollChanged(value);
}

quint8 CameraStabSettings::getAccelTime_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.AccelTime[1];
}
void CameraStabSettings::setAccelTime_Pitch(quint8 value)
{
   mutex->lock();
   bool changed = data.AccelTime[1] != value;
   data.AccelTime[1] = value;
   mutex->unlock();
   if (changed) emit AccelTime_PitchChanged(value);
}

quint8 CameraStabSettings::getAccelTime_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.AccelTime[2];
}
void CameraStabSettings::setAccelTime_Yaw(quint8 value)
{
   mutex->lock();
   bool changed = data.AccelTime[2] != value;
   data.AccelTime[2] = value;
   mutex->unlock();
   if (changed) emit AccelTime_YawChanged(value);
}

quint8 CameraStabSettings::getDecelTime(quint32 index) const
{
   QMutexLocker locker(mutex);
   return data.DecelTime[index];
}
void CameraStabSettings::setDecelTime(quint32 index, quint8 value)
{
   mutex->lock();
   bool changed = data.DecelTime[index] != value;
   data.DecelTime[index] = value;
   mutex->unlock();
   if (changed) emit DecelTimeChanged(index,value);
}

quint8 CameraStabSettings::getDecelTime_Roll() const
{
   QMutexLocker locker(mutex);
   return data.DecelTime[0];
}
void CameraStabSettings::setDecelTime_Roll(quint8 value)
{
   mutex->lock();
   bool changed = data.DecelTime[0] != value;
   data.DecelTime[0] = value;
   mutex->unlock();
   if (changed) emit DecelTime_RollChanged(value);
}

quint8 CameraStabSettings::getDecelTime_Pitch() const
{
   QMutexLocker locker(mutex);
   return data.DecelTime[1];
}
void CameraStabSettings::setDecelTime_Pitch(quint8 value)
{
   mutex->lock();
   bool changed = data.DecelTime[1] != value;
   data.DecelTime[1] = value;
   mutex->unlock();
   if (changed) emit DecelTime_PitchChanged(value);
}

quint8 CameraStabSettings::getDecelTime_Yaw() const
{
   QMutexLocker locker(mutex);
   return data.DecelTime[2];
}
void CameraStabSettings::setDecelTime_Yaw(quint8 value)
{
   mutex->lock();
   bool changed = data.DecelTime[2] != value;
   data.DecelTime[2] = value;
   mutex->unlock();
   if (changed) emit DecelTime_YawChanged(value);
}

quint8 CameraStabSettings::getServo1PitchReverse() const
{
   QMutexLocker locker(mutex);
   return data.Servo1PitchReverse;
}
void CameraStabSettings::setServo1PitchReverse(quint8 value)
{
   mutex->lock();
   bool changed = data.Servo1PitchReverse != value;
   data.Servo1PitchReverse = value;
   mutex->unlock();
   if (changed) emit Servo1PitchReverseChanged(value);
}

quint8 CameraStabSettings::getServo2PitchReverse() const
{
   QMutexLocker locker(mutex);
   return data.Servo2PitchReverse;
}
void CameraStabSettings::setServo2PitchReverse(quint8 value)
{
   mutex->lock();
   bool changed = data.Servo2PitchReverse != value;
   data.Servo2PitchReverse = value;
   mutex->unlock();
   if (changed) emit Servo2PitchReverseChanged(value);
}


