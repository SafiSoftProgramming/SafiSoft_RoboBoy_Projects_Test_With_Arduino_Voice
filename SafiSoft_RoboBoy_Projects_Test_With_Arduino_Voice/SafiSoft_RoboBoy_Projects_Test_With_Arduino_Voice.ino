
#include<SoftwareSerial.h>

// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 

//Bluetooth serial stuff
const int txpin = 5;       
const int rxpin = 6;

SoftwareSerial blue(txpin, rxpin);
char content = 'P';
String state = "center" ;


void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  blue.begin(9600);
  blue.setTimeout(10);
}


void loop() {
     if (blue.available()) {
      
         content = blue.read();

           if(content == 'L' && state == "left"){
      blue.println("Glass Says : no more moving to left you so stuped"); 
      }

       if(content == 'R' && state == "right"){
      blue.print("Glass Says : no more moving to right you so stuped"); 
      }
    
      if (content == 'L' && state == "center"){
       state = "left" ;
       digitalWrite(dirPin,HIGH);  
       move(); 
       
     }           
      
     else if (content == 'R' && state == "center"){
      state = "right" ;
      digitalWrite(dirPin,LOW); 
      move();
     }  

     else if (content == 'C' && state == "left" || state == "right" ){
      if(state == "left"){
        digitalWrite(dirPin,LOW); 
        }
      if(state == "right"){
        digitalWrite(dirPin,HIGH);
        }  
      state = "center" ;
      move();
     }  

   
  }
}

void move(){
   for(int x = 0; x < 25; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(10000);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(10000);
      }
  }
