int ENA=5;
int ENB=6;
int IN1=7;
int IN2=8;
int IN3=9;
int IN4=11;


void setup() {
  // put your setup code here, to run once:
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
digitalWrite(ENA,HIGH);
digitalWrite(ENB,HIGH);


}

void loop() {
  tenfeet();
  left180();
  stopNwait();
  
  tenfeet();
  right180();
  stopNwait();
}


void stopNwait(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  delay(1500);
  }

void tenfeet(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(500);
  }

void right180(){
  digitalWrite(IN1,HIGH);   /*right*/
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(700);
}

void left180(){
  digitalWrite(IN1,LOW);    /*left*/
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(700);
  
  }
