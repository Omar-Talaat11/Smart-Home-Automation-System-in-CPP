#ifndef SMARTDEVICEFACTORY_HPP
#define SMARTDEVICEFACTORY_HPP

#include "devices.hpp"
#include "devices_adapter.hpp"
#include <memory>
using namespace std;

/* ------------------- Abstract Factory ------------------- */
class SmartDeviceFactory {
public:
    virtual ~SmartDeviceFactory() = default;

    virtual shared_ptr<Light> getLED_Light() = 0; 
    virtual shared_ptr<Light> getHalogen_Light() = 0;

    virtual shared_ptr<Thermostat> getTypeA_Thermostat() = 0; 
    virtual shared_ptr<Thermostat> getTypeB_Thermostat() = 0; 

    virtual shared_ptr<SecurityCamera> getWired_SecCamera() = 0;
    virtual shared_ptr<SecurityCamera> getWireless_SecCamera() = 0;
};

/* ------------------- Concrete LG Factory ------------------- */
class Smart_LG_DeviceFactory : public SmartDeviceFactory {
public:
    shared_ptr<Light> getLED_Light() override;
    shared_ptr<Light> getHalogen_Light() override;

    shared_ptr<Thermostat> getTypeA_Thermostat() override;
    shared_ptr<Thermostat> getTypeB_Thermostat() override;

    shared_ptr<SecurityCamera> getWired_SecCamera() override;
    shared_ptr<SecurityCamera> getWireless_SecCamera() override;
};

/* ------------------- Concrete Samsung Factory ------------------- */
class Smart_Samsung_DeviceFactory : public SmartDeviceFactory {
public:
    shared_ptr<Light> getLED_Light() override;
    shared_ptr<Light> getHalogen_Light() override;

    shared_ptr<Thermostat> getTypeA_Thermostat() override;
    shared_ptr<Thermostat> getTypeB_Thermostat() override;

    shared_ptr<SecurityCamera> getWired_SecCamera() override;
    shared_ptr<SecurityCamera> getWireless_SecCamera() override;
};

/* ------------------- Factory Method for Motion Sensor ------------------- */
class MotionSensorFactoryInterface {
public:
    virtual shared_ptr<MotionSensor> createSensor() = 0;
};

class MotionSensorFactory : public MotionSensorFactoryInterface{
public:
    shared_ptr<MotionSensor> createSensor() override;
};

/* ------------------- Factory Method for Door Lock ------------------- */
class DoorLockFactoryInterface {
public:
    virtual shared_ptr<DoorLock> createDoorLock() = 0;
};

class DoorLockFactory : public DoorLockFactoryInterface{
public:
    shared_ptr<DoorLock> createDoorLock() override;
};

#endif // SMARTDEVICEFACTORY_HPP
