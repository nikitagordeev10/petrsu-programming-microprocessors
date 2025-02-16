#define GREEN_LED 3
#define YELLOW_LED 5
#define RED_LED 7

unsigned long previousMillis = 0;
int state = 0;
int blinkCount = 0;
bool isBlinking = false;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  switch (state) {
    case 0: // Зеленый 3 сек
      digitalWrite(GREEN_LED, HIGH);
      if (currentMillis - previousMillis >= 3000) {
        previousMillis = currentMillis;
        state = 1;
        blinkCount = 0;
        isBlinking = true;
      }
      break;

    case 1: // Зеленый мигает 3 раза
      if (isBlinking && currentMillis - previousMillis >= 300) {
        previousMillis = currentMillis;
        digitalWrite(GREEN_LED, !digitalRead(GREEN_LED));
        blinkCount++;
        if (blinkCount >= 6) { // 3 цикла включения/выключения
          digitalWrite(GREEN_LED, LOW);
          state = 2;
          previousMillis = currentMillis;
        }
      }
      break;

    case 2: // Желтый 1 сек
      digitalWrite(YELLOW_LED, HIGH);
      if (currentMillis - previousMillis >= 1000) {
        digitalWrite(YELLOW_LED, LOW);
        previousMillis = currentMillis;
        state = 3;
      }
      break;

    case 3: // Красный 3 сек
      digitalWrite(RED_LED, HIGH);
      if (currentMillis - previousMillis >= 3000) {
        digitalWrite(RED_LED, LOW);
        previousMillis = currentMillis;
        state = 0;
      }
      break;
  }
}