#include <IRremote.h>
int ENA=5;
int ENB=6;
int IN1=7;
int IN2=8;
int IN3=9;
int IN4=11;
int IRpin = 12;
IRrecv IR(IRpin);             //IR is the object for the infared censor
decode_results cmd;           //cmd is the object where the results go into from the censor
float d=1;
int degRot=90;
int left;
int right;
float v=1.2;
char blue;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
digitalWrite(ENA,HIGH);
digitalWrite(ENB,HIGH);
  IR.enableIRIn();            //This is to enable the Infared LED Censor
  IR.blink13(true);           //This will blink when signal is received

}

void loop() {
  int wv;
  wv=(v-.206)/.0086;
  left=wv;
  right=wv;
  setSpeed(left,right); 

  while (Serial.available()== 0) {  }
    blue=Serial.read();
    if(blue=='f') {forward(d,v);              }
    if(blue=='b') {backward(d,v);             }
    if(blue=='l') {turnLeft(degRot,wv);       }
    if(blue=='r') {turnRight(degRot,wv);      }
    if(blue=='d') {}
      while (Serial.available()==0){          }
        blue=Serial.read();
        if(blue=='0') {d=0;                   }
        if(blue=='1') {d=1;                   }
        if(blue=='2') {d=2;                   }
        if(blue=='3') {d=3;                   }
        if(blue=='4') {d=4;                   }
        if(blue=='5') {d=5;                   }
        if(blue=='6') {d=6;                   }
        if(blue=='7') {d=7;                   }
        if(blue=='8') {d=8;                   }
        if(blue=='9') {d=9;                   }
    if(blue=='s') {}
      while (Serial.available()==0){          }
        blue=Serial.read();
        if(blue=='0') {v=1.10;                }
        if(blue=='1') {v=1.23;                }
        if(blue=='2') {v=1.36;                }
        if(blue=='3') {v=1.49;                }
        if(blue=='4') {v=1.62;                }
        if(blue=='5') {v=1.74;                }
        if(blue=='6') {v=1.87;                }
        if(blue=='7') {v=2.00;                }
        if(blue=='8') {v=2.13;                }
        if(blue=='9') {v=2.26;                }
        blue="";
    
  
//  while (IR.decode(&cmd)==0) {  }
//  
//    if (cmd.value == 0xFF629D) {  forward(d,v);        }
//    if (cmd.value == 0xFFA857) {  backward(d,v);       }
//    if (cmd.value == 0xFF22DD) {  turnLeft(degRot,wv); }
//    if (cmd.value == 0xFFC23D) {  turnRight(degRot,wv);}
//    
//    if (cmd.value == 0xFF52AD) {     //This is where we set distance
//        delay(500);
//        IR.resume();
//        while (IR.decode(&cmd)==0) {   }
//        delay(100);
//        if (cmd.value == 0xFF4AB5) { d=0; }
//        if (cmd.value == 0xFF6897) { d=1; }
//        if (cmd.value == 0xFF9867) { d=2; }
//        if (cmd.value == 0xFFB04F) { d=3; }
//        if (cmd.value == 0xFF30CF) { d=4; }
//        if (cmd.value == 0xFF18E7) { d=5; }
//        if (cmd.value == 0xFF7A85) { d=6; }
//        if (cmd.value == 0xFF10EF) { d=7; }
//        if (cmd.value == 0xFF38C7) { d=8; }
//        if (cmd.value == 0xFF5AA5) { d=9; }
//        }
//        
//    if (cmd.value == 0xFF42BD) {     //This is where we set speed
//        delay(500);
//        IR.resume();
//        while (IR.decode(&cmd)==0) {   }
//        delay(100);
//        if (cmd.value == 0xFF4AB5) { v=1.10; }
//        if (cmd.value == 0xFF6897) { v=1.23; }
//        if (cmd.value == 0xFF9867) { v=1.36; }
//        if (cmd.value == 0xFFB04F) { v=1.49; }
//        if (cmd.value == 0xFF30CF) { v=1.62; }
//        if (cmd.value == 0xFF18E7) { v=1.74; }
//        if (cmd.value == 0xFF7A85) { v=1.87; }
//        if (cmd.value == 0xFF10EF) { v=2.00; }
//        if (cmd.value == 0xFF38C7) { v=2.13; }
//        if (cmd.value == 0xFF5AA5) { v=2.26; }
//        }
//IR.resume();
}

void setSpeed(int leftVal,int rightVal){
  analogWrite(ENA,leftVal);
  analogWrite(ENB,rightVal);
}


void forward(float d, float v){
float t;
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
t=d/v*1000;
delay(t);
stopCar();
}


void backward(float d, float v){
float t;

digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
t=d/v*1000;
delay(t);
stopCar();
}
void turnRight(int deg, int wv){
  float t;
  stopCar();
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
t=(deg+33.67)/176.86*1000.;
Serial.println(deg);
delay(t);
stopCar();
  analogWrite(ENA, wv);
  analogWrite(ENB, wv);
}


void turnLeft(int deg, int wv){
  float t;
  stopCar();
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
t=(deg+33.67)/176.86*1000.;
Serial.println(deg);
delay(t);
stopCar();
  analogWrite(ENA, wv);
  analogWrite(ENB, wv);

}

void stopCar(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
}

void calF(){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
delay(5000);
stopCar();
}
void calB(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
delay(5000);
stopCar();
}

void calR(){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
delay(3000);
stopCar();
}
void calL(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
delay(5000);
stopCar();
}
