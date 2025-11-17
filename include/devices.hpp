#ifndef SMARTDEVICES_HPP
#define SMARTDEVICES_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "light_automation.hpp"

using namespace std;

class Device : public std::enable_shared_from_this<Device> { // Interface for all devices
protected:
    shared_ptr<State> state;
public:
    Device();
    Device(shared_ptr<State> s);
    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
    void setState(shared_ptr<State> s);
    virtual void stateExecute(stateCode s);
};

/* ------------------- Light Products ------------------- */

class Light : public Device { // Interface for all Light Brands
protected:
    shared_ptr<LightMode> mode;
    int brightness;
public:
    Light();
    virtual ~Light() = default;
    virtual void update(bool on);
    void SetBrightness(char br);
    void setMode(shared_ptr<LightMode> m);
    void stateExecute(stateCode s) override;
};

/* LG Light Variants */
class LG_LED_Light : public Light {
public:
    void TurnOn() override;
    void TurnOff() override;
};

class LG_Halogen_Light : public Light {
public:
    void TurnOn() override;
    void TurnOff() override;
};

/* Samsung Light Variants */
class Samsung_LED_Light : public Light {
public:
    void TurnOn() override;
    void TurnOff() override;
};

class Samsung_Halogen_Light : public Light {
public:
    void TurnOn() override;
    void TurnOff() override;
};

/* ------------------- Thermostat Products ------------------- */

class Thermostat : public Device{ // Interface for all Thermostat Brands
protected:
    int temperature;
public:
    virtual ~Thermostat() = default;
    virtual void SetMode(string mode) = 0;
    void SetTemperature(char temp);
    void TurnOn() override;
    void TurnOff() override;

    void measureCurrentTemp(int cTemp);
};

/* LG Thermostat Variants */
class LG_TypeA_Thermostat : public Thermostat {
public:
    void SetMode(string mode) override;
};

class LG_TypeB_Thermostat : public Thermostat {
public:
    void SetMode(string mode) override;
};

/* Samsung Thermostat Variants */
class Samsung_TypeA_Thermostat : public Thermostat {
public:
    void SetMode(string mode) override;
};

class Samsung_TypeB_Thermostat : public Thermostat {
public:
    void SetMode(string mode) override;
};

/* ------------------- Security Camera Products ------------------- */

class SecurityCamera : public Device { // Interface for all Security Cameras Brands
protected:
    bool state;
    bool securityState;
    bool night_vision;
public:
    virtual ~SecurityCamera() = default;
    virtual void switchOpMode(string mode) = 0;
    void switchNightVision(bool nVision);
    void TurnOn() override;
    void TurnOff() override;
    void update(bool locked); // Observer Update Method
};

/* LG SecurityCamera Variants */
class LG_Wired_SecurityCamera : public SecurityCamera {
public:
    void switchOpMode(string mode) override;
};

class LG_Wireless_SecurityCamera : public SecurityCamera {
public:
    void switchOpMode(string mode) override;
};

/* Samsung SecurityCamera Variants */
class Samsung_Wired_SecurityCamera : public SecurityCamera {
public:
    void switchOpMode(string mode) override;
};

class Samsung_Wireless_SecurityCamera : public SecurityCamera {
public:
    void switchOpMode(string mode) override;
};


/* ------------------- External Door Lock Product - Adapter DP - ------------------- */
class DoorLockExternal {
public:
    void lockExternal();
    void unlockExternal();
};

/* ------------------- Motion Sensor ------------------- */
class MotionSensor : public Device { 
private:
    vector<shared_ptr<Light>> observers;
public:
    void TurnOn() override;
    void TurnOff() override;
    void subscribe(shared_ptr<Light> light);
    void notify(bool on);
};
#endif // SMARTDEVICES_HPP
