#include <math.h>

int main(int, char**) {
    int result;
    double d = 1.1;
    float f = 1.1f;
    
#define myclassify(__x) \
	((sizeof(__x) == sizeof(float))  ? \
    __fpclassifyf((double)__x) : \
	__fpclassifyd(__x))

    #undef isnan
#define isnan(y) (myclassify(y) == 1)

    result = isnan(d);
    result = isnan(f);
    return result;
}
