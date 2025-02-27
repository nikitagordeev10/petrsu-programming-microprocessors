const int button1 = 4;     // кнопка для первого светодиода (моментальное включение)
const int led1 = A1;       // первый светодиод

const int button2 = 7;     // кнопка для второго светодиода (переключение)
const int led2 = A2;       // второй светодиод

bool led2State = false;    // состояние второго светодиода
bool button2LastState = LOW; 

void setup() {
    pinMode(button1, INPUT);
    pinMode(led1, OUTPUT);

    pinMode(button2, INPUT);
    pinMode(led2, OUTPUT);
    
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
}
