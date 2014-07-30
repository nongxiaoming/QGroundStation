/**
 ******************************************************************************
 *
 * @file       camerastabsettings.h
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
#ifndef CAMERASTABSETTINGS_H
#define CAMERASTABSETTINGS_H

#include "uavobjects/uavdataobject.h"
#include "uavobjects/uavobjectmanager.h"

class UAVOBJECTS_EXPORT CameraStabSettings: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float MaxAxisLockRate READ getMaxAxisLockRate WRITE setMaxAxisLockRate NOTIFY MaxAxisLockRateChanged);
    Q_PROPERTY(quint16 MaxAccel READ getMaxAccel WRITE setMaxAccel NOTIFY MaxAccelChanged);
    Q_PROPERTY(quint8 Input_Roll READ getInput_Roll WRITE setInput_Roll NOTIFY Input_RollChanged);
    Q_PROPERTY(quint8 Input_Pitch READ getInput_Pitch WRITE setInput_Pitch NOTIFY Input_PitchChanged);
    Q_PROPERTY(quint8 Input_Yaw READ getInput_Yaw WRITE setInput_Yaw NOTIFY Input_YawChanged);
    Q_PROPERTY(quint8 InputRange_Roll READ getInputRange_Roll WRITE setInputRange_Roll NOTIFY InputRange_RollChanged);
    Q_PROPERTY(quint8 InputRange_Pitch READ getInputRange_Pitch WRITE setInputRange_Pitch NOTIFY InputRange_PitchChanged);
    Q_PROPERTY(quint8 InputRange_Yaw READ getInputRange_Yaw WRITE setInputRange_Yaw NOTIFY InputRange_YawChanged);
    Q_PROPERTY(quint8 InputRate_Roll READ getInputRate_Roll WRITE setInputRate_Roll NOTIFY InputRate_RollChanged);
    Q_PROPERTY(quint8 InputRate_Pitch READ getInputRate_Pitch WRITE setInputRate_Pitch NOTIFY InputRate_PitchChanged);
    Q_PROPERTY(quint8 InputRate_Yaw READ getInputRate_Yaw WRITE setInputRate_Yaw NOTIFY InputRate_YawChanged);
    Q_PROPERTY(quint8 StabilizationMode_Roll READ getStabilizationMode_Roll WRITE setStabilizationMode_Roll NOTIFY StabilizationMode_RollChanged);
    Q_PROPERTY(quint8 StabilizationMode_Pitch READ getStabilizationMode_Pitch WRITE setStabilizationMode_Pitch NOTIFY StabilizationMode_PitchChanged);
    Q_PROPERTY(quint8 StabilizationMode_Yaw READ getStabilizationMode_Yaw WRITE setStabilizationMode_Yaw NOTIFY StabilizationMode_YawChanged);
    Q_PROPERTY(quint8 OutputRange_Roll READ getOutputRange_Roll WRITE setOutputRange_Roll NOTIFY OutputRange_RollChanged);
    Q_PROPERTY(quint8 OutputRange_Pitch READ getOutputRange_Pitch WRITE setOutputRange_Pitch NOTIFY OutputRange_PitchChanged);
    Q_PROPERTY(quint8 OutputRange_Yaw READ getOutputRange_Yaw WRITE setOutputRange_Yaw NOTIFY OutputRange_YawChanged);
    Q_PROPERTY(quint8 ResponseTime_Roll READ getResponseTime_Roll WRITE setResponseTime_Roll NOTIFY ResponseTime_RollChanged);
    Q_PROPERTY(quint8 ResponseTime_Pitch READ getResponseTime_Pitch WRITE setResponseTime_Pitch NOTIFY ResponseTime_PitchChanged);
    Q_PROPERTY(quint8 ResponseTime_Yaw READ getResponseTime_Yaw WRITE setResponseTime_Yaw NOTIFY ResponseTime_YawChanged);
    Q_PROPERTY(quint8 GimbalType READ getGimbalType WRITE setGimbalType NOTIFY GimbalTypeChanged);
    Q_PROPERTY(quint8 FeedForward_Roll READ getFeedForward_Roll WRITE setFeedForward_Roll NOTIFY FeedForward_RollChanged);
    Q_PROPERTY(quint8 FeedForward_Pitch READ getFeedForward_Pitch WRITE setFeedForward_Pitch NOTIFY FeedForward_PitchChanged);
    Q_PROPERTY(quint8 FeedForward_Yaw READ getFeedForward_Yaw WRITE setFeedForward_Yaw NOTIFY FeedForward_YawChanged);
    Q_PROPERTY(quint8 AccelTime_Roll READ getAccelTime_Roll WRITE setAccelTime_Roll NOTIFY AccelTime_RollChanged);
    Q_PROPERTY(quint8 AccelTime_Pitch READ getAccelTime_Pitch WRITE setAccelTime_Pitch NOTIFY AccelTime_PitchChanged);
    Q_PROPERTY(quint8 AccelTime_Yaw READ getAccelTime_Yaw WRITE setAccelTime_Yaw NOTIFY AccelTime_YawChanged);
    Q_PROPERTY(quint8 DecelTime_Roll READ getDecelTime_Roll WRITE setDecelTime_Roll NOTIFY DecelTime_RollChanged);
    Q_PROPERTY(quint8 DecelTime_Pitch READ getDecelTime_Pitch WRITE setDecelTime_Pitch NOTIFY DecelTime_PitchChanged);
    Q_PROPERTY(quint8 DecelTime_Yaw READ getDecelTime_Yaw WRITE setDecelTime_Yaw NOTIFY DecelTime_YawChanged);
    Q_PROPERTY(quint8 Servo1PitchReverse READ getServo1PitchReverse WRITE setServo1PitchReverse NOTIFY Servo1PitchReverseChanged);
    Q_PROPERTY(quint8 Servo2PitchReverse READ getServo2PitchReverse WRITE setServo2PitchReverse NOTIFY Servo2PitchReverseChanged);


public:
    // Field structure
    typedef struct {
        float MaxAxisLockRate;
        quint16 MaxAccel;
        quint8 Input[3];
        quint8 InputRange[3];
        quint8 InputRate[3];
        quint8 StabilizationMode[3];
        quint8 OutputRange[3];
        quint8 ResponseTime[3];
        quint8 GimbalType;
        quint8 FeedForward[3];
        quint8 AccelTime[3];
        quint8 DecelTime[3];
        quint8 Servo1PitchReverse;
        quint8 Servo2PitchReverse;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field MaxAxisLockRate information
    // Field MaxAccel information
    // Field Input information
    /* Enumeration options for field Input */
    typedef enum { INPUT_ACCESSORY0=0, INPUT_ACCESSORY1=1, INPUT_ACCESSORY2=2, INPUT_ACCESSORY3=3, INPUT_ACCESSORY4=4, INPUT_ACCESSORY5=5, INPUT_NONE=6 } InputOptions;
    /* Array element names for field Input */
    typedef enum { INPUT_ROLL=0, INPUT_PITCH=1, INPUT_YAW=2 } InputElem;
    /* Number of elements for field Input */
    static const quint32 INPUT_NUMELEM = 3;
    // Field InputRange information
    /* Array element names for field InputRange */
    typedef enum { INPUTRANGE_ROLL=0, INPUTRANGE_PITCH=1, INPUTRANGE_YAW=2 } InputRangeElem;
    /* Number of elements for field InputRange */
    static const quint32 INPUTRANGE_NUMELEM = 3;
    // Field InputRate information
    /* Array element names for field InputRate */
    typedef enum { INPUTRATE_ROLL=0, INPUTRATE_PITCH=1, INPUTRATE_YAW=2 } InputRateElem;
    /* Number of elements for field InputRate */
    static const quint32 INPUTRATE_NUMELEM = 3;
    // Field StabilizationMode information
    /* Enumeration options for field StabilizationMode */
    typedef enum { STABILIZATIONMODE_ATTITUDE=0, STABILIZATIONMODE_AXISLOCK=1 } StabilizationModeOptions;
    /* Array element names for field StabilizationMode */
    typedef enum { STABILIZATIONMODE_ROLL=0, STABILIZATIONMODE_PITCH=1, STABILIZATIONMODE_YAW=2 } StabilizationModeElem;
    /* Number of elements for field StabilizationMode */
    static const quint32 STABILIZATIONMODE_NUMELEM = 3;
    // Field OutputRange information
    /* Array element names for field OutputRange */
    typedef enum { OUTPUTRANGE_ROLL=0, OUTPUTRANGE_PITCH=1, OUTPUTRANGE_YAW=2 } OutputRangeElem;
    /* Number of elements for field OutputRange */
    static const quint32 OUTPUTRANGE_NUMELEM = 3;
    // Field ResponseTime information
    /* Array element names for field ResponseTime */
    typedef enum { RESPONSETIME_ROLL=0, RESPONSETIME_PITCH=1, RESPONSETIME_YAW=2 } ResponseTimeElem;
    /* Number of elements for field ResponseTime */
    static const quint32 RESPONSETIME_NUMELEM = 3;
    // Field GimbalType information
    /* Enumeration options for field GimbalType */
    typedef enum { GIMBALTYPE_GENERIC=0, GIMBALTYPE_YAWROLLPITCH=1, GIMBALTYPE_YAWPITCHROLL=2, GIMBALTYPE_ROLLPITCHMIXED=3 } GimbalTypeOptions;
    // Field FeedForward information
    /* Array element names for field FeedForward */
    typedef enum { FEEDFORWARD_ROLL=0, FEEDFORWARD_PITCH=1, FEEDFORWARD_YAW=2 } FeedForwardElem;
    /* Number of elements for field FeedForward */
    static const quint32 FEEDFORWARD_NUMELEM = 3;
    // Field AccelTime information
    /* Array element names for field AccelTime */
    typedef enum { ACCELTIME_ROLL=0, ACCELTIME_PITCH=1, ACCELTIME_YAW=2 } AccelTimeElem;
    /* Number of elements for field AccelTime */
    static const quint32 ACCELTIME_NUMELEM = 3;
    // Field DecelTime information
    /* Array element names for field DecelTime */
    typedef enum { DECELTIME_ROLL=0, DECELTIME_PITCH=1, DECELTIME_YAW=2 } DecelTimeElem;
    /* Number of elements for field DecelTime */
    static const quint32 DECELTIME_NUMELEM = 3;
    // Field Servo1PitchReverse information
    /* Enumeration options for field Servo1PitchReverse */
    typedef enum { SERVO1PITCHREVERSE_FALSE=0, SERVO1PITCHREVERSE_TRUE=1 } Servo1PitchReverseOptions;
    // Field Servo2PitchReverse information
    /* Enumeration options for field Servo2PitchReverse */
    typedef enum { SERVO2PITCHREVERSE_FALSE=0, SERVO2PITCHREVERSE_TRUE=1 } Servo2PitchReverseOptions;

  
    // Constants
    static const quint32 OBJID = 0xEA58E53A;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 1;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    CameraStabSettings();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static CameraStabSettings* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getMaxAxisLockRate() const;
    Q_INVOKABLE quint16 getMaxAccel() const;
    Q_INVOKABLE quint8 getInput(quint32 index) const;
    Q_INVOKABLE quint8 getInput_Roll() const;
    Q_INVOKABLE quint8 getInput_Pitch() const;
    Q_INVOKABLE quint8 getInput_Yaw() const;
    Q_INVOKABLE quint8 getInputRange(quint32 index) const;
    Q_INVOKABLE quint8 getInputRange_Roll() const;
    Q_INVOKABLE quint8 getInputRange_Pitch() const;
    Q_INVOKABLE quint8 getInputRange_Yaw() const;
    Q_INVOKABLE quint8 getInputRate(quint32 index) const;
    Q_INVOKABLE quint8 getInputRate_Roll() const;
    Q_INVOKABLE quint8 getInputRate_Pitch() const;
    Q_INVOKABLE quint8 getInputRate_Yaw() const;
    Q_INVOKABLE quint8 getStabilizationMode(quint32 index) const;
    Q_INVOKABLE quint8 getStabilizationMode_Roll() const;
    Q_INVOKABLE quint8 getStabilizationMode_Pitch() const;
    Q_INVOKABLE quint8 getStabilizationMode_Yaw() const;
    Q_INVOKABLE quint8 getOutputRange(quint32 index) const;
    Q_INVOKABLE quint8 getOutputRange_Roll() const;
    Q_INVOKABLE quint8 getOutputRange_Pitch() const;
    Q_INVOKABLE quint8 getOutputRange_Yaw() const;
    Q_INVOKABLE quint8 getResponseTime(quint32 index) const;
    Q_INVOKABLE quint8 getResponseTime_Roll() const;
    Q_INVOKABLE quint8 getResponseTime_Pitch() const;
    Q_INVOKABLE quint8 getResponseTime_Yaw() const;
    Q_INVOKABLE quint8 getGimbalType() const;
    Q_INVOKABLE quint8 getFeedForward(quint32 index) const;
    Q_INVOKABLE quint8 getFeedForward_Roll() const;
    Q_INVOKABLE quint8 getFeedForward_Pitch() const;
    Q_INVOKABLE quint8 getFeedForward_Yaw() const;
    Q_INVOKABLE quint8 getAccelTime(quint32 index) const;
    Q_INVOKABLE quint8 getAccelTime_Roll() const;
    Q_INVOKABLE quint8 getAccelTime_Pitch() const;
    Q_INVOKABLE quint8 getAccelTime_Yaw() const;
    Q_INVOKABLE quint8 getDecelTime(quint32 index) const;
    Q_INVOKABLE quint8 getDecelTime_Roll() const;
    Q_INVOKABLE quint8 getDecelTime_Pitch() const;
    Q_INVOKABLE quint8 getDecelTime_Yaw() const;
    Q_INVOKABLE quint8 getServo1PitchReverse() const;
    Q_INVOKABLE quint8 getServo2PitchReverse() const;


