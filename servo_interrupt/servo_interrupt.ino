// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 

 
Servo myservo1;  // create servo object to control a servo direita do cão
Servo myservo2; // create servo object to control a servo esquerda do cão
 
int pos = 0;    // variable to store the servo position 
int dir = 0;

void setup() 
{ 
  myservo1.attach(11);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(12);
  	 
  // initialize Timer1
  noInterrupts(); // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
	 
  TCNT1 = 34286; // preload timer 65536-16MHz/256/2Hz
  TCCR1B |= (1 << CS12); // 256 prescaler
  TIMSK1 |= (1 < TOIE1); // enable timer overflow interrupt
  interrupts(); // enable all interrupts} 
} 

ISR(Timer1_OVF_vect) // interrupt service routine that wraps a user defined function supplied by attachInterrupt
{
  TCNT1 = 34286; // preload timer
  //digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
  if (dir == 0)
  {
    pos++;
    if (pos >= 180) dir = 1;
  }
  else if (dir == 1)
  {
    pos--;
    if (pos <=0) dir = 0;
  }  
}

void loop() 
{ 
  /*
  for(pos = 110; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 70; pos>=100; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
   myservo2.write(pos);
   delay(15);                       // waits 15ms for the servo to reach the position 
  }
  for(pos = 70; pos < 140; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=110; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo1.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  */
  myservo1.write(pos);

} 
