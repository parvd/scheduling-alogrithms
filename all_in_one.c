#include<stdio.h>
float fcfs(int [],int [],int);
float rrb(int [],int [],int,int ,int,int [] );
main()
{
int n,a[10],b[10],bc[10],i,m,qt,time,by;
float c,y;
            for(i=0;i<10;i++)
            {
                        a[i]=0; b[i]=0;
            }
printf("enter the number of process:");
            scanf("%d",&n);
printf("enter the burst times\n");
            for(i=0;i<n;i++)
                {
				scanf("%d",&b[i]);
                bc[i]=b[i];
				}
    printf("\nenter the arrival times\n");
            for(i=0;i<n;i++)
                scanf("%d",&a[i]);
                
	loop:printf("Enter 1.FCFS 2.Round-robin 3.exit\n");
    scanf("%d",&m);
     do
     {
     	switch(m)
     	{
     		case 1:	c=fcfs(b,a,n);
			     	printf("\nanswer-fcfs= %f\n",c);
			     
			case 2:	printf("Enter quantum time:\n");
					scanf("%d",&qt);
			    	y=rrb(bc,a,n,qt,time,b);
			    	printf("\nanswer-round-robin= %f",y);
			    	
			case 3:	exit(0);
		 }
	printf("\nWant to continue 1-yes & 0-no\n");
	scanf("%d",&by);	
	if(by==0)
	exit(0);
	else 
	goto loop;
	}while(m!=3);
}
float fcfs(int b1[],int a1[],int u)
{
	int t[10],w[10],g[10],i;
	float att=0,awt=0;
	for(i=0;i<10;i++)
            {
                        w[i]=0;
						g[i]=0;
            }
	

    g[0]=0;
             for(i=0;i<10;i++)
                   g[i+1]=g[i]+b1[i];
             for(i=0;i<u;i++)
            {     
                        w[i]=g[i]-a1[i];
                        t[i]=g[i+1]-a1[i];
                        awt=awt+w[i];
                        att=att+t[i]; 
            }
            awt =awt/u;
            att=att/u;
            printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
            for(i=0;i<u;i++)
            {
                        printf("P[%d]\t|\t%d\t|\t%d\n",i,t[i],w[i]);
            }
printf("the average waiting time is %f\n",awt);
printf("the average turn around time is %f\n",att);

return awt;
}
float rrb(int b2[],int a2[],int v,int qt1,int t,int x[])
{
	 printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
	int c,flag=0;
	int r=v;
	float att=0,awt=0;
	for(t=0,c=0;r!=0;)
	{
		if(b2[c]<=qt1 && b2[c]>0)
		{
			t+=b2[c];
			b2[c]=0;
			flag=1;
		}
		else if(b2[c]>0)
		{
			b2[c]-=qt1;
			t+=qt1;
		}
	if(b2[c]==0 && flag==1) 
    { 
      r--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",c+1,t-a2[c],t-a2[c]-x[c]); 
      awt+=t-a2[c]-x[c]; 
      att+=t-a2[c]; 
      flag=0; 
    } 
    if(c==v-1) 
      c=0; 
    else if(a2[c+1]<=t) 
      c++; 
    else 
      c=0; 
  } 
	printf("\nAverage Waiting Time= %f\n",awt/v); 
    printf("Avg Turnaround Time = %f",att/v);
	
	return awt/v; 
  	
	}
	
