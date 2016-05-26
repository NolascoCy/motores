#include <IRremote.h>
#define E1 10
#define E2 11

int pi = 8;
int pin = 9;
#define B1 12
#define B2 13

#define RP 7
#define LD 6

IRrecv irrecv(RP);
decode_results results;
int encendido = 0;
int direccion = 0;
void setup() {

    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);

    pinMode(pi, OUTPUT);
    pinMode(pin, OUTPUT);
    pinMode(B1, OUTPUT);
    pinMode(B2, OUTPUT);
  	
    pinMode(LD, OUTPUT);
  	
  	Serial.begin(9600);
	irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results))
  {
    Serial.println(results.value);
    digitalWrite(LD, HIGH);
    if(results.value == 4294967295)
    {
      if(encendido == 0)
      {
        encendido = 1;
      }
      else
      {
        encendido = 0;
      }
      delay(500);
    }
    if(results.value == 16589023)
    {
      digitalWrite(E1, LOW);
      digitalWrite(E2, LOW);
      direccion = 0;
      digitalWrite(LD, HIGH);
      delay(200);
    }
    if(results.value == 16605343)
    {
      digitalWrite(E1, LOW);
      digitalWrite(E2, LOW);
      direccion = 1;
      digitalWrite(LD, HIGH);
      delay(200);
    }
    Serial.print(encendido);
    Serial.print(" - ");
    Serial.println(direccion);
    
  	irrecv.resume();
  }
  digitalWrite(LD, LOW);
  if((encendido == 1) && (direccion == 0))
  {
    analogWrite(E1, 255);
    analogWrite(E2, 255);
 
    digitalWrite(pi, HIGH);
    digitalWrite(pin, LOW);
    digitalWrite(B1, HIGH);
    digitalWrite(B2, LOW);   
  }
  if((encendido == 1) && (direccion == 1))
  {
    analogWrite(E1, 255);
    analogWrite(E2, 255);
 
    digitalWrite(pi, LOW);
    digitalWrite(pin, LOW);
    digitalWrite(B1, LOW);
    digitalWrite(B2, HIGH);
  }
  if(encendido == 0)
   {
     digitalWrite(E1, LOW);
     digitalWrite(E2, LOW);
   }
} 		 	 

