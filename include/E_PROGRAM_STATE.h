#ifndef E_PROGRAM_STATE_H
#define E_PROGRAM_STATE_H

enum E_PROGRAM_STATE
{
  /**
   * Were loading text would appear for a few seconds
  */
  BOOT,

  /**
   * Were greeting text would appear for a few seconds
  */
  INITIAL,

  /**
   * Were Temperature and humidity would appear and will stay on screen
  */
  HOME,

  /**
   * Show set threshold
  */
  SHOW_THRESHOLD,

  /**
   * Set/Modify threshold
  */
  SET_THRESHOLD,

  
  RUN_TEST,
  
  PRESET // We will set the program state variable 
  // to PRESET as initial value since BOOT value
  // a staten value and not an actual initial value
};

#endif
