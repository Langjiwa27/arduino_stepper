
// Motor X
const int stepPin = 3;
const int dirPin = 6; 

// Motor Y
const int stepPin2 = 2;
const int dirPin2 = 5; 
 
void setup() {
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}                                                                               
void loop() {
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
  delayMicroseconds(500);}
}
