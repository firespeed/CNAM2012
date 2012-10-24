#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int i, n;
    
    if (argc > 1)
        n = atoi(argv[1]);
    else
        n = 1;

    printf("n = %d\n", n);
    for (i = 0 ; i < n ; i++) {
        int pid, ppid;
        fork();
        pid = getpid();
        ppid = getppid();
        printf("PID = %d, PPID = %d, i = %d\n", pid, ppid, i);
    }

    /* for (i = 0 ; i < n ; i++) */
    /*     wait(NULL); */

    return 0;
}
