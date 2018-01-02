float BaseFrequency;
float DutyCycle;
float BaseCycleTime;
unsigned int DCOnTime;
unsigned int DCOffTime;
long DCOn;
long DCOff;

void setup() {
// pinMode (13, OUTPUT);
// analogWrite (13, 254);

// ########  Input Values  ##############
BaseFrequency = 300; //Hertz
DutyCycle = 33;     // %
// ######################################

BaseCycleTime = 1e6 / BaseFrequency; // Microseconds
DCOnTime = int (BaseCycleTime * DutyCycle / 100);
DCOffTime = int (BaseCycleTime - DCOnTime);

DCOn = long (DCOnTime / 1000);
DCOff = long (DCOffTime / 1000);

Serial.begin (9600);
Serial.println (BaseCycleTime);
Serial.println (DCOnTime);
Serial.println (DCOffTime);
Serial.println (DCOn);
Serial.println (DCOff);
}

void loop() {
pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM20);
  TCCR2B = _BV(CS22);
  OCR2A = 180;
  OCR2B = 50;
}
