#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include "devices.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

/* -------------------- Room Devices  - Composite DP -------------------- */
class RoomDevices : public Device {
private:
    string roomName;
    vector<shared_ptr<Device>> devices;
public:
    explicit RoomDevices(const string& rName);
    void addDevice(shared_ptr<Device> device);
    void TurnOn() override;
    void TurnOff() override;
    void switchLights(bool on);
    string getRoomName();
};

/* -------------------- Floor Devices  - Composite DP -------------------- */
class FloorDevices : public Device {
private:
    string floorName;
    vector<shared_ptr<Device>> rooms;
public:
    explicit FloorDevices(const string& fName);
    void addDevice(shared_ptr<Device> room);
    void TurnOn() override;
    void TurnOff() override;
    void switchLights(bool on);
    string getFloorName();
};

/* -------------------- Lighting Group  - Composite DP -------------------- */
class LightingGroup : public Device {
private:
    vector<shared_ptr<Device>> lights;
public:
    void addDevice(shared_ptr<Device> light);
    void TurnOn() override;
    void TurnOff() override;
};

/* -------------------- Security Group  - Composite DP -------------------- */
class SecurityGroup : public Device {
private:
    vector<shared_ptr<Device>> securityDevices;
public:
    void addDevice(shared_ptr<Device> secDevice);
    void TurnOn() override;
    void TurnOff() override;
};

#endif // COMPOSITE_HPP
