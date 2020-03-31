#include <SoftwareSerial.h>

String voice; //to store voice command

int l1 = 3; //Positive of left motor
int l2 = 4; //Negative of left motor
int r1 = 5; //Positive of right motor
int r2 = 6; //negative of right motor
int LED1 = 8; // LED 1 pin
int LED2 = 9; //LED 2 pin 
 
void setup()
{
  Serial.begin(9600); //start serial communication

  pinMode(3 ,OUTPUT);
  pinMode(4 ,OUTPUT);
  pinMode(5 ,OUTPUT);
  pinMode(6 ,OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}
 
void loop() 
{
  while (Serial.available()){ //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = Serial.read(); //Conduct a serial read
    Serial.println( c);
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
   
  }
  if (voice.length() > 0){
    if(voice == "move forward"){
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, LOW);
      delay(3000);
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      
      }
    else if(voice == "go back"){
     digitalWrite(l1, LOW);
     digitalWrite(l2, HIGH);
     digitalWrite(r1, LOW);
     digitalWrite(r2, HIGH);
     delay(3000);
     digitalWrite(l1, LOW);
     digitalWrite(l2, LOW);
     digitalWrite(r1, LOW);
     digitalWrite(r2, LOW);
      }
    else if(voice == "turn right" ) {
     digitalWrite(l1, HIGH);
     digitalWrite(l2, LOW);
     digitalWrite(r1, LOW);
     digitalWrite(r2, LOW);
     delay(1500);
     digitalWrite(l1, LOW);
     digitalWrite(l2, LOW);
     digitalWrite(r1, LOW);
     digitalWrite(r2, LOW);
    }
    else if(voice == "turn left") {
     digitalWrite(l1, LOW);
     digitalWrite(l2, LOW);
     digitalWrite(r1, HIGH);
     digitalWrite(r2, LOW);
     delay(1500);
     digitalWrite(l1, LOW);
     digitalWrite(l2, LOW);
     digitalWrite(r1, LOW);
     digitalWrite(r2, LOW);
    }
    else if(voice == "headlights on") {
       digitalWrite(LED1, HIGH);
       digitalWrite(LED2, HIGH);
    }
    else if(voice == "headlights off") {
       digitalWrite(LED1, LOW);
       digitalWrite(LED2, LOW);
    }
    else if(voice == "stop") {
     digitalWrite(l1, LOW);
     digitalWrite(l2, LOW);
     digitalWrite(r1, LOW);
     digitalWrite(r2, LOW);
    }
    
  voice=""; //Reset the variable after initiating
  }
}
