#include<stdio.h>
int main()
{
	int p[5] = {1,2,3,4,5};
	int n = sizeof p / sizeof p[0];
	
	int bt[5] = {4,8,5,4,7};
	float avg_wt,avg_tat;
	int wt[4],tat[4],i,j,total=0,pos,temp;
	 for(i=0;i<n;i++)
	    {
		pos=i;
		for(j=i+1;j<n;j++)
		{
		    if(bt[j]<bt[pos])
		        pos=j;
		}
	  
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
	  
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	    }
	   
	    wt[0]=0;            
	  
	   
	    for(i=1;i<n;i++)
	    {
		wt[i]=0;
		for(j=0;j<i;j++)
		    wt[i]+=bt[j];
	  
		total+=wt[i];
	    }
	    int total_wt = total;
	    avg_wt=(float)total/n;      
	    total=0;
	  
	    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
	    for(i=0;i<n;i++)
	    {
		tat[i]=bt[i]+wt[i];   
		total+=tat[i];
		printf("\np%d\t    %d\t        \t%d\t  \t%d",p[i],bt[i],wt[i],tat[i]);
	    }
	    
	    int total_tat = total;
	    avg_tat=(float)total/n;  
	    printf("\nTotal waiting time = %d\n", total_wt);
	    printf("Total Turn around time = %d\n", total_tat);  
	    printf("\nAverage Waiting Time = %f",avg_wt);
	    printf("\nAverage Turnaround Time = %f\n",avg_tat);
	}
