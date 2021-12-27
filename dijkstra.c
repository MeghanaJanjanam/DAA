#include<stdio.h>
void dijkstra(int [][],int,int [],int [],int);
main()
{
	int i,j,cost[10][10],dist[10],prev[10],v,n,m,a[10],k;
	printf("enter no of nodes");
	scanf("%d",&n);
	printf("enter edges");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		{
			printf("enter edge from %d to %d\n",i,j);
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
			if(i==j)
				cost[i][j]=0;
		}
	}
	printf("enter source node");
	scanf("%d",&v);
	dijkstra(cost,n,dist,prev,v);
	printf("shortest distance from %d to\n",v);
	for(i=1;i<=n;i++)
	{
		printf("%d is%d\n",i,dist[i]);
		printf("path is %d",v);
		for(j=i,k=1;j!=v;j=prev[j],k++)
		{
			a[k]=j;
		}
		for(m=k-1;m>=1;m--)
			printf("->%d",a[m]);
		printf("\n");
	}
}
void dijkstra(int cost[10][10],int n,int dist[10],int prev[10],int v)
{
	int i,j,min,u,w,s[10];
	//s=state
	for(i=1;i<=n;i++)
	{
		s[i]=0;
		dist[i]=cost[v][i];
		prev[i]=v;
	}
	s[v]=1;
	dist[v]=0;
	for(i=2;i<n;i++)
	{
		min=999;
		for(j=1;j<=n;j++)
		if(s[j]==0&&min>dist[j])
		{
			u=j; 
			min=dist[j];
		}
		s[u]=1;
		for(w=1;w<=n;w++)
		{
			if(cost[u][w]!=999&&s[w]==0)
			{
				if(dist[w]>dist[u]+cost[u][w])
				{
					dist[w]=dist[u]+cost[u][w];
					prev[w]=u;
				}
			}
		}
	}
}