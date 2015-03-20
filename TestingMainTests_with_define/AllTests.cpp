#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MemoryReporterPlugin.h"
#include "CppUTestExt/MockSupportPlugin.h"

int main(int ac, char** av){
    MemoryReporterPlugin plugin;
    MockSupportPlugin mockPlugin;
    TestRegistry::getCurrentRegistry()->installPlugin(&plugin);
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
	return RUN_ALL_TESTS(ac, av);
}
