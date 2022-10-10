#include<stdio.h>

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int p_no[], int at[], int bt[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-1-i; j++){
            if(at[j]>at[j+1]){
                swap(&p_no[j], &p_no[j+1]);
                swap(&at[j], &at[j+1]);
                swap(&bt[j], &bt[j+1]);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of proceses : ");
    scanf("%d",&n);
    int p_no[n], at[n], bt[n], st[n], ct[n], tat[n], wt[n];
    for(int i=0; i<n; i++){
        p_no[i]=i;
        printf("Enter the arrival and burst time for process %d : ", i);
        scanf("%d%d",&at[i], &bt[i]);
    }

    sort(p_no, at, bt, n);

    int cur_t=0;
    float avg_tat=0,avg_wt=0;
    for(int i=0;i<n;i++){
        if(at[i]>cur_t){
            cur_t = at[i];
        }
        st[i] = cur_t;
        ct[i] = cur_t + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = cur_t - at[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
        cur_t+=bt[i];
    }
    avg_tat = avg_tat/(float)n;
    avg_wt = avg_wt/(float)n;
    printf("Processes are completed in the order : \n");
    printf("Process no .\tArrival time\tBurst time\tStart time\tCompletion time\tTurnaround time\tWaiting time\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p_no[i], at[i], bt[i], st[i], ct[i], tat[i], wt[i]);
    }
    printf("Average Turnaround time : %f\nAverage waiting time : %f\n",avg_tat, avg_wt);
    return 0;
}