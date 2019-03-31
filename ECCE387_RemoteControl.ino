#include <IRremote.h>
#include <Keypad.h>
IRsend irsend;

int LED = 10;

const byte ROWS = 4;
const byte CLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
  
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }

  
  irsend.sendRC5(0x111, 12);
  delay(1000);

  for(int i = 0; i < 3; i++){
    irsend.sendRC5(customKey,12)
    delay(40);
  }
  delay(1000);
}
