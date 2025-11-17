# Smart Home Automation System in C++ (Application for Design Patterns)

## 📌 Overview

The **Smart Home Automation System** is a modular C++ project designed to simulate a modern smart home environment. It demonstrates architecture-focused software design using multiple **Creational, Structural, and Behavioral Design Patterns**.

The system manages a variety of devices—including lights, thermostats, security cameras, door locks, and motion sensors—while supporting:

* Dynamic device creation
* Room/zone grouping
* Device interaction
* Automation modes
* Undoable commands
* State-based device behavior

This project showcases clean OOP architecture and pattern-driven design.

---

## 🚀 Features

### Device Creation & Management

* Create multiple device families (LEDLight, HalogenLight, SmartThermostatA/B, Wired/WirelessCamera).
* Support new brands/models without modifying system core (Abstract Factory).
* Centralized device controller using **Singleton**.

### Device Grouping

* Organize devices by rooms, floors, or functional groups.
* Apply actions to:

  * a single device
  * a group of devices
  * the entire system
* Implemented using the **Composite Pattern**.

### Interaction & Automation

* Devices communicate changes automatically (**Observer Pattern**).
* User/automation actions represented as objects (**Command Pattern**).
* Undo operations supported.
* Automation modes switched at runtime using **Strategy Pattern**.
* Devices transition between internal states using **State Pattern**.

### Simplified Control

* Unified API through **Facade Pattern**.
* Integrate legacy devices using **Adapter Pattern**.

---

## 📦 Project Directory Structure

```
.
├── CMakeLists.txt
├── build/
├── include/
│   ├── (all header files)
│   └── ...
└── src/
    ├── main.cpp
    ├── devices/
    ├── (all source files)
    └── ...
└── docs/
    └── Design Patterns Documentation.pdf
```

---

## 🧩 Implemented Devices

### Light

* ON, OFF, DIM brightness
* LED, Halogen
* Multiple brands supported

### Thermostat

* Set temperature
* Heating/Cooling/Off modes
* Variants: Type A, Type B

### Security Camera

* Record / Stop
* Night vision
* Wired/Wireless versions

### Door Lock

* Lock / Unlock
* Sends status updates
* Supports external/legacy locks (via Adapter)

### Motion Sensor

* Detect movement
* Triggers actions (e.g., turn on lights)

---

## 🏠 Device Grouping Examples

### By Room

* LivingRoomGroup
* BedroomGroup
* KitchenGroup

### By Floor

* FirstFloorGroup
* SecondFloorGroup

### By Function

* LightingGroup
* SecurityGroup

Examples of operations:

* Turn OFF all bedroom lights
* Start recording on all security devices on the second floor

---

## ⚙️ Build Instructions (CMake)

From the project root:

```bash
mkdir build
cd build
cmake ..
make
```

Run the program:

```bash
./SmartHome
```

---

## 📚 Design Patterns Overview

### 1. Creational Patterns

#### Abstract Factory

Creates families of related devices (lights, thermostats, cameras).

#### Factory Method

Used for devices with single families such as DoorLock and MotionSensor.

#### Singleton

Centralized **DevicesHub** managing all devices.

---

### 2. Structural Patterns

#### Composite

Uniform operations on individual devices and groups.

#### Adapter

Integrates external classes such as legacy door locks.

#### Facade

Provides simplified unified access to complex subsystems.

---

### 3. Behavioral Patterns

#### Observer

Enables automatic interactions (e.g., MotionSensor → Light).

#### Command

Represents executable, queueable, and undoable actions.

#### Strategy

Switch automation modes at runtime (Energy Saving, Comfort).

#### State

Manages internal device states like ON, OFF, DIMMED.

---

## 📄 Documentation
Detailed explanation of all implemented design patterns is available in the PDF:

[Design Patterns Documentation](docs/DesignPatternsDocumentation.pdf)
