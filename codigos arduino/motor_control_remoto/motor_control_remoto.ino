/* DOCUMENTACIÓN:
 *  
 *  Nombre y Apellido: Joaquín Ducos.
 *  Estado: Proyecto final.
 *  Hardware: Arduino UNO.
 *  Fundación Advant proyecto "BOTS".
 *  
 *  Funcionamiento: Robot que simula las características de un automóvil a control remoto.
 *  Botón 2: Función avanzar hacia adelante.
 *  Botón 4: Función avanzar hacia su derecha.
 *  Botón 5: Función avanzar hacia su izquierda.
 *  Botón 6: Función avanzar hacia adelante.
 *  Botón 8: Función avanzar hacia atrás prendiéndose así las luces rojas.
 *  
 */

#include<IRremote.h>

//Inicializo las variables

int ledRojoDerecho = 5;
int ledRojoIzquierdo = 4;

const int ledTest = 13;
const int  AIA = 3;
const int  AIB = 11;
const int  BIA = 12;
const int  BIB = 10;

//Seteo del receptor

int receptorControl = 2;

IRrecv receptorIr(receptorControl);
decode_results codigoLeido;
decode_results codigoLeidoNuevo;


void setup()
{
    pinMode (ledRojoIzquierdo, OUTPUT); 
    pinMode (ledRojoDerecho, OUTPUT); 
    pinMode (AIA, OUTPUT);
    pinMode (AIB, OUTPUT);
    pinMode (BIA, OUTPUT);
    pinMode (BIB, OUTPUT);

    pinMode (ledTest, OUTPUT);
  
  Serial.begin(9600);

  receptorIr.enableIRIn();

  analogWrite (AIA, 0);
  analogWrite (AIB, 0);
  analogWrite (BIA, 0);
  analogWrite (BIB, 0);

      pinMode(ledTest, OUTPUT);
      digitalWrite(ledTest, LOW);

      //Saludo inicial

      digitalWrite(ledTest, HIGH);
            delay(500);
      digitalWrite(ledTest, LOW);
            delay(500);
      digitalWrite(ledTest, HIGH);
            delay(500);
      digitalWrite(ledTest, LOW);
            delay(500);
      digitalWrite(ledTest, HIGH);
            delay(500);
      digitalWrite(ledTest, LOW);
            delay(500);
}

void loop()
{
  if(receptorIr.decode(&codigoLeidoNuevo))
  {
    receptorIr.resume();
  }
  if(codigoLeidoNuevo.value != codigoLeido.value && codigoLeidoNuevo.value!= 0xFFFFFFFF)
  {
    digitalWrite(ledTest, HIGH);
    delay(50);
    digitalWrite(ledTest, LOW);

    Serial.println(codigoLeido.value, HEX);
    codigoLeido = codigoLeidoNuevo;

    switch (codigoLeido.value)
    {

      case 0xFF18E7:
      digitalWrite(ledRojoDerecho, LOW);
      digitalWrite(ledRojoIzquierdo, LOW);
      adelante();
      delay(200);
      break;

      case 0xFF10EF:
      digitalWrite(ledRojoDerecho, LOW);
      digitalWrite(ledRojoIzquierdo, LOW);
      izquierda();
      delay(200);
      break;

      case 0xFF38C7:
      digitalWrite(ledRojoDerecho, LOW);
      digitalWrite(ledRojoIzquierdo, LOW);
      parar();
      delay(500);
      break; 

      case 0xFF5AA5:
      digitalWrite(ledRojoDerecho, LOW);
      digitalWrite(ledRojoIzquierdo, LOW);
      derecha();
      delay(200);
      break;

      case 0xFF4AB5:
      digitalWrite(ledRojoDerecho, HIGH);
      digitalWrite(ledRojoIzquierdo, HIGH);
      atras();
      delay(200);
      break;

      default:

      digitalWrite(ledTest, HIGH);
      delay(200);
      digitalWrite(ledTest, LOW);
      delay(200);
      digitalWrite(ledTest, HIGH);
      delay(200);
      digitalWrite(ledTest, LOW);
      delay(200);

      break;
}  
receptorIr.resume();
  }
}

void adelante(){

    analogWrite(AIA, 0);
    analogWrite(AIB, 255);
    analogWrite(BIA, 255);
    analogWrite(BIB, 0);
}

void atras(){

     analogWrite(AIA, 255);
     analogWrite(AIB, 0);
     analogWrite(BIA, 0);
     analogWrite(BIB, 255);
}

  void izquierda(){

    analogWrite(AIA, 0);
    analogWrite(AIB, 0);
    analogWrite(BIA, 255);
    analogWrite(BIB, 0);
}

void derecha(){

    analogWrite(AIA, 0);
    analogWrite(AIB, 255);
    analogWrite(BIA, 0);
    analogWrite(BIB, 0);
}

  void parar(){

    analogWrite(AIA, 255);
    analogWrite(AIB, 255);
    analogWrite(BIA, 255);
    analogWrite(BIB, 255);
    delay(200);
}
