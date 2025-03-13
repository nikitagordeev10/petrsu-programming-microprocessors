// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);
}

void loop()
{
  ton(2, 350, 1000);
  delay(1000);
  noTone(2);
  delay(1000);
}