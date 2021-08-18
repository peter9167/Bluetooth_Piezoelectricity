#include <SoftwareSerial.h>
#include <TimerOne.h>

int blueTx=2;   //Tx (보내는핀 설정)at
int blueRx=3;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언

int sensor = A3;   // 압전 센서핀을 A2번으로 설정
int led = 11;      // LED핀을 11번으로 설정
 
void setup(){
  Serial.begin(9600);    //시리얼 통신, 속도는 9600
  mySerial.begin(9600); //블루투스 통신, 속도는 9600
  pinMode(led, OUTPUT);  // LED 결과값으로 설정
}
 
void loop(){
  int val = analogRead(sensor);  //압전 센서의 데이터 받아오기
  if(val >60)             // 압전 센서의 데이터값으로 LED 제어
  {
    digitalWrite(led, HIGH);
    mySerial.println("물건 있음");  //시리얼 모니터 내용을 블루추스 측에 WRITE
  }
  else
  {
    digitalWrite(led,LOW);
    mySerial.println("물건 없음");  //시리얼 모니터 내용을 블루추스 측에 WRITE
  }
}
