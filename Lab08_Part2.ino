#include <Ultrasonic.h>
#define TRIGGER_PIN 13
#define ECHO_PIN 14
volatile boolean state = LOW;
const byte intPin = 8;
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup() {
  pinMode(6,INPUT);
  Serial.begin(9600);
  attachInterrupt(intPin, int0, FALLING);
}
float cmMsec, inMsec;
long microsec;

void loop() {
  if(digitalRead(6) == LOW) {
    noInterrupts();
  }
  else {
    interrupts();
  } 
  Serial.print("MS: "); Serial.print(microsec);
  Serial.print(", CM: "); Serial.print(cmMsec);
  Serial.print(", IN: "); Serial.println(inMsec);
  delay(1000);
}

void int() {
  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
}


