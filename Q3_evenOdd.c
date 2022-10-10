#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements one by one : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int f = fork();
    if(f==0){
        printf("Child process , process id : %d\n", getpid());
        int so=0;
        for(int i=0; i<n; i++){
            if(arr[i]&1)
                so+=arr[i];
        }
        printf("Sum of odd numbers is : %d\n", so);
    }
    else{
        printf("Parent process , process id : %d\n", getpid());
        int se=0;
        for(int i=0; i<n; i++){
            if(!arr[i]&1)
                se+=arr[i];
        }
        printf("Sum of even numbers is : %d\n", se);
    }
    return 0;
}