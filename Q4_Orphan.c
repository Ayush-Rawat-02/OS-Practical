#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    int a,b,c;
    int f = fork();
    if(f==0){
        printf("Child process , process id : %d\n", getpid());
        printf("Enter two numbers( a & b ) : ");
        scanf("%d%d",&a,&b);
        if(a>b){
            printf("Number a = %d is greater than the number b = %d\n",a,b);
        }
        else if(b<a){
            printf("Number b = %d is greater than the number a = %d\n",b,a);
        }
        else{
            printf("Number a = %d and number b = %d are equal\n",a,b);
        }
    }
    else{
        printf("Parent process , process id : %d\n", getpid());
        printf("Enter a number (c) : ");
        scanf("%d",&c);
        if(c&1){
            printf("Number c = %d is odd\n",c);
        }
        else{
            printf("Number c = %d is even\n",c);
        }
    }
    return 0;
}