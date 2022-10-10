#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    int f = fork();
    if(f==0){
        printf("Child process, process id : %d\n", getpid());
    }
    else{
        wait(NULL);
        printf("Parent process , process id : %d after child process is terminated\n", getpid());
    }
    return 0;
}