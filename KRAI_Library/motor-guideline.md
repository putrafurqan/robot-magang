# Motor Control Guidelines

This document provides a comprehensive guide for controlling a motor using the ControlMotor library and its associated components, including encoder feedback, PID control, and sliding mode control.

## Table of Contents

1. [Motor Control Guidelines](#motor-control-guidelines)
   1. [ControlMotor Library](#controlmotor-library)
      - [Overview](#overview)
      - [Usage](#usage)
   2. [Encoder Feedback Libraries](#encoder-feedback-libraries)
      - [encoderHAL Library](#encoderhal-library)
         - [Usage](#usage)
      - [encoderKRAI Library](#encoderkrai-library)
         - [Usage](#usage)
   3. [Motor Control Libraries](#motor-control-libraries)
      - [Motor Library](#motor-library)
         - [Usage](#usage)
      - [PID_KRAI Library](#pid_krai-library)
         - [Usage](#usage)
      - [pidLo Library](#pidlo-library)
         - [Usage](#usage)
      - [SMC_KRAI Library](#smc_krai-library)
         - [Usage](#usage)


## ControlMotor Library

### Overview

The ControlMotor library provides a high-level interface for controlling a motor using various control techniques. It integrates the functionalities of the `encoderHAL`, `encoderKRAI`, `Motor`, `PID_KRAI`, `pidLo`, and `SMC_KRAI` libraries to enable motor control with encoder feedback, PID control, and sliding mode control.

### Usage

To use the ControlMotor library, follow the steps below:

1. Include the necessary library headers in your project:

```cpp
#include "ControlMotor.h"
```

2. Create an instance of the ControlMotor class by specifying the appropriate pins for motor control and encoder feedback:

```cpp
ControlMotor motor(D3, D4, D5, TIM3);
```

The constructor takes the following parameters:
- `pwmPin`: A PinName object representing the pin connected to the motor's PWM input.
- `forwardPin`: A PinName object representing the pin connected to the motor's forward control.
- `reversePin`: A PinName object representing the pin connected to the motor's reverse control.
- `timer`: A TIM_TypeDef* object representing the timer used for encoder feedback.

3. Use the provided methods to control the motor:

```cpp
motor.setControlMode(ControlMode::PID); // Set the control mode to PID
motor.setPIDParameters(0.1, 0.01, 0.001); // Set the PID parameters
motor.setTargetSpeed(100.0); // Set the target speed in RPM
motor.enable(); // Enable the motor control
```

The available methods in the ControlMotor class include:
- `setControlMode()`: Set the control mode to either ControlMode::PID or ControlMode::SMC.
- `setPIDParameters()`: Set the PID control parameters.
- `setSMCParameters()`: Set the SMC control parameters.
- `setTargetSpeed()`: Set the target speed for the motor in RPM.
- `enable()`: Enable the motor control.
- `disable()`: Disable the motor control.

4. Implement a control loop to update the motor control:

```cpp
while (true) {
    motor.update(); // Update the motor control
    wait_ms(10); // Delay between control loop iterations
}
```

The update() method updates the motor control based on the selected control mode. It should be called in a control loop with an appropriate delay between iterations.

## Encoder Feedback Libraries

### encoderHAL Library

The encoderHAL library provides an interface for reading encoder values using hardware timers. It supports various timer modules on the STM32 microcontrollers.

Usage:

To use the encoderHAL library:

1. Include the necessary library headers in your project:

```cpp
#include "encoderHAL.h"
```

2. Create an instance of the encoderHAL class by specifying the appropriate timer:

```cpp
encoderHAL encoder(TIM2);
```

The constructor takes the following parameter:
- `timer`: A TIM_TypeDef* object representing the timer used for encoder feedback.

3. Use the provided methods to read the encoder values:

```cpp
int32_t pulses = encoder.getPulses();
int32_t revolutions = encoder.getRevolutions();
```

The available methods in the encoderHAL class include:
- `getPulses()`: Get the number of pulses from the encoder.
- `getRevolutions()`: Get the number of revolutions based on the encoder pulses.

### encoderKRAI Library

The encoderKRAI library provides an interface for reading encoder values using interrupt-based encoding methods. It supports both X2 and X4 encoding modes.

Usage:

To use the encoderKRAI library:

1. Include the necessary library headers in your project:

```cpp
#include "encoderKRAI.h"
```

2. Create an instance of the encoderKRAI class by specifying the appropriate pins and encoding mode:

```cpp
encoderKRAI encoder(D2, D3, 1000, X4_ENCODING);
```

The constructor takes the following parameters:
- `channelA`: A PinName object representing the channel A pin of the encoder.
- `channelB`: A PinName object representing the channel B pin of the encoder.
- `pulsesPerRev`: An integer representing the number of pulses per revolution of the encoder.
- `encoding`: The encoding mode, either X2_ENCODING or X4_ENCODING.

3. Use the provided methods to read the encoder values:

```cpp
int32_t pulses = encoder.getPulses();
int32_t revolutions = encoder.getRevolutions();
```

The available methods in the encoderKRAI class include:
- `getPulses()`: Get the number of pulses from the encoder.
- `getRevolutions()`: Get the number of revolutions based on the encoder pulses.

## Motor Control Libraries

### Motor Library

The Motor library provides a simple interface for controlling a standard DC motor using an H-bridge. It utilizes a PwmOut pin for speed control and two DigitalOut pins for direction control.

Usage:

To use the Motor library:

1. Include the necessary library headers in your project:

```cpp
#include "Motor.h"
```

2. Create an instance of the Motor class by specifying the appropriate pins:

```cpp
Motor motor(D6, D7, D8);
```

The constructor takes the following parameters:
- `pwm`: A PinName object representing the PWM pin connected to the motor driver.
- `fwd`: A PinName object representing the forward pin for motor direction control.
- `rev`: A PinName object representing the reverse pin for motor direction control.

3. Use the provided methods to control the motor:

```cpp
motor.speed(0.5); // Set the motor speed to 50%
motor.brake(); // Apply brakes to the motor
```

The available methods in the Motor class include:
- `speed()`: Set the speed of the motor as a normalized value between -1.0 and 1.0.
- `brake()`: Apply brakes to the motor.

### PID_KRAI Library

The PID_KRAI library provides a PID controller implementation for controlling motor speed based on encoder feedback. It allows you to set the PID gains and target speed.

Usage:

To use the PID_KRAI library:

1. Include the necessary library headers in your project:

```cpp
#include "PID_KRAI.h"
```

2. Create an instance of the PID_KRAI class by specifying the appropriate PID gains:

```cpp
PID_KRAI pid(0.1, 0.01, 0.001);
```

The constructor takes the following parameters:
- `kp`: The proportional gain.
- `ki`: The integral gain.
- `kd`: The derivative gain.

3. Use the provided methods to control the PID controller:

```cpp
pid.setTarget(targetSpeed); // Set the target speed
pid.setInput(currentSpeed); // Set the current speed as the input value
float output = pid.compute(); // Compute the PID output
```

The available methods in the PID_KRA

I apologize for the incomplete response. Here's the rest of the documentation:

The available methods in the PID_KRAI class include:
- `setTarget()`: Set the target speed for the PID controller.
- `setInput()`: Set the input value for the PID controller.
- `compute()`: Compute the PID output.

### pidLo Library

The pidLo library provides a low-level implementation of a PID controller for motor control. It allows you to set the PID gains and compute the control output.

Usage:

To use the pidLo library:

1. Include the necessary library headers in your project:

```cpp
#include "pidLo.h"
```

2. Create an instance of the pidLo class by specifying the appropriate PID gains:

```cpp
pidLo pid(0.1, 0.01, 0.001);
```

The constructor takes the following parameters:
- `kp`: The proportional gain.
- `ki`: The integral gain.
- `kd`: The derivative gain.

3. Use the provided methods to control the PID controller:

```cpp
pid.setInput(currentSpeed); // Set the current speed as the input value
float output = pid.compute(); // Compute the PID output
```

The available methods in the pidLo class include:
- `setInput()`: Set the input value for the PID controller.
- `compute()`: Compute the PID output.

### SMC_KRAI Library

The SMC_KRAI library provides a sliding mode controller implementation for motor control. It allows you to set the control gains and compute the control output.

Usage:

To use the SMC_KRAI library:

1. Include the necessary library headers in your project:

```cpp
#include "SMC_KRAI.h"
```

2. Create an instance of the SMC_KRAI class by specifying the appropriate control gains:

```cpp
SMC_KRAI smc(0.1, 0.01);
```

The constructor takes the following parameters:
- `lambda`: The reaching rate gain.
- `eta`: The sliding mode gain.

3. Use the provided methods to control the sliding mode controller:

```cpp
smc.setTarget(targetSpeed); // Set the target speed
smc.setInput(currentSpeed); // Set the current speed as the input value
float output = smc.compute(); // Compute the sliding mode control output
```

The available methods in the SMC_KRAI class include:
- `setTarget()`: Set the target speed for the sliding mode controller.
- `setInput()`: Set the input value for the sliding mode controller.
- `compute()`: Compute the sliding mode control output.

---

Documented by *KRAI-15*