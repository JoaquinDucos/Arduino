#include<IRremote.h>


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

//Seteo del led RGB


void setup()
{

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
     /* case 0xFF30CF:
      analogWrite(ledRojo, 0);
      break;*/

      case 0xFF18E7:
      adelante();
      delay(200);
      break;

    /*  case 0xFF7A85:
      analogWrite(ledRojo, 255);
      break; */

      case 0xFF10EF:
      izquierda();
      delay(200);
      break;

      case 0xFF38C7:
      parar();
      delay(500);
      break; 

      case 0xFF5AA5:
      derecha();
      delay(200);
      break;

   /*   case 0xFF42BD:
      analogWrite(ledAzul, 0);
      break;  */

      case 0xFF4AB5:
      atras();
      delay(200);
      break;


   /*   case 0xFF52AD:
      analogWrite(ledAzul, 255);
      break;  */

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
