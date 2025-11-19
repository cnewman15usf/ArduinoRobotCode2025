const int TRIG_PIN = 7; // Set the Trigger Pin
const int ECHO_PIN = 8; // Set the Echo Pin
int in1 = 4; // variable names for the L298N
int in2 = 5; // variable names for the L298N
int in3 = 9; // variable names for the L298N
int in4 = 10; // variable names for the L298N

bool Forward() {
      digitalWrite(in1, HIGH); // Pin High
      digitalWrite(in2, LOW); // Pin Low
      digitalWrite(in3, HIGH); // Pin High
      digitalWrite(in4, LOW); // Pin Low
      return true;
}

bool Backwards() {
  digitalWrite(in1, LOW); // Pin Low
      digitalWrite(in2, HIGH); // Pin High
      digitalWrite(in3, LOW); // Pin Low
      digitalWrite(in4, HIGH); // Pin High
      return true;
}

bool Stop() {
      digitalWrite(in1, LOW); // Pin Low
      digitalWrite(in2, LOW); // Pin Low
      digitalWrite(in3, LOW); // Pin Low
      digitalWrite(in4, LOW); // Pin Low
      return true;
}

bool Left() {
      digitalWrite(in1, HIGH); // Pin High
      digitalWrite(in2, LOW); // Pin Low
      digitalWrite(in3, LOW); // Pin Low
      digitalWrite(in4, HIGH); // Pin High
      return true;
}

bool Right() {
      digitalWrite(in1, LOW); // Pin Low
      digitalWrite(in2, HIGH); // Pin High
      digitalWrite(in3, HIGH); // Pin High
      digitalWrite(in4, LOW); // Pin Low
      return true;
}
int Ping() { // Ping Ultrasound
digitalWrite(TRIG_PIN, LOW); // Clear Trigger Pin
delay(2); // Wait 2 milliseconds
digitalWrite(TRIG_PIN, HIGH); // Power Trigger Pin
delay(10); // Wait 10 milliseconds
digitalWrite(TRIG_PIN, LOW); // Depower the trigger pin

return pulseIn(ECHO_PIN, HIGH); // Return the pulse from Ultra Sound Sensor
}

float ReadUltraSound() { 

  int Distance = Ping();
  
return (Distance * 0.034) / 2; // Measure the distance and return 
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

  if (Distance_cm <= 15) { // Read the data. If distance is less than or equal to 15
    
   Forward();
  }else if (Distance_cm <= 30) // If distance is less than or equal to 30 cm
  {
      Stop();
     Serial.println("Motors not Spinning"); // Stay in Place
  }else if (Distance_cm <= 45) // If distance is less than or equal to 45 cm
  {
      Forward();
      Serial.println("Motors Spinning Forward!"); // Move Motors Forward
  }else // No Obj Detected
  {
    Stop();
    Serial.println("Motors not Spinning"); // Stay in place
  }
  Serial.println("Distance: "); // Print Distance:
  Serial.println(Distance_cm); // Print the read distance variable
}
