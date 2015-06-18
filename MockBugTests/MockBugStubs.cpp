#include "CppUTestExt/MockSupport.h"

extern "C" {

#include "MockBugCode.h"

config_t* config;

void Xyz_FirstMock(void) {
    config = Mbc_GetConfig();
    mock().actualCall("Xyz_FirstMock");
}

void Xyz_SomeMock(void) {
    mock().actualCall("Xyz_SomeMock");
}

} // extern "C"
