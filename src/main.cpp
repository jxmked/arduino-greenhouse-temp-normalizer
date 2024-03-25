#include <Arduino.h>
#include "Program.h"
#include "Button.h"

#define P_SENSOR A0
#define P_INC_BTN 2
#define P_ETR_BTN 3
#define P_DEC_BTN 4

Button plus(P_INC_BTN);
Button minus(P_DEC_BTN);
Button enter(P_ETR_BTN);

Program app;

void setup()
{
  
  app.begin();

  plus.begin();
  plus.set_repeat(500, 200);

  minus.begin();
  minus.set_repeat(500, 200);

  enter.begin();
  enter.set_repeat(5000, 10000);


}

void loop()
{ 
  app.update();
  app.display();

}