#ifndef DHTSensor_h
#define DHTSensor_h


#include "dht11.h"




class DHTSensor {
  public:
    DHTSensor(uint8_t pin);
    void update();
    float temperature();
    float humidity();

  private:
    uint8_t pin;
    float current_temp;
    float current_hum;
    

};




#endif
