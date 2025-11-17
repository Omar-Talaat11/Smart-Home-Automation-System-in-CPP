#include "device_commands.hpp"

// ----- DeviceOnCommand -----
DeviceOnCommand::DeviceOnCommand(shared_ptr<Device> d) : device(d) {}

void DeviceOnCommand::execute() {
    device->stateExecute(stateCode::ON);
}

// ----- DeviceOffCommand -----
DeviceOffCommand::DeviceOffCommand(shared_ptr<Device> d) : device(d) {}

void DeviceOffCommand::execute() {
    device->stateExecute(stateCode::OFF);
}

// ----- DeviceController -----
DeviceController::DeviceController() : command(nullptr) {}

void DeviceController::setCommand(shared_ptr<Command> c) {
    command = c;
}

void DeviceController::startCommand() {
    if (command)
        command->execute();
}

