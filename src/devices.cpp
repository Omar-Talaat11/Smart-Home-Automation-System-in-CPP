#include "devices.hpp"

Device::Device() : state(make_shared<DevOffState>()) {}
Device::Device(shared_ptr<State> s) : state(s){}

void Device::setState(shared_ptr<State> s) { state = s; }
void Device::stateExecute(stateCode s)
{
    if(s==stateCode::ON)       state->handleOnPress(shared_from_this());
    else if(s==stateCode::OFF)  state->handleOffPress(shared_from_this());
}

/* ------------------- Light Implementations ------------------- */

Light::Light() : Device(make_shared<LightOffState>()) {}

void Light::stateExecute(stateCode s)
{
    if(s==stateCode::ON)       state->handleOnPress(shared_from_this());
    else if(s==stateCode::OFF)  state->handleOffPress(shared_from_this());    
    else if(s==stateCode::DIMMED)  state->handleDimCommand(shared_from_this()); 
}

void Light::SetBrightness(char br) { brightness = br; }

void Light::update(bool on) {
    if(on) {
        state->handleOnPress((shared_from_this()));
    }
    else {
        if(mode->decide())
        {
            state->handleDimCommand(shared_from_this());
        }
    }
}

void Light::setMode(shared_ptr<LightMode> m) {
    mode = m;
}



/* LG Lights */
void LG_LED_Light::TurnOn() {  cout << "LG LED Light is On with brightness = " << brightness << " %" << endl; }
void LG_LED_Light::TurnOff() { cout << "LG LED Light is Off" << endl; }

void LG_Halogen_Light::TurnOn() { cout << "LG Halogen Light On with brightness = " << brightness << " %"  << endl; }
void LG_Halogen_Light::TurnOff() { cout << "LG Halogen Light is Off" << endl; }

/* Samsung Lights */
void Samsung_LED_Light::TurnOn() { cout << "Samsung LED Light is On with brightness = " << brightness << " %"  << endl; }
void Samsung_LED_Light::TurnOff() { cout << "Samsung LED Light is Off" << endl; }

void Samsung_Halogen_Light::TurnOn() { cout << "Samsung Halogen Light is On with brightness = " << brightness << " %"  << endl; }
void Samsung_Halogen_Light::TurnOff() { cout << "Samsung Halogen Light is Off" << endl; }

/* ------------------- Thermostat Implementations ------------------- */

void Thermostat::SetTemperature(char temp) { temperature = temp; }
void Thermostat::TurnOn() { cout << "Thermostat Turned On with temperature = " << temperature << endl; }
void Thermostat::TurnOff() { cout << "Thermostat Turned Off" << endl; }

void Thermostat::measureCurrentTemp(int cTemp){
    if(cTemp >= temperature)
    {
        cout << "Current Temperature ( "<< cTemp <<" ) is higher than needed Temperature ( "<< temperature <<" ) , Shuting Thermostat off" << endl;
        this->stateExecute(stateCode::OFF);
    }
    else
    {
        cout << "Current Temperature ( "<< cTemp <<" ) is lower than needed Temperature ( "<< temperature <<" ) , Increasing Thermostat heating" << endl;
        this->stateExecute(stateCode::ON);
    }
}

/* LG Thermostats */
void LG_TypeA_Thermostat::SetMode(string mode) {
    cout << "LG Type (A) Thermostat mode is : " << mode
         << ", with setting temperature = " << temperature << endl;
}

void LG_TypeB_Thermostat::SetMode(string mode) {
    cout << "LG Type (B) Thermostat mode is : " << mode
         << ", with setting temperature = " << temperature << endl;
}

/* Samsung Thermostats */
void Samsung_TypeA_Thermostat::SetMode(string mode) {
    cout << "Samsung Type (A) Thermostat mode is : " << mode
         << ", with setting temperature = " << temperature  << endl;
}

void Samsung_TypeB_Thermostat::SetMode(string mode) {
    cout << "Samsung Type (B) Thermostat mode is : " << mode
         << ", with setting temperature = " << temperature << endl;
}

/* ------------------- Security Camera Implementations ------------------- */

void SecurityCamera::switchNightVision(bool nVision) { night_vision = nVision; }
void SecurityCamera::TurnOn() { 
    if(state==false) {
        cout << "Security Camera Turned On" << endl;
        state = true;
    } 
}
void SecurityCamera::TurnOff() { 
    if(state==true) {
    cout << "Security Camera Turned Off" << endl; 
    state = false;
    securityState = false; 
    }
}
void SecurityCamera::update(bool locked) { 
    if(locked)                                  
    {
        this->stateExecute(stateCode::ON);
        securityState = true;
    }
    else if(!locked && securityState == false)  this->stateExecute(stateCode::OFF);
    else 
    {
        this->stateExecute(stateCode::ON);
        cout << "Potential threat!! Alert is being sent" << endl;
    }
} // Turn on observing cameras automatically when doors are locked or unlocked

/* LG Cameras */
void LG_Wired_SecurityCamera::switchOpMode(string mode) {
    cout << "LG Wired Security Camera is : " << mode
         << ", with night mode temperature = " << boolalpha << night_vision << endl;
}

void LG_Wireless_SecurityCamera::switchOpMode(string mode) {
    cout << "LG Wireless Security Camera is : " << mode
         << ", with night mode temperature = " << boolalpha << night_vision << endl;
}

/* Samsung Cameras */
void Samsung_Wired_SecurityCamera::switchOpMode(string mode) {
    cout << "Samsung Wired Security Camera is : " << mode
         << ", with night mode temperature = " << boolalpha << night_vision << endl;
}

void Samsung_Wireless_SecurityCamera::switchOpMode(string mode) {
    cout << "Samsung Wireless Security Camera is : " << mode
         << ", with night mode temperature = " << boolalpha << night_vision << endl;
}

/* ------------------- External Door Lock Product - Adapter DP - ------------------- */
void DoorLockExternal::lockExternal() {
    cout << "Door is Locked" << endl;
}

void DoorLockExternal::unlockExternal() {
    cout << "Door is Unlocked" << endl;
}

/* ------------------- Motion Sensor ------------------- */
void MotionSensor::TurnOn() {
    cout << "Motion sensor is On" << endl;
}
void MotionSensor::TurnOff() {
    cout << "Motion sensor is Off" << endl;
}
void MotionSensor::subscribe(shared_ptr<Light> light) {
    observers.push_back(light);
}

void MotionSensor::notify(bool on) {
    if(on)  cout << "Motion Sensor Detected Movement" << endl;
    else    cout << "Motion Sensor doesn't detect any Movement" << endl;
    for(auto light : observers) { light->update(on); }
}
