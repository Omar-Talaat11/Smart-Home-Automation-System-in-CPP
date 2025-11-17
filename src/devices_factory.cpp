#include "devices_factory.hpp"

/* ------------------- LG Factory Implementation ------------------- */

shared_ptr<Light> Smart_LG_DeviceFactory::getLED_Light() {
    return make_shared<LG_LED_Light>();
}

shared_ptr<Light> Smart_LG_DeviceFactory::getHalogen_Light() {
    return make_shared<LG_Halogen_Light>();
}

shared_ptr<Thermostat> Smart_LG_DeviceFactory::getTypeA_Thermostat() {
    return make_shared<LG_TypeA_Thermostat>();
}

shared_ptr<Thermostat> Smart_LG_DeviceFactory::getTypeB_Thermostat() {
    return make_shared<LG_TypeB_Thermostat>();
}

shared_ptr<SecurityCamera> Smart_LG_DeviceFactory::getWired_SecCamera() {
    return make_shared<LG_Wired_SecurityCamera>();
}

shared_ptr<SecurityCamera> Smart_LG_DeviceFactory::getWireless_SecCamera() {
    return make_shared<LG_Wireless_SecurityCamera>();
}

/* ------------------- Samsung Factory Implementation ------------------- */

shared_ptr<Light> Smart_Samsung_DeviceFactory::getLED_Light() {
    return make_shared<Samsung_LED_Light>();
}

shared_ptr<Light> Smart_Samsung_DeviceFactory::getHalogen_Light() {
    return make_shared<Samsung_Halogen_Light>();
}

shared_ptr<Thermostat> Smart_Samsung_DeviceFactory::getTypeA_Thermostat() {
    return make_shared<Samsung_TypeA_Thermostat>();
}

shared_ptr<Thermostat> Smart_Samsung_DeviceFactory::getTypeB_Thermostat() {
    return make_shared<Samsung_TypeB_Thermostat>();
}

shared_ptr<SecurityCamera> Smart_Samsung_DeviceFactory::getWired_SecCamera() {
    return make_shared<Samsung_Wired_SecurityCamera>();
}

shared_ptr<SecurityCamera> Smart_Samsung_DeviceFactory::getWireless_SecCamera() {
    return make_shared<Samsung_Wireless_SecurityCamera>();
}

/* ------------------- Factory Method for Motion Sensor ------------------- */
shared_ptr<MotionSensor> MotionSensorFactory::createSensor()
{
    return make_shared<MotionSensor>();
}


/* ------------------- Factory Method for Door Lock ------------------- */
shared_ptr<DoorLock> DoorLockFactory::createDoorLock()
{
    return make_shared<DoorLock>();
}