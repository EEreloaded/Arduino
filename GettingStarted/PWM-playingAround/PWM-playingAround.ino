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
BaseFrequency = 100; //Hertz
DutyCycle = 50;     // %
// ######################################

BaseCycleTime = 1e6 / BaseFrequency; // Microseconds
DCOnTime = int (BaseCycleTime * DutyCycle / 100);
DCOffTime = int (BaseCycleTime - DCOnTime);

DCOn = long (DCOnTime / 1000);
DCOff = long (DCOffTime / 1000);

Serial.begin (9600);
Serial.print ("Frequenz = ");
Serial.println (BaseFrequency);
Serial.print ("Tastverhältnis = ");
Serial.println (DutyCycle);
Serial.println (BaseCycleTime);
Serial.println (DCOnTime);
Serial.println (DCOffTime);
Serial.println (DCOn);
Serial.println (DCOff);
}

void loop() {
digitalWrite (13, HIGH);
//delay (DCOn);
delayMicroseconds (DCOnTime);
digitalWrite (13, LOW);
//delay (DCOff);
delayMicroseconds (DCOffTime);
}
