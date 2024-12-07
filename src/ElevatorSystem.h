#ifndef ELEVATORSYSTEM_H
#define ELEVATORSYSTEM_H

#include <Keypad.h>
#include <Stepper.h>
#include <Servo.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"

// Constants and Configuration
const int stepsPerRevolution = 200;
const float revolutionsPerFloor = 6.25;
const int pinServo = 11;
const int IRSensor = 12; // IR Sensor pin
const int LED = 13;      // LED pin

// Keypad configuration
extern Keypad keypad;
extern char keys[4][3];
extern byte rowPins[4];
extern byte colPins[3];

// OLED Display
extern SSD1306AsciiAvrI2c oled;

// Function Prototypes
void initializeSystem();
void displayWelcomeMessage();
void processFloorChange();
bool closeLiftGate();
void openLiftGate();
void moveLift(int floors);

#endif // ELEVATORSYSTEM_H
