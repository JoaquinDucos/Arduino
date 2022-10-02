#include<IRremote.h>

int ledTest = 13;

//Seteo del receptor

int receptorControl = 2;

IRrecv receptorIr(receptorControl);
decode_results codigoLeido;
decode_results codigoLeidoNuevo;

//Seteo del led RGB

int ledRojo =9;
int ledVerde =10;
int ledAzul =6;

int potenciaRojo = 0;
int potenciaVerde = 0;
int potenciaAzul = 0;

void setup()
{
  Serial.begin(9600);

  receptorIr.enableIRIn();

  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  analogWrite(ledRojo, 0);
    analogWrite(ledVerde, 0);
      analogWrite(ledAzul, 0);

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
      case 0xFF5AA5:
      analogWrite(ledRojo, 0);
      break;

      case 0xFF30CF:
      analogWrite(ledRojo, 127);
      break;

            case 0xFF18E7:
      analogWrite(ledRojo, 255);
      break;

      case 0xFF7A85:
      analogWrite(ledVerde, 0);
      break;

      case 0xFF10EF:
      analogWrite(ledVerde, 127);
      break;

      case 0xFF38C7:
      analogWrite(ledVerde, 255);
      break;

      case 0xFF42BD:
      analogWrite(ledAzul, 0);
      break;

      case 0xFF4AB5:
      analogWrite(ledAzul, 127);
      break;

      case 0xFF52AD:
      analogWrite(ledAzul, 255);
      break;

      case 0xFFA25D:
      analogWrite(ledRojo, 0);
      analogWrite(ledVerde, 0);
      analogWrite(ledAzul, 0);
      break;

      case 0xFFE21D:
      analogWrite(ledRojo, 255);
      analogWrite(ledVerde, 255);
      analogWrite(ledAzul, 255);
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
  }
}
