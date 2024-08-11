#include "AlpacaSwitch.h"

void AlpacaSwitch::registerCallbacks()
{
    AlpacaDevice::registerCallbacks();
    this->createCallBack(LHF(aGetMaxSwitch), HTTP_GET, "maxswitch");
    this->createCallBack(LHF(aGetCanWrite), HTTP_GET, "canwrite");
    this->createCallBack(LHF(aGetGetSwitch), HTTP_GET, "getswitch");
    this->createCallBack(LHF(aGetGetSwitchDescription), HTTP_GET, "getswitchdescription");
    this->createCallBack(LHF(aGetGetSwitchName), HTTP_GET, "getswitchname");
    this->createCallBack(LHF(aGetGetSwitchValue), HTTP_GET, "getswitchvalue");
    this->createCallBack(LHF(aGetMinSwitchValue), HTTP_GET, "minswitchvalue");
    this->createCallBack(LHF(aGetMaxSwitchValue), HTTP_GET, "maxswitchvalue");
    this->createCallBack(LHF(aGetSwitchStep), HTTP_GET, "switchstep");

    this->createCallBack(LHF(aPutSetSwitch), HTTP_PUT, "setswitch");
    this->createCallBack(LHF(aPutSetSwitchName), HTTP_GET, "setswitchname");
    this->createCallBack(LHF(aPutSetSwitchValue), HTTP_GET, "setswitchvalue");
}

void AlpacaSwitch::aGetInterfaceVersion(AsyncWebServerRequest *request)
{
    _alpacaServer->respond(request, ALPACA_SWITCH_INTERFACE_VERSION);
};