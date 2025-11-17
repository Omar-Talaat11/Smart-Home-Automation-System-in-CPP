#ifndef DEVICES_FACADE_HPP
#define DEVICES_FACADE_HPP

#include <memory>
#include "devices_factory.hpp"
#include "devices_hub.hpp"
#include "device_groups.hpp"
#include "device_commands.hpp"

enum class Brand {
    LG,
    SAMSUNG
};

enum class LightType {
    LED,
    Halogen
};

enum class ThermostatType {
    TypaA,
    TypeB
};

enum class CameraType {
    Wireless,
    Wired
};

class DevicesFacade {
private:
    std::shared_ptr<DevicesHub> myHub;
    vector<shared_ptr<Device>> HouseDevices;
    vector<shared_ptr<RoomDevices>> Rooms;
    vector<shared_ptr<FloorDevices>> Floors;
    shared_ptr<LightingGroup> lightGroup;
    shared_ptr<SecurityGroup> secGroup;
    shared_ptr<DeviceController> Controller;

public:
    DevicesFacade();
    std::shared_ptr<Light> getLight(Brand brand, LightType type,shared_ptr<RoomDevices> roomGroup=nullptr);
    std::shared_ptr<Thermostat> getThermostat(Brand brand, ThermostatType type,shared_ptr<RoomDevices> roomGroup=nullptr);
    std::shared_ptr<SecurityCamera> getCamera(Brand brand, CameraType type,shared_ptr<RoomDevices> roomGroup=nullptr);
    std::shared_ptr<MotionSensor> getMotionSensor(shared_ptr<RoomDevices> roomGroup=nullptr);
    std::shared_ptr<DoorLock> getDoorLock(shared_ptr<RoomDevices> roomGroup=nullptr);
    void addRoom(shared_ptr<RoomDevices> room);
    void addFloor(shared_ptr<FloorDevices> room);

    void Switch_AllLights(bool on);
    void Switch_RoomDevices(string roomName, bool on);
    void Switch_Security(bool on);
    void Switch_RoomLights(string roomName, bool on);
};

#endif // DEVICES_FACADE_HPP
