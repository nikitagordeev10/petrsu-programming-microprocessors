#define LED1_PIN =  7;      // номер выхода, подключенного к светодиоду
int LED_1_STATUS = LOW;    // этой переменной устанавливаем состояние светодиода

int LED_BUILTIN_STATUS = LOW;             

long previousMillis = 0;        // храним время последнего переключения светодиода 
long interval = 1000;           // интервал между включение/выключением светодиода (1 секунда)
 
void setup() {
  // задаем режим выхода для порта, подключенного к светодиоду
  pinMode(LED1_PIN, OUTPUT);     
  pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop()
{
  // здесь будет код, который будет работать постоянно
  // и который не должен останавливаться на время между переключениями свето
  unsigned long currentMillis = millis();
  
  //проверяем не прошел ли нужный интервал, если прошел то
  if(currentMillis - previousMillis > interval) {
    // сохраняем время последнего переключения
    previousMillis = currentMillis; 
 
    // если светодиод не горит, то зажигаем, и наоборот
    if (LED_BUILTIN_STATUS == LOW)
        LED_BUILTIN_STATUS = HIGH;
    else
        LED_BUILTIN_STATUS = LOW;
 
    // устанавливаем состояния выхода, чтобы включить или выключить светодиод
    digitalWrite(LED1_PIN, LED_BUILTIN_STATUS);
  }

    //проверяем не прошел ли нужный интервал, если прошел то
    if(currentMillis - previousMillis > interval) {
        // сохраняем время последнего переключения
        previousMillis = currentMillis; 
     
        // если светодиод не горит, то зажигаем, и наоборот
        if (LED_BUILTIN_STATUS == LOW)
            LED_BUILTIN_STATUS = HIGH;
        else
            LED_BUILTIN_STATUS = LOW;
     
        // устанавливаем состояния выхода, чтобы включить или выключить светодиод
        digitalWrite(LED_BUILTIN, LED_BUILTIN_STATUS);
      }
}
