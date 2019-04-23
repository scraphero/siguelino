#include <QTRSensors.h>

//DECLARACION DE ENTRADAS

//{BOTONES
	const int btn1=19;
	const int btn2=4; //}

//{ PINES
	int PWMA=9;     // PIN PWM MOTOR A
	int ain2=8;
	int ain1=7;
	int PWMB=6;     // PIN PWM MOTOR B
	int bin2=5;
	int bin1=4; //}

int cruzero = 80; // VELOCIDAD REFERENCIA



int P=0;          // ERROR
int I=0;          // INTEGRAL
int D=0;          // DERIVATIVO
int LAST=0;
float vel;

#define NUM_SENSORS   8      // number of sensors used
#define TIMEOUT       2500   // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   20     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {17, 16, 15, 14, 13, 12, 11, 10},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];

unsigned int position=0;

void setup()
{

  pinMode(btn1, INPUT);
    
  pinMode(PWMA,OUTPUT);
  pinMode(ain1,OUTPUT);
  pinMode(ain2,OUTPUT);
  pinMode(PWMB,OUTPUT);
  pinMode(bin1,OUTPUT);
  pinMode(bin2,OUTPUT);
  
  pinMode(18,OUTPUT);

//Serial.begin(9600); // set the data rate in bits per second for serial data transmission
  delay(1500);
  digitalWrite(18, HIGH);
   for (int j = 0; j < 40; j++)  
 {                                 
                    
  qtrrc.calibrate();       

 }
 
  digitalWrite(18, LOW); 
                                                                   
 digitalWrite(ain1,LOW);
 digitalWrite(ain2,HIGH);
 
 digitalWrite(bin1,HIGH);
 digitalWrite(bin2,LOW);
 
 analogWrite(PWMA,0);
 analogWrite(PWMB,0);
}


void loop()
{
  
  if (digitalRead(btn1)==1){

for(;;){ 

  qtrrc.read(sensorValues);

     position = qtrrc.readLine(sensorValues, QTR_EMITTERS_ON, 0);
                                             
                                                                                        
 P = ((position)-(3500)); /// ERROR
/////FRENOS////
if(P<-3500){
 analogWrite(PWMA,120);    // VELOCIDAD PARA EL MOTOR DERECHO
  analogWrite(PWMB,180);   // VELOCIDAD PARA EL MOTOR IZQUIERDO
 digitalWrite(ain1,LOW);   // FRENTE
 digitalWrite(ain2,HIGH);
 digitalWrite(bin1,LOW);   // RETROCEDE
 digitalWrite(bin2,HIGH);

} else if (P>3500){
 analogWrite(PWMA,135);    // VELOCIDAD PARA EL MOTOR DERECHO
 analogWrite(PWMB,90);     // VELOCIDAD PARA EL MOTOR IZQUIERDO
 digitalWrite(ain1,HIGH);  // RETROCEDE
 digitalWrite(ain2,LOW);
 digitalWrite(bin1,HIGH);  // FRENTE
 digitalWrite(bin2,LOW);

}
/////////////////////////
  else{
 D= (P - LAST); /// ERROR MENOS EL ERROR ANTERIOR , DERIVATIVO
   I=(P+ LAST); //INTEGRAL
   
   
//vel=(P*0.025)+(D*0.095)+(I*0); // PID
   
vel=(P*0.045)+(D*0.07)+(I*0.00065);// para velocidad 120//////estaba en 0.0925

//vel=(P*0.0428)+(D*0.085)+(I*0); //para velocidad 80 kd=0.06

///CRUZERO =VELOCIDAD PUNTA , V

    if(vel >cruzero) vel=cruzero;
    if(vel<-cruzero) vel=-cruzero;

  analogWrite(PWMA,cruzero-vel); // VELOCIDAD PARA EL MOTOR DERECHO
  analogWrite(PWMB,cruzero+vel); //  VELOCIDAD PARA EL MOTOR IZQUIERDO

 digitalWrite(ain1,LOW);   ///FRENTE
 digitalWrite(ain2,HIGH);
 digitalWrite(bin1,HIGH);  ///FRENTE
 digitalWrite(bin2,LOW);
 
LAST=P;
  }
}////BUCLE INFINITO
}///PRESIONO BOTON
}///FIN DEL LOOP