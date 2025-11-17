#include "devices_adapter.hpp"


/* ------------------- Adapter for External Door Lock Product - Adapter DP - ------------------- */

void DoorLock::lock() {
    doorlock->lockExternal();
    this->notify(true); 
}

void DoorLock::unlock()  {
    doorlock->unlockExternal();   
    this->notify(false); 
}

void DoorLock::TurnOn() { unlock(); }
void DoorLock::TurnOff() { lock(); }

void DoorLock::subscribe(shared_ptr<SecurityCamera> cam) {
    observers.push_back(cam);
}

void DoorLock::notify(bool locked) {
    for(auto camera : observers) { camera->update(locked); }
}