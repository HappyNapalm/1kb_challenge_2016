#include <Servo.h>

int var = 0;
Servo servo_01;
int i = 0;

void setup() {
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  servo_01.attach(9);

}

void loop() {
  for (i=0;i<160;i++){
    servo_01.write(i);
    Serial.println(i);
    delay(10);
  }
  for (i=160;i>0;i--){
    servo_01.write(i);
    Serial.println(i);
    delay(10);
  }
  servo_01.write(90);
  delay(500);
  

}
