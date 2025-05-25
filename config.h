#pragma once

//#define USE_MATRIX_I2C

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

#ifdef RGBLIGHT_ENABLE
    #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
    #define RGB_MATRIX_SLEEP // turn off effects when suspended
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
    #define RGB_MATRIX_HUE_STEP 115
    #define RGB_MATRIX_SAT_STEP 100
    #define RGB_MATRIX_VAL_STEP 70
    #define RGB_MATRIX_SPD_STEP 10

    #define ENABLE_RGB_MATRIX_BREATHING
    #define RGB_MATRIX_DEFAULT_ON false
#endif
#define TAPPING_TERM 200
#define NO_ACTION_ONESHOT
#ifndef NO_DEBUG
#define NO_DEBUG
#endif
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif