#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/shm.h>

int main()
{
    int idFile, id1, id2;
    sem_t *m1, *m2;
    idFile = shmget(10111, 20, 0);
    id1 = shmget(10112, 1000, 0);
    id2 = shmget(10113, 1000, 0);
    char *file = (char *)shmat(idFile, NULL, 0);
    m1 = (sem_t *)shmat(id1, NULL, 0);
    m2 = (sem_t *)shmat(id2, NULL, 0);
    int size = 20;
    char str[size];
    sem_wait(m1);
    while (1)
    {
        strncpy(str, file, size);
        if (str[0] == '$')
            break;
        else
        {
            printf("%s\n", str);
            sem_post(m2);
            sem_wait(m1);
        }
    }

    shmdt(m1);
    shmdt(m2);
    shmdt(file);
    shmctl(id1, IPC_RMID, NULL);
    shmctl(idFile, IPC_RMID, NULL);
    shmctl(id2, IPC_RMID, NULL);
}