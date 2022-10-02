const int AIA = 10;
const int AIB = 11;

void setup() {
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);

  analogWrite(AIA, 0);
  analogWrite(AIB, 0);

}

void loop() {
  analogWrite(AIA, 100);
  analogWrite(AIB, 0);
  delay(1000);
  analogWrite(AIA, 150);
  analogWrite(AIB, 0);
  delay(1000);
  analogWrite(AIA, 200);
  analogWrite(AIB, 0);
  delay(1000);
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
   delay(1000);
}
