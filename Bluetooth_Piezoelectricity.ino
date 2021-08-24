#include <SoftwareSerial.h>
#include <TimerOne.h>
#include <FastLED.h>

int blueTx=2;   //Tx (보내는핀 설정)at
int blueRx=3;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언

int sensor = A3;   // 압전 센서핀을 A3번으로 설정
int led = 13;      // LED핀을 11번으로 설정

int val_count = 0;
int bt_count = 0;

#define LED_PIN 5
#define NUM_LEDS 100
#define BRIGHTNESS 250
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

void setup(){
  Serial.begin(9600);    //시리얼 통신, 속도는 9600
  mySerial.begin(9600); //블루투스 통신, 속도는 9600
  pinMode(led, OUTPUT);  // LED 결과값으로 설정
}
 
void loop(){
  int val = analogRead(sensor);  //압전 센서의 데이터 받아오기
  if(val > 50)             // 압전 센서의 데이터값으로 LED 제어
  {
    digitalWrite(led, HIGH);
    mySerial.println("물건 있음");  //시리얼 모니터 내용을 블루추스 측에 WRITE
    Serial.println("물건 있음");
  } else
  {
    digitalWrite(led,LOW);
    mySerial.println("물건 없음");  //시리얼 모니터 내용을 블루추스 측에 WRITE
    Serial.println("물건 없음");
  }
}
