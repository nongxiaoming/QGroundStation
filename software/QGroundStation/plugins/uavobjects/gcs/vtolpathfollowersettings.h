/**
 ******************************************************************************
 *
 * @file       vtolpathfollowersettings.h
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
#ifndef VTOLPATHFOLLOWERSETTINGS_H
#define VTOLPATHFOLLOWERSETTINGS_H

#include "uavdataobject.h"
#include "uavobjectmanager.h"

class UAVOBJECTS_EXPORT VtolPathFollowerSettings: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float HorizontalPosPI_Kp READ getHorizontalPosPI_Kp WRITE setHorizontalPosPI_Kp NOTIFY HorizontalPosPI_KpChanged);
    Q_PROPERTY(float HorizontalPosPI_Ki READ getHorizontalPosPI_Ki WRITE setHorizontalPosPI_Ki NOTIFY HorizontalPosPI_KiChanged);
    Q_PROPERTY(float HorizontalPosPI_ILimit READ getHorizontalPosPI_ILimit WRITE setHorizontalPosPI_ILimit NOTIFY HorizontalPosPI_ILimitChanged);
    Q_PROPERTY(float HorizontalVelPID_Kp READ getHorizontalVelPID_Kp WRITE setHorizontalVelPID_Kp NOTIFY HorizontalVelPID_KpChanged);
    Q_PROPERTY(float HorizontalVelPID_Ki READ getHorizontalVelPID_Ki WRITE setHorizontalVelPID_Ki NOTIFY HorizontalVelPID_KiChanged);
    Q_PROPERTY(float HorizontalVelPID_Kd READ getHorizontalVelPID_Kd WRITE setHorizontalVelPID_Kd NOTIFY HorizontalVelPID_KdChanged);
    Q_PROPERTY(float HorizontalVelPID_ILimit READ getHorizontalVelPID_ILimit WRITE setHorizontalVelPID_ILimit NOTIFY HorizontalVelPID_ILimitChanged);
    Q_PROPERTY(float VerticalPosPI_Kp READ getVerticalPosPI_Kp WRITE setVerticalPosPI_Kp NOTIFY VerticalPosPI_KpChanged);
    Q_PROPERTY(float VerticalPosPI_Ki READ getVerticalPosPI_Ki WRITE setVerticalPosPI_Ki NOTIFY VerticalPosPI_KiChanged);
    Q_PROPERTY(float VerticalPosPI_ILimit READ getVerticalPosPI_ILimit WRITE setVerticalPosPI_ILimit NOTIFY VerticalPosPI_ILimitChanged);
    Q_PROPERTY(float VerticalVelPID_Kp READ getVerticalVelPID_Kp WRITE setVerticalVelPID_Kp NOTIFY VerticalVelPID_KpChanged);
    Q_PROPERTY(float VerticalVelPID_Ki READ getVerticalVelPID_Ki WRITE setVerticalVelPID_Ki NOTIFY VerticalVelPID_KiChanged);
    Q_PROPERTY(float VerticalVelPID_Kd READ getVerticalVelPID_Kd WRITE setVerticalVelPID_Kd NOTIFY VerticalVelPID_KdChanged);
    Q_PROPERTY(float VerticalVelPID_ILimit READ getVerticalVelPID_ILimit WRITE setVerticalVelPID_ILimit NOTIFY VerticalVelPID_ILimitChanged);
    Q_PROPERTY(float VelocityFeedforward READ getVelocityFeedforward WRITE setVelocityFeedforward NOTIFY VelocityFeedforwardChanged);
    Q_PROPERTY(float MaxRollPitch READ getMaxRollPitch WRITE setMaxRollPitch NOTIFY MaxRollPitchChanged);
    Q_PROPERTY(qint32 UpdatePeriod READ getUpdatePeriod WRITE setUpdatePeriod NOTIFY UpdatePeriodChanged);
    Q_PROPERTY(quint16 HorizontalVelMax READ getHorizontalVelMax WRITE setHorizontalVelMax NOTIFY HorizontalVelMaxChanged);
    Q_PROPERTY(quint16 VerticalVelMax READ getVerticalVelMax WRITE setVerticalVelMax NOTIFY VerticalVelMaxChanged);
    Q_PROPERTY(quint8 GuidanceMode READ getGuidanceMode WRITE setGuidanceMode NOTIFY GuidanceModeChanged);
    Q_PROPERTY(quint8 ThrustControl READ getThrustControl WRITE setThrustControl NOTIFY ThrustControlChanged);
    Q_PROPERTY(quint8 VelocitySource READ getVelocitySource WRITE setVelocitySource NOTIFY VelocitySourceChanged);


public:
    // Field structure
    typedef struct {
        float HorizontalPosPI[3];
        float HorizontalVelPID[4];
        float VerticalPosPI[3];
        float VerticalVelPID[4];
        float VelocityFeedforward;
        float MaxRollPitch;
        qint32 UpdatePeriod;
        quint16 HorizontalVelMax;
        quint16 VerticalVelMax;
        quint8 GuidanceMode;
        quint8 ThrustControl;
        quint8 VelocitySource;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field HorizontalPosPI information
    /* Array element names for field HorizontalPosPI */
    typedef enum { HORIZONTALPOSPI_KP=0, HORIZONTALPOSPI_KI=1, HORIZONTALPOSPI_ILIMIT=2 } HorizontalPosPIElem;
    /* Number of elements for field HorizontalPosPI */
    static const quint32 HORIZONTALPOSPI_NUMELEM = 3;
    // Field HorizontalVelPID information
    /* Array element names for field HorizontalVelPID */
    typedef enum { HORIZONTALVELPID_KP=0, HORIZONTALVELPID_KI=1, HORIZONTALVELPID_KD=2, HORIZONTALVELPID_ILIMIT=3 } HorizontalVelPIDElem;
    /* Number of elements for field HorizontalVelPID */
    static const quint32 HORIZONTALVELPID_NUMELEM = 4;
    // Field VerticalPosPI information
    /* Array element names for field VerticalPosPI */
    typedef enum { VERTICALPOSPI_KP=0, VERTICALPOSPI_KI=1, VERTICALPOSPI_ILIMIT=2 } VerticalPosPIElem;
    /* Number of elements for field VerticalPosPI */
    static const quint32 VERTICALPOSPI_NUMELEM = 3;
    // Field VerticalVelPID information
    /* Array element names for field VerticalVelPID */
    typedef enum { VERTICALVELPID_KP=0, VERTICALVELPID_KI=1, VERTICALVELPID_KD=2, VERTICALVELPID_ILIMIT=3 } VerticalVelPIDElem;
    /* Number of elements for field VerticalVelPID */
    static const quint32 VERTICALVELPID_NUMELEM = 4;
    // Field VelocityFeedforward information
    // Field MaxRollPitch information
    // Field UpdatePeriod information
    // Field HorizontalVelMax information
    // Field VerticalVelMax information
    // Field GuidanceMode information
    /* Enumeration options for field GuidanceMode */
    typedef enum { GUIDANCEMODE_DUAL_LOOP=0, GUIDANCEMODE_VELOCITY_CONTROL=1 } GuidanceModeOptions;
    // Field ThrustControl information
    /* Enumeration options for field ThrustControl */
    typedef enum { THRUSTCONTROL_FALSE=0, THRUSTCONTROL_TRUE=1 } ThrustControlOptions;
    // Field VelocitySource information
    /* Enumeration options for field VelocitySource */
    typedef enum { VELOCITYSOURCE_STATE_ESTIMATION=0, VELOCITYSOURCE_GPS_VELNED=1, VELOCITYSOURCE_GPS_GROUNDSPEED=2 } VelocitySourceOptions;

  
    // Constants
    static const quint32 OBJID = 0xB197967A;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 1;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    VtolPathFollowerSettings();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static VtolPathFollowerSettings* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getHorizontalPosPI(quint32 index) const;
    Q_INVOKABLE float getHorizontalPosPI_Kp() const;
    Q_INVOKABLE float getHorizontalPosPI_Ki() const;
    Q_INVOKABLE float getHorizontalPosPI_ILimit() const;
    Q_INVOKABLE float getHorizontalVelPID(quint32 index) const;
    Q_INVOKABLE float getHorizontalVelPID_Kp() const;
    Q_INVOKABLE float getHorizontalVelPID_Ki() const;
    Q_INVOKABLE float getHorizontalVelPID_Kd() const;
    Q_INVOKABLE float getHorizontalVelPID_ILimit() const;
    Q_INVOKABLE float getVerticalPosPI(quint32 index) const;
    Q_INVOKABLE float getVerticalPosPI_Kp() const;
    Q_INVOKABLE float getVerticalPosPI_Ki() const;
    Q_INVOKABLE float getVerticalPosPI_ILimit() const;
    Q_INVOKABLE float getVerticalVelPID(quint32 index) const;
    Q_INVOKABLE float getVerticalVelPID_Kp() const;
    Q_INVOKABLE float getVerticalVelPID_Ki() const;
    Q_INVOKABLE float getVerticalVelPID_Kd() const;
    Q_INVOKABLE float getVerticalVelPID_ILimit() const;
    Q_INVOKABLE float getVelocityFeedforward() const;
    Q_INVOKABLE float getMaxRollPitch() const;
    Q_INVOKABLE qint32 getUpdatePeriod() const;
    Q_INVOKABLE quint16 getHorizontalVelMax() const;
    Q_INVOKABLE quint16 getVerticalVelMax() const;
    Q_INVOKABLE quint8 getGuidanceMode() const;
    Q_INVOKABLE quint8 getThrustControl() const;
    Q_INVOKABLE quint8 getVelocitySource() const;


