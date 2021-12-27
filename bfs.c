#include<stdio.h>
void bfs(int);
int cost[20][20], visited[20], n;
main(){
	int i, j;
	printf("Enter no. of nodes: ");
	scanf("%d", &n);
	printf("enter costs 1 if there is edge\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		printf("%d-%d:",i,j);
		scanf("%d",&cost[i][j]);
	}
	printf("Visiting order would be\n");
	for(i=1;i<=n;i++)
		visited[i]=0;
	bfs(1);
}
void bfs(int v){
	int u, f=0, r=0, w, q[20];
	u=v;
	visited[v]=1;
	printf("%d\n", v);
	while(1){
		for(w=1; w<=n; w++){
			if(visited[w] == 0)
			{
				q[r++]=w;
				visited[w]=1;
				printf("%d\n",w);	
			}
		}
		if(f==r)
		return;
		u = q[f++];	
	}

}