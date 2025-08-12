#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void display(int arr[], int len) {
	for(int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sortDesc(int arr[], int len) {
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len-i-1; j++) {
			if(arr[j] < arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	display(arr, len);
}

void sortAsc(int arr[], int len) {
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	display(arr, len);
}

void main() {
	int len;
	printf("Enter the number of elements:");
	scanf("%d", &len);
	int arr[len];
	for(int i = 0 ; i < len; i++) {
		printf("Enter %d number: ", i+1);
		scanf("%d", &arr[i]);
	}
	pid_t num = fork();
	if(num < 0) {
		printf("error in fork execution");
	}
	else if (num == 0)  {
		printf("Sorted in ascending order by child process\n");
		sortDesc(arr, len);
		printf("This is the child process id %d\n", getpid());
		printf("This is the child's parent process id %d\n", getppid());		
	}
	else {	
		printf("Sorted in descending order by parent process\n");
		sortAsc(arr, len);
		printf("This is the parent id %d\n", getpid());
		wait(NULL);
	}
	exit(0);
}

/*
gcc fork5.c && ./a.out
Enter the number of elements:6
Enter 1 number: 32
Enter 2 number: 67
Enter 3 number: 00
Enter 4 number: 13
Enter 5 number: 76
Enter 6 number: 88
Sorted in descending order by parent process
0 13 32 67 76 88 
This is the parent id 8950
Sorted in ascending order by child process
88 76 67 32 13 0 
This is the child process id 8951
This is the child's parent process id 8950
*/


