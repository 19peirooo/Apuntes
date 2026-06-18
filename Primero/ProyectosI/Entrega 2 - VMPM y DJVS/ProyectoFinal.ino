//Biblioteca de la Pantalla LCD
#include <LiquidCrystal.h>

//Diseño de las barras
byte V1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte V2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte V3[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};

byte V4[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
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
};

byte V8[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

//Declaro pines
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; //Pines del LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Creo objeto LCD
int pinL = 6, pinR = 7, pinVel = 5, pinTrig = 4, pinEcho = 3, pinBuzzer = 2;

//Variabless Globales que se actualiza mediante el serial
int modo = 0;
int volumen = 0;
int potV = 0; 
float proximidad = 50;
int velocidad = 0;
int sentido = 0;

void setup() {
  //Abro puerto Serial
  Serial.begin(9600);
  Serial.println("Proyecto Final - Diego Jaime Vega Sanchez y Victor Manuel Peiro Martinez");
  printHelp(); //Imprimo el menu de ayuda nada mas empezar el programa

  //Inicio todos los pines para controlar en motor como OUTPUT
  pinMode(pinL, OUTPUT);
  pinMode(pinR, OUTPUT);
  pinMode(pinVel, OUTPUT);
  //Inicializo el emisor de sensor ultrasonidos como salida y el receptor como entrada
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);

  //Creo las barras para la potencia y volumen
  lcd.createChar(0,V1);
  lcd.createChar(1,V2);
  lcd.createChar(2,V3);
  lcd.createChar(3,V4);
  lcd.createChar(4,V5);
  lcd.createChar(5,V6);
  lcd.createChar(6,V7);
  lcd.createChar(7,V7);

  //Instancia las 16 columnas y 2 filas del LCD
  lcd.begin(16, 2);
}

void loop() {
  //Leo su hay orden en el Serial
  comSerial();
  //Muestro la pantalla
  lcd.display();
  //Veo en que modo estoy
  switch (modo){
    //Si estoy en modo 1
    case 1:{
      //Reinicio en zumbador
      noTone(pinBuzzer);
      //El zumbador pita en funcion de su volumen
      tone(pinBuzzer, volumen*10, 200);
      //Imprimo la informacion el la pantalla LCD
      lcd.print("Modo:");
      lcd.print(modo);
      lcd.print(" Radio");
      lcd.setCursor(0,2);
      lcd.print("Volumen:");
      if(volumen == 0){
        lcd.print(" MUTE");
      }else{
        //Veo cuantas barras tengo que imprimir en funcion del valor del volumen. Cambio el valor de 0-100 a 0-8
        int barras = map(volumen,0,100,0,8);
        for (int i = 0; i <= barras; i++){
          lcd.write(byte(i));
        }
      }
    }break;
    //Si estoy en modo 2
    case 2:{
      //Apago el zumbador
      noTone(pinBuzzer);
      //Actualizo el sentido del motor en caso necesario
      setSentido();
      //Imprimo la informacion el la pantalla LCD
      lcd.print("Modo:");
      lcd.print(modo);
      lcd.print(" AC cooler");
      lcd.setCursor(0,2);
      lcd.print("Potencia:");
      if(potV == 0){
        lcd.print(" OFF");
      }else{
        //Veo cuantas barras tengo que imprimir en funcion del valor del volumen. Cambio el valor de 0-100 a 0-7
        int barras = map(potV,0,100,0,7);
        for (int i = 0; i <= barras; i++){
          lcd.write(byte(i));
        }
      }
      //Cambio el valor del serial (0%-100%) a el voltaje a suministar al motor (75-255) --> Minimo 75 porque motor un poco roto
      velocidad = map(potV,0,100,75,255);
      //Hago que el motor gire
      analogWrite(pinVel,velocidad);
    }break;
    //Si estoy en modo 3
    case 3:{
      //Apago el zumbador
      noTone(pinBuzzer);
      //Leo la proximidad
      proximidad = leerDistancia();
      //Cambio la frecuencia de los pitido en funcion de la proximidad
      pitidosProximidad();
      //Imprimo la informacion el la pantalla LCD
      lcd.print("Modo:");
      lcd.print(modo);
      lcd.print(" Parking");
      lcd.setCursor(0,2);
      lcd.print("Proximidad:");
      lcd.print(proximidad);
    }break;    
    //Si no estoy en ningun modo
    default:{
      lcd.print("   Eliga una");
      lcd.setCursor(4,2);
      lcd.print("Opcion!");
    }break;
  }
  delay(100);
  //Vacio la pantalla 
  lcd.clear();
}

