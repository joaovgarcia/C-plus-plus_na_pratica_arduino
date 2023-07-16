// C++ code
//
#include <Servo.h>

Servo servoFront;
Servo servoBack;

int frontServo = A5;
int backServo = A0;

int rightServo = A3;
int leftServo = A1;

int leftServoUp = A4;
int rightServoUp = A2;

int ultraRight[4] = {2,3,4};
int ultraLeft[4] = {5,6,7};

int dUltraFront;
int dUltraBack;


int enLeftMotor = 13;
int in1LeftMotor = 11;
int in2LeftMotor = 10;

int enRightMotor = 12;
int in3RightMotor = 8;
int in4RightMotor = 9;


void setup()
{
  Serial.begin(9600);
  
  pinMode(enLeftMotor, OUTPUT);
  pinMode(enRightMotor, OUTPUT);
  
  pinMode(in1LeftMotor, OUTPUT);
  pinMode(in2LeftMotor, OUTPUT);
  
  pinMode(in3RightMotor, OUTPUT);
  pinMode(in4RightMotor, OUTPUT);
  
  servoFront.attach(frontServo);
  servoBack.attach(backServo);
  
  pinMode(frontServo, OUTPUT);
  pinMode(backServo, OUTPUT);

  pinMode(leftServo, OUTPUT);
  pinMode(rightServo, OUTPUT);
  
  pinMode(leftServoUp, OUTPUT);
  pinMode(rightServoUp, OUTPUT);
  
  pinMode(ultraRight[0], OUTPUT);
  pinMode(ultraRight[1], OUTPUT);
  pinMode(ultraRight[2], OUTPUT);
  
  pinMode(ultraLeft[0], OUTPUT);
  pinMode(ultraLeft[1], OUTPUT);
  pinMode(ultraLeft[2], OUTPUT);
 
}

void loop()
{
  	analogWrite(enLeftMotor, 200);
  	analogWrite(enRightMotor, 200);
	
	dUltraBack = 0.01723 * readUltrasonicDistance(ultraLeft[2]);
  	dUltraFront = 0.01723 * readUltrasonicDistance(ultraRight[2]);
  	
  if (dUltraFront < 15){
    servoFront.write(90);
    
    digitalWrite(in1LeftMotor, LOW);
    digitalWrite(in2LeftMotor, HIGH);
    digitalWrite(in3RightMotor, LOW);
    digitalWrite(in4RightMotor, HIGH);
  }
  if (dUltraBack < 15) {
    servoBack.write(90);
    
     digitalWrite(in1LeftMotor, LOW);
    digitalWrite(in2LeftMotor, LOW);
    digitalWrite(in3RightMotor, LOW);
    digitalWrite(in4RightMotor, LOW);
  }
  if (dUltraBack > 15 && dUltraFront > 15){
   	servoBack.write(0);
    servoFront.write(0);
    
    digitalWrite(in1LeftMotor, HIGH);
    digitalWrite(in2LeftMotor, LOW);
    digitalWrite(in3RightMotor, HIGH);
    digitalWrite(in4RightMotor, LOW);
    
    
  }
    
  	Serial.print(dUltraFront);
  	Serial.println();
  	Serial.println("-");
  	
  	delay(5);
}

long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);  // Clear the trigger
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  // Sets the pin on HIGH state for 10 micro seconds
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  // Reads the pin, and returns the sound wave travel time in microseconds
  return pulseIn(pin, HIGH);
  
}