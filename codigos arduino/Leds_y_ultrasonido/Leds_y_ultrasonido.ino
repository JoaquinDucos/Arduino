
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

  //iniciar pines de salida
  
  pinMode(ledTest, OUTPUT);
  pinMode(disparo, OUTPUT);
  pinMode(eco, INPUT);

  digitalWrite(disparo, LOW);
  analogWrite(ledRojo,0);
  analogWrite(ledVerde,0);
  analogWrite(ledAzul,0);

  //Saludo inicial

  for(int i=0; i<3; i++){
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  }
  
}

 void loop(){
  //iniciar el disparo de la señal
  
  digitalWrite(disparo, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparo, LOW);

  tiempoPulso = pulseIn(eco, HIGH);

  if(tiempoPulso<550){
    analogWrite(ledRojo,255);
    analogWrite(ledVerde,0);
    analogWrite(ledAzul,0);
  }

  else if(tiempoPulso>=550 && tiempoPulso<860){
    analogWrite(ledRojo,255);
    analogWrite(ledVerde,255);
    analogWrite(ledAzul,0);
  }
  else if(tiempoPulso>=860 && tiempoPulso<1140){
    analogWrite(ledRojo,0);
    analogWrite(ledVerde,255);
    analogWrite(ledAzul,0);
  }
  else {
    tVal=constrain(tiempoPulso, 1140,5700);
    intensidad = map (tVal, 1140, 5700,0,255);
    analogWrite(ledRojo, intensidad);
    analogWrite(ledVerde, intensidad);
    analogWrite(ledAzul, intensidad);
  }
 }
  
 