public slots:
    void setHorizontalPosPI(quint32 index, float value);
    void setHorizontalPosPI_Kp(float value);
    void setHorizontalPosPI_Ki(float value);
    void setHorizontalPosPI_ILimit(float value);
    void setHorizontalVelPID(quint32 index, float value);
    void setHorizontalVelPID_Kp(float value);
    void setHorizontalVelPID_Ki(float value);
    void setHorizontalVelPID_Kd(float value);
    void setHorizontalVelPID_ILimit(float value);
    void setVerticalPosPI(quint32 index, float value);
    void setVerticalPosPI_Kp(float value);
    void setVerticalPosPI_Ki(float value);
    void setVerticalPosPI_ILimit(float value);
    void setVerticalVelPID(quint32 index, float value);
    void setVerticalVelPID_Kp(float value);
    void setVerticalVelPID_Ki(float value);
    void setVerticalVelPID_Kd(float value);
    void setVerticalVelPID_ILimit(float value);
    void setVelocityFeedforward(float value);
    void setMaxRollPitch(float value);
    void setUpdatePeriod(qint32 value);
    void setHorizontalVelMax(quint16 value);
    void setVerticalVelMax(quint16 value);
    void setGuidanceMode(quint8 value);
    void setThrustControl(quint8 value);
    void setVelocitySource(quint8 value);


