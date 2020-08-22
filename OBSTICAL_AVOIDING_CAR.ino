
/*
 * Name -  HET KHAMAR
 * STUDENT ID - 200424199
 * 
 * NAME - OM MAJITHIA 
 * STUDENT ID - 200424199
 * 
 * 
 * THIS IS OUR MODE 2 FOR THIS PROJECT AND NEED A ADDITIONAL LIBRARY TO run this and upload it 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
//START OF CODE 

#include <Servo.h>         
#include <NewPing.h>        //Ultrasonic sensor function library. We got this online on google and will be including in our repository 

// this are the pins to control the motor driver 
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 5;
const int RightMotorBackward = 4;

//This pins goes into our ultrasonic sensor
#define triger_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200 //so we have set a maximum distance 
boolean goesForward = false; 
int distance = 100;

NewPing sonar(triger_pin, echo_pin, maximum_distance); //ultrasonic sensor function 
Servo servo_motor; //name for the servo motor 


void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(10); //our servo pin to control the angles 
/* after going on angle 115 senor senses 4 times*/
  servo_motor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 35)  // so When the distance is less than thirty five the car stops and take a reverse and after 400 . the sensor looks right and left again to check 
  {
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft)
    {
      turnRight();
      moveStop();
    }
    else
    {
      turnLeft();
      moveStop();
    }
  }
  else
  {
    moveForward(); 
  }
    distance = readPing();
}

int lookRight()// this is Function that tells senor to look right 
{  
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft() // this is Function that tells senor to look left 
{
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}

int readPing() 
{
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop()
{
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward()
{

  if(!goesForward)
  {

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward()
{

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight()
{

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(250);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft()
{

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(250);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

// END OF THE CODE .
