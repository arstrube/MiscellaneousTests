#include <stdio.h>

void Foo_Func2(void)
{
	printf("Foo_Func2() called\n");
}

void Foo_Func3(void)
{
    printf("Foo_Func3() called\n");
}

void Foo_Func1(int i)
{
	printf("Foo_Func1() called\n");
    if(0 != i)
    {
    	Foo_Func2();
    	Foo_Func3();
    }
}

int main(void)
{
	printf("main() called\n");
	Foo_Func1(1);
	return 0;
}
