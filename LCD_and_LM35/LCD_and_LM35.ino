#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int Temp=A0;
int TempC;
int TempF;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

}
void loop() {
  TempC=analogRead(Temp);
  TempC=(TempC/1024.0)*5000;
  TempC=TempC/10;

  TempF=((TempC*9)/5+32);

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Temp= ");
  lcd.print(TempC);
  lcd.print(" C");
  Serial.print("TempC= ");
  Serial.println(TempC);
  
  lcd.setCursor(0,1);
  lcd.print(" Temp= ");
  lcd.print(TempF);
  lcd.print(" F");
  Serial.print("TempF= ");
  Serial.println(TempF);
  
  delay(1000);

}
