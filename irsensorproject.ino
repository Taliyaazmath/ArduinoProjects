// Define pins for the sensors and relay
const int sensor1Pin = D1; // Infrared sensor 1 connected to D1
const int sensor2Pin = D2; // Infrared sensor 2 connected to D2
const int relayPin = D5;   // Relay module connected to D5

// Variable to store the count of people in the room
int peopleCount = 0;

void setup() {
  // Initialize the serial communication
  Serial.begin(115200);

  // Set the sensor pins as input
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);

  // Set the relay pin as output
  pinMode(relayPin, OUTPUT);

  // Initially turn off the light
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Read the state of the sensors
  int sensor1State = digitalRead(sensor1Pin);
  int sensor2State = digitalRead(sensor2Pin);

  // Check if a person has entered the room
  if (sensor1State == HIGH && sensor2State == LOW) {
    peopleCount++;
    delay(1000); // Debounce delay
  }

  // Check if a person has exited the room
  if (sensor1State == LOW && sensor2State == HIGH) {
    peopleCount--;
    delay(1000); // Debounce delay
  }

  // Ensure the people count does not go below zero
  if (peopleCount < 0) {
    peopleCount = 0;
  }

  // Control the relay based on the number of people in the room
  if (peopleCount > 0) {
    digitalWrite(relayPin, HIGH); // Turn on the light
  } else {
    digitalWrite(relayPin, LOW); // Turn off the light
  }

  // Print the people count for debugging purposes
  Serial.print("People count: ");
  Serial.println(peopleCount);

  // Short delay before next loop iteration
  delay(100);
}
