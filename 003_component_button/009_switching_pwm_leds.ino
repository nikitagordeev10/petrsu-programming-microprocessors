const int led1Pin = 11;  // Пин для светодиода №1
const int led2Pin = 3;   // Пин для светодиода №2
const int buttonPin = 9;  // Пин для кнопки

int buttonState = 0;      // Переменная для хранения состояния кнопки
int lastButtonState = 0;  // Переменная для хранения предыдущего состояния кнопки
int ledMode = 0;          // Переменная для хранения текущего режима работы светодиодов

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Считываем состояние кнопки
  buttonState = digitalRead(buttonPin);

  // Проверяем, было ли нажатие кнопки
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // Меняем режим работы светодиодов
      ledMode = (ledMode + 1) % 2;
    }
    // Задержка для устранения дребезга кнопки
    delay(50);
  }
  lastButtonState = buttonState;

  // Управление светодиодами в зависимости от режима
  if (ledMode == 0) {
    // Режим 0: светодиод №1 плавно мерцает, светодиод №2 выключен
    analogWrite(led1Pin, 128 + 127 * cos(millis() / 200.0));
    digitalWrite(led2Pin, LOW);
  } else if (ledMode == 1) {
    // Режим 1: светодиод №1 выключен, светодиод №2 включен
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
  }
}