# ArduinoProjects
# There are two main project file one of which is the Automatic light project 
# Room Occupancy Detection and Light Control

## Overview

This project uses an Arduino (or compatible board) to count the number of people in a room using two infrared sensors. Based on the number of people detected, it controls a relay module to automatically turn a light on or off.

## Features

- Count the number of people entering and exiting a room using infrared sensors.
- Automatically control a light based on room occupancy.
- Display the number of people in the room via serial monitor.

## Hardware Requirements

- Arduino (or compatible board)
- 2 Infrared sensors
- Relay module
- Light (connected to relay)
- Connecting wires

## Circuit Diagram

1. **Infrared Sensor 1**:
   - VCC to 5V
   - GND to GND
   - OUT to D1

2. **Infrared Sensor 2**:
   - VCC to 5V
   - GND to GND
   - OUT to D2

3. **Relay Module**:
   - VCC to 5V
   - GND to GND
   - IN to D5
   - Connect the light to the relay's normally open (NO) and common (COM) terminals.

## Code Explanation

### Define Pins and Variables

```cpp
const int sensor1Pin = D1; // Infrared sensor 1 connected to D1
const int sensor2Pin = D2; // Infrared sensor 2 connected to D2
const int relayPin = D5;   // Relay module connected to D5

int peopleCount = 0; // Variable to store the count of people in the room
```

### Setup Function

```cpp
void setup() {
  Serial.begin(115200);    // Initialize the serial communication
  pinMode(sensor1Pin, INPUT);  // Set the sensor pins as input
  pinMode(sensor2Pin, INPUT);
  pinMode(relayPin, OUTPUT);   // Set the relay pin as output
  digitalWrite(relayPin, LOW); // Initially turn off the light
}
```

### Loop Function

```cpp
void loop() {
  int sensor1State = digitalRead(sensor1Pin); // Read the state of the sensors
  int sensor2State = digitalRead(sensor2Pin);

  if (sensor1State == HIGH && sensor2State == LOW) { // Check if a person has entered the room
    peopleCount++;
    delay(1000); // Debounce delay
  }

  if (sensor1State == LOW && sensor2State == HIGH) { // Check if a person has exited the room
    peopleCount--;
    delay(1000); // Debounce delay
  }

  if (peopleCount < 0) { // Ensure the people count does not go below zero
    peopleCount = 0;
  }

  if (peopleCount > 0) { // Control the relay based on the number of people in the room
    digitalWrite(relayPin, HIGH); // Turn on the light
  } else {
    digitalWrite(relayPin, LOW); // Turn off the light
  }

  Serial.print("People count: "); // Print the people count for debugging purposes
  Serial.println(peopleCount);

  delay(100); // Short delay before next loop iteration
}
```

## Usage

1. **Upload the code** to your Arduino board using the Arduino IDE.
2. **Connect the infrared sensors and relay module** as per the circuit diagram.
3. **Open the serial monitor** in the Arduino IDE to view the people count.
4. The light will automatically turn on when the room is occupied and turn off when the room is empty.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Arduino for the microcontroller platform.
- Community tutorials and forums for guidance and support.

---

Feel free to modify and expand this project. Contributions are welcome!
