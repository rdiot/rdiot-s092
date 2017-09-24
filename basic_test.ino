/* TPM-300 Air Quality Module (TPM-300) [S092] : http://rdiot.tistory.com/111 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int pinA = 2; // A
int pinB = 3; // B

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);  
  delay(1000);

  lcd.clear();
}
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S092:TPM-300 Air Q");

  int valueA = digitalRead(pinA);
  int valueB = digitalRead(pinB);
  int airGrade = -1;

  lcd.setCursor(0,1);
  lcd.print("pinA(H/L)=" + (String)valueA + " ");
  
  lcd.setCursor(0,2);
  lcd.print("pinB(H/L)=" + (String)valueB + " ");


  if(valueA == LOW && valueB == LOW)
  {
    airGrade = 0;
  }
  else if(valueA == LOW && valueB == HIGH)
  {
    airGrade = 1;
  }
  else if(valueA == HIGH && valueB == LOW)
  {
    airGrade = 2;
  }
  else if(valueA == HIGH && valueB == HIGH)
  {
    airGrade = 3;
  }

  lcd.setCursor(0,3);
  lcd.print("Air Grade 0~3=" + (String)airGrade + " ");

  delay(300);
}
