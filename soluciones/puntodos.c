#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
extern int errno;

int main(int argc, char *argv[])
{

    int fd = open("puntodos.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }

    printf("Hello, this program modifies the puntodos.txt file\n");

    int rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        write(fd, "Add new line from child process.\n", strlen("Add new line from child process.\n"));
        close(fd);
        printf("Process (pid:%d) execute success\n", (int)getpid());
    }
    else
    {
        write(fd, "Add new line from parent process.\n", strlen("Add new line from parent process.\n"));
        close(fd);
        printf("Process %d (pid:%d) execute success\n",
               rc, (int)getpid());
    }
    return 0;
}