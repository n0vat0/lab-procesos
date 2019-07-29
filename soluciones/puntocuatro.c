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
        printf("Hello next you shower all directories!\n\n");

        int exec = fork();

        if (exec == 0)
        {

            int execv = fork();

            if (execv == 0)
            {

                int execlp == fork();

                if (execlp == 0)
                {
                    execlp("/bin/ls", "/bin/ls", "-F", "-l", NULL);
                }
            }
        }
    }

    wait(2);
    printf("Goodbye!\n");

    return 0;
}