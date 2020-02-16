const int motorPin = 3;

void setup()
{
pinMode(motorPin, OUTPUT);
Serial.begin(9600);
}

void loop()
{
Serial.println("loop");  
digitalWrite(motorPin, HIGH);
delay(1000);
digitalWrite(motorPin, LOW);
delay(1000);
}
