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
        printf("Hello!\n");
        close(STDOUT_FILENO);
        printf("se cerró el proceso estandar\n");
    }
    else
    {
        // parent goes down this path (original process)
        printf("Goodbye!\n");
    }
    return 0;
}