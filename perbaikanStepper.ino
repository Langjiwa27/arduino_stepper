#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);



// Motor X
const int stepPin = 3;
const int dirPin = 6; 

// Motor Y
const int stepPin2 = 2;
const int dirPin2 = 5; 

//Tombol Start / Stop
const int TblStart = 14; // masuk pin A1
const int TblStop = 15;  // masuk pin A2

int stepCount = 0;

int buttonState;             
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
 
void setup() {
  Serial.begin(9600);
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
  LCD.begin(16, 2);
  LCD.setCursor(0, 0); 
  LCD.print("     Resusitasi");
  LCD.setCursor(0, 1); 
  LCD.print("    Jantung Paru ");
  delay(2000);
  LCD.clear();
  LCD.print("    Tekan Tombol");
  LCD.setCursor(0, 1); 
  LCD.print("       Start ");
  
}
                                                                               
void loop() {
  if (digitalRead(TblStart)==0) {
    digitalWrite(dirPin,HIGH); // Motor X - putar searah
    digitalWrite(dirPin2,HIGH); // Motor Y - putar searah
    for(int x = 0; x < 500; x++) {
      digitalWrite(stepPin,HIGH);
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      digitalWrite(stepPin2,LOW);
      delayMicroseconds(500);
    }
    delay(200);

    digitalWrite(dirPin,LOW); // Motor X - putar balik
    digitalWrite(dirPin2,LOW); // Motor Y - putar balik
    for(int x = 0; x < 500; x++) {
  // x < 400; 
      digitalWrite(stepPin,HIGH);
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(500); //500
      digitalWrite(stepPin,LOW);
      digitalWrite(stepPin2,LOW);
      delayMicroseconds(500);
    }
    LCD.clear();
   Serial.println(" kompresi");
   LCD.setCursor(6, 2);
   LCD.print("  kompresi");
   
   LCD.setCursor(5, 2);
   LCD.print(stepCount);
   Serial.print(stepCount);
   stepCount++;

   if (stepCount == 30){
    digitalWrite(dirPin,LOW);
    digitalWrite(dirPin2,LOW);
    delay (3000);
   }
   if (stepCount == 60){
    digitalWrite(dirPin,LOW);
    digitalWrite(dirPin2,LOW);
    delay (3000);
   }
   if (stepCount == 90){
    digitalWrite(dirPin,LOW);
    digitalWrite(dirPin2,LOW);
    delay (3000);
   }
  }

  else if (digitalRead(TblStop)==0) {
    LCD.clear();
    Serial.println("Reset");
    LCD.setCursor(6, 2);
    LCD.print(" Reset ");
    stepCount = 0;
    delay(500);
    delay(2000);
    LCD.clear();
    LCD.print("    Tekan Tombol");
    LCD.setCursor(0, 1); 
    LCD.print("       Start ");
  }
}
