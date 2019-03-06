#define CUSTOM_SETTINGS
#define INCLUDE_FINGERPRINT_SCANNER_SHIELD

#include <OneSheeld.h>

const int buttonPin = 2;     
const int ledPin =  13;  
const int relay = 7;
int buttonState = 0;    

void setup() 
{
  OneSheeld.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(buttonPin,HIGH);
}

void loop() 
{
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) 
  {
    digitalWrite(ledPin, HIGH);
  } else 
  {
    digitalWrite(ledPin, LOW);
  }
  
  if(FingerprintScanner.isNewFingerScanned() && FingerprintScanner.isVerified())
  {
    digitalWrite(relay, LOW);
    delay(1000);
  } else 
  {
    digitalWrite(relay, HIGH);
  }
}
