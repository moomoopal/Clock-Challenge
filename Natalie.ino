#include <Servo.h>

Servo blue;

void clockChallenge(){
   blue.write(180); //goes to 12
   delay(375); //Gives motor time to reach destination
   digitalWrite(7,HIGH);
   delay(1000); //motor is not moving
   digitalWrite(7,LOW);
   
   blue.write(75); //goes to 3
   delay(200); //gives motor time to reach destination
   digitalWrite(7,HIGH);
   delay(1000); //motor is not moving
   digitalWrite(7,LOW);
   
   blue.write(0); //goes to 6
   delay(200); //gives motor time to reach destination
   digitalWrite(7,HIGH);
   delay(1000); //motor is not moving
   digitalWrite(7,LOW);
}
void hotCross(){
   tone(6,493);
   delay(500);
   noTone(6);
   delay(500);
   tone(6,440);
   delay(500);
   noTone(6);
   delay(500);
   tone(6,392);
   delay(500);
   noTone(6); 
   delay(500);
}


void blinkyFast(){
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  delay(500);
}


void blinky(){
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(7,LOW);
  delay(1000);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  blue.attach(9);
  pinMode(2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
// blinky();
 //blinkyFast();

 //if button is pressed, 
 if(digitalRead(2)==LOW){
   //start clockChallenge
  delay(2000);
  if(digitalRead(2)==LOW){
     clockChallenge();
  }
  //clockChallenge();
  //delay(1000);
  //clockChallenge();
 
 }
 //if button is not pressed
 if(digitalRead(2)==HIGH){
   //turn light off
   digitalWrite(7,LOW);
 }


 


  /*digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(7,LOW);
  delay(1000); 
  */

 
 
 

/*
 digitalWrite(7,HIGH);
 blue.write(180);
 digitalWrite(7,LOW);
 digitalWrite(7,HIGH);
 delay(1000);
 
 //notmoving


 digitalWrite(7,LOW);
 blue.write(90);
 digitalWrite(7,HIGH);
 delay(1000);
 //notmoving

 

 digitalWrite(7,LOW);
 blue.write(0);
 digitalWrite(7,HIGH);
 delay(1000);
 //notmoving


 digitalWrite(7,LOW);
 blue.write(150);
 digitalWrite(7,HIGH);
 delay(1000);
 //notmoving


*/
 
}
