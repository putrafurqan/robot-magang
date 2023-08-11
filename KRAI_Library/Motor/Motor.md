# Motor Library Documentation

This documentation provides a detailed explanation of the Motor library, which is used for controlling a standard DC motor with an H-bridge using a PwmOut and two DigitalOut pins. The library consists of two files: `Motor.h` and `Motor.cpp`. It allows you to set the speed of the motor, control the H-bridge to make the motor go forward or backward, and apply brakes to stop the motor.

## Motor Class

### Constructor

The Motor class is used to create an interface for controlling a DC motor. It has the following constructor:

```cpp
Motor::Motor(PinName pwm, PinName fwd, PinName rev)
```

The constructor initializes the motor control interface with the specified pins:
- `pwm`: A `PwmOut` pin that drives the H-bridge enable line to control the motor's speed.
- `fwd`: A `DigitalOut` pin that is set high when the motor should go forward.
- `rev`: A `DigitalOut` pin that is set high when the motor should go backward.

### Methods

The Motor class provides the following methods:

#### `void speed(float speed)`

Sets the speed of the motor. The `speed` parameter is a normalized value between -1.0 and 1.0, where -1.0 represents full speed backward, 0.0 represents stop, and 1.0 represents full speed forward.

#### `void period(float period)`

Sets the period of the PWM duty cycle. This method is a wrapper for the `PwmOut::period()` method. The `period` parameter represents the PWM duty cycle in seconds.

#### `void brake(int highLow)`

Brakes the H-bridge to GND or VCC. By default, the method brakes to VCC. The `highLow` parameter can be set to `BRAKE_HIGH` to brake to VCC (inA = inB = 1) or `BRAKE_LOW` to brake to GND (inA = inB = 0).

#### `void forcebrake()`

Forces the motor to brake by setting the PWM to maximum duty cycle (1.0) and both the forward and reverse pins to high (inA = inB = 1).

## How to Use

To use the Motor library in your projects, follow these steps:

1. Include the `Motor.h` header file in your project.

2. Create an instance of the `Motor` class by specifying the appropriate pins for PWM, forward, and reverse control.

**Example:**

```cpp
#include "Motor.h"

// Create a motor control interface using pins D5, D6, and D7
Motor motor(D5, D6, D7);
```

3. Use the `speed()` method to set the speed of the motor. Provide a normalized value between -1.0 and 1.0.

**Example:**

```cpp
// Set the motor speed to full speed forward
motor.speed(1.0);

// Set the motor speed to half speed backward
motor.speed(-0.5);
```

4. Use the `period()` method to set the PWM duty cycle period if required.

**Example:**

```cpp
// Set the PWM duty cycle period to 1 ms
motor.period(0.001);
```

5. Use the `brake()` method to apply brakes to the motor. By default, the method applies brakes to VCC (inA = inB = 1). Optionally, you can pass `BRAKE_LOW` as a parameter to brake to GND (inA = inB = 0).

**Example:**

```cpp
// Apply brakes to the motor using VCC
motor.brake();

// Apply brakes to the motor using GND
motor.brake(BRAKE_LOW);
```

6. Use the `forcebrake()` method to forcefully stop the motor by applying maximum PWM duty cycle and setting both the forward and reverse pins to high.

**Example:**

```cpp
// Forcefully stop the motor
motor.forcebrake();
```
---

Documented by *KRAI-15*

from the library ControlMotor, encoderHAL, encoderKRAI, Motor, PID_KRAI, pidLo, and SMC_KRAI make a whole guideline on controlling motor. Make it the exact documentation format as the above one. Make sure to use the whole library in the documentation.