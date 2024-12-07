
# SmartElevatorSystem

## Overview  
SmartElevatorSystem is an Arduino-based simulation of an elevator control system designed for educational and experimental purposes. This project combines multiple components, including a keypad, stepper motor, servo motor, OLED display, and IR sensor, to replicate the functionality of a real-world elevator.

## Features  
- **Keypad Interface**: Select desired floors using a 4x3 keypad.  
- **OLED Display**: Real-time updates about the current floor, target floor, and error messages.  
- **Servo-Controlled Lift Gate**: Smooth and automatic opening and closing of elevator gates.  
- **Stepper Motor Movement**: Accurate and smooth elevator movement between floors.  
- **IR Obstruction Detection**: Ensures safety by preventing gate closure if an obstruction is detected.  
- **User Feedback**: Visual feedback via OLED display and an LED indicator for errors.

## Hardware Components  
- **Arduino Board**: Core microcontroller.  
- **Stepper Motor**: Simulates elevator movement.  
- **Servo Motor**: Operates the lift gate.  
- **4x3 Keypad**: For floor selection.  
- **IR Sensor**: Detects obstructions at the lift gate.  
- **OLED Display**: Provides user feedback.  
- **LED Indicator**: Alerts users in case of obstructions.

## Software Components  
- **Arduino IDE**: For coding and uploading firmware.  
- **Libraries Used**:  
  - `Keypad.h`: Manages keypad input.  
  - `Stepper.h`: Controls stepper motor movement.  
  - `Servo.h`: Operates the lift gate servo motor.  
  - `SSD1306Ascii.h`: Displays messages on the OLED screen.

## Setup Diagram  
![alt text](image.png)

## Future Improvements  
- Add more floors to the system.  
- Integrate IoT capabilities for remote control.  
- Implement advanced safety features like emergency braking.  
- Enhance the UI for better user experience.

## License  
This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).

