
const byte led_7pin = 7; // 7 вывод Arduino Nano для подключения светодиода

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // 13 вывод Arduino Nano
  pinMode(led_7pin, OUTPUT); // 7 вывод Arduino Nano, к нему подключён внешний на светодиод
}

void loop() {
  for (int i = 100; i <= 1000; i = i + 100) {
    digitalWrite(LED_BUILTIN, HIGH); // зажигаем светодиод
    digitalWrite(led_7pin, HIGH);   // зажигаем светодиод
    delay(i);                      // ждём i мс
    digitalWrite(LED_BUILTIN, LOW); // гасим светодиод
    digitalWrite(led_7pin, LOW);    // гасим светодиод
    delay(i);                      // ждём i мс
  }
}

