#ifndef E_PROGRAM_STATE_H
#define E_PROGRAM_STATE_H

enum E_PROGRAM_STATE
{
  BOOT,
  INITIAL,
  HOME,
  SHOW_THRESHOLD,
  SET_THRESHOLD,
  PRESET // We will set the program state variable 
  // to PRESET as initial value since BOOT value
  // a staten value and not an actual initial value
};

#endif
