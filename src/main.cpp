#include <iostream>
#include "devices_factory.hpp"
#include "devices_adapter.hpp"
#include "devices_facade.hpp"
#include "device_commands.hpp"
#include "devices_hub.hpp"

using namespace std;

void case1();
void case2();
void case3();
void case4();
void case5();
void case6();
void runCases();

/*
    Create House Devices, Rooms & Floors
*/
auto create_my_house()
{
    auto Facade = make_shared<DevicesFacade>();

    /* Create First Room -> 2 Lights, 1 Thermostat, 1 DoorLock, 1 Motion Sensor, 2 Security Cameras */
    auto roomGroup1 = make_shared<RoomDevices>("Bed Room");
    auto light1 = Facade->getLight(Brand::LG,LightType::LED,roomGroup1);
    auto light2 = Facade->getLight(Brand::SAMSUNG,LightType::Halogen,roomGroup1);
    auto thermostat = Facade->getThermostat(Brand::LG,ThermostatType::TypeB,roomGroup1);
    auto dLock = Facade->getDoorLock(roomGroup1);
    auto mSensor = Facade->getMotionSensor(roomGroup1);
    auto secCamera1 = Facade->getCamera(Brand::LG,CameraType::Wireless,roomGroup1);
    auto secCamera2 = Facade->getCamera(Brand::LG,CameraType::Wireless,roomGroup1);

    /* Create RelationShips between Room Devices */
    mSensor->subscribe(light1);
    mSensor->subscribe(light2);
    dLock->subscribe(secCamera1);
    dLock->subscribe(secCamera2);

    Facade->addRoom(roomGroup1);

    /* Create Second Room -> 2 Lights, 1 Thermostat, 1 DoorLock, 1 Motion Sensor, 2 Security Cameras */
    auto roomGroup2 = make_shared<RoomDevices>("Main Room");
    light1 = Facade->getLight(Brand::LG,LightType::LED,roomGroup2);
    light2 = Facade->getLight(Brand::SAMSUNG,LightType::Halogen,roomGroup2);
    thermostat = Facade->getThermostat(Brand::LG,ThermostatType::TypeB,roomGroup1);
    dLock = Facade->getDoorLock(roomGroup2);
    mSensor = Facade->getMotionSensor(roomGroup2);
    secCamera1 = Facade->getCamera(Brand::LG,CameraType::Wireless,roomGroup2);
    secCamera2 = Facade->getCamera(Brand::LG,CameraType::Wireless,roomGroup2);

    /* Create RelationShips between Room Devices */
    mSensor->subscribe(light1);
    mSensor->subscribe(light2);
    dLock->subscribe(secCamera1);
    dLock->subscribe(secCamera2);

    Facade->addRoom(roomGroup2);

    /* Create Third Room -> 3 Lights, 1 Motion Sensor, 2 Security Cameras */
    auto roomGroup3 = make_shared<RoomDevices>("Hall Way");
    light1 = Facade->getLight(Brand::LG,LightType::LED,roomGroup3);
    light2 = Facade->getLight(Brand::SAMSUNG,LightType::Halogen,roomGroup3);
    auto light3 = Facade->getLight(Brand::SAMSUNG,LightType::Halogen,roomGroup3);
    mSensor = Facade->getMotionSensor(roomGroup3);
    secCamera1 = Facade->getCamera(Brand::LG,CameraType::Wireless,roomGroup3);
    secCamera2 = Facade->getCamera(Brand::LG,CameraType::Wireless,roomGroup3);

    /* Create RelationShips between Room Devices */
    mSensor->subscribe(light1);
    mSensor->subscribe(light2);

    Facade->addRoom(roomGroup3);

    /* Create the Floor */
    auto floor = make_shared<FloorDevices>("My Floor");
    floor->addDevice(roomGroup1);
    floor->addDevice(roomGroup2);
    floor->addDevice(roomGroup3);

    Facade->addFloor(floor);

    return Facade;
}





int main()
{
    // auto house = create_my_house();
    // house->Switch_AllLights(true);
    // house->Switch_AllLights(false);
    // house->Switch_RoomLights("Bed Room",true);

    runCases();
}




void runCases()
{
    cout << "--------------------------------------------\n";
    cout << " Welcome to Smart Home Automation System\n";
    cout << " Developed by -- Omar Talaat --\n";
    cout << "--------------------------------------------\n\n";

    cout << "We have 6 test case scenarios that you can use to test the project.\n";
    while (true)
    {
        cout << "\nPlease enter a number from 1 to 6 (or 0 to exit): ";

        string ch;
        cin >> ch;

        int choice;
        try {
            choice = stoi(ch);
        } catch (...) {
            cout << "Invalid input! Please enter a number between 0 and 6.\n";
            continue;;
        }

        switch (choice)
        {
        case 0:
            cout << "Exiting program. Goodbye!\n";
            return;
        case 1:
            cout << "\n--- Running Test Case 1 ---\n";
            case1();
            break;
        case 2:
            cout << "\n--- Running Test Case 2 ---\n";
            case2();
            break;
        case 3:
            cout << "\n--- Running Test Case 3 ---\n";
            case3();
            break;
        case 4:
            cout << "\n--- Running Test Case 4 ---\n";
            case4();
            break;
        case 5:
            cout << "\n--- Running Test Case 5 ---\n";
            case5();
            break;
        case 6:
            cout << "\n--- Running Test Case 6 ---\n";
            case6();
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 6.\n";
            break;
        }
    }

    cout << "\n--------------------------------------------\n";
    cout << "Program finished.\n";
    cout << "--------------------------------------------\n";
}

