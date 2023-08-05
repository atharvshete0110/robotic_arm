
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servobottom;
int a;
int pos;
int flag = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servobottom.attach(2);
  servo1.attach(4);
  servo2.attach(6);
  servo3.attach(8);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    a = Serial.read();
    Serial.println(a);
  }

  if (a == 97) {         //a       //normal
    servobottom.write(100);          //90
    delay(500);
    servo1.write(180);
    servo2.write(100);
    servo3.write(70);
  }

  if (a == 98) {         //b      //move down
    delay(100);
    servo1.write(120);
    delay(500);
    servo2.write(95);
    delay(100);
  }

  if (a == 99) {           //c      //grab
    if(flag == 0){
    for (int e = 0; e <= 160; e += 5) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo3.write(e);              // tell servo to go to position in variable 'pos'
//      Serial.println(e);
      delay(30);                       // waits 15 ms for the servo to reach the position
    }
    }flag = 1;
  }

  if (a == 100) {          //d      //release
    //    if (a == ) {
//    if(flag == 1){
    for (pos = 180; pos >= 0; pos -= 5) { // goes from 180 degrees to 0 degrees
      servo3.write(pos);              // tell servo to go to position in variable 'pos'
              Serial.println(pos);
      delay(15);                       // waits 15 ms for the servo to reach the position
      
    }
    return 0;
//    }flag = 2;
  }


  if (a == 101) {            //e        //moveup
    servo2.write(110);
    delay(500);
    servo1.write(180);
    delay(500);
  }

  if (a == 102) {           //f      //rotate
    servobottom.write(0);
    delay(500);
  }

  //if(
}
