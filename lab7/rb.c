// round robin 

#include<stdio.h>
#include<string.h>
struct process
{
    int id,AT,BT,ST,CT,WT,TAT,RT;
}a[10];
void swap(int *b,int *c)
{
    int tem;
    tem=*c;
    *c=*b;
    *b=tem;
}
int queue[100],front=-1,rear=-1;
void insert(int n)
{
    if(front==-1)
     front=0;
    rear=rear+1;
    queue[rear]=n;
}
int delete()
{
    int n;
    n=queue[front];
    front=front+1;
    return n;
}
int main()
{
    int n,TQ,p,t,count=0,min=10000;
    int temp[10],exist[10],f[10];
    memset(exist,0,sizeof exist);
    memset(f,1,sizeof f);
    float total_wt=0,total_tat=0,total_rt=0,Avg_WT,Avg_TAT,Avg_RT;
    printf("Enter the number of the processes\n");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time of each process\n");
    printf("AT BT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].AT,&a[i].BT);
        a[i].id=i+1;
        temp[i]=a[i].BT;
    }
    for(int i=0;i<n;i++)
    {
    for(int j=i+1;j<n;j++)
    {
       if(a[j].AT<a[i].AT)
       {
        swap(&a[i].AT,&a[j].AT);
        swap(&a[i].BT,&a[j].BT);
        swap(&temp[i],&temp[j]);
        swap(&a[i].id,&a[j].id);
       }
    }
    }
    printf("Enter the time quantum\n");
    scanf("%d",&TQ);
    insert(0);
    exist[0]=1;
    t=a[0].AT;
    while(front<=rear)
    {
        p=delete();
        if(f[p])
            a[p].ST=t;
        f[p]=0;
        if(a[p].BT>TQ)
        {
            a[p].BT=a[p].BT-TQ;
            t=t+TQ;
        }
        else
        {
            t=t+a[p].BT;
            a[p].BT=0;
        }
        for(int i=0;i<n;i++)
        {
            if(exist[i]==0 && a[i].AT<=t)
            {
                insert(i);
                exist[i]=1;
            }
        }
        if(a[p].BT==0)
        {
            a[p].CT=t;
            a[p].TAT=t-a[p].AT;
            a[p].WT=a[p].TAT-temp[p];
            a[p].RT=a[p].ST-a[p].AT;
            total_tat+=a[p].TAT;
            total_wt+=a[p].WT;
            total_rt+=a[p].RT;
        }
        else
            insert(p);
        count++;
    }
    Avg_TAT=total_tat/n;
    Avg_WT=total_wt/n;
    Avg_RT=total_rt/n;
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("ProcessID\tArrival\t\tBurst\tStart\tEnd\tTurnAroundTime\tWaitingTime\tResponseTime\n");
    printf("----------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<n;i++)
    {
    printf("%d\t\t%d\t\t%d\t%d\t%d\t%d\t\t%d\t\t%d\n",a[i].id,a[i].AT,temp[i],a[i].ST,a[i].CT,a[i].TAT,a[i].WT,a[i].RT);
    printf("----------------------------------------------------------------------------------------------------\n");
    }
    printf("Avg waiting time is: %f\n",Avg_WT);
    printf("Avg turn around time is: %f\n",Avg_TAT);
    printf("Avg response time is: %f\n",Avg_RT);
    printf("Number of context switches : %d\n",count-1);
    return 0;
}