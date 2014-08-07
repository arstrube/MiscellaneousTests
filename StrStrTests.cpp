#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

extern "C" {
}

char* StrStr(const char* s1, const char* s2)
{
    if(!*s2) return (char*) s1;
    for (; *s1; s1++)
//        if (SimpleString::StrNCmp(s1, s2, SimpleString::StrLen(s2)) == 0)
        if (SimpleString::StrCmp(s1, s2) == 0)
            return (char*) s1;
    return NULL;
}

TEST_GROUP(SimpleString) {};

TEST(SimpleString, StrStr)
{
    char foo[] = "foo";
    char empty[] = "";
    char foobarfoo[] = "foobarfoo";
    char barf[] = "barf";
    CHECK(StrStr(foo, empty) == foo);
    CHECK(StrStr(empty, foo) == 0);
    CHECK(StrStr(foobarfoo, barf) == foobarfoo+3);
    CHECK(StrStr(barf, foobarfoo) == 0);
    CHECK(StrStr(foo, foo) == foo);
}

TEST(SimpleString, StrCmp)
{
    char empty[] = "";
    char blabla[] = "blabla";
    char bla[] = "bla";
    char xxx[] = "xxx";
    CHECK(SimpleString::StrCmp(empty, empty) == 0);
    CHECK(SimpleString::StrCmp(bla, blabla) == -'b');
    CHECK(SimpleString::StrCmp(blabla, bla) == 'b');
    CHECK(SimpleString::StrCmp(bla, empty) == 'b');
    CHECK(SimpleString::StrCmp(empty, bla) == -'b');
    CHECK(SimpleString::StrCmp(bla, bla) == 0);
    (void) xxx;
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
