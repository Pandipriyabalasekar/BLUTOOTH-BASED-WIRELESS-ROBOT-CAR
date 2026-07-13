Bluetooth Based Wireless Robot Car

Overview

The Bluetooth Based Wireless Robot Car is an embedded systems project developed using the ARM7 LPC2129 microcontroller. The robot is controlled wirelessly through a Bluetooth HC-05 module using commands sent from a smartphone. It can move forward, backward, turn left, turn right, and stop based on user input. The project demonstrates wireless communication, motor control, UART communication, and real-time embedded programming.

Features

- Wireless control using Bluetooth HC-05
- Forward, backward, left, and right movement
- Stop function
- ARM7 LPC2129 microcontroller
- L298N/L293D motor driver interface
- LCD display for movement status
- UART communication
- Embedded C programming
- Designed and tested in Proteus and Keil µVision

Hardware Components

- ARM7 LPC2129 Microcontroller
- HC-05 Bluetooth Module
- L298N/L293D Motor Driver
- Two DC Motors
- 16×2 LCD Display
- Power Supply
- Connecting Wires

Software Requirements

- Keil µVision
- Proteus 8 Professional
- Embedded C
- Flash Magic (for hardware programming)

Working Principle

The HC-05 Bluetooth module receives commands from a mobile phone through Bluetooth communication. These commands are transferred to the LPC2129 using UART. The microcontroller processes each command and controls the motor driver to move the robot in the desired direction. The LCD displays the current movement status, such as Forward, Backward, Left, Right, or Stop.

Bluetooth Commands

Command| Action
F| Move Forward
B| Move Backward
L| Turn Left
R| Turn Right
S| Stop

Project Structure

Bluetooth_Robot_Car/
│── main.c
│── uart.c
│── motor.c
│── lcd.c
│── delay.h
│── README.md

Future Enhancements

- Obstacle avoidance using IR or ultrasonic sensors
- Voice-controlled robot
- Line follower mode
- Mobile application with graphical controls
- Camera-based surveillance
- IoT and Wi-Fi control
- GPS navigation

Learning Outcomes

- ARM7 LPC2129 programming
- UART communication
- Bluetooth interfacing
- DC motor control
- LCD interfacing
- Embedded C programming
- Proteus simulation
- Real-time embedded system development

