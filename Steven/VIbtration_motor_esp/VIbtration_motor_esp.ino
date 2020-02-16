

void setup()
{
pinMode(D3, OUTPUT);
Serial.begin(115200);
}

void loop()
{
Serial.println("loop");  
digitalWrite(D3, HIGH);
delay(1000);
digitalWrite(D3, LOW);
delay(1000);
}
