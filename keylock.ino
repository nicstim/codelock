#include <Servo.h> // Подклоючаем библиотеку Servo
#include <Keypad.h> // Подключаем библиотеку Keypad
const byte ROWS = 4; // 4 строки
const byte COLS = 4; // 4 столбца
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; 
int i =0;
byte rowPins[ROWS] = {11,10, 9, 8}; 
byte colPins[COLS] = {7, 6, 5, 4}; 
char password[4];
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
// Пин для сервопривода
int servoPin = 3;
// Создаем объект
Servo Servo1;

void setup() {
  // Нам нужно подключить сервопривод к используемому номеру пина
  Servo1.attach(servoPin);
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();
  if (key){
    if (key != 'A'){
    password[i] = key;
    ++i;
    if (i == 5){
      i = 0;
    }
    for(int a=0;a<i;++a){
       Serial.println(password[a]);
    }
  }
  }
  if (key == 'A'){
    if (password[0] == '1' and password[1] == '3' and password[2] == '3' and password[3] == '7'){
      //Serial.println(key); // Передаем название нажатой клавиши в сериал порт
      // 0 градусов
      Servo1.write(0);
      delay(1000);
      // 90 градусов
      Servo1.write(90);
      delay(1000);
    }
    i = 0;
  }
  if (key == 'C'){
    i = 0;
    Serial.println("clear");
  }
  
}
