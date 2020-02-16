String readString;



void setup() {
  // put your setup code here, to run once:
  pinMode(D3, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  while(!Serial.available()){  
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(D3, LOW);}

  while (Serial.available()>0){
    char c = Serial.read();
    readString +=c;
  
  /*
  Serial.print("Arduino received: ");
  Serial.println(readString);
  Serial.flush();
*/
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(D3, HIGH);
delay(1000);


}

    digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(D3, LOW);
readString = "";
delay(10);
}

  
