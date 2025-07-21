#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int pid;

    switch (pid = fork())
    {

    case 0:
        printf("In child process. ID = %d\n", getpid());
        break;

    case -1:
        perror("fork");
        break;

    default:
        printf("In parent process. ID = %d and child ID = %d\n", getpid(), pid);
        break;
    }
    exit(0);

    return 0;
}