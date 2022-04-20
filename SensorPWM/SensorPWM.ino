/*Este es un sketch para resolver el problema de la palanca de comando de la motoniveladora CAT 160M */
// Cat control GP-Joysick fot 160M motorgrader and others 

int Salpwm = 9;      // Salida PWM al pin digital pin 10
// int analogPin = A0;   // Se conecta el sensor del Joystick a la entrada A3
int val = 0;         // variable to store the read value
int pwm, pwmsup, pwminf ;

void setup() {
pinMode(Salpwm, OUTPUT);// sets the pin as output
Serial.begin(9600);
             }

void loop() {

  val= analogRead(A0);  
  pwm=(val/4)*1.48; 
 
  analogWrite(Salpwm,pwm);        // Modula al 50% , la palanca esta en el medio

if(pwm > 129){
  pwmsup = map(pwm, 128, 190, 128, 229);
  analogWrite(Salpwm,pwmsup);
             }
   else {
    if (pwm < 127){
      pwminf = map(pwm, 126, 60, 126, 25);
      analogWrite(Salpwm,pwminf);
                  }
         }
  Serial.print("Valor PWM = ");
  Serial.println(pwm);
 }
