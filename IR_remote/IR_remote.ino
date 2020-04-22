#include<IRremote.h>

int receive=11;

#define NO1 12495
#define NO2 6375
#define NO3 31365
#define NO4 4335
#define NO5 14535

IRrecv irrecv(receive);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  irrecv.enableIRIn();
}
void loop() {
 if(irrecv.decode(&results)){
  unsigned int value=results.value;
  Serial.println(value);
  irrecv.resume();
  
  switch(value){
  case NO1:
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    break;
  case NO2:
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    break;
   case NO3:
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    break;
   case NO4:
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    break;
   case NO5:
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    break;
  }
  }
  }
