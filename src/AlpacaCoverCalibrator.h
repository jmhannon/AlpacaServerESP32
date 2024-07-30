#pragma once
#include "AlpacaDevice.h"

#define ALPACA_COVER_CALIBRATOR_INTERFACE_VERSION "1"

// don't like this but could not figure out how to use enums for this
#define CNotPresent 0
#define COff 1
#define CNotReady 2
#define CReady 3
#define CUnknown 4
#define CError 5
#define CClosed 1
#define CMoving 2
#define COpen = 3

class AlpacaCoverCalibrator : public AlpacaDevice
{
protected:
    // alpaca commands
    void aGetInterfaceVersion(AsyncWebServerRequest *request);
    virtual void aGetBrightness(AsyncWebServerRequest *request) = 0;
    virtual void aGetCalibratorState(AsyncWebServerRequest *request) = 0;
    virtual void aGetCoverState(AsyncWebServerRequest *request) = 0;
    virtual void aGetMaxBrightness(AsyncWebServerRequest *request) = 0;
    virtual void aGetCoverStatus(AsyncWebServerRequest *request) = 0;
    virtual void aGetCalibratorChanging(AsyncWebServerRequest *request) = 0;
    virtual void aGetConnecting(AsyncWebServerRequest *request) = 0; // needs to move up to alpaca devices as all devices have this method
    virtual void aGetCoverMoving(AsyncWebServerRequest *request) = 0;
    virtual void aGetDeviceState(AsyncWebServerRequest *request) = 0;

    virtual void aPutCalibratorOff(AsyncWebServerRequest *request) = 0;
    virtual void aPutCalibratorOn(AsyncWebServerRequest *request) = 0;
    virtual void aPutCloseCover(AsyncWebServerRequest *request) = 0;
    virtual void aPutHaltCover(AsyncWebServerRequest *request) = 0;
    virtual void aPutOpenCover(AsyncWebServerRequest *request) = 0;

    AlpacaCoverCalibrator() { strcpy(_device_type, "covercalibrator"); }

public:
    void registerCallbacks();
};