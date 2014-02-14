/**
 * Programa do K9
 *
 *
 * Autor: Mauricio de O. Pena
 * Data: 30/03/2012
 *
 */


#include <Ultrasonic.h>
#include <Servo.h> 

// M2 -> MOTOR DIREITO
#define PWM_M2 10  // PWM MOTOR DIREITO -> OK
#define PWM_M1 9   // PWM MOTOR ESQUERDO -> OK
#define DIR_M2 4   // DIRECAO MOTOR DIREITO -> OK
#define DIR_M1 8   // DIRECAO MOTOR ESQUERDO -> OK


Ultrasonic ultrasonic(2, 5);

Servo myservo1;  // inica objeto do servo da direita do cão
Servo myservo2;  // inica objeto do servo da esquerda do cão
 
int pos1 = 0;    // variável para armazenar a posição de servo da direita 
int pos2 = 180;    // variável para armazenar a posição de servo da esquerda 

int dir1 = 1;    // variable to store the servo position 
int dir2 = 0;    // variable to store the servo position 

long distancia = 100000000L;  // variavel recebe valor distancia


void setup() {
    
    // Seta os pinos dos PWM dos motores como saidas
    pinMode(PWM_M1, OUTPUT);
    pinMode(PWM_M2, OUTPUT);
    
    // Seta os 2 pinos de controle dos motores
    pinMode(DIR_M1, OUTPUT);
    pinMode(DIR_M2, OUTPUT);
    
    // Aciona ambos os motores em 100%
    analogWrite(PWM_M1, 255);
    analogWrite(PWM_M2, 255);
  
    // Define direcao dos 2 motores
    digitalWrite(DIR_M1, LOW);
    digitalWrite(DIR_M2, LOW);  
    
    // Configuracao da porta serial, para exibir as leituras do sonar
    Serial.begin( 9600 );
    
    // Configura servos
    myservo1.attach(11);  // atribui o servo no pino 11 para o objeto servo da direita do cão
    myservo2.attach(12);  // atribui o servo no pino 12 para o objeto servo da esquerda do cão
}
 
void loop() {
      
    // Obtem valor do sonar
    distancia = ultrasonic.Ranging(CM);
    
    // Checa se o robo colidiu com algo
    if (distancia <= 45)
    {
      // Movimenta para tras, circulando
      digitalWrite(DIR_M1, HIGH);
      digitalWrite(DIR_M2, LOW); 
      
      // Aguarda 0,5 segundo
      delay(300);
      
      // Movimenta para frente
      digitalWrite(DIR_M1, LOW);
      digitalWrite(DIR_M2, LOW);      
    }
        
    // Exibe leitura do sonar
    Serial.print(distancia);
    Serial.println( "cm" );    
    delay(200);  // tempo necessario para uma nova leitura do sonar


    // Mexe servos
//    for(int i = 0; i<=180; i++)     // goes from 180 degrees to 0 degrees 
//    {                                
      myservo1.write(pos1);
      myservo2.write(pos2);
      delay(15);

      if (dir1 == 1)
      { 
        pos1 += 10;
        if (pos1 == 180)
        {
          dir1 = 0;
        }
      }  
      else
      {
        pos1 -= 10; 
        if (pos1 == 110)
        {
          dir1 = 1;
        }
      }
    
      if (dir2 == 1)
      { 
        pos2 += 10;
        if (pos2 == 140)
        {
          dir2 = 0;
        }
      }  
      else
      {
        pos2 -=10; 
        if (pos2 == 50)
        {
          dir2 = 1;
        }
      }    
 //   }

    Serial.println(pos1);    
    Serial.println(pos2);

}

