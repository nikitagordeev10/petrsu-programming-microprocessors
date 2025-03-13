#define LED_7PIN 7 // номер выхода, подключенного к светодиоду

unsigned long previous_millis_led_7 = 0; // храним время последнего переключения светодиода 
unsigned long previous_millis_led_builtin = 0;

const long interval_led_7 = 1000; // интервал между включение/выключением светодиода (1 секунда)
const long interval_led_builtin = 5000; // интервал между включение/выключением светодиода (5 секунд)

void setup() {
  // задаем режим выхода для порта, подключенного к светодиоду
  pinMode(LED_7PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  unsigned long current_millis = millis();
  
  //проверяем не прошел ли нужный интервал, если прошел то
  if (current_millis - previous_millis_led_7 >= interval_led_7) {
    // сохраняем время последнего переключения
    previous_millis_led_7 = current_millis;
    // устанавливаем состояния выхода, чтобы включить или выключить светодиод
    digitalWrite(LED_7PIN, !digitalRead(LED_7PIN));
  }
  
  //проверяем не прошел ли нужный интервал, если прошел то
  if (current_millis - previous_millis_led_builtin >= interval_led_builtin) {
    // сохраняем время последнего переключения
    previous_millis_led_builtin = current_millis;
    // устанавливаем состояния выхода, чтобы включить или выключить светодиод
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}