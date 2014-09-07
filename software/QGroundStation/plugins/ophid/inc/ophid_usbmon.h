/**
 ******************************************************************************
 *
 * @file       ophid_usbmon.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2013.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup RawHIDPlugin Raw HID Plugin
 * @{
 * @brief Monitors the USB bus for devince insertion/removal
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

#ifndef OPHID_USBMON_H
#define OPHID_USBMON_H

#include "ophid_global.h"

#include <QThread>
#include <QMutex>
#include <QSemaphore>

// Arch dependent
#if defined(Q_OS_MAC)
#include <IOKit/IOKitLib.h>
#include <IOKit/hid/IOHIDLib.h>
#elif defined(Q_OS_UNIX)
#include <libudev.h>
#include <QSocketNotifier>
#elif defined(Q_OS_WIN32)
#ifndef _WIN32_WINNT
    #define _WIN32_WINNT   0x0500
#endif
#ifndef _WIN32_WINDOWS
    #define _WIN32_WINDOWS 0x0500
#endif
#ifndef WINVER
    #define WINVER         0x0500
#endif
#include <windows.h>
#include <dbt.h>
#include <setupapi.h>
#include <hidsdi.h>

// from working mingw hidsdi.h
#ifdef __cplusplus
extern "C" {
#endif

HIDAPI VOID WINAPI HidD_GetHidGuid(LPGUID);
HIDAPI BOOLEAN WINAPI HidD_GetPreparsedData(HANDLE, PHIDP_PREPARSED_DATA *);
HIDAPI BOOLEAN WINAPI HidD_FreePreparsedData(PHIDP_PREPARSED_DATA);
HIDAPI BOOLEAN WINAPI HidD_FlushQueue(HANDLE);
HIDAPI BOOLEAN WINAPI HidD_GetConfiguration(HANDLE, PHIDD_CONFIGURATION, ULONG);
HIDAPI BOOLEAN WINAPI HidD_SetConfiguration(HANDLE, PHIDD_CONFIGURATION, ULONG);
HIDAPI BOOLEAN WINAPI HidD_GetNumInputBuffers(HANDLE, PULONG);
HIDAPI BOOLEAN WINAPI HidD_SetNumInputBuffers(HANDLE HidDeviceObject, ULONG);
HIDAPI BOOLEAN WINAPI HidD_GetPhysicalDescriptor(HANDLE, PVOID, ULONG);
HIDAPI BOOLEAN WINAPI HidD_GetManufacturerString(HANDLE, PVOID, ULONG);
HIDAPI BOOLEAN WINAPI HidD_GetProductString(HANDLE, PVOID, ULONG);
HIDAPI BOOLEAN WINAPI HidD_GetIndexedString(HANDLE, ULONG, PVOID, ULONG);
HIDAPI BOOLEAN WINAPI HidD_GetSerialNumberString(HANDLE, PVOID, ULONG);

#ifdef __cplusplus
}
#endif
#endif // if defined(Q_OS_MAC)


#ifdef Q_OS_WIN
#ifdef QT_GUI_LIB
#include <QWidget>
class USBMonitor;

class USBRegistrationWidget : public QWidget {
    Q_OBJECT
public:
    USBRegistrationWidget(USBMonitor *qese)
    {
        this->qese = qese;
    }
    ~USBRegistrationWidget() {}

protected:
    USBMonitor *qese;
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    bool winEvent(MSG *message, long *result);
#else
    bool nativeEvent(const QByteArray & /*eventType*/, void *msg, long *result);
#endif
};
#endif // ifdef QT_GUI_LIB
#endif // ifdef Q_OS_WIN

struct USBPortInfo {
    // QString friendName; ///< Friendly name.
    // QString physName;
    // QString enumName;   ///< It seems its the only one with meaning
    QString serialNumber; // As a string as it can be anything, really...
    QString manufacturer;
    QString product;
#if defined(Q_OS_WIN32)
    QString devicePath; // only has meaning on windows
#elif  defined(Q_OS_MAC)
    IOHIDDeviceRef dev_handle;
#endif
    int UsagePage;
    int Usage;
    int vendorID; ///< Vendor ID.
    int productID; ///< Product ID
    int bcdDevice;
};

/**
 *   A monitoring thread which will wait for device events.
 */

class OPHID_EXPORT USBMonitor : public QThread {
    Q_OBJECT

public:
    enum RunState {
        Bootloader = 0x01,
        Running    = 0x02
    };

    enum USBConstants {
        idVendor_OpenPilot      = 0x20a0,
        idProduct_OpenPilot     = 0x415a,
        idProduct_CopterControl = 0x415b,
        idProduct_OPLinkMini    = 0x415c
    };

    static USBMonitor *instance();

    USBMonitor(QObject *parent = 0);
    ~USBMonitor();
    QList<USBPortInfo> availableDevices();
    QList<USBPortInfo> availableDevices(int vid, int pid, int boardModel, int runState);
#if defined(Q_OS_WIN32)
    LRESULT onDeviceChangeWin(WPARAM wParam, LPARAM lParam);
#endif
signals:
    /*!
       A new device has been connected to the system.

       setUpNotifications() must be called first to enable event-driven device notifications.
       Currently only implemented on Windows and OS X.
       \param info The device that has been discovered.
     */
    void deviceDiscovered(const USBPortInfo & info);
    void deviceDiscovered();

    /*!
       A device has been disconnected from the system.

       setUpNotifications() must be called first to enable event-driven device notifications.
       Currently only implemented on Windows and OS X.
       \param info The device that was disconnected.
     */
    void deviceRemoved(const USBPortInfo & info);
    void deviceRemoved();

private slots:
    /**
       Callback available for whenever the system that is put in place gets
       an event
     */
    void deviceEventReceived();

private:

    // ! Mutex for modifying the list of available devices
    QMutex *listMutex;

    // ! List of known devices maintained by callbacks
    QList<USBPortInfo> knowndevices;

    Q_DISABLE_COPY(USBMonitor)
    static USBMonitor * m_instance;


    // Depending on the OS, we'll need different things:
#if defined(Q_OS_MAC)
    static void attach_callback(void *context, IOReturn r, void *hid_mgr, IOHIDDeviceRef dev);
    static void detach_callback(void *context, IOReturn r, void *hid_mgr, IOHIDDeviceRef dev);
    void addDevice(USBPortInfo info);
    void removeDevice(IOHIDDeviceRef dev);
    IOHIDManagerRef hid_manager;
#elif defined(Q_OS_UNIX)
    struct udev *context;
    struct udev_monitor *monitor;
    QSocketNotifier *monitorNotifier;
    USBPortInfo makePortInfo(struct udev_device *dev);
#elif defined(Q_OS_WIN32)
    GUID guid_hid;
    void setUpNotifications();
    static int infoFromHandle(const GUID & guid, USBPortInfo & info, HDEVINFO & devInfo, DWORD & index);
    void enumerateDevicesWin(const GUID & guidDev);
    bool matchAndDispatchChangedDevice(const QString & deviceID, const GUID & guid, WPARAM wParam);
#ifdef QT_GUI_LIB
    USBRegistrationWidget *notificationWidget;
#endif
#endif // if defined(Q_OS_MAC)

#ifdef __APPLE__
protected:
    QSemaphore m_terminate;

    void run();
#endif // __APPLE__
};
#endif // OPHID_USBMON_H
