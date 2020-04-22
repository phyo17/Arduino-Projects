#include <Servo.h>
Servo servo1;
Servo servo2;

int joyX=1;
int joyY=0;

int joyVal;

void setup() {

  servo1.attach(3);
  servo2.attach(5);
  Serial.begin(9600);

}
void loop() {
 joyVal=analogRead(joyX);
 Serial.println(joyVal);
 joyVal=map(joyVal,0,1023,0,180);
 servo1.write(joyVal);
 
 joyVal=analogRead(joyY);
 joyVal=map(joyVal,0,1023,0,180);
 servo2.write(joyVal);

 delay(100);
}
