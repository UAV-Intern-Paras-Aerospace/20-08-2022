#define _PIN_PWM_SIGNAL 11
volatile int NbTopsFan;
int Calc;                               
int hallsensor = 2;
int tmp1 = 0;

void rpm () 
{ 
 NbTopsFan++; 


} 
void setup() 
{ 
 pinMode(hallsensor, INPUT); 
 Serial.begin(9600); 


 attachInterrupt(0, rpm, RISING);
} 
void loop ()    
{
 NbTopsFan = 0;    
 sei();            
 delay (1000);
 cli();            
 Calc = (NbTopsFan * 60 / 20.5);  
 tmp1 = Calc * 16.667;
 Serial.print (tmp1, DEC); 
 Serial.print (" ml/minute\r\n");
 analogWrite(_PIN_PWM_SIGNAL, hallsensor);
 //analogWrite(_PIN_PWM_SIGNAL, 254);
}
