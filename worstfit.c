
#include<stdio.h>


void worstFit(int blockSize[], int m, int processSize[],int n)
{
	int allocation[n];
	int new_block[m];
	
	for(int k=0;k<m;k++){
	     new_block[k] = blockSize[k];
	}
	

	for(int i = 0; i < n; i++)
	{
		allocation[i] = -1;
	}

	for (int i=0; i<n; i++)
	{
		
		int wstIdx = -1;
		for (int j=0; j<m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (wstIdx == -1)
					wstIdx = j;
				else if (blockSize[wstIdx] < blockSize[j])
					wstIdx = j;
			}
		}

	
		if (wstIdx != -1)
		{
			allocation[i] = wstIdx;
			blockSize[wstIdx] -= processSize[i];
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
	
	printf("\n");
	
	
	
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
	
	worstFit(blockSize, m, processSize, n);

	return 0 ;
}
