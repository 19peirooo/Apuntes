//Pines Digitales
int pinBit0_1 = 2, pinBit1_1 = 3, pinBit2_1 = 4, pinBit3_1 = 5;
int pinBit0_2 = 6, pinBit1_2 = 7, pinBit2_2 = 8, pinBit3_2 = 9;

void setup() {
  //Inicio Serial
  Serial.begin(9600);

  //Inicializo pines como de salida
  pinMode(pinBit0_1,OUTPUT);
  pinMode(pinBit1_1,OUTPUT);
  pinMode(pinBit2_1,OUTPUT);
  pinMode(pinBit3_1,OUTPUT);
  pinMode(pinBit0_2,OUTPUT);
  pinMode(pinBit1_2,OUTPUT);
  pinMode(pinBit2_2,OUTPUT);
  pinMode(pinBit3_2,OUTPUT);
}
  
void loop(){
  int num1 = 0;
  int num2 = 0;
  for (num1 = 0; num1 < 16; num1++){
    for (num2 = 0; num2 < 16; num2++){
      Serial.print(num1);
      Serial.print("+");
      Serial.println(num2);
      digitalWrite(pinBit0_1, (num1 & 0b0001) ? HIGH : LOW);
      digitalWrite(pinBit1_1, (num1 & 0b0010) ? HIGH : LOW);
      digitalWrite(pinBit2_1, (num1 & 0b0100) ? HIGH : LOW);
      digitalWrite(pinBit3_1, (num1 & 0b1000) ? HIGH : LOW);
      digitalWrite(pinBit0_2, (num2 & 0b0001) ? HIGH : LOW);
      digitalWrite(pinBit1_2, (num2 & 0b0010) ? HIGH : LOW);
      digitalWrite(pinBit2_2, (num2 & 0b0100) ? HIGH : LOW);
      digitalWrite(pinBit3_2, (num2 & 0b1000) ? HIGH : LOW);
      delay(500);
    }
  }
}