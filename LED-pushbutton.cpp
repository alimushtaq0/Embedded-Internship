/*In this code we controlled a basic LED with the help of a push button as when the buttons state was HIGH the LED was turned on and vice versa*/

#define buttonPin 26
#define ledPin 15
int buttonState = 0;

void setup()
{

  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  if (buttonState == 1)
  {
    digitalWrite(ledPin, HIGH);
  } 
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
