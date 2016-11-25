#include "Clavier4x4.h"

Clavier4x4 clavier = Clavier4x4(23,24,25,26,27,28,29,22); // de gauche à droite
void setup(){
Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(11, OUTPUT);
pinMode(13, OUTPUT);
clavier.init();}


void loop()
{
  long dist = getDistanceCm(13);
  delay(1000);
  Serial.println(dist);
  
  
  char key=clavier.getKey();
  if (key != NO_KEY)  {
    if(key == '1'){
      digitalWrite(9,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(13,LOW);
    }
    if(key == '2'){
      digitalWrite(11,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(13,LOW);
    }
    if(key == '3'){
      digitalWrite(13,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(11,LOW);
    }
    if(key == '4'){
      digitalWrite(9,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(13,LOW);
    }
    if(key == '5'){
      digitalWrite(11,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(13,HIGH);
    }
    if(key == '6'){
      digitalWrite(9,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(13,HIGH);
    }
    if(key == '7'){
    }
    if(key == 'D'){     
      digitalWrite(9,LOW);
      digitalWrite(11,LOW);
      digitalWrite(13,LOW);
    }
    Serial.println(key);
  }
  delay(500);
}

long getDistanceCm(const int pin)
{
  // send the ping: low signal
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  // then high signal
  0
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  // end the ping
  digitalWrite(pin, LOW);
  
  // read ping feedback
  pinMode(pin, INPUT);
  // time expressd in microseconds
  long duration = pulseIn(pin, HIGH);
  // convert to cm
  // Sound travels at 340 m/s -> 29 microseconds per centimeter
  // The time is go and back -> divide by 2 to get the distance of the obstacle.
  return duration / 29 / 2;

}
