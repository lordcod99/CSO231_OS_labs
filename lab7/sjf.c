// SHORTEST JOB FIRST

#include<stdio.h>
#include<string.h>
struct process
{
    int WT,AT,BT,ST,CT,TAT,RT;
}a[10];
int max(int a, int b)
{
    return (a >= b ? a : b);
}
int main()
{
    int n,flag[10],ind;
    int t,count,short_P,min=10000;
    memset(flag,1,sizeof flag);
    float total_WT=0,total_TAT=0,total_RT=0,Avg_WT,Avg_TAT,Avg_RT;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    printf("Enter the Arrival time and Burst time of each process\n");
    printf("AT BT\n");
    for(int i=0;i<n;i++)
    {
       scanf("%d%d",&a[i].AT,&a[i].BT);
       if(a[i].AT<min)
           min=a[i].AT;
    }
    a[9].BT=10000;
    t=min;
    for(count=0;count<n;count++)
    {
        short_P=9;
        for(int i=0;i<n;i++)
          if(flag[i])
            if(a[i].BT<a[short_P].BT)
            {
                if(a[i].AT<=t)
           short_P=i;
   }
   else if(a[i].BT==a[short_P].BT)
   {
    if(a[i].AT<=t && a[i].AT<a[short_P].AT)
       short_P=i;
   }
        t=max(t,a[short_P].AT);
        a[short_P].ST=t;
        t+=a[short_P].BT;
        a[short_P].CT=t;
        a[short_P].TAT=a[short_P].CT-a[short_P].AT;
        a[short_P].WT=a[short_P].TAT-a[short_P].BT;
        a[short_P].RT=a[short_P].ST-a[short_P].AT;
        total_WT+=a[short_P].WT;
        total_TAT+=a[short_P].TAT;
        total_RT+=a[short_P].RT;
        flag[short_P]=0;
    }
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    Avg_RT=total_RT/n;
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("ProcessID\tArrival\t\tBurst\tStart\tEnd\tTurnAroundTime\tWaitingTime\tResponseTime\n");
    printf("----------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<n;i++)
    {
    printf("%d\t\t%d\t\t%d\t%d\t%d\t%d\t\t%d\t\t%d\n",i+1,a[i].AT,a[i].BT,a[i].ST,a[i].CT,a[i].TAT,a[i].WT,a[i].RT);
    printf("----------------------------------------------------------------------------------------------------\n");
    }
    printf("Avg waiting time is: %f\n",Avg_WT);
    printf("Avg turn around time is: %f\n",Avg_TAT);
    printf("Avg response time is: %f\n",Avg_RT);
    return 0;
}