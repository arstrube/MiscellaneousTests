#include "Control_class.h"

void main (void) {
    while (1) {
        Task1_run();
        Task2_run();
        Sys_sleep(5);
    }
}