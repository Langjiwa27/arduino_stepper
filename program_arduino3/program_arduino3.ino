#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);

unsigned long mulai, selesai, dataStopWatch;
int i=0;
int fPaus = 0;
long lastButton = 0; 
long delayAntiBouncing = 50; 
long dataPaus = 0;
int state = 0;

//inialisasi masing2 nilai awal waktu
int sepersepuluhDetik = 0;
int detik = 0;
int menit = 0;
int jam = 0;

//Tombol Start / Stop
const int TblStart = 14; // masuk pin A0
const int TblStop = 15;  // masuk pin A1
const int TblReset = 16; // masuk pin A2
////Motor X
const int stepPin = 3;
const int dirPin = 6; 
////Motor Y
const int stepPin2 = 2;
const int dirPin2 = 5; 


void setup(){
  Serial.begin(9600);
//  Motor
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  //Tombol
  pinMode(TblStart,INPUT);
  pinMode(TblStop,INPUT);
  pinMode(TblReset,INPUT);
  digitalWrite(TblStart, HIGH);
  digitalWrite(TblStop, HIGH);
  digitalWrite(TblReset, HIGH);
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
void motor(){
  digitalWrite(dirPin,HIGH);
    digitalWrite(dirPin2,HIGH);
    for(int x = 0; x < 400; x++) {
      digitalWrite(stepPin,HIGH);
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      digitalWrite(stepPin2,LOW);
      delayMicroseconds(500);
      Serial.println("kanan");
      }
      delay(200);

    digitalWrite(dirPin,LOW);
    digitalWrite(dirPin2,LOW); 
    for(int x = 0; x < 400; x++) {
      digitalWrite(stepPin,HIGH);
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      digitalWrite(stepPin2,LOW);
      delayMicroseconds(500);
      Serial.println("kiri");
      }
}

void loop(){
  motor();
}

//void loop(){
//  
//   //jika tombol reset ditekan
//  if (digitalRead(TblReset) == LOW) {
//    //niali state menjadi = 0
//    state = 0;
//    Serial.println("Reset");
//    }
//
////jika tombol stop ditekan
//  else if (digitalRead(TblStop) == LOW)
//  {
//    //niali state menjadi = 1
//    state = 1;
//    Serial.println("Stop");
//  }
//
////jika tombol start ditekan
//  else if (digitalRead(TblStart) == LOW)
//  {
// //nilai state menjadi = 2
//    state = 2;
//    Serial.println("Start");
//  }
//  
////jika nilai state =0, maka
//  if (state == 0)
//  {
// //nilai masing2 variabel menjadi demikian
//    sepersepuluhDetik = 0;
//    detik = 0;
//    menit = 0;
//    jam = 0;
//  }
//
////jika nilai state = 1
//  else if (state == 1)
//  {
// //nilai masing2 variabel tetap
//    sepersepuluhDetik = sepersepuluhDetik;
//    detik = detik;
//    menit = menit;
//    jam = jam;
//  }
//
////jika nilai state = 2
//   else if (state == 2)
//  {
// //nilai sepersepuluhDetik bertambah terus
//    sepersepuluhDetik++;
//  }
//
////jika nilai sepersepuluhDetik lebih besar sama dengan 10
//  if (sepersepuluhDetik >= 10)
//  {
// //nilai sepersepuluhDetik menjadi 0 lagi
//    sepersepuluhDetik = 0;
// //nilai detik bertambah 1
//    detik += 1;
//  }
//
////jika niali detik lebih dari sama dengan 60
//  if (detik >= 60)
//  {
// //niali detik menjadi 0
//    detik = 0;
// //nilai menit bertambah 1
//    menit += 1;
//  }
//
////jika nilai menit lebih dari sama dengan 60
//  if (menit >= 60)
//  {
// //nilai menit kembali menjadi 0
//    menit = 0;
// //nilai jam bertambah 1
//    jam += 1;
//  }
//
////menuliskan pembacaan stopwatch pada lcd
//  lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print("Stopwatch");
//  lcd.setCursor(9, 1); //(0)
//  lcd.print(sepersepuluhDetik);
//  lcd.setCursor(8, 1); //(2)
//  lcd.print(":");
//  lcd.setCursor(6, 1); //(3)
//  lcd.print(detik);
//  lcd.setCursor(5, 1); //(5)
//  lcd.print(":");
//  lcd.setCursor(3, 1); //(6)
//  lcd.print(menit);
//  lcd.setCursor(2, 1); //(8)
//  lcd.print(":");
//  lcd.setCursor(0, 1); //(9)
//  lcd.print(jam);
// //delay untuk perhitungan sepersepuluhDetik
//  delay(100);
//
//}
