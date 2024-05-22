int sensorPin = A0;

void setup() {
  Serial.begin(9600);  // Start the serial communication at 115200 baud rate
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Read the analog value from the sensor
  float voltage = sensorValue * (3.3 / 1023.0);  // Convert the analog value to voltage
  float ppm = (voltage / 3.3) * 1000;  // Simplified conversion to PPM for demonstration purposes

  // Print the sensor value, voltage, and estimated PPM to the Serial Monitor
  Serial.print("MQ-4 Sensor Value: ");
  Serial.println(sensorValue);
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  Serial.print("Estimated PPM: ");
  Serial.print(ppm);
  Serial.println(" ppm");
  Serial.println();

  delay(2000);  // Wait for 2 seconds before reading again
}