public slots:
    void setMaxAxisLockRate(float value);
    void setMaxAccel(quint16 value);
    void setInput(quint32 index, quint8 value);
    void setInput_Roll(quint8 value);
    void setInput_Pitch(quint8 value);
    void setInput_Yaw(quint8 value);
    void setInputRange(quint32 index, quint8 value);
    void setInputRange_Roll(quint8 value);
    void setInputRange_Pitch(quint8 value);
    void setInputRange_Yaw(quint8 value);
    void setInputRate(quint32 index, quint8 value);
    void setInputRate_Roll(quint8 value);
    void setInputRate_Pitch(quint8 value);
    void setInputRate_Yaw(quint8 value);
    void setStabilizationMode(quint32 index, quint8 value);
    void setStabilizationMode_Roll(quint8 value);
    void setStabilizationMode_Pitch(quint8 value);
    void setStabilizationMode_Yaw(quint8 value);
    void setOutputRange(quint32 index, quint8 value);
    void setOutputRange_Roll(quint8 value);
    void setOutputRange_Pitch(quint8 value);
    void setOutputRange_Yaw(quint8 value);
    void setResponseTime(quint32 index, quint8 value);
    void setResponseTime_Roll(quint8 value);
    void setResponseTime_Pitch(quint8 value);
    void setResponseTime_Yaw(quint8 value);
    void setGimbalType(quint8 value);
    void setFeedForward(quint32 index, quint8 value);
    void setFeedForward_Roll(quint8 value);
    void setFeedForward_Pitch(quint8 value);
    void setFeedForward_Yaw(quint8 value);
    void setAccelTime(quint32 index, quint8 value);
    void setAccelTime_Roll(quint8 value);
    void setAccelTime_Pitch(quint8 value);
    void setAccelTime_Yaw(quint8 value);
    void setDecelTime(quint32 index, quint8 value);
    void setDecelTime_Roll(quint8 value);
    void setDecelTime_Pitch(quint8 value);
    void setDecelTime_Yaw(quint8 value);
    void setServo1PitchReverse(quint8 value);
    void setServo2PitchReverse(quint8 value);


