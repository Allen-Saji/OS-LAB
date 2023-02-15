// C++ program to demonstrate
// FCFS Disk Scheduling algorithm

#include <stdio.h>
#include<stdlib.h>

int size = 8;

void FCFS(int arr[], int head)
{
	int seek_count = 0;
	int distance, cur_track;

	for (int i = 0; i < size; i++) {
		cur_track = arr[i];

		distance = abs(cur_track - head);

		seek_count += distance;

		head = cur_track;
	}

	printf("Total number of seek operations = %d", seek_count);
		
	printf( "Seek Sequence is: \n");

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{

	
	int arr[] = { 176, 79, 34, 60, 92, 11, 41, 114 };
	int head = 50;

	FCFS(arr, head);

	return 0;
}
