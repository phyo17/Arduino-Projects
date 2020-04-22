#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int TrigPin=9;
int EchoPin=10;

long duration;
int distanceCm;
int distanceInch;
void setup() {
  lcd.begin(16,2);

  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);

}
void loop() {
 digitalWrite(TrigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(TrigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(TrigPin,LOW);

 duration=pulseIn(EchoPin,HIGH);
 distanceCm=duration*0.034/2;
 distanceInch=duration*0.0133/2;

 lcd.setCursor(0,0);
 lcd.print("Distance=");
 lcd.print(distanceCm);
 lcd.print("cm");
 delay(10);

 lcd.setCursor(0,1);
 lcd.print("Distance=");
 lcd.print(distanceInch);
 lcd.print("inch");

 if(distanceCm<=10){
  lcd.setCursor(0,1);
  lcd.print("Warning Danger  ");
  delay(1000);
  }
}
