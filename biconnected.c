#include<stdio.h>
void bicomp(int,int);
int min(int,int);
int dfn[20],l[20],n,cost[10][10],num=1,sta[20],top=-1;
main()
{
	int i,j;
	printf("enter no of nodes ");
	scanf("%d",&n);
	printf("enter 1 if there is edge ");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		printf("%d-%d:",i,j);
		scanf("%d",&cost[i][j]);
	}
	for(i=1;i<=n;i++)
	{
		dfn[i]=0;
		l[i]=0;
	}
	bicomp(1,0);
}
void bicomp(int u,int v)
{
	int w,x,y;
	dfn[u]=num;
	l[u]=num;
	num++;
	for(w=1;w<=n;w++)
	{
		if(cost[w][u]!=0)
		{
			if(w!=v&&dfn[w]<dfn[u])
			{
				sta[++top]=u;
				sta[++top]=w;
			}
			if(dfn[w]==0)
			{
				bicomp(w,u);
				if(l[w]>=dfn[u])
				{
					printf("bi connected component is\n");
					do
					{
						x=sta[top--];
						y=sta[top--];
						printf("%d\t%d\n",x,y);
					}
					while(!((x==u&&y==w)||(x==w&&y==u)));
				}
				l[u]=min(l[u],l[w]);
			}
			else if(w!=v)
				l[u]=min(l[u],dfn[w]);
		}
	}
}
int min(int a,int b)
{
	if(a>b)
	return b;
	return a;
}

