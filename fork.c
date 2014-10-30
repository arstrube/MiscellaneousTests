#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int
main(int argc, char *argv[])
{
    pid_t cpid, w;
    int status;

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {            /* Code executed by child */
        printf("Child PID is %ld\n", (long) getpid());
        if (argc == 1)
            pause();                  /* Wait for signals */
        int arg = atoi(argv[1]);
        switch(arg) {            /* Raise specific signal */
            case -1: { raise(SIGABRT); break; }
            case -2: { raise(SIGFPE);  break; }
            case -3: { raise(SIGILL);  break; } 
            case -4: { raise(SIGINT);  break; }
            case -5: { raise(SIGSEGV); break; }
            case -6: { raise(SIGTERM); break; }
            case -7: { *(int*)0=0;     break; }
            case -8: { int a=0;a=a/a; break; }
        }
        _exit(arg);

    } else {                   /* Code executed by parent */
        do {
            w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
            if (w == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

            if (WIFEXITED(status)) {
                printf("exited, status=%d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                #ifdef WCOREDUMP
                if (WCOREDUMP(status))
                    printf("coredump, killed by signal %d\n", WTERMSIG(status));
                else
                #endif
                    printf("killed by signal %d\n", WTERMSIG(status));
            } else if (WIFSTOPPED(status)) {
                printf("stopped by signal %d\n", WSTOPSIG(status));
            } else if (WIFCONTINUED(status)) {
                printf("continued\n");
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        
        exit(EXIT_SUCCESS);
    }
}

