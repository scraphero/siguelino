#include "values.h"

// PINS
  // MOTORS
    const int left__forward = 3;         //Salida pwm motor 1a DERECHO
    const int left__backward = 9;         //Salida pwm motor 1b DERECHO
    const int right_forward = 10;         //Salida pwm motor 2a IZQUIERDO
    const int right_backward = 5;         //Salida pwm motor 2b IZQUIERDO
  // PUSH BUTTON
    const int pin_pulsador = 12 ;
    //

int estadoboton;

const int limite = 2000;     //LE DAMOS NOMBRE AL LIMITE PARA SEPARAR ETRE MAXIMO Y MINIMO

const int low = 0;
const int high = 1;

int sens1;              //LE DAMOS NOMBRE A CADA ENTRADA DE SENSOR 8 ENTRADAS DIGITALES
int sens2;
int sens3;
int sens4;
int sens5;
int sens6;
int sens7;
int sens8;

int S1;
int S2;
int S3;
int S4;
int S5;
int S6;
int S7;
int S8;
                  
   


     
// SETUP
  void setup() {
    //Serial.begin(9600);                 // DEBUG
    //void values();
                                 //  OUTPUTS
                                 
    pinMode(left__forward, OUTPUT);       //PWM MOTOR 1 DERECHO
    pinMode(right_forward, OUTPUT);        //PWM MOTOR 2 IZQUIERDO
    pinMode(left__backward, OUTPUT);       //PWM MOTOR 1 DERECHO
    pinMode(right_backward, OUTPUT);       //PWM MOTOR 2 IZQUIERDO
    
    digitalWrite(pin_pulsador, HIGH);
    
  }

