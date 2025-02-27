// стягивающий резистор
// 0 когда мы не нажимаем на кнопку
// 1 когда нажимаем на кнопку

void setup()
{
  pinMode(7, INPUT);
  pinMode(15, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(7));
  digitalWrite(15, digitalRead(7));
  
}