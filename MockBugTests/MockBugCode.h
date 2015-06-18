#ifndef MOCKBUGCODE_H
#define MOCKBUGCODE_H

typedef void (*fp_t)(void);
typedef void(*fp1_t)(int, int);
typedef void(*fp2_t)(int);
typedef struct config_st {
    fp1_t fp1;
    fp2_t fp2;
} config_t;

void Mbc_Init(void);
void Mbc_Process(void);
void Mbc_SetCurrentCallback(fp_t callback);
config_t* Mbc_GetConfig(void);
void Xyz_FirstMock(void);
void Xyz_SomeMock(void);

#endif // MOCKBUGCODE_H
