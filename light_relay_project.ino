// main section
#include "relay.h"
#include "light_sensor.h"
#include "firewire_com.h"


void setup() {
  Serial.begin(9600);
  
  setup_relay();          // relay setup
  setup_light_sensor();   // BH1750 setup
  
}

void loop() {

  // masurement expresed in lumens => 1 lux/m2
  uint16_t lux_value = get_light_measurement();

  // sending data to DB
  post_data(lux_value);
 
  if ( lux_value < 65 ) {
    turn_relay_on(true);
  } else {
    turn_relay_on(false);
  }
  delay(10000);
  

}
