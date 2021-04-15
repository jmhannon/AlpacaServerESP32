# ESPAscomAlpacaServer

This is a library for adding Ascom Alpaca capabilites to your ESP32 arduino project. The motivation
for making this was to have a compact, easily adaptable library for interfacing with Alpaca.

Auto discovery by Ascom is working, and more than one device can be connected to the server.
As of now, only focuser is implemented, but adding other classes is very simple and I'll do so in the future.

To use, simply let your class inherit the relevant AscomDevice-derived class (e.g. AscomFocuser), and make
sure to implement all pure virtual methods:
aGet* should call _alpacaServer->respond(value, <error-code>, <error-message>)
aGet* should call _alpacaServer->respond(nullptr, <error-code>, <error-message>) after reading parameters using _alpacaServer->getParam("<param-name>")

Be sure to check out Ascom API documentation to be sure you handle values and parameters correctly, and
return error responses as needed.

For debugging set AscomServer.debug = true, after you have called Serial.begin();

**platform.io**
```
lib_deps=
   https://github.com/elenhinan/ESPAscomAlpacaServer
```

**myFocuser.h**
```
#include <AlpacaFocuser.h>

class MyFocuser : AlpacaFocuser
{
  [...]
  // alpaca getters
  void aGetAbsolute()             { _alpacaServer->respond(1); }
  void aGetIsMoving()             { _alpacaServer->respond(_isRunning()); }
  void aGetMaxIncrement()         { _alpacaServer->respond(_pos_max); }
  void aGetMaxStep()              { _alpacaServer->respond(_pos_max); }
  void aGetPosition()             { _alpacaServer->respond(_getCurrentPosition()); }
  void aGetStepSize()             { _alpacaServer->respond(_micrometerperstep); }
  void aGetTempComp()             { _alpacaServer->respond(_temp_comp); }
  void aGetTempCompAvailable()    { _alpacaServer->respond(1); }
  void aGetTemperature()          { _alpacaServer->respond(_temp_meas); }

  // alpaca setters
  void aPutTempComp()             { _alpacaServer->getParam("TempComp", _temp_comp); _alpacaServer->respond(nullptr); }
  void aPutHalt()                 { stop(); _alpacaServer->respond(nullptr); }
  void aPutMove()                 { _alpacaServer->getParam("Position", _pos_target); _alpacaServer->respond(nullptr); }
  [...]
}
```

**main.h**
```
#include <AscomServer.h>

#define ALPACA_UDP_PORT 32227
#define ALPACA_TCP_PORT 80
```

**main.cpp**
```
AlpacaServer alpacaServer("ExampleServer");
MyFocuser myFocuserA();
MyFocuser myFocuserB();

void setup()
{
  // make sure wifi is up and running before starting server
  [...]
  alpacaServer.begin(ALPACA_UDP_PORT, ALPACA_TCP_PORT);
  alpacaServer.addDevice(&myFocuserA);
  alpacaServer.addDevice(&myFocuserB);
}

void loop()
{
   [...]
   alpacaServer.update()
}
```
