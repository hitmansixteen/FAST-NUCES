#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int laps, totalseconds;
void print(){
    printf("total time: %d\n", laps * totalseconds);
    exit(0);
}
void my_signal_function(int sig){
    if (sig == SIGCHLD){
        printf("recieved SIGCHLD\n");
        print();
    }
}
void main(int argc, char* argv[]){
    printf("enter the total number of laps: ");
    scanf("%d", &laps);
    printf("enter lap seconds: ");
    scanf("%d", &totalseconds);
    int pid = fork();
    if (pid > 0){
        if (signal(SIGCHLD, my_signal_function) != SIG_ERR){

        }
        else{
            printf("could not capture signal\n");
        }
        while(1){
            sleep(1);
        }
    }
    else{
        for (int i = 0; i < laps; i++){
            sleep(totalseconds);
            printf("lap: %d completed\n", i + 1);
        }
    }
}