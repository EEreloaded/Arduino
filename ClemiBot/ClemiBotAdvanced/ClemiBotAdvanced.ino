#include <Servo.h>
Servo schnuffelservo;

// Hier wird festgelegt, an welche Pins wir die Motoren anschließen und wie die Pins heißen sollen, an die wir die Motoren anschließen

// Motoren links
int einschaltenLinks = 10;
int richtungLinks1 = 8;
int richtungLinks2 = 9;

// Motoren rechts
int einschaltenRechts = 5;
int richtungRechts1 = 6;
int richtungRechts2 = 7;

int geschwindigkeit = 0;

int servopos = 90;

int TriggerPin = 11;
int EchoPin = 12;
long duration = 0;
long Abstand;
long Abst;
long AbstandMessen();
long microsecondsToCentimeters();



// Hier wird festgelegt was die Pins machen sollen
void setup()
{
  // Wir sagen allen Pins, dass sie Ausgänge sind, also die Informationen an die Motoren aus den Pins herausgehen
  pinMode(einschaltenLinks, OUTPUT);
  pinMode(richtungLinks1, OUTPUT);
  pinMode(richtungLinks2, OUTPUT);
  
  pinMode(einschaltenRechts, OUTPUT);
  pinMode(richtungRechts1, OUTPUT);
  pinMode(richtungRechts2, OUTPUT);
  schnuffelservo.attach(4);

  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);

//  Serial.begin(9600);

  schnuffelservo.write(15);
  delay (1000);
  schnuffelservo.write(150);
  delay (1000);
 
}



// ########################  Hier kommt das Bewegungsprogramm hin   ##########################
void loop()
{
  // Schnuffelservo auf geradeaus
  schnuffelservo.write(78);
  
  for (servopos = 45; servopos <= 120; servopos += 2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    schnuffelservo.write(servopos);              // tell servo to go to position in variable 'pos'
    FahrenWennFrei();
    // delay(10);                                  // waits 15ms for the servo to reach the position
  }
  for (servopos = 120; servopos >= 45; servopos -= 2) { // goes from 180 degrees to 0 degrees
    schnuffelservo.write(servopos);              // tell servo to go to position in variable 'pos'
    FahrenWennFrei();
    // delay(10);    
  }
 
}
// #############################  Ende des Bewegungsprogramms    #############################

void FahrenWennFrei()
{
  AbstandMessen ();
 
  if (Abstand >=40)
  {
    geschwindigkeit = 255 ;
  }
  else
  {
    geschwindigkeit = 0;
    delay (500);
    rueckRechts (255,200,2000);
  }
 
  vorDauer (geschwindigkeit);
}


long AbstandMessen ()
{
  // Puls zum Ultraschall sender schicken
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  duration = pulseIn(EchoPin, HIGH);

  // convert the time into a distance
  Abstand = microsecondsToCentimeters(duration);
//  Serial.println(Abstand);

  /*  if (cm <= 500)
  {
    Serial.print(cm);
    Serial.println("cm");
  }
  else Serial.println("Ungueltige Messung ! Entfernung groesser als 5 Meter !!!");
  delay(100);
  */
}

void vorDauer (int vBasic)
{
  // Hier sagen wir den linken Motoren, dass sie sich vorwärts drehen sollen
  digitalWrite(richtungLinks1, LOW);
  digitalWrite(richtungLinks2, HIGH);
  // Hier sagen wir den rechten Motoren, dass sie sich vorwärts drehen sollen
  digitalWrite(richtungRechts1, LOW);
  digitalWrite(richtungRechts2, HIGH);

  // Hier schalten wir die linken Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenLinks, vBasic);
  analogWrite(einschaltenRechts, vBasic);
  delay (15);
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void vor (int vBasic, int Duration)
{
  vorRechts (vBasic, 0, Duration);
}

void rueck (int vBasic, int Duration)
{
  rueckRechts (vBasic, 0, Duration);
}

void stoppen (int Duration)
{
  vorRechts (0, 0, Duration);
}




void vorRechts (int vBasic, int vTurn, int Duration)
{
  // Hier sagen wir den linken Motoren, dass sie sich vorwärts drehen sollen
  digitalWrite(richtungLinks1, LOW);
  digitalWrite(richtungLinks2, HIGH);
  // Hier sagen wir den rechten Motoren, dass sie sich vorwärts drehen sollen
  digitalWrite(richtungRechts1, LOW);
  digitalWrite(richtungRechts2, HIGH);

  // Hier schalten wir die linken Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenLinks, vBasic);
  // Hier schalten wir die rechten Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenRechts, vBasic - vTurn);

  // Dauer der Kurve
  delay(Duration);
}

void vorLinks (int vBasic, int vTurn, int Duration)
{
  // Hier sagen wir den linken Motoren, dass sie sich vorwärts drehen sollen
  digitalWrite(richtungLinks1, LOW);
  digitalWrite(richtungLinks2, HIGH);
  // Hier sagen wir den rechten Motoren, dass sie sich vorwärts drehen sollen
  digitalWrite(richtungRechts1, LOW);
  digitalWrite(richtungRechts2, HIGH);

  // Hier schalten wir die linken Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenLinks, vBasic - vTurn);
  // Hier schalten wir die rechten Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenRechts, vBasic);

  // Dauer der Kurve
  delay(Duration);
}

void rueckRechts (int vBasic, int vTurn, int Duration)
{
  // Hier sagen wir den linken Motoren, dass sie sich rückwärts drehen sollen
  digitalWrite(richtungLinks1, HIGH);
  digitalWrite(richtungLinks2, LOW);
  // Hier sagen wir den rechten Motoren, dass sie sich rückwärts drehen sollen
  digitalWrite(richtungRechts1, HIGH);
  digitalWrite(richtungRechts2, LOW);

  // Hier schalten wir die linken Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenLinks, vBasic);
  // Hier schalten wir die rechten Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenRechts, vBasic - vTurn);

  // Dauer der Kurve
  delay(Duration);
}

void rueckLinks (int vBasic, int vTurn, int Duration)
{
  // Hier sagen wir den linken Motoren, dass sie sich rückwärts drehen sollen
  digitalWrite(richtungLinks1, HIGH);
  digitalWrite(richtungLinks2, LOW);
  // Hier sagen wir den rechten Motoren, dass sie sich rückwärts drehen sollen
  digitalWrite(richtungRechts1, HIGH);
  digitalWrite(richtungRechts2, LOW);

  // Hier schalten wir die linken Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenLinks, vBasic - vTurn);
  // Hier schalten wir die rechten Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenRechts, vBasic);

  // Dauer der Kurve
  delay(Duration);
}


 


/*  for (servopos = 15; servopos <= 150; servopos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    schnuffelservo.write(servopos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (servopos = 150; servopos >= 15; servopos -= 1) { // goes from 180 degrees to 0 degrees
    schnuffelservo.write(servopos);              // tell servo to go to position in variable 'pos'
    delay(10);    
  }
*/

