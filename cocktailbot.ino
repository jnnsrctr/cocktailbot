#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int i = 0;      //init running var
int pump1 = 7;  //pump1 digital pin
int pump2 = 8;  //pump2 digital pin
int pump3 = 9;  //pump3 digital pin
String drink1 = "Mai Tai";  //max 9 chars
int drink1p1 = 2;
int drink1p2 = 2;
int drink1p3 = 2;
String drink2 = "Mojito";  //max 9 chars
int drink2p1 = 2;
int drink2p2 = 2;
int drink2p3 = 2;
String drink3 = "Gin Tonic";  //max 9 chars
int drink3p1 = 2;
int drink3p2 = 2;
int drink3p3 = 2;
String drinkdone;
//const int switchPin = 6;
//int buttons[6];
//buttons[0] = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
  pinMode(pump3, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("CocktailBot is");
  lcd.setCursor(0, 1);
  lcd.print("ready.");
}

void loop() {
  // put your main code here, to run repeatedly:
  int keyVal = analogRead(A0);
  //lcd.print(keyVal);
  //lcd.print("                ");
  if(keyVal == 1023){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mixing " + drink1);
    while (i < 16)
    {
      digitalWrite(pump1, HIGH);      
      lcd.setCursor(i, 1);
      lcd.write(byte(0));
      delay(500);
      i++;
      if (i == drink1p1){digitalWrite(pump1, LOW); digitalWrite(pump2, HIGH);}
      if (i == (drink1p1+drink1p2)){digitalWrite(pump2, LOW); digitalWrite(pump3, HIGH);}
      if (i == (drink1p1+drink1p2+drink1p3)){digitalWrite(pump3, LOW);}
    }
    done(drink1);
  }
  else if(keyVal >= 990 && keyVal <= 1010){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mixing " + drink2);
    while (i < 16)
    {
      lcd.setCursor(i, 1);
      lcd.write(byte(0));
      delay(500);
      i++;
      if (i == drink2p1){digitalWrite(pump1, LOW); digitalWrite(pump2, HIGH);}
      if (i == (drink2p1+drink2p2)){digitalWrite(pump2, LOW); digitalWrite(pump3, HIGH);}
      if (i == (drink2p1+drink2p2+drink2p3)){digitalWrite(pump3, LOW);}
    }
    done(drink2);
  }
  else if(keyVal >= 505 && keyVal <= 515){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mixing " + drink3);
    while (i < 16)
    {
      lcd.setCursor(i, 1);
      lcd.write(byte(0));
      delay(500);
      i++;
      if (i == drink3p1){digitalWrite(pump1, LOW); digitalWrite(pump2, HIGH);}
      if (i == (drink3p1+drink3p2)){digitalWrite(pump2, LOW); digitalWrite(pump3, HIGH);}
      if (i == (drink3p1+drink3p2+drink3p3)){digitalWrite(pump3, LOW);}
    }
    done(drink3);
  }
}

void done(String drink){
  i = 0;      //reset running var
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(drink + " done. ");
  lcd.setCursor(0, 1);
  lcd.print("Click for next.");
}
