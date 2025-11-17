#include "device_groups.hpp"
using namespace std;

/* -------------------- Room Devices -------------------- */
RoomDevices::RoomDevices(const string& rName) : roomName(rName) {}

void RoomDevices::addDevice(shared_ptr<Device> device) {
    devices.push_back(device);
}

void RoomDevices::TurnOn() {
    cout << "Turning ON all Devices in Room: " << roomName << endl;
    for (auto& device : devices)
        device->stateExecute(stateCode::ON);
}

void RoomDevices::TurnOff() {
    cout << "Turning OFF all Devices in Room: " << roomName << endl;
    for (auto& device : devices)
        device->stateExecute(stateCode::OFF);
}

void RoomDevices::switchLights(bool on) {
    if(on)
        for(auto dev : devices){
            auto light = dynamic_pointer_cast<Light>(dev);
            if(light!=nullptr){
                dev->stateExecute(stateCode::ON);
            }
        }
    else
        for(auto dev : devices){
            auto light = dynamic_pointer_cast<Light>(dev);
            if(light!=nullptr){
                dev->stateExecute(stateCode::OFF);
            }
        }
}

string RoomDevices::getRoomName(){
    return roomName;
}

/* -------------------- Floor Devices -------------------- */
FloorDevices::FloorDevices(const string& fName) : floorName(fName) {}

void FloorDevices::addDevice(shared_ptr<Device> room) {
    rooms.push_back(room);
}

void FloorDevices::TurnOn() {
    cout << "Turning ON all Devices in Floor: " << floorName << endl;
    for (auto& room : rooms)
        room->stateExecute(stateCode::ON);
}

void FloorDevices::TurnOff() {
    cout << "Turning OFF all Devices in Floor: " << floorName << endl;
    for (auto& room : rooms)
        room->stateExecute(stateCode::OFF);
}

void FloorDevices::switchLights(bool on) {
    for(auto room : rooms){
        dynamic_pointer_cast<RoomDevices>(room)->switchLights(on);
    }
}

string FloorDevices::getFloorName(){
    return floorName;
}

/* -------------------- Lighting Group -------------------- */
void LightingGroup::addDevice(shared_ptr<Device> light) {
    lights.push_back(light);
}

void LightingGroup::TurnOn() {
    cout << "Turning ON all Lights" << endl;
    for (auto& light : lights)
        light->stateExecute(stateCode::ON);
}

void LightingGroup::TurnOff() {
    cout << "Turning OFF all Lights" << endl;
    for (auto& light : lights)
        light->stateExecute(stateCode::OFF);
}

/* -------------------- Security Group -------------------- */
void SecurityGroup::addDevice(shared_ptr<Device> secDevice) {
    securityDevices.push_back(secDevice);
}

void SecurityGroup::TurnOn() {
    cout << "Turning ON all Security Devices" << endl;
    for (auto& secDevice : securityDevices)
        secDevice->stateExecute(stateCode::ON);
}

void SecurityGroup::TurnOff() {
    cout << "Turning OFF all Security Devices" << endl;
    for (auto& secDevice : securityDevices)
        secDevice->stateExecute(stateCode::OFF);
}
