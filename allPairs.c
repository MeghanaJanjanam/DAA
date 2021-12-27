#include<stdio.h>
void allPairs(int [20][20], int);
main()
{
	int i, cost[20][20], n, j;
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	printf("Enter cost of the edge\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("from %d - %d ", i, j);
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	allPairs(cost, n);
}
void allPairs(int cost[20][20], int n){
	int i, j, k, A[20][20];
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			A[i][j] = cost[i][j];
	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
			{
				if(A[i][k]+A[k][j] < A[i][j])
					A[i][j] = A[i][k]+A[k][j];
			}
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
		{
			if(i==j)
				printf("the shortest distance from %d to %d is 0\n",i,j);
			if(i!=j)
				printf("the shortest distance from %d to %d is %d\n",i,j,A[i][j]);
		}
}