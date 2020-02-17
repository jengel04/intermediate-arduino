#include <Servo.h>

long randNumber;

bool thing1 = false;
 const int echoPin = 11;
 const int trigPin = 12;
 float duration, distance;

Servo servoLeft;




void setup()
{
  servoLeft.attach(10);
randomSeed(analogRead(0));
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop()
{
  Serial.print("Distance");
  Serial.println(GetDistance());
GetDistance();

delay(100);
  if (distance <= 10)
  {
thing1 = true;
  }
  if(thing1 == true){
    randNumber = random(19, 89);
    Serial.println("number");
    Serial.println(randNumber);
      servoLeft.write(randNumber);
      delay(100);
    }
    if (distance <= 10 && thing1 == true){
randNumber = random(110, 179);
Serial.println(randNumber);
Serial.println("yeet");
servoLeft.write(randNumber);
delay(50);

    }
 
     
  

}





  int GetDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  return distance;
}
