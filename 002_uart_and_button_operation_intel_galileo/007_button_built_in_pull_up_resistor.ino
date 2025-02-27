// встроенный подтягивающий резистор
// 1 когда мы не нажимаем на кнопку
// 0 когда нажимаем на кнопку

void setup()
{
  pinMode(7, INPUT_PULLUP);
  pinMode(15, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(7));
  digitalWrite(15, digitalRead(7)); 
}