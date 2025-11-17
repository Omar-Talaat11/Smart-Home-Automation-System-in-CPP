#ifndef LIGHT_MODES_HPP
#define LIGHT_MODES_HPP


#include <memory>

class Device;

/* ---------------- Strategy DP: Automation Modes ---------------- */

class LightMode {
public:
    virtual ~LightMode() = default;
    virtual bool decide() = 0; // true = turn on, false = stay off
};

class EnergySavingMode : public LightMode {
public:
    bool decide() override;
};

class ComfortMode : public LightMode {
public:
    bool decide() override;
};

/* ---------------- State DP: Internal Light States ---------------- */

enum class stateCode {
    ON,
    OFF,
    DIMMED
};

class State {
public:
    virtual ~State() = default;
    virtual void handleOnPress(std::shared_ptr<Device> device) = 0;
    virtual void handleOffPress(std::shared_ptr<Device> device) = 0;
    virtual void handleDimCommand(std::shared_ptr<Device> device) = 0;
};

class LightOnState : public State {
public:
    void handleOnPress(std::shared_ptr<Device> device) override;
    void handleOffPress(std::shared_ptr<Device> device) override;
    void handleDimCommand(std::shared_ptr<Device> device) override;
};

class LightDimmedState : public State {
public:
    void handleOnPress(std::shared_ptr<Device> device) override;
    void handleOffPress(std::shared_ptr<Device> device) override;
    void handleDimCommand(std::shared_ptr<Device> device) override;
};

class LightOffState : public State {
public:
    void handleOnPress(std::shared_ptr<Device> device) override;
    void handleOffPress(std::shared_ptr<Device> device) override;
    void handleDimCommand(std::shared_ptr<Device> device) override;
};

/* ---------------- State DP: Internal Device States ---------------- */


class DevOnState : public State {
public:
    void handleOnPress(std::shared_ptr<Device> device) override;
    void handleOffPress(std::shared_ptr<Device> device) override;
    void handleDimCommand(std::shared_ptr<Device> device) override;
};

class DevOffState : public State {
public:
    void handleOnPress(std::shared_ptr<Device> device) override;
    void handleOffPress(std::shared_ptr<Device> device) override;
    void handleDimCommand(std::shared_ptr<Device> device) override;
};

#endif // LIGHT_MODES_HPP


