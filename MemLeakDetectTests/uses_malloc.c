#include "uses_malloc.h"
#include <stdlib.h>

static long * data;

void allocate(void) {
    data = malloc(10*sizeof(long));
    int i;
    for (i=0; i<10; i++) data[i] = 0x474e4f4c;
}

void deallocate(void) {
    free(data);
}
