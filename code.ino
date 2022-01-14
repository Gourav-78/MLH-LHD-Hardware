#include <IRremote.h>

#define LME 2
#define RME 3
#define LMP 4
#define LMN 5
#define RMP 6
#define RMN 7
#define forw 16601263
#define backw 16584943
#define hault 16580863

int REC_PIN = 12;

IRrecv irrecv(REC_PIN);
decode_results rslts;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LME,OUTPUT);
  pinMode(RME,OUTPUT);
  pinMode(LMP,OUTPUT);
  pinMode(LMN,OUTPUT);
  pinMode(RMP,OUTPUT);
  pinMode(RMN,OUTPUT);
  digitalWrite(LME,HIGH);
  digitalWrite(RME,HIGH);
}

void forward()
{
  digitalWrite(LMP,HIGH);
  digitalWrite(LMN,LOW);
  digitalWrite(RMP,LOW);
  digitalWrite(RMN,HIGH);
}

void backward()
{
  digitalWrite(LMP,LOW);
  digitalWrite(LMN,HIGH);
  digitalWrite(RMP,HIGH);
  digitalWrite(RMN,LOW);
}

void stop()
{
  digitalWrite(LMP,LOW);
  digitalWrite(LMN,LOW);
  digitalWrite(RMP,LOW);
  digitalWrite(RMN,LOW);
}

void loop(){
  if(irrecv.decode(&rslts)){
    unsigned int value = rslts.value;
    switch(value){
      case forw:
        forward();
        break;
      case backw:
        backward();
        break;
      case hault:
        stop();
        break;
    }
    Serial.println(value);
    irrecv.resume();
  }
}