signals:
    void HorizontalPosPIChanged(quint32 index, float value);
    void HorizontalPosPI_KpChanged(float value);
    void HorizontalPosPI_KiChanged(float value);
    void HorizontalPosPI_ILimitChanged(float value);
    void HorizontalVelPIDChanged(quint32 index, float value);
    void HorizontalVelPID_KpChanged(float value);
    void HorizontalVelPID_KiChanged(float value);
    void HorizontalVelPID_KdChanged(float value);
    void HorizontalVelPID_ILimitChanged(float value);
    void VerticalPosPIChanged(quint32 index, float value);
    void VerticalPosPI_KpChanged(float value);
    void VerticalPosPI_KiChanged(float value);
    void VerticalPosPI_ILimitChanged(float value);
    void VerticalVelPIDChanged(quint32 index, float value);
    void VerticalVelPID_KpChanged(float value);
    void VerticalVelPID_KiChanged(float value);
    void VerticalVelPID_KdChanged(float value);
    void VerticalVelPID_ILimitChanged(float value);
    void VelocityFeedforwardChanged(float value);
    void MaxRollPitchChanged(float value);
    void UpdatePeriodChanged(qint32 value);
    void HorizontalVelMaxChanged(quint16 value);
    void VerticalVelMaxChanged(quint16 value);
    void GuidanceModeChanged(quint8 value);
    void ThrustControlChanged(quint8 value);
    void VelocitySourceChanged(quint8 value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // VTOLPATHFOLLOWERSETTINGS_H
