#define PLAYER_COUNT 2

// Пины для кнопок и светодиодов
int buttonPins[PLAYER_COUNT] = {2, 13};
int ledPins[PLAYER_COUNT] = {3, 12};

// Пин для светодиода №3
#define LED3_PIN 9

// Переменные для хранения состояния игры
bool gameActive = false;
unsigned long gameStartTime;
unsigned long gameDuration;
bool buttonPressedBeforeEnd[PLAYER_COUNT]; // Состояние кнопок до окончания мерцания


void setup() {
  // Инициализация пинов для кнопок и светодиодов
  for (int i = 0; i < PLAYER_COUNT; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  // Инициализация светодиода №3
  pinMode(LED3_PIN, OUTPUT);
  digitalWrite(LED3_PIN, LOW);
	
  Serial.begin(9600);
  // Запуск игры
  startGame();
}

void loop() {
  if (gameActive) {
    // Проверка, истекло ли время мерцания светодиода №3
    if (millis() - gameStartTime >= gameDuration) {
      digitalWrite(LED3_PIN, LOW);  // Выключение светодиода №3
      gameActive = false;
	  
      // Сохраняем состояние кнопок в момент выключения светодиода
      for (int i = 0; i < PLAYER_COUNT; i++) {
        buttonPressedBeforeEnd[i] = digitalRead(buttonPins[i]) == HIGH;
      }
      
      // Ожидание нажатия кнопки
      int winner = -1;
      Serial.println("Get winer");
      unsigned long reactionTime = millis();

      while (winner == -1) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
          if (digitalRead(buttonPins[i]) == HIGH && !buttonPressedBeforeEnd[i]) {
            winner = i;
            break;
          }
        }
        if (millis() - reactionTime > 2000) {
          break;
        }
      }

      // Включение светодиода победителя
      digitalWrite(ledPins[winner], HIGH);
      delay(500);  // Задержка для визуализации победы
      digitalWrite(ledPins[winner], LOW);

      // Перезапуск игры
      startGame();
    }
  }
}

void startGame() {
  // Генерация случайного времени мерцания светодиода №3
  gameDuration = random(1000, 2500);
  gameStartTime = millis();
  gameActive = true;

  // Плавное мерцание светодиода №3
  for (int i = 0; i < 255; i++) {
    analogWrite(LED3_PIN, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED3_PIN, i);
    delay(10);
  }
}