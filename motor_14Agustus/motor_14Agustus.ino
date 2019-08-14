#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);

unsigned long mulai, selesai, dataStopWatch;
int i=0;
int fPaus = 0;
long lastButton = 0; 
long delayAntiBouncing = 50; 
long dataPaus = 0;

//Tombol Start / Stop
const int TblStart = 14; // masuk pin A1
const int TblStop = 15;  // masuk pin A2
//Motor X
const int stepPin = 3;
const int dirPin = 6; 
//Motor Y
const int stepPin2 = 2;
const int dirPin2 = 5; 


void setup(){
  Serial.begin(9600);
  //Motor
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  //Tombol
  pinMode(TblStart,INPUT);
  pinMode(TblStop,INPUT);
  digitalWrite(TblStart,1);
  digitalWrite(TblStop,1);
  //LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0); 
  lcd.print("     Resusitasi");
  lcd.setCursor(0, 1); 
  lcd.print("    Jantung Paru ");
  delay(2000);
  lcd.clear();
  lcd.print("    Tekan Tombol");
  lcd.setCursor(0, 1); 
  lcd.print("       Start ");
}

void motor() {
  digitalWrite(dirPin,HIGH);
  digitalWrite(dirPin2,HIGH);
   for(int x = 0; x < 400; x++) {
     digitalWrite(stepPin,HIGH);
     digitalWrite(stepPin2,HIGH);
     delayMicroseconds(500);
     Serial.print("Motor Muter High");
     Serial.println("");
     digitalWrite(stepPin,LOW);
     digitalWrite(stepPin2,LOW);
     delayMicroseconds(500);
     Serial.print("Motor Muter Low");
     Serial.println("");
     }
     delay(200);

      digitalWrite(dirPin,LOW);
      digitalWrite(dirPin2,LOW); 
      for(int x = 0; x < 400; x++) {
        digitalWrite(stepPin,HIGH);
        digitalWrite(stepPin2,HIGH);
        delayMicroseconds(500);
        Serial.print("Motor Muter High");
        Serial.println("");
        digitalWrite(stepPin,LOW);
        digitalWrite(stepPin2,LOW);
        delayMicroseconds(500);
        Serial.print("Motor Muter Low");
        Serial.println("");
        }
}

void loop(){
  if (digitalRead(TblStart)==0){
    motor();
    delay(4000);
    break();
   
      if ((millis() - lastButton) > delayAntiBouncing){
        if (i==0){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Start ");
          mulai = millis();
          fPaus = 0;
        }
        else if (i==1){
          lcd.setCursor(0, 0);
          lcd.print("Stop  ");
          dataPaus = dataStopWatch;
          fPaus = 1;
        }
        i =!i;
      }
      lastButton = millis();
  }
  else if (digitalRead(TblStop)==0 && fPaus == 1){
    Serial.print("Motor Berhenti");
    dataStopWatch = 0;
    dataPaus = 0; 
    lcd.clear();
    lcd.print("Sistem Reset ");
    lcd.setCursor(0, 1); 
    lcd.print("Berhasil");  
    delay(2000);
    lcd.clear();
    lcd.print("    Tekan Tombol");
    lcd.setCursor(0, 1); 
    lcd.print("       Start ");
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
//   if (digitalRead(TblStart)==0){
//      
}
