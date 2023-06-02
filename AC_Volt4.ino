#include <LiquidCrystal.h>  // initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int sensorIn = A0;
double Voltage = 0;
double VRMS = 0;
int i;

void setup(){ 
 Serial.begin(9600);
 lcd.begin(16,2); // set up the LCD’s number of columns and rows:
}

void loop(){
  
  VRMS = voltage_READ();
  lcd.setCursor(0,0); 
  lcd.print("V=");
  lcd.print(VRMS);
  lcd.print("V");
 // Serial.print("V = ");
  //Serial.print(VRMS);
  //Serial.println("V");
  delay(1000);
}


 float voltage_READ(void)
 {
 float max;
 int i;
 unsigned int temp=0;
 float maxpoint = 0;
 for(i=0;i<500;i++)
      {
         if(temp =analogRead(sensorIn),temp>maxpoint)
         {
            maxpoint = temp;
         }
      }

 maxpoint = maxpoint * (5.0/1023.0);
maxpoint = (maxpoint - 2.5);              //offset voltage
maxpoint = maxpoint * 214.6383;        //Gain
 max=maxpoint *.7071;
 return max;
 }
