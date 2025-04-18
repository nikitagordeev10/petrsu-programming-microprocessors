/*
 * Этот код читает значение с аналогового датчика на пине A5 и управляет светодиодом.
 * Если значение с датчика превышает порог (512, что соответствует ~2.5 В), светодиод включается.
 * В противном случае светодиод выключается.
 */

const int ledPin = 12;  // Пин, к которому подключен светодиод (измените на ваш пин)
const int sensorPin = A5;  // Пин, к которому подключен аналоговый датчик

void setup() {
  pinMode(ledPin, OUTPUT);  // Настраиваем пин светодиода как выход
  Serial.begin(9600);       // Инициализируем последовательное соединение для отладки
}

void loop() {
  int sensorValue;              // Переменная для хранения значения с датчика
  sensorValue = analogRead(sensorPin);  // Читаем значение с аналогового датчика

  // Выводим значение датчика в монитор последовательного порта для отладки
  Serial.println(sensorValue);

  // Если значение с датчика больше 512 (~2.5 В), включаем светодиод
  if (sensorValue > 512) {
    digitalWrite(ledPin, HIGH);  // Включаем светодиод
  } else {
    digitalWrite(ledPin, LOW);   // Выключаем светодиод
  }

  delay(100);  // Небольшая задержка для стабилизации (можно изменить)
}