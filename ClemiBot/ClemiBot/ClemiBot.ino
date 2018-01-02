// Hier wird festgelegt, an welche Pins wir die Motoren anschließen und wie die Pins heißen sollen, an die wir die Motoren anschließen

// Motoren links
int einschaltenLinks = 10;
int richtungLinks1 = 9;
int richtungLinks2 = 8;

// Motoren rechts
int einschaltenRechts = 5;
int richtungRechts1 = 7;
int richtungRechts2 = 6;


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
}

void loop()
{
// Erstmal volle Pulle geradeaus fahren
  // Hier sagen wir den linken Motoren, dass sie sich vorwärts drehen sollen
  digitalWrite(richtungLinks1, LOW);
  digitalWrite(richtungLinks2, HIGH);
  // Hier schalten wir die linken Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenLinks, 255);

  // Hier sagen wir den rechten Motoren, dass sie sich vorwärts drehen sollen
  digitalWrite(richtungRechts1, LOW);
  digitalWrite(richtungRechts2, HIGH);
  // Hier schalten wir die rechten Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenRechts, 255);
    
  // Hier warten wir 5000 Millisekunden = 5 Sekunden, bevor der Computer einen neuen Auftrag bekommt
  delay(5000);

// Dann Rechtskurve fahren
    // Hier schalten wir die linken Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenLinks, 255);

  // Hier schalten wir die rechten Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenRechts, 0);

  // Hier warten wir 3000 Millisekunden = 3 Sekunden, bevor der Computer einen neuen Auftrag bekommt
  delay(3000);

// Jetzt Rechtskurve rückwärts  
  // Hier sagen wir den linken Motoren, dass sie sich rückwärts drehen sollen
  digitalWrite(richtungLinks1, HIGH);
  digitalWrite(richtungLinks2, LOW);  
  
  // Hier sagen wir den rechten Motoren, dass sie sich rückwärts drehen sollen
  digitalWrite(richtungRechts1, HIGH);
  digitalWrite(richtungRechts2, LOW); 

  // Hier warten wir 3000 Millisekunden = 3 Sekunden, bevor der Computer einen neuen Auftrag bekommt
  delay(3000);

// Jetzt geradeaus rückwärts
   // Hier schalten wir die linken Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenLinks, 255);

  // Hier schalten wir die rechten Motoren ein mit einer Geschwindigkeit zwischen 0~255
  analogWrite(einschaltenRechts, 255);
  
  // Hier warten wir 5000 Millisekunden = 5 Sekunden, bevor der Computer einen neuen Auftrag bekommt
  delay(5000);

// Und jetzt fängt er wieder von oben an
}

