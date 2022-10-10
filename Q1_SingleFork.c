#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    printf("Before fork , Parent id : %d\n", getpid());
    int f=fork();
    if(f==0){
        printf("After fork , Child id : %d\n", getpid());
    }
    return 0;
}