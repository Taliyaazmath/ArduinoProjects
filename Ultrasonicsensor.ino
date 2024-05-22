// Define pins for the ultrasonic sensor and alarm
const int trigPin = D1;  // Trig pin of the ultrasonic sensor connected to D1
const int echoPin = D2;  // Echo pin of the ultrasonic sensor connected to D2
const int alarmPin = D5; // Alarm (buzzer) connected to D5

// Define the distance threshold (in centimeters)
const int distanceThreshold = 10; // Change this value as per your requirement

void setup() {
  // Initialize the serial communication
  Serial.begin(115200);

  // Set the pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(alarmPin, OUTPUT);

  // Ensure the alarm is initially off
  digitalWrite(alarmPin, LOW);
}

void loop() {
  // Variable to store the measured distance
  long duration;
  int distance;

  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Print the distance for debugging purposes
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is below the threshold
  if (distance > 0 && distance < distanceThreshold) {
    digitalWrite(alarmPin, HIGH); // Turn on the alarm
  } else {
    digitalWrite(alarmPin, LOW);  // Turn off the alarm
  }

  // Short delay before the next loop iteration
  delay(100);
}
