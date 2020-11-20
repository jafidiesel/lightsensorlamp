#include "firewire_com.h";
#include <Arduino.h>

const String URL = "http://fiware-iot.ddns.net:7896/iot/d?";
const String APIKEY = "k=2tggokgpepnvsb2uv4s40d59oc";
const String SENSOR_NAME = "&i=LightSensor";
String resultUrl;

void post_data(unsigned int value){
  resultUrl = URL + APIKEY + SENSOR_NAME + "#l|" + value + "\\";
  Serial.println(resultUrl);
}
