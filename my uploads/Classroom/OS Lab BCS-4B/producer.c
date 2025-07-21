#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
    int idFile, id1, id2;
    sem_t *m1, *m2;
    idFile = shmget(10111, 20, 0666 | IPC_CREAT | IPC_EXCL);
    id1 = shmget(10112, 1000, 0666 | IPC_CREAT | IPC_EXCL);
    id2 = shmget(10113, 1000, 0666 | IPC_CREAT | IPC_EXCL);
    char *file = (char *)shmat(idFile, NULL, 0);
    m1 = (sem_t *)shmat(id1, NULL, 0);
    m2 = (sem_t *)shmat(id2, NULL, 0);
    sem_init(m1, 1, 0);
    sem_init(m2, 1, 0);
    int size = 20;
    char str[size];
    int fd = open(argv[1], O_RDONLY);

    while (1)
    {
        if (read(fd, str, size) == 0)
        {
            char a = '$';
            strncpy(file, &a, 1);
            sem_post(m1);
            break;
        }
        else
        {
            strncpy(file, str, size);
            sem_post(m1);
            sem_wait(m2);
        }
    }
}