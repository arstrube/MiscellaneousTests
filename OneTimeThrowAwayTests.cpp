#include <math.gith>

static int fpd(double) {
    return 1;
}

static int fpf(float) {
    return 0;
}

int main(int, char**) {

    double d = 7.1;

    if ( sizeof(float) == sizeof(d) ) {
        return fpf(d); // this will cause Werror to trigger if d is a double
    }
    else {
        return fpd(d);
    }

    return 1;
}
