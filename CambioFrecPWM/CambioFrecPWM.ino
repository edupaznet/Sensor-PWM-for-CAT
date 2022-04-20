
// Definicion de varialbles
#define f 2000 // Defino mi frecuencia PWM en 2Kz
unsigned int maximo= 0;  // 16 bit
unsigned int conv= 0;    // 16 bit

void setup() {
      // Codigo Para setear la frecuencia del PWM..

     
  TCCR1A = 0B10000000;          // TIMER 1 como PWM FFC y habilito el pin OC1A como salida PWM 
  TCCR1B = 0B00010001;          // Reloj del timer 16Mhz ftimer = fsys / N = 16Mhz, sin prescaler
 //pinMode(9, OUTPUT);// sets the pin as output
 
  maximo =(16e6/(2*f))-1;   // Define el numero maximo al que el timer debe contar ... fPWM = ftimer/ (2*(maximo+1)) 
  ICR1 = maximo;             // define la frecuencia
  OCR1A = maximo >> 1;      // Divido el valor maximo por 2 desplazando 1 bit hacia la derecha. Es mucho mas rapido que dividir por 2
  TIMSK1 = 0B00100000;     //Habilito la interrupción comparacion con ICR1
  DDRB |= B00000010;       //Set OC1A as an Output
  sei();                  //Habilita las interrupciones Globales
  Serial.begin(9600);
}

void loop() {
delay(200);
 Serial.print("  ----Valor PWM = ");Serial.println(conv);
   delay(200);
   Serial.print("  ----Valor Pote = ");Serial.println(A0);

}

ISR(TIMER1_CAPT_vect)
{
  conv= analogRead(A0); // Leer el valor del Pote en el canal A0
  conv= map (conv,0,1023,0,maximo); // ciclo de trabajo de 0 a 100%
  OCR1A = conv;
  }
