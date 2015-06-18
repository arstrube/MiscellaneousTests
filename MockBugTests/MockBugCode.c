#include "MockBugCode.h"

static fp_t currentCallback;
static config_t config;

void fp1_func(int a, int b) {
    (void) a;
    (void) b;
    if(0 != currentCallback) {
        currentCallback();
    }
}
void fp2_func(int a) {
    (void) a;
    if(0 != currentCallback) {
        currentCallback();
    }
}
void Mbc_Init(void) {
    currentCallback = 0;
    config.fp1 = &fp1_func;
    config.fp2 = &fp2_func;
    Xyz_FirstMock();
}
void Mbc_Process(void) {
    Xyz_SomeMock();
}
void Mbc_SetCurrentCallback(fp_t callback) {
    currentCallback = callback;
}
config_t* Mbc_GetConfig(void) {
    return &config;
}
