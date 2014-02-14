/**
 * Programa que aciona 2 motores DC usando PWM.
 * Um dos motores sera acionado a 25% e o outro a 50%.
 *
 *
 * Autor: Mauricio de O. Pena
 * Data: 01/03/2012
 *
 */

// M2 -> MOTOR DIREITO
#define PWM_M2 10   // PWM MOTOR DIREITO -> OK
#define PWM_M1 9   // 
#define DIR_M2 4  // DIRECAO MOTOR DIREITO -> OK
#define DIR_M1 8   // direcao do modor esquerdo -> OK

void setup() {
    // Seta os pinos dos PWM dos motores como saidas
    pinMode(PWM_M1, OUTPUT);
    pinMode(PWM_M2, OUTPUT);
    
    // Seta os 2 pinos de controle dos motores
    pinMode(DIR_M1, OUTPUT);
    pinMode(DIR_M2, OUTPUT);
    
    // Seta PWM, nos 2 motores, em 25% e 50% (Obs.: analogWrite values from 0 to 255)
    analogWrite(PWM_M1, 255/1);
    analogWrite(PWM_M2, 255/1);
    //digitalWrite(PWM_M1, HIGH);  
    //analogWrite(PWM_M1, 255/2);
    //digitalWrite(PWM_M2, HIGH);  

}
 
void loop() {
    // Define direcao dos 2 motores
    digitalWrite(DIR_M1, LOW);
    digitalWrite(DIR_M2, LOW);  
                
    // Pausa por 4 segundos
    delay(4000);
    
    // Inverte direcao dos 2 motores
    digitalWrite(DIR_M1, HIGH); // faz o motor parar <------------------------------gm
    digitalWrite(DIR_M2, HIGH);
    
    // Pausa por 4 segundos
    delay(4000);  
}

