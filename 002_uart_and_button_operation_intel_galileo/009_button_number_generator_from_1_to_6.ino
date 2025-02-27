// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  pinMode(A0, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(A0) == 1) {
  	int rand = random(1, 7);
    Serial.println(rand);
    
    if (rand == 1) {
    	digitalWrite(2, 1);
    }
    if (rand == 2) {
    	digitalWrite(2, 1);
        digitalWrite(3, 1);
    }
    if (rand == 3) {
    	digitalWrite(2, 1);
        digitalWrite(3, 1);
        digitalWrite(4, 1);
    }
    if (rand == 4) {
    	digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
    }
    if (rand == 5) {
    	digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
    }
    if (rand == 6) {
    	digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
    }
    
    delay(3000);
    
       digitalWrite(2, 0);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 0);
  }
}