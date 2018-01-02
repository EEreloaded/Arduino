void __ardublockDigitalWrite(int pinNumber, boolean status)
{
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, status);
}


void setup()
{
}

void loop()
{
  __ardublockDigitalWrite(13, HIGH);
  delay( 200 );
  __ardublockDigitalWrite(12, HIGH);
  delay( 200 );
  __ardublockDigitalWrite(8, HIGH);
  delay( 500 );
  __ardublockDigitalWrite(13, LOW);
  delay( 200 );
  __ardublockDigitalWrite(12, LOW);
  delay( 200 );
  __ardublockDigitalWrite(8, LOW);
  delay( 500 );
}


