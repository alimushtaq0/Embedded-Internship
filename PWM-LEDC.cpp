/*In this code we applied PWM on an LED using the LEDC library instead of the normal analogWrite function, to control the brightness of the LED*/

#define pinno1 12
#define pinno2 13
#define pinno3 14
#define freq 200

void setup() {
  // put your setup code here, to run once:
  pinMode(pinno1,OUTPUT);
  pinMode(pinno2,OUTPUT);
  pinMode(pinno3,OUTPUT);
  
  ledcAttach(pinno1,freq,8);
  ledcAttach(pinno2,freq,8);
  ledcAttach(pinno3,freq,8);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0;i<=255;i++)
  {
    ledcWrite(pinno1,i);
    ledcWrite(pinno2,i);
    ledcWrite(pinno3,i);
    delay(10);
  }
  for (int j=255;j>=0;j--)
  {
    ledcWrite(pinno1,j);
    ledcWrite(pinno2,j);
    ledcWrite(pinno3,j);
    delay(10);
  }
}
