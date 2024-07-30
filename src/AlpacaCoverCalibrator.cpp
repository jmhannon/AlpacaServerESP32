#include "AlpacaCoverCalibrator.h"

void AlpacaCoverCalibrator::registerCallbacks()
{
    AlpacaDevice::registerCallbacks();
    this->createCallBack(LHF(aGetBrightness), HTTP_GET, "brightness");
    this->createCallBack(LHF(aGetCalibratorState), HTTP_GET, "calibratorstate");
    this->createCallBack(LHF(aGetCoverState), HTTP_GET, "coverstate");
    this->createCallBack(LHF(aGetMaxBrightness), HTTP_GET, "maxbrightness");
    this->createCallBack(LHF(aGetCoverStatus), HTTP_GET, "coverstatus");
    this->createCallBack(LHF(aGetCalibratorChanging), HTTP_GET, "calibratorchanging");
    this->createCallBack(LHF(aGetCoverMoving), HTTP_GET, "calibratormoving");
    this->createCallBack(LHF(aGetDeviceState), HTTP_GET, "devicestate");
    this->createCallBack(LHF(aGetConnecting), HTTP_GET, "connecting");

    this->createCallBack(LHF(aPutCalibratorOff), HTTP_PUT, "calibratoroff");
    this->createCallBack(LHF(aPutCalibratorOn), HTTP_PUT, "calibratoron");
    this->createCallBack(LHF(aPutCloseCover), HTTP_PUT, "closecover");
    this->createCallBack(LHF(aPutHaltCover), HTTP_PUT, "haltcover");
    this->createCallBack(LHF(aPutOpenCover), HTTP_PUT, "opencover");
}

void AlpacaCoverCalibrator::aGetInterfaceVersion(AsyncWebServerRequest *request)
{
    _alpacaServer->respond(request, ALPACA_COVER_CALIBRATOR_INTERFACE_VERSION);
};