void case1() /* Motion Sensor detects movement in the hallway at night, it automatically turns ON the light*/
{
    cout << "\nSenario 1 : Motion Sensor detects movement in the hallway at night, it automatically turns ON the light\n" << endl;
    DevicesFacade facade;

    auto light = facade.getLight(Brand::LG,LightType::LED);
    auto msensor = facade.getMotionSensor();

    msensor->subscribe(light);
    msensor->notify(true);
}

void case2() /* thermostat detects that the temperature is below the target, it sends a signal to the heating system to increase heat */
{
    cout << "\nSenario 2 :thermostat detects that the temperature is below the target, it sends a signal to the heating system to increase heat \n" << endl;
    DevicesFacade facade;


    auto thermo = facade.getThermostat(Brand::SAMSUNG,ThermostatType::TypeB);
    thermo->SetTemperature(38);
    thermo->measureCurrentTemp(37);
}

void case3() /* door lock is unlocked unexpectedly while the security system is armed, the security camera starts recording and sends an alert notification */
{
    cout << "\nSenario 3 : door lock is unlocked unexpectedly while the security system is armed, the security camera starts recording and sends an alert notification\n" << endl;
    DevicesFacade facade;

    auto dLock = facade.getDoorLock();
    auto secCam =  facade.getCamera(Brand::LG,CameraType::Wireless);
    dLock->subscribe(secCam);
    dLock->lock();
    dLock->unlock();
}

void case4() /* user command to turn OFF all bedroom lights can be sent as an object, executed immediately or queued, and undone if needed */
{
    cout << "\nSenario 4 : user command to turn OFF all bedroom lights can be sent as an object, executed immediately or queued, and undone if needed\n" << endl;
    DevicesFacade facade;

    auto BedRoom = make_shared<RoomDevices>("Bed Room");
    auto light1 = facade.getLight(Brand::LG,LightType::LED,BedRoom);
    auto light2 = facade.getLight(Brand::SAMSUNG,LightType::Halogen,BedRoom);

    light1->SetBrightness(100);
    light2->SetBrightness(100);

    DeviceOnCommand onCommand(BedRoom);

    DeviceController controller;
    controller.setCommand(make_shared<DeviceOnCommand>(BedRoom));

    string choice;
    /* Command is Created */
    while(true)
    {
        cout<< "On Command is created, Now choose to: " << endl;
        cout<< "1. Execute now" << endl;
        cout<< "2. Queue and keep waiting" << endl;
        cout<< "3. Undone" << endl;
        cout<< "Your Choice: ";
        cin>>choice;

        if     (choice=="1") break;
        else if(choice=="2") continue;
        else if(choice=="3") return;
        else cout<<"Incorrect Choice, Try again now" << endl;
    }
    controller.startCommand();
}

void case5() /* The system can switch between "Energy Saving Mode" and "Comfort Mode":
o In Energy Saving Mode, lights dim or turn off automatically when rooms are unoccupied.
o In Comfort Mode, lights maintain preset brightness and temperature preferences. */
{
    cout << "\nSenario 5 : the system can switch between Energy Saving Mode and Comfort Mode" << endl;

    string choice;
    shared_ptr<LightMode> mode;
    DevicesFacade facade;
    
    auto light1 = facade.getLight(Brand::LG,LightType::LED);
    auto light2 = facade.getLight(Brand::SAMSUNG,LightType::Halogen);

    auto mSensor = facade.getMotionSensor();
    
    mSensor->subscribe(light1);
    mSensor->subscribe(light2);

    while(true){

        cout<< "Choose Which Mode to work with: " << endl;
        cout<< "1. Comfort Mode" << endl;
        cout<< "2. Energy Saving Mode" << endl;
        cout<< "Your Choice: ";
        cin>>choice;

        if      (choice == "1") {mode = make_shared<ComfortMode>();         break;}
        else if (choice == "2") {mode = make_shared<EnergySavingMode>();    break;}
        else {
            cout << "Incorrect choice, Please try again" << endl;
        }
    }

    light1->setMode(mode);
    light2->setMode(mode);

    mSensor->notify(false);
}

void case6() /* A light might have states like OFF, ON, and DIMMED, and smoothly transition between these based on commands or automation logic */
{
    cout << "\nSenario 6 : A light might have states like OFF, ON, and DIMMED, and smoothly transition between these\n" << endl;
    DevicesFacade facade;
    
    auto light1 = facade.getLight(Brand::LG,LightType::LED);

    string choice;
    shared_ptr<LightMode> mode;
    cout << "Light current state is Off" << endl;
    while(true) {
        cout << "Choose next State (1 = ON , 2 = OFF , 3 = DIMMED) or 0 to end : ";
        cin >> choice;
        if      (choice == "0") break;

        else if (choice == "1") {
            light1->stateExecute(stateCode::ON);
            cout << "Light current state is On" << endl;
        }
        else if (choice == "2") {
            light1->stateExecute(stateCode::OFF);
            cout << "Light current state is Off" << endl;
        }
        else if (choice == "3") {
            light1->stateExecute(stateCode::DIMMED);
            cout << "Light current state is Dimmed" << endl;
        }
        else {
            cout << "Incorrect Choice, try again" << endl;
            continue;
        }
    }
}