int disparo = 4;
int eco = 2;

int ledTest = 13;
  int ledRojo = 11;
  int ledVerde = 10;
  int ledAzul = 9;
  
int intensidad = 0;

  long tiempoPulso;
  long tVal;

  void setup(){
    //Iniciar pines de salida
    pinMode(ledTest, OUTPUT);
    pinMode(disparo, OUTPUT);
    pinMode(eco, INPUT);

    digitalWrite(disparo, LOW);
    analogWrite(ledRojo, 0);
    analogWrite(ledVerde, 0);
    analogWrite(ledAzul, 0);

    //saludo inicial

    for(int i=0; i<3; i++){
      digitalWrite(ledTest, HIGH);
      delay(500);
      digitalWrite(ledTest, LOW);
      delay(500);
    }
  }

   void loop(){
    //inicializar el disparo de la señal

    digitalWrite(disparo, HIGH);
    delayMicroseconds(10);
    digitalWrite(disparo, LOW);
    delayMicroseconds(10);
  }
  
