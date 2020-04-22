#include<LiquidCrystal.h>
#include<DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);
LiquidCrystal lcd(12,11,5,4,3,2);

float hum;
float temp;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  dht.begin();

}
void loop() {
  delay(2000);
  hum=dht.readHumidity();
  temp=dht.readTemperature();
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Humidity=");
  lcd.print(hum);
  lcd.print("%");
  Serial.print("Humidity=");
  Serial.print(hum);
  Serial.print("%  ");
  lcd.setCursor(0,1);
  lcd.print("Temp=");
  lcd.print(temp);
  lcd.print("`C");
  Serial.print("Temp=");
  Serial.print(temp);
  Serial.println("`C");
  delay(500);
  if(temp>=30.0){
    digitalWrite(13,HIGH);
    lcd.clear();

    lcd.print("The temp is high");
    delay(1000);
    }else{
      digitalWrite(13,LOW);
      delay(1000);
      }
  
}
