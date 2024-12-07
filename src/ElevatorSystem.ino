#include "ElevatorSystem.h"

// Variables
Servo myservo;
Stepper myStepper(stepsPerRevolution, 7, 8, 9, 10);
int currentFloor = 1; // Starting floor
int nextFloor;

// Keypad configuration
char keys[4][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};
byte rowPins[4] = {2, 3, 4, 5};
byte colPins[3] = {6, 7, 8};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 3);

// OLED Display
SSD1306AsciiAvrI2c oled;

// Function Definitions
void initializeSystem() {
    myservo.attach(pinServo);
    pinMode(IRSensor, INPUT);
    pinMode(LED, OUTPUT);
    myStepper.setSpeed(60);

#if RST_PIN >= 0
    oled.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
#else
    oled.begin(&Adafruit128x64, I2C_ADDRESS);
#endif
    oled.setFont(Adafruit5x7);
    displayWelcomeMessage();
}

void displayWelcomeMessage() {
    oled.clear();
    oled.set2X();
    oled.println("Welcome to \nElevator \nControl \nSystem");
    delay(2000);
    oled.clear();
    oled.println("Enter Floor");
}

void processFloorChange() {
    char key = keypad.getKey();
    if (key) {
        int keyNum = key - '0';
        nextFloor = keyNum;

        if (keyNum > 4) {
            oled.clear();
            oled.println("Invalid \nFloor");
            return;
        }

        int floorDifference = nextFloor - currentFloor;
        if (floorDifference != 0) {
            closeLiftGate();
            moveLift(floorDifference);
        } else {
            oled.clear();
            oled.println("Already on \nFloor:");
            oled.println(nextFloor);
        }
    }
}

bool closeLiftGate() {
    oled.clear();
    oled.println("Going to \nFloor:");
    oled.println(nextFloor);

    for (int pos = 90; pos >= 0; pos--) {
        myservo.write(pos);
        delay(20);
        if (digitalRead(IRSensor) == 0) {
            myservo.write(90);
            return false;
        }
    }
    return true;
}

void openLiftGate() {
    for (int pos = 0; pos <= 90; pos++) {
        myservo.write(pos);
        delay(20);
    }
}

void moveLift(int floors) {
    while (true) {
        if (closeLiftGate()) {
            digitalWrite(LED, LOW);
            myStepper.step(stepsPerRevolution * revolutionsPerFloor * floors);
            currentFloor = nextFloor;

            oled.clear();
            oled.println("Reached \nFloor:");
            oled.println(nextFloor);

            openLiftGate();
            oled.clear();
            oled.println("Enter Floor");
            break;
        } else {
            digitalWrite(LED, HIGH); // Obstruction detected
        }
    }
}
