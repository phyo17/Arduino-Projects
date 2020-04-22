#include<Servo.h>
Servo servo1;

int potenPin=A0;
int value;
void setup() {
  servo1.attach(9);

}

void loop() {
  value=analogRead(potenPin);
  value=map(value,0,1023,0,180);
  servo1.write(value);
  delay(15);
}
