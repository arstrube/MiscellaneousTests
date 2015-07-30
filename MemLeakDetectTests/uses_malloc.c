#include "uses_malloc.h"
#include <stdlib.h>

int * data;

void allocate(void) {
    data = malloc(10);
}

void deallocate(void) {
    free(data);
}
