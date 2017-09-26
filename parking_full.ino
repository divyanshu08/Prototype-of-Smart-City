
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,13,9,4,5,6,7);

int ir1=2;
int ir2=3;

int proxy1=0;
int proxy2=0;

void setup()
{

  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  
  Serial.begin(9600);
  lcd.begin(16,2);

}

void loop()
{
  proxy1=digitalRead(ir1);
  proxy2=digitalRead(ir2);

  lcd.setCursor(0,0);
 

  if(proxy1==LOW && proxy2==LOW)
  {
    lcd.println("space available");
    Serial.print("empty"); 
    
  }

  if(proxy1==HIGH && proxy2==LOW)
  {
    lcd.println("space available");
    Serial.print("space available"); 
  }
  if(proxy1==LOW && proxy2==HIGH)
  {
    lcd.println("space available");
    Serial.print("space available"); 
  }
   if(proxy1==HIGH&&proxy2==HIGH)
   
  {
    lcd.println("FULL");
    Serial.print("full");
  }
  
}

