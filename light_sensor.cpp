#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

String lightLevel = "normal";

/*
  there are 3 light levels expecified here
  high -> when we are pointing light sensor with a flashlight o it's receiving sunny light directly
          here we're talking about a light greatter than 4k lux
  normal -> this level it depends on the day light that you're having or the artificial light provided by your lamp
          for this example i was getting 54 lux as a regular light in daylight or at evening with my lamp
          but asume that is everything between 4k and 65 lux
  low -> when having a poor light such a dark room or a distant lamp
          we are taking less than 65 lux

  have in mind that it depends on your workstation lights and diferent sensors may difier.
*/

void setup_light_sensor(){
  // light sensor setup
  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();
  // On esp8266 you can select SCL and SDA pins using Wire.begin(D4, D3);
  // For Wemos / Lolin D1 Mini Pro and the Ambient Light shield use Wire.begin(D2, D1);
  
  lightMeter.begin();
  // We setup lightMeter by default to 



 }

 uint16_t get_light_measurement(){
  
  
  uint16_t lux = lightMeter.readLightLevel();
  uint16_t lux_updated = lux;


if (lux > 4000 & lightLevel != "high") {
      // reduce measurement time - needed in direct sun light
      if (lightMeter.setMTreg(32)) {
        lightLevel = "high";
        lux_updated = lightMeter.readLightLevel();
      }
      else {
        // here we would print some error but we're not gonnna do it because we are
        // using serial port to comunicate with python script
        //Serial.println(F("Error setting MTReg to low value for high light environment"));
      }
    }
    else {
        if (lux > 65 & lightLevel != "normal") {
          // typical light environment
          if (lightMeter.setMTreg(69)) {
            lightLevel = "normal";
            lux_updated = lightMeter.readLightLevel();
          }
          else {
            // here we would print some error but we're not gonnna do it because we are
            // using serial port to comunicate with python script
            //Serial.println(F("Error setting MTReg to default value for normal light environment"));
          }
        }
        else {
          if (lux <= 65) {
            //very low light environment
            if (lightMeter.setMTreg(138)) {
              lightLevel = "low";
              lux_updated = lightMeter.readLightLevel();
            }
            else {
              // here we would print some error but we're not gonnna do it because we are
              // using serial port to comunicate with python script
              //Serial.println(F("Error setting MTReg to high value for low light environment"));
            }
          }
       }

    } 
    return lux_updated;
 }
