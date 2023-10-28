#define sec 50 //13วินาที
#include <Servo.h>
#include <NewPing.h>

unsigned long time_1 = 0;

int led1_Red = 12;
int led1_Blue = 3;
int led1_Green = 2;

int led2_Red = 4;
int led2_Blue = 6;
int led2_Green = 5;

int led3_Red = 7;
int led3_Blue = 11;
int led3_Green =10;

int echo = 8;
int trigger = 9;

int buzzer = 1;

Servo motor;
int motorPin = 13;

//for Ultrasonic
int echoPin = 8;
int triggerPin = 9;
NewPing sonar(triggerPin, echoPin, 100);

void setup()
{
  Serial.begin(9600);
  pinMode(led1_Red, OUTPUT);
  pinMode(led1_Blue, OUTPUT);
  pinMode(led1_Green, OUTPUT);
  
  pinMode(led2_Red, OUTPUT);
  pinMode(led2_Blue, OUTPUT);
  pinMode(led2_Green, OUTPUT);
  
  pinMode(led3_Red, OUTPUT);
  pinMode(led3_Blue, OUTPUT);
  pinMode(led3_Green, OUTPUT);
  
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  
  pinMode(buzzer, OUTPUT);

  motor.attach(motorPin);
  
}

void loop()
{
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
 	digitalWrite(9, LOW);
 	int pulseWidth = pulseIn(8, HIGH);
 	Serial.print("Pulse Width: ");
 	Serial.println(pulseWidth);
 	long distance = pulseWidth/29/2;
 	Serial.print("Distance: ");
	Serial.println(distance);

	delay(100);

  digitalWrite(led1_Red,HIGH);
  digitalWrite(led1_Blue,HIGH);
  digitalWrite(led1_Green,HIGH);

  digitalWrite(led2_Red,HIGH);
  digitalWrite(led2_Blue,HIGH);
  digitalWrite(led2_Green,HIGH);
  
  digitalWrite(led3_Red,HIGH);
  digitalWrite(led3_Blue,HIGH);
  digitalWrite(led3_Green,HIGH);

  
  if((distance>30) || (distance==0)){
    digitalWrite(led1_Red,HIGH);
    digitalWrite(led1_Blue,HIGH);
    digitalWrite(led1_Green,LOW);

    digitalWrite(led2_Red,HIGH);
    digitalWrite(led2_Blue,HIGH);
    digitalWrite(led2_Green,HIGH);
    
    digitalWrite(led3_Red,HIGH);
    digitalWrite(led3_Blue,HIGH);
    digitalWrite(led3_Green,HIGH);

    digitalWrite(buzzer , LOW); //หยุดร้อง
    delay(1000); // หยุดร้อง 1 วินาที  

    motor.write(0); // สั่งให้ Servo หมุนไปองศาที่ 
    delay(100); // หน่วงเวลา 1000ms 
  }
  else if((distance<=30) && (distance>10)){
    digitalWrite(led1_Red,HIGH);
    digitalWrite(led1_Blue,LOW);
    digitalWrite(led1_Green,HIGH);

    digitalWrite(led2_Red,HIGH);
    digitalWrite(led2_Blue,LOW);
    digitalWrite(led2_Green,HIGH);
    
    digitalWrite(led3_Red,HIGH);
    digitalWrite(led3_Blue,HIGH);
    digitalWrite(led3_Green,HIGH);

    digitalWrite(buzzer , LOW); //หยุดร้อง
    delay(500); // หยุดร้อง 1 วินาที  

    motor.write(45); // สั่งให้ Servo หมุนไปองศาที่ 
    delay(100); // หน่วงเวลา 1000ms

  }
  else if(distance<=10){
    digitalWrite(led1_Red,LOW);
    digitalWrite(led1_Blue,HIGH);
    digitalWrite(led1_Green,HIGH);

    digitalWrite(led2_Red,LOW);
    digitalWrite(led2_Blue,HIGH);
    digitalWrite(led2_Green,HIGH);
    
    digitalWrite(led3_Red,LOW);
    digitalWrite(led3_Blue,HIGH);
    digitalWrite(led3_Green,HIGH);

    digitalWrite(buzzer , LOW); //หยุดร้อง
    delay(100); // หยุดร้อง 1 วินาที 

    motor.write(90); // สั่งให้ Servo หมุนไปองศาที่ 180
    delay(100); // หน่วงเวลา 1000ms
  }
}