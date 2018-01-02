#include <IRremote.h>

int RECV_PIN = 11;
int gruen = 2;
int gelb = 3;
int rot = 4;


IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
  //LED-Schalter();
  //digitalWrite(gruen, HIGH);
  //digitalWrite(gelb, HIGH);
  //digitalWrite(rot, HIGH);
  switch(results.value)
  {
  case 0xFF30CF:
    digitalWrite(gruen, HIGH);
    break;
  
  case 0xFF18E7:  
    digitalWrite(gruen, LOW);
    break;
  }
  
}

