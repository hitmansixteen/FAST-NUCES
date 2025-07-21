#include <iostream>
#include <unistd.h>
#include <wait.h>

using namespace std;

int main()
{
    pid_t pid;
    int status, number;

    cout << "Enter a number: ";
    cin >> number;

    pid = fork();

    if (pid == 0)
    {
        int fact = 1;
        for (int i = 1; i <= number; i++)
            fact *= i;
        cout << "Factorial of " << number << " is " << fact << endl;
        exit(0);
    }
    else if (pid > 0)
    {
        wait(&status);
        if (WIFEXITED(status))
            cout << "Child process exited with status: " << WEXITSTATUS(status) << endl;
        exit(0);
    }
    else
    {
        cout << "Error: Failed to create child.\n";
        exit(1);
    }

    return 0;
}