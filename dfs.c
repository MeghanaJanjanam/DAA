#include<stdio.h>
void dfs(int);
int n,cost[10][10],visited[10];
main()
{
	int i,j;
	printf("enter no of nodes ");
	scanf("%d",&n);
	printf("enter 1 if there is edge\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		{
			printf("%d-%d: ",i,j);
			scanf("%d",&cost[i][j]);
		}
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
	dfs(1);
}
void dfs(int v)
{
	int u;
	visited[v]=1;
	printf("%d\n",v);
	for(u=1;u<=n;u++)
	{
		if(cost[u][v]==1)
			if(visited[u]==0)
				dfs(u);
	}
}