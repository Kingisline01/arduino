// Define ultrasonic sensor pins
const int trigPin = 9; // Trigger pin of ultrasonic sensor
const int echoPin = 10; // Echo pin of ultrasonic sensor

// Define LED pin
const int ledPin = 13; // LED pin

// Define variables for duration and distance
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set the trigger pin as an output
  pinMode(trigPin, OUTPUT);
  
  // Set the echo pin as an input
  pinMode(echoPin, INPUT);
  
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond pulse to the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse on the echo pin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if the distance is within a certain range (e.g., less than 20 cm)
  if (distance < 20) {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn off the LED
    digitalWrite(ledPin, LOW);
  }
  
  // Delay before the next measurement
  delay(100);
}
