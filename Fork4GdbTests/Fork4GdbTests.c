#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int child_run(void) {
    return *(volatile int*) 0; /* should terminate with signal 11 */
}

void parent_run(void) {
    pid_t cpid;
    int status;
    cpid = fork();
    if(0 == cpid) {
        (void) child_run();
    } else {
        do {
            waitpid(cpid, &status, WUNTRACED);
            if(WIFSIGNALED(status)) {
                printf("\nChild exited with signal 11\n\n");
                return;
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        printf("\nChild exited normally\n\n");
    }
}

int main(int ac, char** av) {
	parent_run();
    return 0;
}
