#pragma once
#include "AlpacaDevice.h"

#define ALPACA_SAFETYMONITOR_INTERFACE_VERSION "3"

class AlpacaSafetyMonitor : public AlpacaDevice
{
    protected:
        // alpaca commands
        void aGetInterfaceVersion(AsyncWebServerRequest *request);
        virtual void aGetAbsolute(AsyncWebServerRequest *request) = 0;
        virtual void aGetIsMoving(AsyncWebServerRequest *request) = 0;
        virtual void aGetMaxIncrement(AsyncWebServerRequest *request) = 0;
        virtual void aGetMaxStep(AsyncWebServerRequest *request) = 0;
        virtual void aGetPosition(AsyncWebServerRequest *request) = 0;
        virtual void aGetStepSize(AsyncWebServerRequest *request) = 0;
        virtual void aGetTempComp(AsyncWebServerRequest *request) = 0;
        virtual void aPutTempComp(AsyncWebServerRequest *request) = 0;
        virtual void aGetTempCompAvailable(AsyncWebServerRequest *request) = 0;
        virtual void aGetTemperature(AsyncWebServerRequest *request) = 0;
        virtual void aPutHalt(AsyncWebServerRequest *request) = 0;
        virtual void aPutMove(AsyncWebServerRequest *request) = 0;
        AlpacaSafetyMonitor() {strcpy(_device_type, "SafetyMonitor");}
    public:
        void registerCallbacks();
};