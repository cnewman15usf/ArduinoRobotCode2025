const int TRIG_PIN = 12; // Set the Trigger Pin
const int ECHO_PIN = 11; // Set the Echo Pin

void Ping() { // Ping Ultrasound
digitalWrite(TRIG_PIN, LOW); // Clear Trigger Pin
delay(2); // Wait 2 milliseconds
digitalWrite(TRIG_PIN, HIGH); // Power Trigger Pin
delay(10); // Wait 10 milliseconds
digitalWrite(TRIG_PIN, LOW); // Depower the trigger pin

return pulseIn(ECHO_PIN, HIGH); // Return the pulse from Ultra Sound Sensor
}

void ReadUltraSound() { 
return (Ping() * 0.034) / 2; // Measure the distance and return 
}

void setup() {
 Serial.begin(9600);
 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
}

void loop() {
  const float Distance_cm = ReadUltraSound(); // Call the ReadUtltraSound Function

  if (distance_cm <= 15) { // Read the data. If distance is less than or equal to 15
    Serial.println("Motors Spinning Backwards"); // Move Motors Backwards
  
  }else if (Distance_cm <= 30) // If distance is less than or equal to 30 cm
  {
     Serial.println("Motors not Spinning"); // Stay in Place
  }else if (Distance_cm <= 45) // If distance is less than or equal to 45 cm
  {
      Serial.println("Motors Spinning Forward!"); // Move Motors Forward
  }else // No Obj Detected
  {
    Serial.println("Motors not Spinning"); // Stay in place
  }
  Serial.println("Distance: "); // Print Distance:
  Serial.println(Distance_cm); // Print the read distance variable
}
