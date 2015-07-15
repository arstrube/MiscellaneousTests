/*
 * Copyright (c) 2015, Michael Feathers, James Grenning, Bas Vodde
 * and Arnd Strube. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE EARLIER MENTIONED AUTHORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTest/IEEE754ExceptionFlagsPlugin.h"
#include <cfenv>
#include <limits>

extern "C" { 
    #include "FETests_c.h"
}

TEST_GROUP(FE_Demo) {
    void setup(void) override {
        std::feclearexcept(FE_ALL_EXCEPT);
    }
};
TEST(FE_Demo, should_fail_when__FE_DIVBYZERO__is_set) {
    DOUBLES_EQUAL(std::numeric_limits<double>::infinity(), 1.0d / 0.0d, 0.0d);
}
TEST(FE_Demo, should_fail_when__FE_UNDERFLOW__is_set) {
    set_underflow_c();
}
TEST(FE_Demo, should_succeed_FE_INEXACT_set) {
    DOUBLES_EQUAL(5.2f, 15.6f / 3.0f, 0.000001f);
}
TEST(FE_Demo, should_succeed_when_no_flags_are_set) {
    DOUBLES_EQUAL(5.0f, 15.0f / 3.0f, 0.0f);
}

int main(int ac, char** av) {
    IEEE754ExceptionFlagsPlugin ieee754Plugin{"IEEE754"};
    TestRegistry::getCurrentRegistry()->installPlugin(&ieee754Plugin);
	return RUN_ALL_TESTS(ac, av);
}
