int TrigPin=11;
int EchoPin=12;
int duration;
int distanceCm;
int distanceInch;

void setup() {
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  Serial.begin(9600);

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

  Serial.print("Distance Cm=");
  Serial.println(distanceCm);
  Serial.print("Distance Inch=");
  Serial.println(distanceInch);

  delay(1500);
  

}
