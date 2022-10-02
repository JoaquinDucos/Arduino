#include <IRremote.h>
//Variables

int ledTest = 13;

//seteo del receptor

int receptorControl = 3;

IRrecv receptor(receptorControl);
decode_results codigoLeido;


void setup() {
 
Serial.begin(9600);
//habilitamos la lectura del sensor

receptor.enableIRIn ();
//seteamos salidas

pinMode(ledTest, OUTPUT);
digitalWrite(ledTest, LOW);

//saludo inicial

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
  if(receptor.decode(&codigoLeido))
  {
    Serial.print("0x");
    Serial.println(codigoLeido.value, HEX);
    delay(50);

    receptor.resume();
  } 
}

/*0x2C2E80FF   adelante
0x5A1A483D     atras
0xDC18602C     derecha
0x9578646A      izquierda
*/
  
