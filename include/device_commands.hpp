#ifndef DEVICE_COMMANDS_HPP
#define DEVICE_COMMANDS_HPP

#include "device_groups.hpp"  // Needed for Device class

// ----- Command Interface -----
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// ----- Concrete Command: Turn On -----
class DeviceOnCommand : public Command {
private:
    shared_ptr<Device> device;
public:
    DeviceOnCommand(shared_ptr<Device> d);
    void execute() override;
};

// ----- Concrete Command: Turn Off -----
class DeviceOffCommand : public Command {
private:
    shared_ptr<Device> device;
public:
    DeviceOffCommand(shared_ptr<Device> d);
    void execute() override;
};

// ----- Invoker -----
class DeviceController {
private:
    shared_ptr<Command> command;
public:
    DeviceController();
    void setCommand(shared_ptr<Command> c);
    void startCommand();
};

#endif // DEVICE_COMMANDS_HPP
