#include <LiquidCrystal.h> //Libreria de la Pantalla LCD
#include <dht.h> //Libreria del DHT

//Declaro Pines
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; //Pines del LCD
int pinDHT = 7, pinLED = 6, pinTilt = 5, pinBuzzer = 4, pinLEDR = 3, pinLEDB = 2; //Pines Digitales para el resto de componentes
int pinLDR = A5, pinBtn = A4; //Pines Analogicos

//Declaro objecto pantalla LCD
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

//Declaro Objecto DHT
dht DHT;

//Valor Estandar del tilt
int vStdTilt = 0;

//Simbolo del Sol
byte sun[8] = {
  B00100,
  B10101,
  B01110,
  B11011,
  B01110,
  B10101,
  B00100,
};

//Simbolo de la Luna
byte moon[8] = {
  B00111,
  B01001,
  B10010,
  B10100,
  B10010,
  B01001,
  B00111,
};

//Simbolo de la Alerta
byte alert[8] = {
  B01110,
  B10101,
  B10101,
  B10001,
  B10101,
  B10001,
  B01110,
};

//Funcion que se ejecuta al inicio
void setup() {
  //Inicializo pantalla LCD
  lcd.begin(16, 2);

  //Creo los caracteres especiales
  lcd.createChar(0, sun);
  lcd.createChar(1, moon);
  lcd.createChar(2, alert);

  //Inicio Serial Por Si Es Necesario Usarlo
  Serial.begin(9600);
  Serial.println("Estacion Metereologica");

  //Establezco los LEDs como output y el sensor de inclinación como input
  pinMode(pinLED, OUTPUT);
  pinMode(pinLEDR, OUTPUT);
  pinMode(pinLEDB, OUTPUT);
  pinMode(pinTilt, INPUT);

}

//Funcion que se ejecuta constantemente
void loop() {
  //Inicializo el cursor del LCD para que este en el primer elemento
  lcd.setCursor(0, 0);
  //Valor del LDR
  int vLDR = analogRead(pinLDR);

  //Valor del Boton
  int vBtn = analogRead(pinBtn);
  
  //Valor del sensor de inclinacion
  int vTilt = digitalRead(pinTilt);

  //Si el sensor esta en vertical
  if (vTilt != vStdTilt){
    lcd.clear();
    lcd.write(byte(2)); // Escribe el simbolo de alerta
    lcd.write("   ALERTA!!   ");
    lcd.write(byte(2));
    lcd.setCursor(0,1);
    lcd.write("Vientos Extremos");
    //Sonido de alarma que suena y cambia el led enciendido
    tone(pinBuzzer, 500, 1000);
    digitalWrite(pinLEDR, HIGH);
    digitalWrite(pinLEDB, LOW);
    delay(500);
    tone(pinBuzzer, 300, 1000);
    digitalWrite(pinLEDB, HIGH);
    digitalWrite(pinLEDR, LOW);
    delay(500);
  } else {
    //Apaga los LEDs de la alrma
    digitalWrite(pinLEDR, LOW);
    digitalWrite(pinLEDB, LOW);
    //Si boton Pulsado
    //Imprimir temperatura y Humedad
    if (vBtn > 100){
      //Valor del DHT
      int vDHT = DHT.read11(pinDHT);
      delay(1500); // Condicion necesaria
      lcd.print("Temp oC:  ");
      lcd.print(DHT.temperature);
      lcd.setCursor(0,1); //Cambia a la segunda fila
      lcd.print("Humedad:  ");
      lcd.print(DHT.humidity);
      lcd.setCursor(0,0);
      delay(500);
    } else {
      //Sino Imprimir Nombre
      lcd.clear();
      lcd.print(" Hastro Station");
      //Si la luminosidad es menor de 200
      if (vLDR < 200){
        //Pone el simbolo de la luna en el centro de la segunda fila
        lcd.setCursor(8, 1); 
        lcd.write(byte(1));
      } else {
        //Sino, pone el sol en el centro de la segunda fila
        lcd.setCursor(8, 1);
        lcd.write(byte(0));
      }
      delay(500);
    }
    // Si luminosidad menor que 200
    if (vLDR < 200){
      //Encender LED
      digitalWrite(pinLED, HIGH);
    } else {
      //Sino, apagar LED
      digitalWrite(pinLED, LOW);
    }
  }
}
