#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/shm.h>

int main(){
    int idfile,idmut1,idmut2;
    sem_t* mutex1,*mutex2;
    idfile = shmget(10111, 20, 0);
    idmut1 = shmget(10122, 1000, 0);
    idmut2 = shmget(10133, 1000, 0);
    char* file = (char*) shmat(idfile, NULL, 0);
    mutex1 = (sem_t*)shmat(idmut1,NULL, 0);
    mutex2 = (sem_t*)shmat(idmut2,NULL, 0);
	int size = 20;
    char str[size];
    sem_wait(mutex1);
    while(1){
        strncpy(str, file, size);
        if (str[0] == '$')
            break;
        else{
            printf("%s\n",str);
            sem_post(mutex2);
            sem_wait(mutex1);
        }
    }
     
    shmdt(mutex1);
    shmdt(mutex2);
    shmdt(file);
    shmctl(idmut1, IPC_RMID, NULL);
    shmctl(idfile, IPC_RMID, NULL);
    shmctl(idmut2, IPC_RMID, NULL);
}