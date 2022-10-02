//Definiendo Variables

const int emIzquierda = 9;
const int emDerecha =8;
const int ledTest = 13;

// Definir Variables del motor

const int  AIA = 3;
const int  AIB = 11;
const int  BIA = 10;
const int  BIB = 6;

//Variables de entrada

const int reIzquierda = A0;
const int reDerecha= A1;

//Valores

int valIzq = 0;
int valDer = 0;

void setup()
{
  //Iniciamos salidas

     pinMode(emIzquierda, OUTPUT);
   pinMode(emDerecha, OUTPUT);
   pinMode(ledTest, OUTPUT);

   digitalWrite(ledTest, LOW);
   analogWrite(emIzquierda, 0);
   analogWrite(emIzquierda, 0);

    analogWrite(AIA, 0);
    analogWrite(AIB, 0);
    analogWrite(BIA, 0);
    analogWrite(BIB, 0);

    //Saludo Inicial

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

          Serial.begin(9600);
}

void loop()
{
  digitalWrite(ledTest, HIGH);
  digitalWrite(emIzquierda, HIGH);
  valIzq = analogRead(reIzquierda);

  digitalWrite(emDerecha, HIGH);
  valDer = analogRead(reDerecha);
  digitalWrite(ledTest, LOW);

  Serial.print(valIzq);
  Serial.print(",");
  Serial.println(valDer);

  movimiento();
  delay(50);
}

void movimiento()
{
  if(valDer < 970 && valIzq < 970)  //Blanco < 970 y Negro > 970
  {
    atras(); 
  }
  else if(valDer > 970 && valIzq > 970)
  {
    adelante();
  }

  else if(valDer < 970 && valIzq > 970)
  {
    derecha();
  }
    else if(valDer > 970 && valIzq < 970)
  {
    izquierda();
  }
  }

  void adelante()
  {
    analogWrite(AIA, 255);
    analogWrite(AIB, 0);
    analogWrite(BIA, 255);
    analogWrite(BIB, 0);
  }
  void atras()
  {
    analogWrite(AIA, 0);
    analogWrite(AIB, 255);
    analogWrite(BIA, 0);
    analogWrite(BIB, 255);
  }

  void derecha()
  {
    analogWrite(AIA, 255);
    analogWrite(AIB, 255);
    analogWrite(BIA, 255);
    analogWrite(BIB, 0);
  }

  void izquierda()
  {
    analogWrite(AIA, 255);
    analogWrite(AIB, 0);
    analogWrite(BIA, 255);
    analogWrite(BIB, 255);
}
