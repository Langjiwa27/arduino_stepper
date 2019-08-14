#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
unsigned long mulai, selesai, dataStopWatch;

const int TblStart = 14;
const int TblStop = 15;
int fPaus = 0;
long lastButton = 0; 
long delayAntiBouncing = 50; 
long dataPaus = 0;

void setup(){
  pinMode(TblStart,INPUT);
  digitalWrite(TblStart,HIGH); //1
  pinMode(TblStop,INPUT);
  digitalWrite(TblStop,HIGH); //1
  
  lcd.begin(16, 2);
  lcd.clear();
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

double i = 0;
double a = millis();
double c ;

void loop(){
  lcd.clear();
    lcd.print("press start");
    delay(100);

    if(digitalRead(TblStart) == LOW) {
        lcd.clear();
        a = millis();
        while(digitalRead(TblStop) == HIGH) {

            c = millis();
            i = (c - a) / 1000;
            lcd.print(i);
            lcd.setCursor(0, 1);   
            lcd.print("00:00:0.0"); 
            lcd.setCursor(7,0);
            lcd.print("Sec's");
            lcd.setCursor(0,0);
            Serial.println(c);
            Serial.println(a);
            Serial.println(i);
            Serial.println("......");
            delay(100);
        }

        if(digitalRead(TblStop) == LOW) {
            while(digitalRead(TblStart) == HIGH) {

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
//                lcd.setCursor(0,0);
//                lcd.print(i);
//                lcd.setCursor(11,0);
//                lcd.print("");
//                lcd.setCursor(0,0);
//                delay(100);
//            }
//        }
    }
    }
    }
}
