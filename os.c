#include<stdio.h>
#include<conio.h>
void os(int no,int rt[30],int ct[30],int at[30],int  bt[30]);
main()
{
int pn, j, no, ct,rmp,indicat,time_s,w,lol,at[30],bt[30],rt[30],x=1;
indicat=0;
w=0;
lol=0;
printf("Enter number of processes");
scanf("%d",&no);
rmp=no;
printf("\nEnter Arrival time and brust time");
for(pn=0;pn<no;pn++)
{
	printf("\nProcess p%d\n",pn+1);
	printf("Arrival time=");
	scanf("%d",&at[pn]);
	printf("Burst time=");
scanf("%d",&bt[pn]);
rt[pn]=bt[pn];
}
printf("Time slice for first round 6");
time_s=6;
ct=0;
for(pn=0;rmp!=0;)
{
	if(rt[pn]<=time_s && rt[pn]>0)
	{
		ct+=rt[pn];
		rt[pn]=0;
        indicat=1;
	}
	else if(rt[pn]>0)
	{
		rt[pn]-=time_s;
		ct+=time_s;
	}
	if(rt[pn]==0 && indicat==1)
	{
		printf("%d",pn);
		rmp--;
		printf("P %d",pn+1);
		printf("\t\t\t%d",&ct-at[pn]);
		printf("\t\t\t%d\n",ct-bt[pn]-at[pn]);
		w+=ct-at[pn]-bt[pn];
		lol+=ct-at[pn];
		indicat=0;
	}
	if(pn=no-1)
	{
		x++;
		if(x==2)
		{
			pn=0;
			time_s=10;
			printf("Time slice for second round is 10.\n");
		}
		else
		{
			break;
		}
	}
	else if(ct>= at[pn+1])
	{
		pn++;
}
else
{
pn=0;
}
}
os(no,rt,ct,at,bt);
return 0;
}

void os(int no,int rt[30],int ct[30],int at[30],int  bt[30])
float avg_wt,avg_lol;
int i,j,n,tem,btm[40],pn[40],wt[40],lolt[40],loc;
int total=0;
int n=no;
printf("Third round with least burst time.\n");
for(int i=0;i<n;i++)
{
	btm[i]=rt[i];
	wt[i]=ct-at[i]-bt[i];
		pn[i]=i+1;
}
for(i=0;i<n;i++)
{
	loc=I;
	for(j=i+1;j<n;j++)
	{
		If(btm[j]<btm[loc])
		{
		loc=j;
		}
	}
	temp=btm[i];
	btm[i]=btm[loc];
	btm[loc]=tem;
tem=pn[i]
pn[i]=pn[loc];
pn[loc]=temp;
}
for(i=1;i<n;i++)
{
	for(j=0;j<I;j++)
		{
			wt[i]+=bt[j];
		}
	total+=wt[i];
}
avg_wt=(float)total/n;
total=0;
printf("\nProcess\t\tBurst time\t\tWaiting time\t\tTurnaround time");
for(int i=0;i<n;i++)
{
	lolt[i]=bt[i]+wt[i];
	total=total+lolt[i];
	printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",pn[i],bt[i],wt[i],lolt[i]);
}
avg_lol=(float)total/n;
printf("\n\nAverage waiting time=%f",avg_wt);
printf("\n\nAverage turnaround time=%f\n",avg_lol);
}



