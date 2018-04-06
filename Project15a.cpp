#include<stdio.h>
#include<Math.h>
int main() 
{ 
	int i,j,AT[10],BT[10],n;
	float Sum_WT=0,Sum_TAT=0,complete_time;
	printf("Processes:\n");
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
		printf("Arrival Time P[%d] : ",i+1);
		scanf("%d",&AT[i]);
		printf("Burst Time P[%d] : ",i+1);
		scanf("%d",&BT[i]); 
	}
	int store_burst[10];
	for(i=0;i<n;i++)
	{
		store_burst[i]=BT[i];
	}
	BT[9]=INFINITY;
	int count=0;
	int t,TAT[10],WT[10];
		int min;
	for(t=0;count!=n;t++)
	{

		min=9;
		for(i=0;i<n;i++)
		{
			if(BT[i]<BT[min] && BT[i]>0 &&AT[i]<=t)
			{
				min=i;
			}
		}
		BT[min]--;
		if(BT[min]==0)
		{
			count++;
			complete_time=t+1;
			Sum_TAT+=complete_time-AT[min];
			Sum_WT=Sum_WT+complete_time-AT[min]-store_burst[min];
		}
		
	}
	printf("\nProcesses\tArrival Time\tBurst Time\n");
	for(i=0;i<n;i++)
	{
		printf("P[%d]\t\t%d\t\t%d\n",i+1,AT[i],store_burst[i]);
		//printf("P[%d]\n",i+1,"\t\t",AT[i],"\t\t",store_burst[i],"\n");
	}
	printf("Average Turnaround Time = %f",Sum_TAT/n);
	printf("\n\nAverage Waiting Time = %f\n",Sum_WT/n);
	return 0;
}
