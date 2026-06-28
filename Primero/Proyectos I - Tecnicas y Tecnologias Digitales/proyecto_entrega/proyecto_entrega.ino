// include the library code:
#include <LiquidCrystal.h>


byte V1[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B11111,
};
byte V2[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B11111,
B11111,
};
byte V3[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B11111,
B11111,
B11111,
};
byte V4[8] = {
B00000,
B00000,
B00000,
B00000,
B11111,
B11111,
B11111,
B11111,
};
byte V5[8] = {
B00000,
B00000,
B00000,
B11111,
B11111,
B11111,
B11111,
B11111,
};
byte V6[8] = {
B00000,
B00000,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
};
byte V7[8] = {
B00000,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
};byte V8[8] = {
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
};

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pin_BTN = 0;
int modo = 2;
int int_vol = 3;
float proximidad = 10.0;
void setup() {
  lcd.createChar(0,V1);
  lcd.createChar(1,V2);
  lcd.createChar(2,V3);
  lcd.createChar(3,V4);
  lcd.createChar(4,V5);
  lcd.createChar(5,V6);
  lcd.createChar(6,V7);
  lcd.createChar(7,V7);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
    
    lcd.display();
    switch (modo){
      case 1:
      lcd.write("Modo:");
      lcd.print(modo);
      lcd.print(" Radio");
      lcd.setCursor(0,2);
      lcd.print("Volumen:");
      if(int_vol = 0){
        lcd.print("MUTE");
      }else{
        for(int i = 0; i<8;i++){
          lcd.write(byte(i));
        }
      }
      delay(1000);
      lcd.clear();
      break;
      case 2: 
      lcd.write("Modo:");
      lcd.print(modo);
      lcd.print(" AC cooler");
      lcd.setCursor(0,2);
      lcd.print("Potencia:");
      if(int_vol = 0){
        lcd.print("OFF");
      }else{
      for(int i = 0; i<8;i++){
        lcd.write(byte(i));
      }
      }
      delay(1000);
      lcd.clear();
      break;
      case 3:
      lcd.write("Modo:");
      lcd.print(modo);
      lcd.print(" Parking");
      lcd.setCursor(0,2);
      lcd.print("Proximidad:");
      lcd.print(proximidad);
      delay(1000);
      lcd.clear();
      break;
      default:
      lcd.print("Seleccione una  ");
      lcd.setCursor(0,2);
      lcd.print("opci0n");
      delay(1000);
      lcd.clear();
      break;
    }
    delay(1500);
}
}

