/**
 ******************************************************************************
 *
 * @file       overosyncstats.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: overosyncstats.xml. 
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
#ifndef OVEROSYNCSTATS_H
#define OVEROSYNCSTATS_H

#include "uavdataobject.h"
#include "uavobjectmanager.h"

class UAVOBJECTS_EXPORT OveroSyncStats: public UAVDataObject
{
    Q_OBJECT
    Q_PROPERTY(quint32 Send READ getSend WRITE setSend NOTIFY SendChanged);
    Q_PROPERTY(quint32 Received READ getReceived WRITE setReceived NOTIFY ReceivedChanged);
    Q_PROPERTY(quint32 FramesyncErrors READ getFramesyncErrors WRITE setFramesyncErrors NOTIFY FramesyncErrorsChanged);
    Q_PROPERTY(quint32 UnderrunErrors READ getUnderrunErrors WRITE setUnderrunErrors NOTIFY UnderrunErrorsChanged);
    Q_PROPERTY(quint32 DroppedUpdates READ getDroppedUpdates WRITE setDroppedUpdates NOTIFY DroppedUpdatesChanged);
    Q_PROPERTY(quint32 Packets READ getPackets WRITE setPackets NOTIFY PacketsChanged);
    Q_PROPERTY(quint8 Connected READ getConnected WRITE setConnected NOTIFY ConnectedChanged);


public:
    // Field structure
    typedef struct {
        quint32 Send;
        quint32 Received;
        quint32 FramesyncErrors;
        quint32 UnderrunErrors;
        quint32 DroppedUpdates;
        quint32 Packets;
        quint8 Connected;

    } __attribute__((packed)) DataFields;

    // Field information
    // Field Send information
    // Field Received information
    // Field FramesyncErrors information
    // Field UnderrunErrors information
    // Field DroppedUpdates information
    // Field Packets information
    // Field Connected information
    /* Enumeration options for field Connected */
    typedef enum { CONNECTED_FALSE=0, CONNECTED_TRUE=1 } ConnectedOptions;

  
    // Constants
    static const quint32 OBJID = 0xD2085FAC;
    static const QString NAME;
    static const QString DESCRIPTION;
    static const QString CATEGORY;
    static const bool ISSINGLEINST = 1;
    static const bool ISSETTINGS = 0;
    static const quint32 NUMBYTES = sizeof(DataFields);

    // Functions
    OveroSyncStats();

    DataFields getData();
    void setData(const DataFields& data);
    Metadata getDefaultMetadata();
    UAVDataObject* clone(quint32 instID);
	UAVDataObject* dirtyClone();
	
    static OveroSyncStats* GetInstance(UAVObjectManager* objMngr, quint32 instID = 0);

    Q_INVOKABLE quint32 getSend() const;
    Q_INVOKABLE quint32 getReceived() const;
    Q_INVOKABLE quint32 getFramesyncErrors() const;
    Q_INVOKABLE quint32 getUnderrunErrors() const;
    Q_INVOKABLE quint32 getDroppedUpdates() const;
    Q_INVOKABLE quint32 getPackets() const;
    Q_INVOKABLE quint8 getConnected() const;


public slots:
    void setSend(quint32 value);
    void setReceived(quint32 value);
    void setFramesyncErrors(quint32 value);
    void setUnderrunErrors(quint32 value);
    void setDroppedUpdates(quint32 value);
    void setPackets(quint32 value);
    void setConnected(quint8 value);


signals:
    void SendChanged(quint32 value);
    void ReceivedChanged(quint32 value);
    void FramesyncErrorsChanged(quint32 value);
    void UnderrunErrorsChanged(quint32 value);
    void DroppedUpdatesChanged(quint32 value);
    void PacketsChanged(quint32 value);
    void ConnectedChanged(quint8 value);


private slots:
    void emitNotifications();
	
private:
    DataFields data;

    void setDefaultFieldValues();

};

#endif // OVEROSYNCSTATS_H
