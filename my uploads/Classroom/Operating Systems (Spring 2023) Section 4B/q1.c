#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
        printf("Error: Failed to create a child process.\n");
    else if (pid == 0)
        printf("I am Child my ID is=%d and my Parent is=%d\n", getpid(), getppid());
    else
        printf("I am Parent my ID is=%d and my Child ID is=%d\n", getpid(), pid);

    return 0;
}