// LOOP
  void loop() {
      //Serial.println("you are here");  // DEBUG

      estadoboton = digitalRead(pin_pulsador);
      while(estadoboton == HIGH){

        digitalWrite(left__forward, LOW);     
        digitalWrite(right_forward, LOW);
        digitalWrite(left__backward, LOW);     
        digitalWrite(right_backward, LOW);

        estadoboton = digitalRead(pin_pulsador);
      

      while(estadoboton == LOW){

          delay(1250);
      while(estadoboton == LOW){

            
          
          
        
      


    
    S1 = analogRead(0); //LES DAMOS NOMBRE A LOS PINES POR LOS QUE LEE A CADA SENSOR
    S2 = analogRead(1);
    S3 = analogRead(2);
    S4 = analogRead(3);
    S5 = analogRead(4);
    S6 = analogRead(5);
    S7 = analogRead(6);
    S8 = analogRead(7);  




  //LES DAMOS VALOR DE ALTO O BAJO A LAS ENTRADAS ANALOGICAS


    if(S1 > limite){
      sens1 = high;
    }
    else{
      sens1 = low;
    }

    if(S2 > limite){
      sens2 = high;
    }
    else{
      sens2 = low;
    }

    if(S3 > limite){
      sens3 = high;
    }
    else{
      sens3 = low;
    }

    if(S4 > limite){
      sens4 = high;
    }
    else{
      sens4 = low;
    }

    if(S5 > limite){
      sens5 = high;
    }
    else{
      sens5 = low;
    }

    if(S6 > limite){
      sens6 = high;
    }
    else{
      sens6 = low;
    }

    if(S7 > limite){
      sens7 = high;
    }
    else{
      sens7 = low;
    }

    if(S8 > limite){
      sens8 = high;
    }
    else{
      sens8 = low;
    }


    
    //PARA QUE VAYA RECTO

  //  1   2   3    4    5   6   7   8             
  // LOW LOW LOW HIGH HIGH LOW LOW LOW      
        
    if (sens1 == LOW && sens2 == LOW &&  sens3 == LOW && sens4 == HIGH &&  sens5 == HIGH &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == LOW){    
     
      analogWrite(left__forward, pwmR);
      analogWrite(right_forward, pwmR);
      analogWrite(left__backward, pwmA1b);
      analogWrite(right_backward, pwmA2b);
     
   
      
       }

  //  1   2   3    4    5   6   7   8             
  // LOW LOW HIGH HIGH HIGH HIGH LOW LOW      
        
    if (sens1 == LOW && sens2 == LOW &&  sens3 == HIGH && sens4 == HIGH &&  sens5 == HIGH &&  sens6 == HIGH &&  sens7 == LOW &&  sens8 == LOW){    
     
      analogWrite(left__forward, pwmR);
      analogWrite(right_forward, pwmR); 
      analogWrite(left__backward, pwmA1b);
      analogWrite(right_backward, pwmA2b);  
      
       }
          
                              //SI SE SALE PARA LA DERECHA
  //  1   2   3    4    5   6   7   8             
  // LOW LOW HIGH HIGH HIGH LOW LOW LOW    CURVA A IZQUIERDAS

    if (sens1 == LOW && sens2 == LOW &&  sens3 == LOW && sens4 == HIGH &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == LOW){    
       
      analogWrite(left__forward, pwm_A_outside_wheel);
      analogWrite(right_forward, pwm_A_inside_wheel);   
      analogWrite(left__backward, pwmA1b);
      analogWrite(right_backward, pwmA2b);
       }
  //  1   2   3    4    5   6   7   8             
  // LOW LOW HIGH HIGH LOW LOW LOW LOW    CURVA B IZQUIERDAS

    if (sens1 == LOW && sens2 == LOW &&  sens3 == HIGH && sens4 == HIGH &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == LOW){    
    
      analogWrite(left__forward, pwmB1a);
      analogWrite(right_forward, pwmB2a);  
      analogWrite(left__backward, pwmB1b);
      analogWrite(right_backward, pwmB2b); 
      
       }
  //  1   2   3    4    5   6   7   8             
  // LOW HIGH HIGH HIGH LOW LOW LOW LOW    CURVA C IZQUIERDAS

    if (sens1 == LOW && sens2 == LOW &&  sens3 == HIGH && sens4 == LOW &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == LOW){    
    
      analogWrite(left__forward, pwmC1a);
      analogWrite(right_forward, pwmC2a);   
      analogWrite(left__backward, pwmC1b);
      analogWrite(right_backward, pwmC2b);
      
       }
  //  1   2   3    4    5   6   7   8             
  // LOW HIGH HIGH LOW LOW LOW LOW LOW    CURVA D IZQUIERDAS

    if (sens1 == LOW && sens2 == HIGH &&  sens3 == HIGH && sens4 == LOW &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == LOW){    
    
      analogWrite(left__forward, pwmD1a);
      analogWrite(right_forward, pwmD2a);   
      analogWrite(left__backward, pwmD1b);
      analogWrite(right_backward, pwmD2b);
      
       }
       
  //  1   2   3    4    5   6   7   8             
  // HIGH HIGH HIGH LOW LOW LOW LOW LOW    CURVA E IZQUIERDAS

    if (sens1 == LOW && sens2 == HIGH &&  sens3 == LOW && sens4 == LOW &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == LOW){    
     
      analogWrite(left__forward, pwmE1a);
      analogWrite(right_forward, pwmE2a); 
      analogWrite(left__backward, pwmE1b);
      analogWrite(right_backward, pwmE2b);  
      
       }
  //  1    2    3    4    5   6   7   8             
  // HIGH HIGH HIGH HIGH LOW LOW LOW LOW    CURVA E IZQUIERDAS

    if (sens1 == HIGH && sens2 == HIGH &&  sens3 == HIGH && sens4 == HIGH &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == LOW){    
     
      analogWrite(left__forward, pwmE1a);
      analogWrite(right_forward, pwmE2a);
      analogWrite(left__backward, pwmE1b);
      analogWrite(right_backward, pwmE2b);   
      
       }     
  //  1   2   3    4    5   6   7   8             
  // HIGH HIGH LOW LOW LOW LOW LOW LOW    CURVA F IZQUIERDAS

    if (sens1 == HIGH && sens2 == HIGH &&  sens3 == LOW && sens4 == LOW &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == LOW){    
           
      analogWrite(left__forward, pwmF1a);
      analogWrite(right_forward, pwmF2a);   
      analogWrite(left__backward, pwmF1b);
      analogWrite(right_backward, pwmF2b);
      
       }
  //  1   2   3    4    5   6   7   8             
  // HIGH LOW LOW LOW LOW LOW LOW LOW    CURVA G IZQUIERDAS

    if (sens1 == HIGH && sens2 == LOW &&  sens3 == LOW && sens4 == LOW &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == LOW){    
        
      analogWrite(left__forward, pwmG1a);
      analogWrite(right_forward, pwmG2a);   
      analogWrite(left__backward, pwmG1b);
      analogWrite(right_backward, pwmG2b);
      
       }

                              //SI SE SALE PARA LA IZQUIERDA

  //  1   2   3    4    5   6   7   8             
  // LOW LOW LOW HIGH HIGH HIGH LOW LOW    CURVA A DERECHAS

    if (sens1 == LOW && sens2 == LOW &&  sens3 == LOW && sens4 == LOW &&  sens5 == HIGH &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == LOW){    
        
      analogWrite(left__forward, pwm_A_inside_wheel);
      analogWrite(right_forward, pwm_A_outside_wheel);   
      analogWrite(left__backward, pwmA1b);
      analogWrite(right_backward, pwmA2b);
      
       }

  //  1   2   3    4    5   6   7   8             
  // LOW LOW LOW LOW HIGH HIGH LOW LOW    CURVA B DERECHAS 

    if (sens1 == LOW && sens2 == LOW &&  sens3 == LOW && sens4 == LOW &&  sens5 == HIGH &&  sens6 == HIGH &&  sens7 == LOW &&  sens8 == LOW){    
        
      analogWrite(left__forward, pwmB2a);
      analogWrite(right_forward, pwmB1a);   
      analogWrite(left__backward, pwmB2b);
      analogWrite(right_backward, pwmB1b);
      
       }
  //  1   2   3    4    5   6   7   8             
  // LOW LOW LOW LOW HIGH HIGH HIGH LOW    CURVA C DERECHAS

    if (sens1 == LOW && sens2 == LOW &&  sens3 == LOW && sens4 == LOW &&  sens5 == LOW &&  sens6 == HIGH &&  sens7 == LOW &&  sens8 == LOW){    
        
      analogWrite(left__forward, pwmC2a);
      analogWrite(right_forward, pwmC1a);   
      analogWrite(left__backward, pwmC2b);
      analogWrite(right_backward, pwmC1b);
      
       }
  //  1   2   3    4    5   6   7   8             
  // LOW LOW LOW LOW LOW HIGH HIGH LOW    CURVA D DERECHAS 

    if (sens1 == LOW && sens2 == LOW &&  sens3 == LOW && sens4 == LOW &&  sens5 == LOW &&  sens6 == HIGH &&  sens7 == HIGH &&  sens8 == LOW){    
        
      analogWrite(left__forward, pwmD2a);
      analogWrite(right_forward, pwmD1a);   
      analogWrite(left__backward, pwmD2b);
      analogWrite(right_backward, pwmD1b);
      
       }
  //  1   2   3    4    5   6   7   8             
  // LOW LOW LOW LOW LOW HIGH HIGH HIGH    CURVA E DERECHAS

    if (sens1 == LOW && sens2 == LOW &&  sens3 == LOW && sens4 == LOW &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == HIGH &&  sens8 == LOW){    
        
      analogWrite(left__forward, pwmE2a);
      analogWrite(right_forward, pwmE1a);   
      analogWrite(left__backward, pwmE2b);
      analogWrite(right_backward, pwmE1b);
      
       }
  //  1   2   3    4   5   6    7   8             
  // LOW LOW LOW LOW HIGH HIGH HIGH HIGH    CURVA E DERECHAS

    if (sens1 == LOW && sens2 == LOW &&  sens3 == LOW && sens4 == LOW &&  sens5 == HIGH &&  sens6 == HIGH &&  sens7 == HIGH &&  sens8 == HIGH){    
        
      analogWrite(left__forward, pwmE2a);
      analogWrite(right_forward, pwmE1a);   
      analogWrite(left__backward, pwmE2b);
      analogWrite(right_backward, pwmE1b);
      
       }
       
  //  1   2   3    4    5   6   7   8             
  // LOW LOW LOW LOW LOW LOW HIGH HIGH    CURVA F DERECHAS 

    if (sens1 == LOW && sens2 == LOW &&  sens3 == LOW && sens4 == LOW &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == HIGH &&  sens8 == HIGH){    
        
      analogWrite(left__forward, pwmF2a);
      analogWrite(right_forward, pwmF1a);   
      analogWrite(left__backward, pwmF2b);
      analogWrite(right_backward, pwmF1b);
      
       }
  //  1   2   3    4    5   6   7   8             
  // LOW LOW LOW LOW LOW LOW LOW HIGH    CURVA G DERECHAS

    if (sens1 == LOW && sens2 == LOW &&  sens3 == LOW && sens4 == LOW &&  sens5 == LOW &&  sens6 == LOW &&  sens7 == LOW &&  sens8 == HIGH){    
        
      analogWrite(left__forward, pwmG2a);
      analogWrite(right_forward, pwmG1a);   
      analogWrite(left__backward, pwmG2b);
      analogWrite(right_backward, pwmG1b);
      
       }

          }
          }
  }
  }
