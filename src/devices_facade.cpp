#include "devices_facade.hpp"
#include <memory>

using namespace std;

DevicesFacade::DevicesFacade():
myHub(DevicesHub::getInstance()),
lightGroup(make_shared<LightingGroup>()),
secGroup(make_shared<SecurityGroup>()),
Controller(make_shared<DeviceController>())
{}


std::shared_ptr<Light> DevicesFacade::getLight(Brand brand, LightType type,shared_ptr<RoomDevices> roomGroup)
{
    shared_ptr<Light> light;
    DeviceID id;
    if(type == LightType::LED)  id = DeviceID::LEDLight;
    else                        id = DeviceID::HalogenLight;

    if(brand == Brand::LG)      light =  dynamic_pointer_cast<Light>(myHub->getLGDevice(id));
    else                        light = dynamic_pointer_cast<Light>(myHub->getSamsungDevice(id));

    if(roomGroup != nullptr)    roomGroup->addDevice(light);
    
    lightGroup->addDevice(light);
    HouseDevices.push_back(light);
    return light;
}


std::shared_ptr<Thermostat> DevicesFacade::getThermostat(Brand brand, ThermostatType type,shared_ptr<RoomDevices> roomGroup)
{
    shared_ptr<Thermostat> thermo;
    DeviceID id;
    if(type == ThermostatType::TypaA)  id = DeviceID::TypeAThermo;
    else                               id = DeviceID::TypeBThermo;

    if(brand == Brand::LG)      thermo = dynamic_pointer_cast<Thermostat>(myHub->getLGDevice(id));
    else                        thermo = dynamic_pointer_cast<Thermostat>(myHub->getSamsungDevice(id));

    if(roomGroup != nullptr)    roomGroup->addDevice(thermo);
    
    HouseDevices.push_back(thermo);
    return thermo;
}

std::shared_ptr<SecurityCamera> DevicesFacade::getCamera(Brand brand, CameraType type,shared_ptr<RoomDevices> roomGroup)
{
    shared_ptr<SecurityCamera> cam;
    DeviceID id;
    if(type == CameraType::Wired)      id = DeviceID::WiredSecCam;
    else                               id = DeviceID::WirelessSecCam;

    if(brand == Brand::LG)      cam = dynamic_pointer_cast<SecurityCamera>(myHub->getLGDevice(id));
    else                        cam = dynamic_pointer_cast<SecurityCamera>(myHub->getSamsungDevice(id));

    if(roomGroup != nullptr)    roomGroup->addDevice(cam);
    
    secGroup->addDevice(cam);
    HouseDevices.push_back(cam);

    return cam;
}

std::shared_ptr<MotionSensor> DevicesFacade::getMotionSensor(shared_ptr<RoomDevices> roomGroup)
{
    shared_ptr<MotionSensor> sensor;
    sensor = myHub->getMotionSensor();
    
    if(roomGroup != nullptr)    roomGroup->addDevice(sensor);

    HouseDevices.push_back(sensor);
    return sensor;
}

std::shared_ptr<DoorLock> DevicesFacade::getDoorLock(shared_ptr<RoomDevices> roomGroup)
{
    shared_ptr<DoorLock> dLock;
    dLock = myHub->getDoorLock();
    
    if(roomGroup != nullptr)    roomGroup->addDevice(dLock);

    secGroup->addDevice(dLock);
    HouseDevices.push_back(dLock);

    return dLock;
}

void DevicesFacade::addRoom(shared_ptr<RoomDevices> room){
    Rooms.push_back(room);
}

void DevicesFacade::addFloor(shared_ptr<FloorDevices> floor){
    Floors.push_back(floor);
}

void DevicesFacade::Switch_AllLights(bool on) {
    if(on){
        cout << "-- Turning On All House Lights: --\n";

        shared_ptr<Command> c = make_shared<DeviceOnCommand>(lightGroup);
        Controller->setCommand(c);
        Controller->startCommand();

        cout << "-- All House Lights are turned on --\n";
    }
    else {
        cout << "-- Turning Off All House Lights: --\n";
        shared_ptr<Command> c = make_shared<DeviceOffCommand>(lightGroup);
        Controller->setCommand(c);
        Controller->startCommand();
        cout << "-- All House Lights are turned off --\n";
    }
}

void DevicesFacade::Switch_RoomDevices(string roomName, bool on){
    if(on)
        for(auto room : Rooms)
        {
            if(roomName==room->getRoomName()) {
                cout << "-- Turning On " <<roomName<<" Devices: --\n";

                shared_ptr<Command> c = make_shared<DeviceOnCommand>(room);
                Controller->setCommand(c);
                Controller->startCommand();

                cout << "-- All Room Devices are turned On --\n";
                return;
            }
        }
    else
        for(auto room : Rooms)
        {
            if(roomName==room->getRoomName()) {
                cout << "-- Turning Off " <<roomName<<" Devices: --\n";

                shared_ptr<Command> c = make_shared<DeviceOffCommand>(room);
                Controller->setCommand(c);
                Controller->startCommand();

                cout << "-- All Room Devices are turned off --\n";
                return;
            }
        }
    cout << "-- Room Name is Invalid --\n";
}

void DevicesFacade::Switch_Security(bool on){
    if(on){
        cout << "-- Turning On All House Security: --\n";

        shared_ptr<Command> c = make_shared<DeviceOnCommand>(secGroup);
        Controller->setCommand(c);
        Controller->startCommand();

        cout << "-- All House Security are turned on --\n";
    }
    else {
        cout << "-- Turning Off All House Security: --\n";

        shared_ptr<Command> c = make_shared<DeviceOffCommand>(secGroup);
        Controller->setCommand(c);
        Controller->startCommand();

        cout << "-- All House Security are turned off --\n";
    }
}

void DevicesFacade::Switch_RoomLights(string roomName, bool on){
    for(auto room : Rooms)
    {
        if(roomName==room->getRoomName()) {
            cout << "-- Turning On " <<roomName<<" Lights: --\n";
            room->switchLights(on);
            cout << "-- All Room Lights are turned On --\n";
            return;
        }
    }
    
    cout << "-- Room Name is Invalid --\n";
}