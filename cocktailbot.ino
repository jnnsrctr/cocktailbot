#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int i = 0;      //init running var
int pump1 = 7;  //pump1 digital pin
int pump2 = 8;  //pump2 digital pin
int pump3 = 9;  //pump3 digital pin
int dellay = 750;
String drinkdone;
bool showPump = true;
String version = "v0.7";

///////////////////
// BEGIN RECIPES //
///////////////////

String drink1 = "Red Bull";  //max 9 chars
int drink1p1 = 8;
int drink1p2 = 8;
int drink1p3 = 0;
String drink2 = "Manpower";  //max 9 chars
int drink2p1 = 0;
int drink2p2 = 8;
int drink2p3 = 8;
String drink3 = "Lavendar";  //max 9 chars
int drink3p1 = 8;
int drink3p2 = 0;
int drink3p3 = 8;

///////////////////
//  END RECIPES  //
///////////////////

void setup() {
  // put your setup code here, to run once:
  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
  pinMode(pump3, OUTPUT);
  kill(); //switch off all pumps
  //start LCD and dispay welcome screen
  lcd.begin(16, 2);
  lcd.print("CocktailBot");
  lcd.setCursor(0, 1);
  lcd.print("is ready.");
  lcd.setCursor(12, 1);
  lcd.print(version);
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
      if (i == 0)
      {
        if (drink1p1 != 0)
        {
          digitalWrite(pump1, HIGH);
        } else if (drink1p2 != 0)
        {
          digitalWrite(pump2, HIGH);
        } else if (drink1p3 != 0)
        {
          digitalWrite(pump3, HIGH);
        } else
        {
          done("ERROR");
        }
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print("1");
        }
      } 
      lcd.setCursor(i, 1);
      lcd.write(byte(0));
      delay(dellay);
      i++;
      if (i == drink1p1)
      {
        digitalWrite(pump1, LOW);
        digitalWrite(pump2, HIGH);
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print("2");
        }
      }
      if (i == (drink1p1+drink1p2))
      {
        digitalWrite(pump2, LOW);
        digitalWrite(pump3, HIGH);
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print("3");
        }
      }
      if (i == (drink1p1+drink1p2+drink1p3))
      {
        digitalWrite(pump3, LOW);
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print(" ");
        }
      }
    }
    done(drink1);
  }
  else if(keyVal >= 990 && keyVal <= 1010){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mixing " + drink2);
    while (i < 16)
    {
      if (i == 0)
      {
        if (drink2p1 != 0)
        {
          digitalWrite(pump1, HIGH);
        } else if (drink2p2 != 0)
        {
          digitalWrite(pump2, HIGH);
        } else if (drink2p3 != 0)
        {
          digitalWrite(pump3, HIGH);
        } else
        {
          done("ERROR");
        }
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print("1");
        }
      } 
      lcd.setCursor(i, 1);
      lcd.write(byte(0));
      delay(dellay);
      i++;
      if (i == drink2p1)
      {
        digitalWrite(pump1, LOW);
        digitalWrite(pump2, HIGH);
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print("2");
        }
      }
      if (i == (drink2p1+drink2p2))
      {
        digitalWrite(pump2, LOW);
        digitalWrite(pump3, HIGH);
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print("3");
        }
      }
      if (i == (drink2p1+drink2p2+drink2p3))
      {
        digitalWrite(pump3, LOW);
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print(" ");
        }
      }
    }
    done(drink2);
  }
  else if(keyVal >= 505 && keyVal <= 515){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mixing " + drink3);
    while (i < 16)
    {
      if (i == 0)
      {
        if (drink3p1 != 0)
        {
          digitalWrite(pump1, HIGH);
        } else if (drink3p2 != 0)
        {
          digitalWrite(pump2, HIGH);
        } else if (drink3p3 != 0)
        {
          digitalWrite(pump3, HIGH);
        } else
        {
          done("ERROR");
        }
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print("1");
        }
      } 
      lcd.setCursor(i, 1);
      lcd.write(byte(0));
      delay(dellay);
      i++;
      if (i == drink3p1)
      {
        digitalWrite(pump1, LOW);
        digitalWrite(pump2, HIGH);
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print("2");
        }
      }
      if (i == (drink3p1+drink3p2))
      {
        digitalWrite(pump2, LOW);
        digitalWrite(pump3, HIGH);
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print("3");
        }
      }
      if (i == (drink3p1+drink3p2+drink3p3))
      {
        digitalWrite(pump3, LOW);
        if (showPump == true)
        {
          lcd.setCursor(15, 1);
          lcd.print(" ");
        }
      }
    }
    done(drink3);
  }
}

void done(String drink){
  kill();
  i = 0;      //reset running var
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(drink + " done. ");
  lcd.setCursor(0, 1);
  lcd.print("Click for next.");
}

void kill(){
  digitalWrite(pump1, LOW);
  digitalWrite(pump2, LOW);
  digitalWrite(pump3, LOW);
}
