int DutyCycle;
int DCOnTime;
int analogPin = A0;
long analogVal = 0;
long dimVal = 0;
long potiDC;

void setup() {
// ########  Input Values  ##############
DutyCycle = 50;     // %
// ######################################

DCOnTime = 255 * DutyCycle / 100;


Serial.begin (9600);
/*Serial.print ("Tastverhältnis = ");
Serial.println (DutyCycle);
Serial.print ("Umgerechnet = ");
Serial.println (DCOnTime);*/

pinMode (2, OUTPUT);
analogWrite (2, DCOnTime);
pinMode (3, OUTPUT);
analogWrite (3, DCOnTime);

pinMode (4, OUTPUT);

pinMode (5, OUTPUT);
analogWrite (5, DCOnTime);
pinMode (6, OUTPUT);
analogWrite (6, DCOnTime);
pinMode (7, OUTPUT);
analogWrite (7, DCOnTime);
pinMode (8, OUTPUT);
analogWrite (8, DCOnTime);
pinMode (9, OUTPUT);
analogWrite (9, DCOnTime);
pinMode (10, OUTPUT);
analogWrite (10, DCOnTime);
pinMode (11, OUTPUT);
analogWrite (11, DCOnTime);
pinMode (12, OUTPUT);
analogWrite (12, DCOnTime);
pinMode (13, OUTPUT);
analogWrite (13, DCOnTime);
}

void loop () {
  analogVal = analogRead (analogPin);
  dimVal = analogVal * 255 / 1023;
  potiDC = dimVal * 100 /255;
/*  Serial.print (analogVal);
  Serial.print ("     ");
  Serial.print (dimVal);
  Serial.print ("     "); */
  Serial.println (potiDC);
  analogWrite (4, dimVal);
  delay (10);
}
