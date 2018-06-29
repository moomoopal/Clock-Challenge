#include <Servo.h>

Servo blue;
#define a_note 440
#define b_note 494
#define d_note 587
#define g_note 392

#define tempo 1
// variable to store the distance (cm)
int distance = 0 ;
  
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

void nightLight(){
  //if it is dark 995
  if (analogRead(1)>900){
    //turn light on
    digitalWrite(7,HIGH);
    jingleBells();
 }  
  //if it is light 820
  if (analogRead(1)<900){
    //turn light off
    digitalWrite(7,LOW);
  }
}  
void jingleBells(){
  musicChallenge(b_note, 4);
  musicChallenge(b_note, 4);
  musicChallenge(b_note, 2);
  musicChallenge(b_note, 4);
  musicChallenge(b_note, 4);
  musicChallenge(b_note, 2);
  musicChallenge(b_note, 4);
  musicChallenge(d_note, 4);
  musicChallenge(g_note, 4);
  musicChallenge(a_note, 4);
  musicChallenge(b_note, 1);
}



void musicChallenge(int freq, int note){
  //if note equals one = whole note
  //if note equals two = half note
  //if note equals four = quarter note
  
  int wholeNote = 1000*tempo;
  tone(6,freq);
  delay(wholeNote/note);
  noTone(6);
  /*if (note==1){
    tone(6,freq);
    delay(wholeNote);
    noTone(6);
  }
  if (note==2){
    tone(6,freq);
    delay(wholeNote/note);
    noTone(6);
  }
  if (note==4){
    tone(6,freq);
    delay(wholeNote/note);
    noTone(6);
  }*/
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
  Serial.begin(9600);
  digitalWrite( 3 , LOW );
}

// connect pin 3 to the trigger pin
// connect pin 4 to the echoPin


// function for ultrasonic 
int ultrasonic(int trigPin, int echoPin)
{
    long duration;

    // setup trigger and echo pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // send out trigger signal
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(trigPin, LOW);

    // wait for a pulse on the echo pin
    duration = pulseIn(echoPin, HIGH);
  
    // take the pulse and scale it to cm
    duration = duration / 59;

    // if duration is less than two or greater than 300, something is wrong.  Return an error.
    // if ((duration < 2) || (duration > 300)) return false;

    return duration;
}



void loop() {
  // put your main code here, to run repeatedly:
// blinky();
 //blinkyFast();

 distance = ultrasonic( 3 , 4 ) ;
 nightLight();

 
 //Serial.println(analogRead(1));
 Serial.print(distance);
 Serial.println(" cm");

 if (distance<10){
  jingleBells();
 }



 //if button is pressed, 
 if(digitalRead(2)==LOW){
   //start clockChallenge
  delay(1000);
  if(digitalRead(2)==LOW){
     clockChallenge();
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
