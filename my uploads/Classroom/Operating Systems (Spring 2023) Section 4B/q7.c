#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    int number, factorial, square;
    int pipe1[2], pipe2[2];
    pid_t pid1, pid2;

    if (pipe(pipe1) < 0 || pipe(pipe2) < 0)
    {
        perror("pipe\n");
        exit(1);
    }

    if ((pid1 = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid1 == 0)
    {
        read(pipe1[0], &number, sizeof(number));

        factorial = 1;
        for (int i = 1; i <= number; i++)
            factorial *= i;

        close(pipe1[0]);
        write(pipe1[1], &factorial, sizeof(factorial));
        close(pipe1[1]);

        exit(0);
    }

    if ((pid2 = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid2 == 0)
    {
        read(pipe2[0], &number, sizeof(number));
        square = number * number;

        close(pipe2[0]);
        write(pipe2[1], &square, sizeof(square));
        close(pipe2[1]);

        exit(0);
    }

    printf("Enter a number: ");
    scanf("%d", &number);

    write(pipe1[1], &number, sizeof(number));
    close(pipe1[1]);
    write(pipe2[1], &number, sizeof(number));
    close(pipe2[1]);

    wait(NULL);
    wait(NULL);

    read(pipe1[0], &factorial, sizeof(factorial));
    close(pipe1[0]);
    read(pipe2[0], &square, sizeof(square));
    close(pipe2[0]);

    printf("Factorial: %d\n", factorial);
    printf("Square: %d\n", square);

    return 0;
}