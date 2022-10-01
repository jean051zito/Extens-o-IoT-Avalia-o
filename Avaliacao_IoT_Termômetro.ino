// C++ code
//
int Graus = 0;

void setup()
{
  pinMode(A3, INPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  Graus = (-40 + 0.488155 * (analogRead(A3) - 20));
  delay(1000); // Wait for 1000 millisecond(s)
  Serial.println(Graus);
  if (Graus > 30) {
    digitalWrite(2, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    tone(8, 26, 1000); // play tone 8 (G#0 = 26 Hz)
    delay(1000); // Wait for 1000 millisecond(s)
    Serial.println("ALERTA! Temperatura elevada!");
  }
  if (Graus == random(1, 29 + 1)) {
    delay(1000); // Wait for 1000 millisecond(s)
    Serial.println("Temperatura normal:");
    digitalWrite(3, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
  }
  if (Graus <= 0) {
    digitalWrite(4, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    tone(8, 24, 1000); // play tone 7 (G0 = 24 Hz)
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    Serial.println("ALERTA! Temperatura baixa!");
  }
}