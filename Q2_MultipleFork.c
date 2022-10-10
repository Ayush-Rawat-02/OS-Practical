#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    printf("HEllo , process id : %d\n", getpid());
    fork();
    printf("I am a robot , process id ; %d\n", getpid());
    fork();
    printf("Final line , process id : %d\n", getpid());
    return 0;
}