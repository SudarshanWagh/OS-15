#include<stdio.h>
#include<conio.h>
int main()
{
    int BT[20],AT[10],n,temp,x[10],y[10],WT[10],TAT[10],P[10],sum_WT=0,sum_TAT=0;
    float avg_TAT,avg_WT;
    printf("Total Processes: ");
    scanf("%d",&n); 
    for(int i=0;i<n;i++)
    {
        printf("\nArrival Time P[%d] : ",i+1);
        scanf("%d", &AT[i]);
        printf("Burst Time P[%d] : ",i+1);
        scanf("%d", &BT[i]); 
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(BT[i]<BT[j])
            {
                temp=AT[i];
                AT[i]=AT[j];
                AT[j]=temp;
                temp=BT[i];
                BT[i]=BT[j];
                BT[j]=temp;
                temp=P[i];
                P[i]=P[j];
                P[j]=temp;
            }
        }
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            x[i]=AT[i];
        }
        else
        {
            x[i]=y[i-1];
        }
        WT[i]=x[i]-AT[i];
        y[i]=x[i]+BT[i];
        TAT[i]=y[i]-AT[i];
        sum_WT+=WT[i];
        sum_TAT+=TAT[i];
    }
    avg_TAT=(float)sum_TAT/n;
    avg_WT=(float)sum_WT/n;
    printf("\nAverage Turnaround Time :%f",avg_TAT);
    printf("\nAverage Waiting Time:%f",avg_WT);
    getch();
}
