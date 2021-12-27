#include<stdio.h>
int backward(int [][],int,int,int []);
main()
{
	int n,cost[20][20],k,p[20],i,j,min,stage[20];
	printf("enter no of stages ");
	scanf("%d",&k);
	printf("enter no of nodes ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("enter stage of %d node ",i);
		scanf("%d",&stage[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<j&&stage[i]+1==stage[j])
			{
				printf("enter cost from %d node to %dnode ",i,j);
				scanf("%d",&cost[i][j]);
				if(cost[i][j]==0)
					cost[i][j]=999;
			}
			else
				cost[i][j]=999;
		}
	}
	min=backward(cost,n,k,p);
	printf("minimum cost from source to sink is %d\n ",min);
	printf("the path is ");
	for(i=1;i<=k;i++)
		printf("%d->",p[i]);
		
	printf("\n");
}
int backward(int c[20][20],int n,int k,int p[20])
{
	int cost[20],min,l,i,j,d[20];
	cost[1]=0;
	for(j=2;j<=n;j++)
	{
		min=999;
		for(i=1;i<=j;i++)
		{
			if(c[i][j]!=999&&min>c[i][j]+cost[i])
			{
				min=c[i][j]+cost[i];
				l=i;
			}
		}
		cost[j]=c[l][j]+cost[l];
		d[j]=l;
	}
	p[1]=1;
	p[k]=n;
	for(j=k-1;j>=2;j--)
		p[j]=d[p[j+1]];
	return cost[n];
}