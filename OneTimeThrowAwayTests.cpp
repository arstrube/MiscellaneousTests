#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

// In a header file:
typedef struct
{
    uint8_t *data;
    uint16_t data_length;
} network_dto;

typedef void (*net_rx_callback)(network_dto dto);

void network_setup(net_rx_callback cb);

// In my mock file:
void network_setup(net_rx_callback cb)
{
    mock("network").setData("cb", (void*)cb);
    mock("network").actualCall("network_setup");
}

// In my test:
net_rx_callback callback_pointer;

void test_callback(network_dto)
{
     // whatever
}

TEST_GROUP(network) {};

TEST(network, callback_test)
{
    mock("network")
         .expectOneCall("network_setup")
         .ignoreOtherParameters();

    network_setup(test_callback);

    callback_pointer = (net_rx_callback)(mock("network").getData("cbx").getPointerValue());

    mock().clear();
}

int main(int argc, char** argv) {
    return RUN_ALL_TESTS(argc, argv);
}
