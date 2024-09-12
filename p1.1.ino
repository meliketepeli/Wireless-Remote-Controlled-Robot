
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(1,0); 
char t;

#define MLa 5     
#define MLb 6     
#define MRa 9    
#define MRb 10    
#define trigPin 7           
#define echoPin 8        
#define ledPin 13
long duration, distance;
bool canMove = true; 

void setup() {
bluetooth.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(MLa,OUTPUT);   
pinMode(MLb,OUTPUT);   
pinMode(MRa,OUTPUT);   
pinMode(MRb,OUTPUT);   
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}
 
void loop() 
{
  if(bluetooth.available()>0)
  {
    t = bluetooth.read();
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);


 duration = pulseIn(echoPin, HIGH);        
 distance = duration * 0.0344 / 2;                       
 if(distance < 20){
   canMove = false;
   digitalWrite(ledPin, HIGH);
 }
 else{
   canMove = true;
   digitalWrite(ledPin, LOW);
 }

 switch(t)
 {
  case 'F':
          if(canMove){
              digitalWrite(MLa,LOW);
              digitalWrite(MLb,HIGH);
              digitalWrite(MRa,LOW);
              digitalWrite(MRb,HIGH);
            }
   break;
   
  case 'B':
            digitalWrite(MLa,HIGH);
            digitalWrite(MLb,LOW);
            digitalWrite(MRa,HIGH);
            digitalWrite(MRb,LOW);
          
   break;
   
  case 'L':
          digitalWrite(MLa,LOW); 
          digitalWrite(MLb,HIGH); 
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,LOW);
   break;
   
  case 'R':
          digitalWrite(MLa,LOW); 
          digitalWrite(MLb,LOW); 
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,HIGH);
   break;
   
    case 'S':
         
          digitalWrite(MLa,LOW);
          digitalWrite(MLb,LOW); 
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,LOW);

        
  }
  delay(10);
}