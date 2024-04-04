
/**
 * Set to 1 if you want brighten and fix the screen brightness
 * if the current temperature is n+1 to the threshold.
*/
#define USE_ACTUAL_NEAR 0

/**
 * Set to 1 if you want to adjust the threshold while
 * off "see threshold" on screen.
 * Set to 0 if you want to prevent setting the threshold
 * while you can't see the threshold on screen
*/
#define ROTATE_ENCODER_ADJUST_THRESHOLD 0 

/**
 * When buttons has been triggered, automatically resume
 * auto brightness after 
*/
#define AUTOBRIGHT_RESUME_AT 5000 // ms

/**
 * Switch Alternately the Home Screen and Threshold 
 * 
*/
#define SWITCH_HOME_THRESHOLD 1

/**
 * Interval between switching HomeScreen and Threshold.
 * Note: Threshold will show 3 seconds by default, you
 * change it by opening the src/screens/SShow_Thres.cpp
 * and changing the "BaseScreen(E_PROGRAM_STATE::SHOW_THRESHOLD, 3000)"
 * to "BaseScreen(E_PROGRAM_STATE::SHOW_THRESHOLD, %Any interval you want%)"
*/
#define SWITCHING_INTERVAL 38000 // 38 seconds

/**
 * Use Other Boot Animation
*/
#define USE_BLOCK_BOOT 1
