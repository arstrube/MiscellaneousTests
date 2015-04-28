#include "LedState.h"

typedef enum {
    LedAllOff = 0U,
    Led1On = 1U,
    Led2On = 2U,
    Led3On = 3U,
    Led4On = 4U,
    Led5On = 5U,
    LedAllOn = 6U
} LedState_enum;

LedState_enum ledState = LedAllOff;

typedef unsigned char uint8;

static void LedState_incr(void) {
    if(ledState < LedAllOn) (*(uint8*)&ledState)++;
}

static void LedState_setLedState(LedState_enum state) {
    ledState = state; 
}

/** This is just for demonstration; probably doesn't make sense */

void LedState_setFiveLedsOn(void) {
    for (ledState = LedAllOff; ledState < Led5On; LedState_incr()) {
       LedState_setLedState(ledState);
    }    
}
void LedState_setSixLedsOn(void) {
    for (ledState = LedAllOff; ledState < LedAllOn; LedState_incr()) {
       LedState_setLedState(ledState);
    }    
}
