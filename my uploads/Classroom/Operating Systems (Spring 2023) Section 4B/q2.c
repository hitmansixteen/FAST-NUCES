#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    int lapTime, numOfLaps;
    printf("Enter lap time in seconds: ");
    scanf("%d", &lapTime);
    printf("Enter number of laps: ");
    scanf("%d", &numOfLaps);

    pid_t totalTimePid = fork();

    if (totalTimePid < 0)
        printf("Could not create process.\n");
    else if (totalTimePid == 0)
    {
        int totalTime = 0;
        while (totalTime < (lapTime * numOfLaps))
        {
            sleep(1);
            totalTime++;
        }
        exit(totalTime);
    }

    pid_t lapTimePid = fork();

    if (lapTimePid < 0)
        printf("Could not create process.\n");
    else if (lapTimePid == 0)
    {
        int lapNumber = 1;
        while (lapNumber <= numOfLaps)
        {
            sleep(lapTime);
            printf("Lap %d: %d seconds\n", lapNumber, lapTime);
            lapNumber++;
        }
        exit(0);
    }

    int timeStatus, lap;
    waitpid(totalTimePid, &timeStatus, 0);
    waitpid(lapTimePid, &lap, 0);

    int time = WEXITSTATUS(timeStatus);
    printf("Total time: %d seconds\n", time);

    return 0;
}
