
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("\n\n");
    int rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        sleep(3);
        wait(NULL);
        printf("Hello!\n");
    }
    else
    {
        // parent goes down this path (original process)
        wait(NULL);
        printf("Goodbye!\n");
    }
    return 0;
}