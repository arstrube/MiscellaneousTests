#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int child_run(void) {
    return *(volatile int*) 0; /* should terminate with signal 11 */
}

int main(int ac, char** av) {
    int status;
    pid_t cpid = fork();
    if(0 == cpid) {
        (void) child_run();
    } else {
        do {
            waitpid(cpid, &status, WUNTRACED);
            if(WIFSIGNALED(status)) {
                printf("\nChild exited with signal 11\n\n");
                return 0;
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        printf("\nChild exited normally\n\n");
    }
    return 0;
}
