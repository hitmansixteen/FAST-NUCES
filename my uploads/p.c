#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/shm.h>

int main(int argc, char* argv[]){
    int idfile,idmut1,idmut2;
    sem_t* mutex1,*mutex2;
    idfile = shmget(10111, 20, 0666 | IPC_CREAT | IPC_EXCL);
    idmut1 = shmget(10122, 1000, 0666 | IPC_CREAT | IPC_EXCL);
    idmut2 = shmget(10133, 1000, 0666 | IPC_CREAT | IPC_EXCL);
    char* file = (char*) shmat(idfile, NULL, 0);
    mutex1 = (sem_t*)shmat(idmut1,NULL, 0);
    mutex2 = (sem_t*)shmat(idmut2,NULL, 0);
    sem_init(mutex1,1,0);
    sem_init(mutex2,1,0);
	int size = 20;
    char str[size];
    int fd = open(argv[1], O_RDONLY);

    while(1){
        if(read(fd, str, size) == 0){
            char a = '$';
            strncpy(file,&a,1);
            sem_post(mutex1);
            break;
        }
        else{
           strncpy(file,str,size);
            sem_post(mutex1);
            sem_wait(mutex2);
        }
    }
}