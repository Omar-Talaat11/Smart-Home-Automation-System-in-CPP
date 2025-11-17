#include "devices_hub.hpp"

std::shared_ptr<DevicesHub> DevicesHub::hubInstance = nullptr;

DevicesHub::DevicesHub() = default;

std::shared_ptr<DevicesHub> DevicesHub::getInstance() {
    if (hubInstance == nullptr)
        hubInstance = std::shared_ptr<DevicesHub>(new DevicesHub());
    return hubInstance;
}

std::shared_ptr<Device> DevicesHub::getLGDevice(DeviceID deviceID)
{
    switch (deviceID)
    {
    case DeviceID::LEDLight:         return LgFactory.getLED_Light();
    case DeviceID::HalogenLight:     return LgFactory.getHalogen_Light();
    case DeviceID::TypeAThermo:      return LgFactory.getTypeA_Thermostat();
    case DeviceID::TypeBThermo:      return LgFactory.getTypeB_Thermostat();
    case DeviceID::WiredSecCam:      return LgFactory.getWired_SecCamera();
    case DeviceID::WirelessSecCam:   return LgFactory.getWireless_SecCamera();
    default:                         return nullptr;
    }
}

std::shared_ptr<Device> DevicesHub::getSamsungDevice(DeviceID deviceID)
{
    switch (deviceID)
    {
    case DeviceID::LEDLight:         return SamsungFactory.getLED_Light();
    case DeviceID::HalogenLight:     return SamsungFactory.getHalogen_Light();
    case DeviceID::TypeAThermo:      return SamsungFactory.getTypeA_Thermostat();
    case DeviceID::TypeBThermo:      return SamsungFactory.getTypeB_Thermostat();
    case DeviceID::WiredSecCam:      return SamsungFactory.getWired_SecCamera();
    case DeviceID::WirelessSecCam:   return SamsungFactory.getWireless_SecCamera();
    default:                         return nullptr;
    }
}

std::shared_ptr<MotionSensor> DevicesHub::getMotionSensor()
{
    return mSensorFactory.createSensor();
}

std::shared_ptr<DoorLock> DevicesHub::getDoorLock()
{
    return dLockFactory.createDoorLock();
}
