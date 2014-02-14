// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;
                // a maximum of eight servo objects can be created 
 
int pos1 = 0;    // variable to store the servo position 
int pos2 = 180;    // variable to store the servo position 

int dir1 = 1;    // variable to store the servo position 
int dir2 = 0;    // variable to store the servo position 


 
void setup() 
{ 
  myservo1.attach(11);  // attaches the servo on pin 11 to the servo object on dog right
  myservo2.attach(12);  // attaches the servo on pin 12 to the servo object on dog left
  
  // Configuracao da porta serial, para exibir as leituras do sonar
  Serial.begin( 9600 );  
  
} 
 
 
void loop() 
{ 
  /*
  for(pos = 110; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 50; pos>=100; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
   myservo2.write(pos);
   delay(15);                       // waits 15ms for the servo to reach the position 
  }
  for(pos = 50; pos < 140; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=110; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo1.write(pos);
    delay(15);               
  }
  */
  
  for(int i = 0; i<=180; i++)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo1.write(pos1);
    myservo2.write(pos2);
    delay(15);

    if (dir1 == 1)
    { 
      pos1++;
      if (pos1 == 180)
      {
        dir1 = 0;
      }
    }  
    else
    {
      pos1--; 
      if (pos1 == 110)
      {
        dir1 = 1;
      }
    }
    
    if (dir2 == 1)
    { 
      pos2++;
      if (pos2 == 140)
      {
        dir2 = 0;
      }
    }  
    else
    {
      pos2--; 
      if (pos2 == 50)
      {
        dir2 = 1;
      }
    }    
    
  }

  Serial.println(pos1);    
  Serial.println(pos2); 
  
} 
