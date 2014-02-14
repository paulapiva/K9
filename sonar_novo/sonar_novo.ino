
/**
 * Teste do novo sonar
 *
 * Autor: Mauricio de O. Pena
 * Data: 04/06/2012
 * Ultima atualizacao: 15/11/2012
 *
 */

#include <Ultrasonic.h>

//Ultrasonic ultrasonic(2, 5) trigger echo;
Ultrasonic ultrasonic(2, 5);


void setup()
{
  Serial.begin( 9600 );
}

void loop()
{
  Serial.print( ultrasonic.Ranging(CM) );
  Serial.println( "cm" );
    
  delay(1000);
}

