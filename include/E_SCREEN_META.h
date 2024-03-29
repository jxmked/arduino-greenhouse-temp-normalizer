#ifndef E_SCREEN_META_h
#define E_SCREEN_META_h

enum class E_SCREEN_META {
  /**
   * Screen Brightness is set to 
   * minimum and still visible a little.
  */
  OFF,

  /**
   * Screen Brightness is set to 
   * Maximum but not to bright
  */
  ON,

  /**
   * Screen Brightness automatically increase and decrease
   * in a period of time but also automatically set to 
   * ON mode if buttons changes states and/or the 
   * temperature is near (±1 degree celsius).
  */
  AUTO
};

#endif