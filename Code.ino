#include <Nokia_5110.h>

#define RST 3
#define CE 4
#define DC 5
#define DIN 11
#define CLK 13

Nokia_5110 lcd = Nokia_5110(RST, CE, DC, DIN, CLK);

#define echo 9
#define trigger 8

float time=0,distance=0;
int p1=7;
int p2=A2;
int aa1;
int kk=0;
int j=0;

void setup()
{
   lcd.setContrast(50);
  aa1=0;
  pinMode(p1,OUTPUT);
   pinMode(trigger,OUTPUT);
   pinMode(echo,INPUT);
   pinMode(p2, INPUT);
   digitalWrite(trigger, LOW);
}

void loop()
{
  kk = analogRead(p2);
 if (kk > 220) {
 if(aa1==0){ 
      digitalWrite(p1,HIGH);
      aa1=1; 
      }
      else{
        digitalWrite(p1,LOW);
      aa1=0;
      }}
  digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=time*340/2000;
  j=distance;

      if (j < 150)
      {
 lcd.clear();
 lcd.setCursor(3, 0);
 lcd.println("Distance:  (mm)");
 lcd.setCursor(31, 3);
 lcd.print(j);
 lcd.print("mm");
 Serial.println(j);
 delay(1000);
      }
      else if  (j < 600)
      {
 lcd.clear();
 lcd.setCursor(3, 0);
 lcd.println("Distance:  (cm)");
 lcd.setCursor(31, 3);
 lcd.print(distance/10);
 lcd.print("cm");
 delay(1000);
      }
      else if  (j >= 600)
      {
 
 lcd.clear();
 lcd.setCursor(3, 0);
 lcd.println("Distance:  (m)");
 lcd.setCursor(31, 3);
 lcd.print(distance/1000);
 lcd.print("m");
 delay(1000);
      }

}

