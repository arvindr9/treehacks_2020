#include <Servo.h>

int servo1pin = 3;
int servo2pin = 5;


Servo servo1;
Servo servo2;




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo1.attach(servo1pin);
servo2.attach(servo2pin);



}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("servo1");
servo1.write(0);
servo2.write(0);


delay(1000);

servo1.write(120);
servo2.write(120);

delay (1000);
}
