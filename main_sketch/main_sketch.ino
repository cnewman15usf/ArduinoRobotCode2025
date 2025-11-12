const int TRIG_PIN = 12; // Set the Trigger Pin
const int ECHO_PIN = 11; // Set the Echo Pin
int in1 = 4; // variable names for the L298N
int in2 = 5; // variable names for the L298N
int in3 = 9; // variable names for the L298N
int in4 = 10; // variable names for the L298N


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
 pinMode(TRIG_PIN, OUTPUT); // Trigger pin is an output
 pinMode(ECHO_PIN, INPUT); // Echo is an input
 pinMode (in1, OUTPUT); // all L298N digital pins are outputs
 pinMode (in2, OUTPUT); // all L298N digital pins are outputs
 pinMode (in3, OUTPUT); // all L298N digital pins are outputs
 pinMode (in4, OUTPUT); // all L298N digital pins are outputs
}

void loop() {
  const float Distance_cm = ReadUltraSound(); // Call the ReadUtltraSound Function

  if (distance_cm <= 15) { // Read the data. If distance is less than or equal to 15
    Serial.println("Motors Spinning Backwards"); // Move Motors Backwards
    digitalWrite(in1, LOW); // Set Pin Low
    digitalWrite(in2, HIGH); // Set Pin HIGH
    digitalWrite(in3, LOW); // Set Pin Low
    digitalWrite(in4, HIGH); // Set Pin High
  }else if (Distance_cm <= 30) // If distance is less than or equal to 30 cm
  {
    digitalWrite(in1, LOW); // Set Pin Low
    digitalWrite(in2, LOW); // Set Pin HIGH
    digitalWrite(in3, LOW); // Set Pin Low
    digitalWrite(in4, LOW); // Set Pin High
     Serial.println("Motors not Spinning"); // Stay in Place
  }else if (Distance_cm <= 45) // If distance is less than or equal to 45 cm
  {
      digitalWrite(in1, HIGH); // Pin High
      digitalWrite(in2, LOW); // Pin Low
      digitalWrite(in3, HIGH); // Pin High
      digitalWrite(in4, LOW); // Pin Low
      Serial.println("Motors Spinning Forward!"); // Move Motors Forward
  }else // No Obj Detected
  {
    digitalWrite(in1, LOW); // Set Pin Low
    digitalWrite(in2, LOW); // Set Pin HIGH
    digitalWrite(in3, LOW); // Set Pin Low
    digitalWrite(in4, LOW); // Set Pin High
    Serial.println("Motors not Spinning"); // Stay in place
  }
  Serial.println("Distance: "); // Print Distance:
  Serial.println(Distance_cm); // Print the read distance variable
}
