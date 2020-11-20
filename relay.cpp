#import "relay.h"
#import <Arduino.h>


int relayPin = 3;


void setup_relay(){
  // relay setup
  pinMode(relayPin, OUTPUT); //set pin as output
  digitalWrite(relayPin, LOW); //set initial state OFF for 
}

void turn_relay_on(bool flag){

  if(flag){
    digitalWrite(relayPin, HIGH);
    // relay is on
    delay(2000); // wait for 2 seconds
  } else {
  // relay is off
    digitalWrite(relayPin, LOW);
    delay(2000);  
  }
}
