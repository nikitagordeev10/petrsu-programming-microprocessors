#define LED_PIN 10
#define BUTTON_PIN 2

boolean button_was_up = true;
boolean led_enabled = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}
 
void loop() {
   // узнаем, отпущена ли кнопка сейчас
   boolean button_is_up = digitalRead(BUTTON_PIN);
 
   // если кнопка была отпущена и не отпущена сейчас
   if (button_was_up && !button_is_up) {

      // исключаем дребезг контактов тактовой кнопки
      delay(10);

      // считываем сигнал с кнопки снова
      button_is_up = digitalRead(BUTTON_PIN);

      // если кнопка нажата, то переворачиваем сигнал светодиода
      if (!button_is_up) {
         led_enabled = !led_enabled;
         digitalWrite(LED_PIN, led_enabled);
      }
   }
 
   // запоминаем состояние кнопки для новой итерации
   button_was_up = button_is_up;
}