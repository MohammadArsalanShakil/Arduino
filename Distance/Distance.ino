// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int bu = 3;
const int hieghttrigpin = 5;
const int hieghtechopin = 6;

// defines variables
long duration;
int distance;
int safetyDistance;
int hieghtDistance;
int HD;
int h;

#include <SoftwareSerial.h>

// The serial connection to the GPS module
SoftwareSerial ss(13, 12);

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(hieghttrigpin,OUTPUT);
pinMode(hieghtechopin,INPUT);
Serial.begin(9600); // Starts the serial communication
ss.begin(9600);
}


void loop() {
  while (ss.available() > 0){
    // get the byte data from the GPS
    byte gpsData = ss.read();
    Serial.write(gpsData);
  }
 int sensorReading = analogRead(A0);
  if (sensorReading < 700){
  //Serial.println("Rain is Detected");
  digitalWrite(bu,HIGH);
  }
 else{
  //Serial.println("Rain is not Detected");
 }
// Clears the trigPin
digitalWrite(trigPin, LOW);
digitalWrite(hieghttrigpin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 1 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(1);
digitalWrite(trigPin, LOW);


// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;


safetyDistance = distance;

if (safetyDistance <= 10){
  digitalWrite(buzzer, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
}



digitalWrite(hieghttrigpin, HIGH);
delayMicroseconds(1);
digitalWrite(hieghttrigpin, LOW);

hieghtDistance= HD*0.034/2;
h=hieghtDistance;
if (h>=10||h<=100){
  digitalWrite(bu, HIGH);
}
else{
  digitalWrite(bu, LOW);
}
HD = pulseIn(hieghtechopin,HIGH);

// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);
//Serial.print("Hieght: ");
//Serial.println(hieghtDistance);
}
