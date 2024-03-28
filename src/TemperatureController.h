#ifndef TemperatureController_h
#define TemperatureController_h

class TemperatureController {
public:
  TemperatureController();
  void begin();
  void setThreshold(int thres);
  void setTempHumd(float t, float h);
  void update(unsigned long ms);
  bool isThresholdExceed();

private:
  float temperature;
  float humidity;
  int threshold;

};

#endif