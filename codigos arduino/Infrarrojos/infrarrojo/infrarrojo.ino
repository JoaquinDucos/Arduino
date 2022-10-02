

//Constantes de Salida
const int emIzquierda = 9;
const int emDerecha =8;
const int ledTest = 13;

//Definir constantes de entrada

const int reIzquierda = 0;
const int reDerecha= 1;

//Datos de reflectividad guardados
int refDer = 0;
int refIzq = 0;

void setup ()
{    Serial.begin(9600);
  //Iniciar Salidas
   pinMode(emIzquierda, OUTPUT);
   pinMode(emDerecha, OUTPUT);
   pinMode(ledTest, OUTPUT);

   digitalWrite(emIzquierda, LOW);
   digitalWrite(emDerecha, LOW);
   digitalWrite(ledTest, LOW);

// Saludo inicial

       for( int i=0;i<3; i++)
       {
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
}

void loop(){

  digitalWrite(emIzquierda, HIGH);
  refIzq = analogRead(reIzquierda);
  delay(100);
  digitalWrite(emIzquierda, LOW);

  digitalWrite(emDerecha, HIGH);
  refDer = analogRead(reDerecha);
  delay(100);
  digitalWrite(emDerecha, LOW);

  //Enviamos la información al puerto serie
  Serial.println("Izquierda/Derecha");
  Serial.println(refIzq);
  Serial.println(",");
  Serial.println(refDer);
  
  delay(500);
}
