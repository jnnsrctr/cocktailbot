#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//const int switchPin = 6;
//int buttons[6];
//buttons[0] = 2;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("CocktailBot rdy.");
}

void loop() {
  // put your main code here, to run repeatedly:
  int keyVal = analogRead(A0);
  //lcd.print(keyVal);
  //lcd.print("                ");
  if(keyVal == 1023){
    lcd.setCursor(0, 0);
    lcd.print("Button 1        ");
  }
  else if(keyVal >= 990 && keyVal <= 1010){
    lcd.setCursor(0, 0);
    lcd.print("Button 2        ");
  }
  else if(keyVal >= 505 && keyVal <= 515){
    lcd.setCursor(0, 0);
    lcd.print("Button 3        ");
  }
  else{
    lcd.setCursor(0, 0);
    lcd.print("CocktailBot rdy.");
  }
}