signals:
    void MaxAxisLockRateChanged(float value);
    void MaxAccelChanged(quint16 value);
    void InputChanged(quint32 index, quint8 value);
    void Input_RollChanged(quint8 value);
    void Input_PitchChanged(quint8 value);
    void Input_YawChanged(quint8 value);
    void InputRangeChanged(quint32 index, quint8 value);
    void InputRange_RollChanged(quint8 value);
    void InputRange_PitchChanged(quint8 value);
    void InputRange_YawChanged(quint8 value);
    void InputRateChanged(quint32 index, quint8 value);
    void InputRate_RollChanged(quint8 value);
    void InputRate_PitchChanged(quint8 value);
    void InputRate_YawChanged(quint8 value);
    void StabilizationModeChanged(quint32 index, quint8 value);
    void StabilizationMode_RollChanged(quint8 value);
    void StabilizationMode_PitchChanged(quint8 value);
    void StabilizationMode_YawChanged(quint8 value);
    void OutputRangeChanged(quint32 index, quint8 value);
    void OutputRange_RollChanged(quint8 value);
    void OutputRange_PitchChanged(quint8 value);
    void OutputRange_YawChanged(quint8 value);
    void ResponseTimeChanged(quint32 index, quint8 value);
    void ResponseTime_RollChanged(quint8 value);
    void ResponseTime_PitchChanged(quint8 value);
    void ResponseTime_YawChanged(quint8 value);
    void GimbalTypeChanged(quint8 value);
    void FeedForwardChanged(quint32 index, quint8 value);
    void FeedForward_RollChanged(quint8 value);
    void FeedForward_PitchChanged(quint8 value);
    void FeedForward_YawChanged(quint8 value);
    void AccelTimeChanged(quint32 index, quint8 value);
    void AccelTime_RollChanged(quint8 value);
    void AccelTime_PitchChanged(quint8 value);
    void AccelTime_YawChanged(quint8 value);
    void DecelTimeChanged(quint32 index, quint8 value);
    void DecelTime_RollChanged(quint8 value);
    void DecelTime_PitchChanged(quint8 value);
    void DecelTime_YawChanged(quint8 value);
    void Servo1PitchReverseChanged(quint8 value);
    void Servo2PitchReverseChanged(quint8 value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // CAMERASTABSETTINGS_H
