#include <Arduino.h>

#include <Wire.h>
#include <dht11.h>

dht11 dht;

#define dht_pin A0

void setup() {
  Serial.begin(9600);

  while(!Serial);


}

void loop() {
  dht.read(dht_pin);
  
  int hum = dht.humidity;
  float tempi = (float) dht.temperature;

  Serial.print(hum);
  Serial.print(" : ");
  Serial.print(tempi);



  delay(2000);
}

