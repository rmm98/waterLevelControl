#include <LiquidCrystal.h>

int level1 = A0;
int level2 = A1;
int level3 = A2;
int level4 = A3;
int level5 = A5;

int motor = 7;

int a;
int b;
int c;
int d;
int e;

int r; //Water Pump status flag
int z = 100; // Adjust this value from 100 to 1023 if your circuit do not show correct value.


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(motor, OUTPUT);
  lcd.begin(16,2);
}

void loop()
{
  a = analogRead(level1);
  b = analogRead(level2);
  c = analogRead(level3);
  d = analogRead(level4);
  e = analogRead(level5);
  
  lcd.clear();

  if(a>z && b>z && c>z && d>z && e>z)
  {
    digitalWrite(motor,LOW);
    lcd.setCursor(0,0);
    lcd.print("Tank is Full.");
  }

  else if(a>z && b>z && c>z && d>z && e<z)
  {
    lcd.setCursor(0,0);
    lcd.print("Tank is 80% Full");
  }

  else if(a>z && b>z && c>z && d<z && e<z)
  {
    lcd.setCursor(0,0);
    lcd.print("Tank is 60% Full");
  }

  else if(a>z && b>z && c<z && d<z && e<z)
  {
    lcd.setCursor(0,0);
    lcd.print("Tank is 40% Full");
  }

  else if(a>z && b<z && c<z && d<z && e<z)
  {
    lcd.setCursor(0,0);
    lcd.print("Tank is 20% Full");
  }

  else
  {
    lcd.setCursor(0,0);
    lcd.print("Tank is Empty");
    digitalWrite(motor,HIGH);
  }

  r = digitalRead(motor);
  
  if (r == LOW)
  {
    lcd.setCursor(0,1);
    lcd.print("Water Pump - OFF");
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("Water Pump - ON");
  }
  
  delay(1000);
  lcd.clear();
}
