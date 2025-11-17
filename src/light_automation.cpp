#include "devices.hpp"
#include "light_automation.hpp"

/* ---------------- Strategy Implementations ---------------- */

bool EnergySavingMode::decide() {
    // Example: auto on if energy usage is low
    return true;
}

bool ComfortMode::decide() {
    // Example: always on for comfort lighting
    return false;
}

/* ---------------- State Implementations ---------------- */

void LightOnState::handleOnPress(std::shared_ptr<Device> device) {
    // Already on, do nothing
}

void LightOnState::handleOffPress(std::shared_ptr<Device> device) {
    device->TurnOff();
    device->setState(std::make_shared<LightOffState>());
}

void LightOnState::handleDimCommand(std::shared_ptr<Device> dev) {
    auto device = dynamic_pointer_cast<Light>(dev);
    device->SetBrightness(50);
    device->setState(std::make_shared<LightDimmedState>());
}

/* ----- Dimmed State ----- */

void LightDimmedState::handleOnPress(std::shared_ptr<Device> dev) {
    auto device = dynamic_pointer_cast<Light>(dev);
    device->SetBrightness(100);
    device->setState(std::make_shared<LightOnState>());
}

void LightDimmedState::handleOffPress(std::shared_ptr<Device> dev) {
    auto device = dynamic_pointer_cast<Light>(dev);
    device->TurnOff();
    device->setState(std::make_shared<LightOffState>());
}

void LightDimmedState::handleDimCommand(std::shared_ptr<Device> device) {
    // Already dimmed, do nothing
}

/* ----- Off State ----- */

void LightOffState::handleOnPress(std::shared_ptr<Device> dev) {
    auto device = dynamic_pointer_cast<Light>(dev);
    device->SetBrightness(100);
    device->TurnOn();
    device->setState(std::make_shared<LightOnState>());
}

void LightOffState::handleOffPress(std::shared_ptr<Device> device) {
    // Already off, do nothing
}

void LightOffState::handleDimCommand(std::shared_ptr<Device> dev) {
    auto device = dynamic_pointer_cast<Light>(dev);
    device->SetBrightness(50);
    device->TurnOn();
    device->setState(std::make_shared<LightDimmedState>());
}

/* ---------------- State DP: Internal Device States ---------------- */

void DevOnState::handleOnPress(std::shared_ptr<Device> device) {
    // Already on, do nothing
}

void DevOnState::handleOffPress(std::shared_ptr<Device> device) {
    device->TurnOff();
    device->setState(std::make_shared<DevOffState>());
}


void DevOnState::handleDimCommand(std::shared_ptr<Device> device) {
    // Not applicable, do nothing
}

void DevOffState::handleOnPress(std::shared_ptr<Device> device) {
    device->TurnOn();
    device->setState(std::make_shared<DevOnState>());
}

void DevOffState::handleOffPress(std::shared_ptr<Device> device) {
    // Already off, do nothing
}

void DevOffState::handleDimCommand(std::shared_ptr<Device> device) {
    // Not applicable, do nothing
}