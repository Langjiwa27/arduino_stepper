#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
const int stepPin = 3; // Motor X
const int dirPin = 6; // Motor X
const int stepPin2 = 2; // Motor Y
const int dirPin2 = 5;  // Motor Y
unsigned long mulai, selesai, dataStopWatch;
int i=0;
int fPaus = 0;
long lastButton = 0; 
long delayAntiBouncing = 50; 
long dataPaus = 0;

const int TblStart = 14;
const int TblStop = 15;

void setup(){
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(TblStart,INPUT);
  pinMode(TblStop,INPUT);
  digitalWrite(A0,1);
  digitalWrite(A1,1);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0); 
  lcd.print("   Resusitasi");
  lcd.setCursor(0, 1); 
  lcd.print("  Jantung Paru ");
  delay(2000);
  lcd.clear();
  lcd.print("  Tekan ");
  lcd.setCursor(0, 1); 
  lcd.print("  Start");
  lcd.backlight();
}

void loop(){
if (digitalRead(TblStart)== LOW){
  if ((millis() - lastButton) > delayAntiBouncing){
      if (i==1){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Start Timer");
          mulai = millis();
            }
       else if (i==0){
    fPaus = 0;
          // program Motor Stepper
        lcd.setCursor(0, 0);
        lcd.print("Timer  ");
        dataPaus = dataStopWatch;
        fPaus = 1;
        }
       i =!i;
      }
      lastButton = millis();
  }
 else if (digitalRead(TblStop)==0 && fPaus == 1){
  dataStopWatch = 0;
  dataPaus = 0; 
  lcd.clear();
  lcd.print("Reset Timer");
  lcd.setCursor(0, 1); 
  lcd.print("00:00:0.0");  
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 1); 
  lcd.print("  Start / Stop");
 }
  
  if (i==1){
      selesai = millis(); 
      float jam, menit, detik, miliDetik;
      unsigned long over;

      // MATH time!!!
      dataStopWatch = selesai - mulai;
      dataStopWatch = dataPaus + dataStopWatch;

      jam = int(dataStopWatch / 3600000);
      over = dataStopWatch % 3600000;
      menit = int(over / 60000);
      over = over % 60000;
      detik = int(over / 1000);
      miliDetik = over % 1000;

      lcd.setCursor(0, 1);
      lcd.print(jam, 00); 
      lcd.print(":"); 
      lcd.print(menit, 00);
      lcd.print(":");
      lcd.print(detik, 00);
      lcd.print(".");
      if (jam < 10){
          lcd.print(miliDetik, 0);
          lcd.print("   ");
       }
   }
}
