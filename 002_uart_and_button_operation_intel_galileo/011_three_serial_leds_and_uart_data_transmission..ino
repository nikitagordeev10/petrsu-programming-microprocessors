const int button1 = 4;     // кнопка для первого светодиода (моментальное включение)
const int led1 = A1;       // первый светодиод

const int button2 = 7;     // кнопка для второго светодиода (переключение)
const int led2 = A2;       // второй светодиод

const int led3 = A3;       // третий светодиод
const int builtInLED = LED_BUILTIN; // встроенный светодиод (на Arduino Uno — пин 13)

bool led2State = false;    // состояние второго светодиода
bool button2LastState = LOW; 

void setup() {
    pinMode(button1, INPUT);
    pinMode(led1, OUTPUT);

    pinMode(button2, INPUT);
    pinMode(led2, OUTPUT);

    pinMode(led3, OUTPUT);
    pinMode(builtInLED, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    // Первая часть (светодиод включается при нажатии кнопки, выключается при отпускании)
    int button1State = digitalRead(button1);
    digitalWrite(led1, button1State);

    // Вторая часть (переключение состояния светодиода)
    int button2State = digitalRead(button2);

    if (button2State == HIGH && button2LastState == LOW) {
        led2State = !led2State; // переключаем состояние
        digitalWrite(led2, led2State);
        delay(200); // защита от дребезга контактов
    }
    button2LastState = button2State; // сохраняем состояние кнопки

    // Третья часть (управление светодиодами через Serial)
    if (Serial.available() > 0) {
        char command = Serial.read();
        
        // Игнорируем символы новой строки и возврата каретки
        if (command == '\n' || command == '\r') return;

        Serial.print("Получена команда: ");
        Serial.println(command);

        switch (command) {
            case '1': // Включить встроенный светодиод
                digitalWrite(builtInLED, HIGH);
                break;
            case '0': // Выключить встроенный светодиод
                digitalWrite(builtInLED, LOW);
                break;
            case '3': // Включить третий светодиод
                digitalWrite(led3, HIGH);
                break;
            case '4': // Выключить третий светодиод
                digitalWrite(led3, LOW);
                break;
            default:
                Serial.println("Неизвестная команда.");
                break;
        }
    }
}
