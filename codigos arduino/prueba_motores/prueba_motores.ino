int blueLed = 9;
int brightness = 255;

void setup () {
// definir las salidas
pinMode (blueLed, OUTPUT);
}
void loop () {
analogWrite(blueLed, brightness);
delay (500);
analogWrite(blueLed, 230);
delay (500); 
analogWrite(blueLed, 205); 
delay (500);
analogWrite(blueLed, 180);
delay (500); 
analogWrite(blueLed, 155);
delay (500); 
analogWrite(blueLed, 130);
delay (500); 
analogWrite(blueLed, 105);
delay (500); 
analogWrite(blueLed, 80);
delay (500); 
}
