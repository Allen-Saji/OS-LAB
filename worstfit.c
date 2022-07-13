
#include<stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int i, j;
	int allocation[n];
	int new_block[m];

	
	for(i = 0; i < n; i++)
	{
		allocation[i] = -1;
	}

	for (i = 0; i < n; i++)	 
	{
		for (j = 0; j < m; j++)	
		{
			if (blockSize[j] >= processSize[i])
			{
				allocation[i] = j;
				new_block[j] = blockSize[j];
				blockSize[j] -= processSize[i];
				break; 
			}
		}
	}

	printf("\nProcess No.\tProcess Size\t\t\tBlock no.\t\t\tBlock Size\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		
		if (allocation[i] != -1){
			printf("%i\t\t\t", allocation[i] + 1);
			printf("%d\t\t\t",new_block[allocation[i]] );
		}else
			printf("Not Allocated");
		
		printf("\n");
	}
}

int main()
{
	int m; 
	printf("Enter the number of blocks: ");
	scanf("%d",&m);
	int n; 
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int blockSize[m];
	
	printf("Enter the block sizes: ");
	for(int i=0;i<m;i++){
		scanf("%d",&blockSize[i]);
	}
	
	int processSize[n];
	printf("Enter the process sizes: ");
	for(int i=0;i<n;i++){
		scanf("%d",&processSize[i]);
	}
	
	
	firstFit(blockSize, m, processSize, n);

	return 0 ;
}
