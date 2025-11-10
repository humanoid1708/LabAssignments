#include <stdio.h>

void display_arr(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



void display_mat(int row, int col, int arr[row][col]) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void safety(int *avail, int rnum, int pnum, int need[pnum][rnum], int alloc[pnum][rnum]) {
    int work[rnum];
    for(int j = 0; j < rnum; j++) {
        work[j] = avail[j];
    }

    int finish[pnum];
    for(int i = 0; i < pnum; i++) {
        finish[i] = 0;
    }

    int safe[pnum];
    int count = 0;

    for (int k = 0; k < pnum; k++) {
        for (int i = 0; i < pnum; i++) {
            if (finish[i] == 0) {
                int proceed = 1;
                for (int j = 0; j < rnum; j++) {
                    if (need[i][j] > work[j]) {
                        proceed = 0;
                        break;
                    }
                }
                if (proceed == 1) {
                    for (int j = 0; j < rnum; j++) {
                        work[j] += alloc[i][j];
                    }
                    safe[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    if (count == pnum) {
        printf("System is in a safe state.\n");
        printf("Safe Sequence: ");
        display_arr(safe, pnum);
    } else {
        printf("System is in an unsafe state. Deadlock may occur.\n");
    }

}

int main() {
    int pnum, rnum;
    printf("Enter the number of processes: ");
    scanf("%d", &pnum);
    printf("Enter the number of resources: ");
    scanf("%d", &rnum);

    int resource[rnum];
    for(int i = 0; i < rnum; i++) {
        int ins;
        printf("Enter the instances of the %d resource: ", i+1);
        scanf("%d", &ins);
        resource[i] = ins;
    }
    
    int alloc[pnum][rnum];
    printf("Enter information for the allocation matrix\n");
    for(int i = 0; i < pnum; i++) {
        for(int j = 0; j < rnum; j++) {
            int inst;
            printf("Enter instances of resource %d for the process %d : ", j+1, i+1);
            scanf("%d", &inst);
            alloc[i][j] = inst;
        }
    }
    display_mat(pnum, rnum, alloc);

    int max[pnum][rnum];
    printf("Enter information for the max matrix\n");
    for(int i = 0; i < pnum; i++) {
        for(int j = 0; j < rnum; j++) {
            int inst;
            printf("Enter instances of resource %d for the process %d : ", j+1, i+1);
            scanf("%d", &inst);
            max[i][j] = inst;
        }
    }
    display_mat(pnum, rnum, max);

    int avail[rnum];
    for(int j = 0; j < rnum; j++) {
        int sum = 0;
        for(int i = 0; i < pnum; i++) {
            sum += alloc[i][j];
        }
        avail[j] = resource[j] - sum;
    }
    display_arr(avail, rnum);

    int need[pnum][rnum];
    for(int i = 0; i < pnum; i++) {
        for(int j = 0; j < rnum ; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    display_mat(pnum, rnum, need);

    safety(avail, rnum, pnum, need, alloc);

    int c = 0;
    while(c == 0) {
        int option;
        printf("Do you want to request for resources? (1/0) :");
        scanf("%d", &option);
        if(option == 1) {
            int pro_num;
            printf("Enter the process number: ");
            scanf("%d", &pro_num);
            for(int j = 0; j < rnum; j++) {
                int add;
                printf("Enter the instances for resource %d : ", j+1);
                scanf("%d", &add);
                alloc[pro_num][j] += add;
            }
            for(int j = 0; j < rnum; j++) {
                int sum = 0;
                for(int i = 0; i < pnum; i++) {
                    sum += alloc[i][j];
                }
                avail[j] = resource[j] - sum;
            }
            for(int i = 0; i < pnum; i++) {
                for(int j = 0; j < rnum ; j++) {
                    need[i][j] = max[i][j] - alloc[i][j];
                }
            }
            safety(avail, rnum, pnum, need, alloc);
        }
        else c = 1;
    }

    return 0;
}