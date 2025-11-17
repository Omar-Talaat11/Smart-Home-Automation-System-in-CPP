#ifndef ADAPTER_HPP
#define ADAPTER_HPP

#include "devices.hpp"
#include <memory>
#include <vector>

/* ------------------- Adapter for External Door Lock Product - Adapter DP - ------------------- */
class TargetDoorLock  : public Device { // Target Interface
public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

class DoorLock : public TargetDoorLock { // Adapter
private:
    vector<shared_ptr<SecurityCamera>> observers;
    shared_ptr<DoorLockExternal> doorlock;
public:
    void TurnOn() override;
    void TurnOff() override;
    void lock() override;
    void unlock() override;
    void subscribe(shared_ptr<SecurityCamera> cam);
    void notify(bool locked);
};

#endif