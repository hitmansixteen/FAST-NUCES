#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char *mesag = "This is a message ";
int main()
{
    char buf[1024];
    int fd[2];
    pipe(fd);
    if (fork() != 0)
    { /* I am parent */
        close(fd[0]);
        write(fd[1], mesag, strlen(mesag) + 1);
        close(fd[1]);
    }
    else
    { /* child */
        close(fd[1]);
        read(fd[0], buf, 1024);
        printf("Got this from MaMa !!!\n%s\n", buf);
        close(fd[0]);
    }
    return 0;
}