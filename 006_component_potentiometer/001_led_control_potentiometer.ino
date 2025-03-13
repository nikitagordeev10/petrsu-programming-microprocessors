int ledPin=9;
int potPin=A0;
int potValue;
int pinValue;
int DT=1000;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  potValue=analogRead(potPin);
  Serial.println(potValue);
  delay(DT);
  pinValue=(255.0/1023.0)*potValue;
  analogWrite(ledPin,pinValue);
}
