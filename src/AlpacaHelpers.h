#pragma once
#include <Arduino.h>

// settings
#define ALPACA_MAX_DEVICES 8

#define ALPACA_DISCOVERY_HEADER "alpacadiscovery"
#define ALPACA_DISCOVERY_LENGTH 64

// discovery package
typedef struct
{
private:
    char _header[15];
    char _version;
    char _reserved[48];

public:
    bool valid() { return strncmp(_header, ALPACA_DISCOVERY_HEADER, 15) == 0; }
    char version() { return _version; }
} AlpacaDiscoveryPacket;
static_assert(sizeof(AlpacaDiscoveryPacket) == ALPACA_DISCOVERY_LENGTH, "Wrong size of struct");

typedef union
{
    AlpacaDiscoveryPacket data;
    char buffer[ALPACA_DISCOVERY_LENGTH];
} AlpacaDiscoveryBuffer;

// return
#define ALPACA_API_VERSIONS "[1]"
#define ALPACA_DRIVER_VER "v0.1.1"
#define ALPACA_DRIVER_DESC "ESP32 Ascom Alpaca driver"
#define ALPACA_DRIVER_INFO "ESP32 Ascom Alpaca driver by Njaal Brekke & @agnuca"
#define ALPACA_DESCRIPTION "{\"ServerName\":\"ESP32 Ascom Alpaca Server\",\"Authors\":\"Njaal Brekke & @agnuca\",\"ServerVersion\":\"v1.1\"}"
#define ALPACA_DEFAULT_NAME "%s-%i"
#define ALPACA_UNIQUE_NAME "%s#%s%02X"
#define ALPACA_JSON_TYPE "application/json"
#define ALPACA_DEVICE_COMMAND "/api/v1/%s/%d/%s"
#define ALPACA_DEVICE_LIST "{\"DeviceName\":\"%s\",\"DeviceType\":\"%s\",\"DeviceNumber\":%i,\"UniqueID\":\"%s\"}"
#define ALPACA_RESPOSE_ERROR "{\n\t\"ClientTransactionID\": %i,\n\t\"ServerTransactionID\": %i,\n\t\"ErrorNumber\": %i,\n\t\"ErrorMessage\": \"%s\"\n}"
#define ALPACA_RESPOSE_VALUE_ERROR "{\n\t\"Value\": %s,\n\t\"ClientTransactionID\": %i,\n\t\"ServerTransactionID\": %i,\n\t\"ErrorNumber\": %i,\n\t\"ErrorMessage\": \"%s\"\n}"
#define ALPACA_RESPOSE_VALUE_ERROR_STR "{\n\t\"Value\": \"%s\",\n\t\"ClientTransactionID\": %i,\n\t\"ServerTransactionID\": %i,\n\t\"ErrorNumber\": %i,\n\t\"ErrorMessage\": \"%s\"\n}"

enum AscomErrorCode : int64_t
{
    ActionNotImplementedException = 0x40C, // to indicate that the requested action is not implemented in this driver.
    DriverBase = 0x500,                    // The starting value for driver-specific error numbers.
    DriverMax = 0xFFF,                     // The maximum value for driver-specific error numbers.
    InvalidOperationException = 0x40B,     // to indicate that the requested operation can not be undertaken at this time.
    InvalidValue = 0x401,                  // for reporting an invalid value.
    InvalidWhileParked = 0x408,            // used to indicate that the attempted operation is invalid because the mount is currently in a Parked state.
    InvalidWhileSlaved = 0x409,            // used to indicate that the attempted operation is invalid because the mount is currently in a Slaved state.
    NotConnected = 0x407,                  // used to indicate that the communications channel is not connected.
    NotImplemented = 0x400,                // for property or method not implemented.
    NotInCacheException = 0x40D,           // to indicate that the requested item is not present in the ASCOM cache.
    SettingsProviderError = 0x40A,         // related to settings.
    UnspecifiedError = 0x4FF,              // used when nothing else was specified.
    ValueNotSet = 0x402                    // for reporting that a value has not been set.
};