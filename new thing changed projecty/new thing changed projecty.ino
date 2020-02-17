#include <Servo.h>

bool thing1 = false;
 const int echoPin = 11;
 const int trigPin = 12;
 float duration, distance;

Servo servoRight;
Servo servoLeft;




void setup()
{
  servoLeft.attach(10);
  servoRight.attach(8);
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop()
{
  Serial.print("Distance");
  Serial.println(GetDistance());
GetDistance();
forward();


  if (distance <= 5)
  {
thing1 = true;
  }
  if(thing1 == true){
      turnRight();
      delay();
      turnLeft();
      delay();
      turnRight();
      delay();
      turnLeft();
      
  }
  if  (distance > 5){
    delay(100);
    forward();
  }
  if(thing1 == false){
    forward();
  }

}

  void turnLeft() {
    servoLeft.write(170);
    servoRight.write(80);
  }



  void forward()     {
  servoLeft.write(80);
    servoRight.write(80);

  }
  void turnRight(){

    servoLeft.write(80);
    servoRight.write(170);
  }
  void Stop()
  {
    servoLeft.write(0);
    servoRight.write(0);
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
