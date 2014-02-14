/*
  Analog input, analog output, serial output
 
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground
 
 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int PWM1_PIN = 9; // Analog output pin that the LED is attached to
const int PWM2_PIN = 10; // Analog output pin that the LED is attached to

const int DIR1_PIN = 8; // Analog output pin that the LED is attached to
const int DIR2_PIN = 4; // Analog output pin that the LED is attached to


int outputValue1 = 0;        // value output to the PWM (analog out)
int outputValue2 = 0;        // value output to the PWM (analog out)

int direcao1 = 0;
int direcao2 = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
 
  pinMode( PWM1_PIN, OUTPUT  );
  pinMode( PWM2_PIN, OUTPUT  );

  pinMode( DIR1_PIN , OUTPUT  );
  pinMode( DIR2_PIN , OUTPUT  );
  
  pinMode( 13 , OUTPUT  );

  outputValue1 = 0;
  outputValue2 = 0;
  
  direcao1 = 0;
  direcao2 = 0;
  
}

void loop() {
  
 
  analogWrite(PWM1_PIN, outputValue1);           
  analogWrite(PWM2_PIN, outputValue2);           

  digitalWrite( DIR1_PIN, direcao1 );
  digitalWrite( DIR2_PIN, direcao2 );
  
  
  
  if( Serial.available() ) {
     int bin = Serial.read();
     
     if( bin == 'z' ){
       if( outputValue1 > 0 )
         outputValue1--;
       Serial.print("motor 1 =");
       Serial.println( outputValue1 );
     } 
     
     if( bin == 'x' ){
       if( outputValue1 < 255 )
         outputValue1++;
       Serial.print("motor 1 =");
       Serial.println( outputValue1 );
     } 

     if( bin == 'c' ){
       if( direcao1 == LOW )
         direcao1 = HIGH;
       else
         direcao1 = LOW;
         
       Serial.print("direcao 1 =");
       Serial.println( direcao1 );
     } 


     if( bin == 'a' ){
       if( outputValue2 > 0 )
         outputValue2--;
       Serial.print("motor 2 =");
       Serial.println( outputValue2 );
     } 
     
     if( bin == 's' ){
       if( outputValue2 < 255 )
         outputValue2++;
       Serial.print("motor 2 =");
       Serial.println( outputValue2 );
     } 

     if( bin == 'd' ){
       if( direcao2 == LOW )
         direcao2 = HIGH;
       else
        direcao2 = LOW;
       Serial.print("direcao 2 =");
       Serial.println( direcao2 );
     } 


    
  }
  
}
