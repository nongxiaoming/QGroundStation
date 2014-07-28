/**
 ******************************************************************************
 *
 * @file       gpssettings.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: gpssettings.xml. 
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
#ifndef GPSSETTINGS_H
#define GPSSETTINGS_H

#include "uavdataobject.h"
#include "uavobjectmanager.h"

class UAVOBJECTS_EXPORT GPSSettings: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(float MaxPDOP READ getMaxPDOP WRITE setMaxPDOP NOTIFY MaxPDOPChanged);
    Q_PROPERTY(quint8 DataProtocol READ getDataProtocol WRITE setDataProtocol NOTIFY DataProtocolChanged);
    Q_PROPERTY(quint8 MinSattelites READ getMinSattelites WRITE setMinSattelites NOTIFY MinSattelitesChanged);


public:
    // Field structure
    typedef struct {
        float MaxPDOP;
        quint8 DataProtocol;
        quint8 MinSattelites;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field MaxPDOP information
    // Field DataProtocol information
    /* Enumeration options for field DataProtocol */
    typedef enum { DATAPROTOCOL_NMEA=0, DATAPROTOCOL_UBX=1 } DataProtocolOptions;
    // Field MinSattelites information

  
    // Constants
    static const quint32 OBJID = 0xE7736A6E;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 1;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    GPSSettings();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static GPSSettings* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE float getMaxPDOP() const;
    Q_INVOKABLE quint8 getDataProtocol() const;
    Q_INVOKABLE quint8 getMinSattelites() const;


public slots:
    void setMaxPDOP(float value);
    void setDataProtocol(quint8 value);
    void setMinSattelites(quint8 value);


signals:
    void MaxPDOPChanged(float value);
    void DataProtocolChanged(quint8 value);
    void MinSattelitesChanged(quint8 value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // GPSSETTINGS_H
