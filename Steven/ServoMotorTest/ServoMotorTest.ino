#include <Servo.h>


 Servo test_Servo;

void setup() {
  // put your setup code here, to run once:
  test_Servo.attach(D6);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  test_Servo.write(50);
  delay (1000);
  test_Servo.write(30);
  delay (1000);
  Serial.println("loop");
}
