#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    int f = fork();
    if(f==0){
        printf("Child process , process id : %d\n", getpid());
    }
    else{
        sleep(200);
        printf("Parent process , process id : %d\n", getpid());
    }
    return 0;
}