#ifndef DEVICES_HUB_HPP
#define DEVICES_HUB_HPP

#include "devices_factory.hpp"
#include <memory>

enum class DeviceID {
    LEDLight,
    HalogenLight,
    TypeAThermo,
    TypeBThermo,
    WiredSecCam,
    WirelessSecCam
};

class DevicesHub {
private:
    Smart_LG_DeviceFactory LgFactory;
    Smart_Samsung_DeviceFactory SamsungFactory;
    MotionSensorFactory mSensorFactory;
    DoorLockFactory dLockFactory;

    static std::shared_ptr<DevicesHub> hubInstance;
    DevicesHub(); // private constructor

public:
    static std::shared_ptr<DevicesHub> getInstance();

    std::shared_ptr<Device> getLGDevice(DeviceID deviceID);
    std::shared_ptr<Device> getSamsungDevice(DeviceID deviceID);
    std::shared_ptr<MotionSensor> getMotionSensor();
    std::shared_ptr<DoorLock> getDoorLock();
};

#endif // DEVICES_HUB_HPP