//Funcion de comunicación por Seriañ
void comSerial(){
  //Si esta libre el buffer
  if(Serial.available()>0){
    //Leo la entrada
    String in = Serial.readString();
    //Paso letra a mayuscula
    in.toUpperCase();
    //Elimina espacios repetidos
    in.trim();
    //Orden es el primer caracter
    char orden = in.charAt(0);
    //Cojo el primer numero --> En posicion 2. Como es una cadena, lo paso a entero
    int valor = in.substring(1,2).toInt();
    //Cojo el primer numero de 3 cifras--> En posicion 2,3,4. Como es una cadena, lo paso a entero
    int valor3Digitos = in.substring(1,4).toInt();
    //Orden M --> Cambia modo
    if (orden == 'M'){
      if (valor == 1){
        modo = 1;
      }
      else if (valor == 2){
        modo = 2;
      }
      else if (valor == 3){
        modo = 3;
      }
      else {
        Serial.println("ERROR: Modo no definido");
      }
    }
    //Orden V --> Cambia el volumen
    else if (orden == 'V'){
      //Compruebo que el valor sea de 0 a 100
      if (valor3Digitos >= 0 && valor3Digitos <= 100){
        volumen = valor3Digitos;
      }
      //Sino, no cambia
      else {
        Serial.println("ERROR: Valor no aceptado");
      }
    }
    //Orden P --> Cambia potencia
    else if (orden == 'P'){
      //Compruebo que el valor sea de 0 a 100
      if (valor3Digitos >= 0 && valor3Digitos <= 100){
        potV = valor3Digitos;
      }
      //Sino, no cambia
      else {
        Serial.println("ERROR: Valor no aceptado");
      }
    }
    //Orden H --> Ayuda
    else if (orden == 'H'){
      printHelp();
    }
    else if (orden == 'D'){
      //Veo si el valor es 0 o 1
      if (valor == 1 || valor == 0){
        sentido = valor;
      }
      //Sino, no cambia
      else{
        Serial.println("ERROR: Valor no aceptado");
      }
    }
    else{
      Serial.println("ERROR: Orden no encontrada");
    }
  }
}

//Imprime listado de Ordenes y valores
void printHelp(){
  Serial.println("Mn: Cambia al modo n. Valores: 1,2,3");
  Serial.println("Vn: Cambia el volumen del pitido. Valores: 0-100");
  Serial.println("Pn: Cambia la Potencia del Motor. Valores: 0-100");
  Serial.println("Dn: Cambio el sentido de giro del motor. Valores: 0(Izq), 1(Der)");
  Serial.println("H: Ayuda");
}

//Lee la distacia
int leerDistancia(){
  int dist = 0;
  long duracion = 0;

  //Envio pulsos
  digitalWrite(pinTrig,LOW);
  delayMicroseconds(4);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig,LOW);

  //Leo cuanto tarda la onda transmitida en volver al sensor
  duracion = pulseIn(pinEcho,HIGH);
  //Calculo distancia donde la v = 340m/s = 0,034 cm/microsecs v = 2d/t --> d = v*t/2
  dist = (duracion*0.034)/2;
  return dist;
}

//Calcula la frequencia de los pitidos en funcion de su proximidad
void pitidosProximidad(){
  int retardo = 0;
  //Empieza a pitar cuando la proximidad es menor que 50
  if (proximidad > 50){
    noTone(pinBuzzer);
  }
  else{
    //Por cada multiplo de 10, baja la frecuencia 100Hz
    for (int i = 50; i != 0; i-=10){
      if (i > proximidad){
        retardo += 100;
      }
    }
    tone(pinBuzzer,400+retardo, 200);
  }
}

//Cambia el sentido del motor
void setSentido(){
  if (sentido == 1){
    digitalWrite(pinL, LOW);
    digitalWrite(pinR, HIGH);
  }
  else {
    digitalWrite(pinL, HIGH);
    digitalWrite(pinR, LOW);
  }
}
