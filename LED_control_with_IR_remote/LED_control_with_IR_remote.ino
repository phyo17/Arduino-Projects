#include<IRremote.h>

int receive=5;

#define NO1 48703
#define NO2 58359
#define NO3 539
#define NO4 25979
#define NO5 15547

IRrecv irrecv(receive);
decode_results results;
void setup() {
  Serial.begin(9600);
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
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        break;
      case NO5:
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        break;
      }

}
} 
