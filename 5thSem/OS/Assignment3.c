#include <stdio.h>

void display(int* arr, int* bur, int* gantt, int* tat, int* wt,int num) {
    printf("\nP \tAT\tBT\tCT\tTAT\tWT\n");
    for(int j = 0; j < num; j++) {
            printf("P%d\t", j+1);
            printf("%d\t", arr[j]);
            printf("%d\t", bur[j]);
            printf("%d\t", gantt[j]);
            printf("%d\t", tat[j]);
            printf("%d\t\n", wt[j]);
    }
}

void displayGantt(int* arr, int num) {
    printf("\nGantt Chart:-\n");
    printf("0");
    for(int i = 0; i < num; i++) {
        printf("---P%d---", i+1);
        printf("%d", arr[i]);
    }
    printf("\n\n");
}

int idealTime(int* arr, int* gantt, int num) {
    int time = 0;
    if(arr[0] != 0) {
        time += arr[0];
    }
    for(int i = 1; i < num; i++) {
        if(gantt[i-1] < arr[i]) {
            time += (arr[i] - gantt[i-1]);
        }
    }
    return time;
}
int main() {
    int num;
    printf("Enter the number of processes: ");
    scanf("%d", &num);

    float div = num;
    int arr[num];
    int bur[num];
    printf("Enter the arrival time of the processes:-\n");
    for(int i = 0; i < num; i++) {
        printf("Process %d : ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the burst time of the processes:-\n");
    for(int i = 0; i < num; i++) {
        printf("Process %d : ", i+1);
        scanf("%d", &bur[i]);
    }

    int gantt[num];
    int tat[num];
    int wt[num];

    gantt[0] = bur[0];
    for(int i = 1; i < num; i++) {
        gantt[i] = gantt[i-1] + bur[i];
    }

    int sumTat = 0;
    for(int i = 0; i < num; i++) {
        tat[i] = gantt[i] - arr[i];
        sumTat += tat[i];
    }
    float avgTat = sumTat/div;

    int sumWt = 0;
    for(int i  =0; i <num; i++) {
        wt[i] = tat[i] - bur[i];
        sumWt += wt[i];
    }

    float avgWt = sumWt/div;

    display(arr, bur, gantt, tat, wt, num);
    displayGantt(gantt, num);
    printf("Average Turnaround time is %f sec \n", avgTat);
    printf("Average Waiting time is %f sec\n", avgWt);

    int time = idealTime(arr, gantt, num);
    printf("\nThe ideal time of cpu is %d sec.\n", time);
    return 0;
}
