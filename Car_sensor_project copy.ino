//www.elegoo.com
//2016.12.08
#include <SR04.h>
#define R_PIN 6
#define G_PIN 5
#define BUZZ_PIN 13
#define TRIG_PIN 12
#define ECHO_PIN 11 
  int d1=0;
  int d2=0;
  int d3=0;

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long lastToggle = 0;
bool buzzerState = false;


void setup() {
  pinMode(R_PIN, OUTPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
   Serial.begin(9600);//Initialization of Serial Port
   delay(1000);
}

void loop() {

   int distance = sr04.Distance();
   distance = constrain(distance, 0, 100);

   d1=d2;
   d2=d3;
   d3=distance;
   int avgdistance = (d1+d2+d3)/3;
   int RedColor_distance = map(avgdistance, 100, 1, 0, 255);
   int GreenColor_distance = map(avgdistance, 100, 1, 255, 0);

   analogWrite(R_PIN, RedColor_distance);
   analogWrite(G_PIN, GreenColor_distance);

    int interval=0;
  if(avgdistance <= 100 && avgdistance > 25 ){
    interval = 100000;
    digitalWrite(BUZZ_PIN, LOW);
     return;
  }else{
    if(avgdistance <= 24 && avgdistance > 12 ){
    interval = 200;
   }else if(avgdistance <= 11 && avgdistance > 8 ){
    interval = 120;
   }else if(avgdistance <= 7 && avgdistance > 4 ){
    interval = 90;
   } else{
    interval = 40;
   }
   if( millis() - lastToggle >= interval) {
    lastToggle = millis();
    buzzerState = !buzzerState;
    digitalWrite(BUZZ_PIN, buzzerState);
    delay(50);
    
   }}}