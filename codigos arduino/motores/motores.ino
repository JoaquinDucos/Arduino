#include <IRremote.h>
// definiendo constantes

int receptorControl = 3;
IRrecv receptor(receptorControl);
decode_results codigoObjeto;
decode_results codigoLeidoNuevo;

const int  AIA = 9;
const int  AIB = 10;
const int  BIA = 5;
const int  BIB = 6;

// Ambas entradas para cada motor

const int ledTest = 13;

void setup () {

Serial.begin(9600);
//habilitamos la lectura del sensor
receptor.enableIRIn ();
//seteamos salidas

// definimos las salidas
pinMode (AIA, OUTPUT);
pinMode (AIB, OUTPUT);
pinMode (BIA, OUTPUT);
pinMode (BIB, OUTPUT);

pinMode (ledTest, OUTPUT);

//salidas apagadas

analogWrite (AIA, 0);
analogWrite (AIB, 0);
analogWrite (BIA, 0);
analogWrite (BIB, 0);

digitalWrite(ledTest, LOW);

//Saludo inicial

digitalWrite(ledTest, HIGH);
delay (400);
digitalWrite(ledTest, LOW);
delay (400);
digitalWrite(ledTest, HIGH);
delay (400);
digitalWrite(ledTest, LOW);
delay (400);
digitalWrite(ledTest, HIGH);
delay (400);
digitalWrite(ledTest, LOW);
delay (400);
}

void loop (){

 if(receptor.decode(&codigoLeidoNuevo))
  {
    receptor.resume();
  }
 if(codigoLeidoNuevo.value != codigoObjeto.value && codigoLeidoNuevo.value!= 0xFFFFFFFF)
  {
   codigoObjeto = codigoLeidoNuevo; 
   switch (codigoObjeto.value)
    {
      case 0x2C2E80FF:
        adelante();
        delay(100);
        break;

      case 0x5A1A483D:
        atras();
        delay(100);
        break;

      case 0xDC18602C:
        derecha();
        delay(100);
        break;

      case 0x9578646A:
        izquierda();
        delay(100);
        break;

      case 0xCB3CC07F:
        parar();
        delay(100);
        break;
    }  
  }
}

void adelante(){

  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

void atras(){

  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}

  void derecha(){

  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}

void izquierda(){

  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

void parar(){

  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255);
  delay(500);
}

void parpadeo(int veces){
   for ( int j= 0; j<= veces; j++)
     {

       digitalWrite (ledTest, HIGH);
       delay (200);
       digitalWrite (ledTest, LOW);
       delay (200);
    
     }
}
/* 
0x2C2E80FF   adelante
0x5A1A483D     atras
0xDC18602C     derecha
0x9578646A      izquierda
0xCB3CC07F  parar
*/
