#include "AlpacaDevice.h"

#define ALPACA_SWITCH_INTERFACE_VERSION "3"

class AlpacaSwitch : public AlpacaDevice
{
protected:
    // alpaca commands
    void aGetInterfaceVersion(AsyncWebServerRequest *request);
    virtual void aGetMaxSwitch(AsyncWebServerRequest *request) = 0;
    virtual void aGetCanWrite(AsyncWebServerRequest *request) = 0;
    virtual void aGetGetSwitch(AsyncWebServerRequest *request) = 0;
    virtual void aGetGetSwitchDescription(AsyncWebServerRequest *request) = 0;
    virtual void aGetGetSwitchName(AsyncWebServerRequest *request) = 0;
    virtual void aGetGetSwitchValue(AsyncWebServerRequest *request) = 0;
    virtual void aGetMinSwitchValue(AsyncWebServerRequest *request) = 0;
    virtual void aGetMaxSwitchValue(AsyncWebServerRequest *request) = 0;
    virtual void aGetSwitchStep(AsyncWebServerRequest *request) = 0;

    virtual void aPutSetSwitch(AsyncWebServerRequest *request) = 0;
    virtual void aPutSetSwitchName(AsyncWebServerRequest *request) = 0;
    virtual void aPutSetSwitchValue(AsyncWebServerRequest *request) = 0;
    AlpacaSwitch() { strcpy(_device_type, "switch"); }

public:
    void registerCallbacks();
};