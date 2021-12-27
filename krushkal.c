#include<stdio.h>
void kruskal(int [][],int,int [][]);
void Union(int,int);
void sort(int [],int);
int find(int);
int id[10];
main()
{
	int cost[10][10],t[10][2],i,j,p,n;
	printf("enter no of nodes");
	scanf("%d",&n);
	printf("enter cost of edges");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("enter edge from %d to %d\n",i,j);
			scanf("%d",&cost[i][j]);
		}
	}
	kruskal(cost,n,t);
	for(i=1;i<n;i++)
	{
		for(j=1;j<=2;j++)
			printf("%d\t",t[i][j]);
			printf("\n");
	}
}
void kruskal(int cost[10][10],int n,int t[10][2])
{
	int x,y,b=0,a[50],i,j,g,k,u,v,mincost=0,m=1,s=1,p;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(cost[i][j]!=0)
				a[b++]=cost[i][j];
	sort(a,b);
	for(i=0;i<b;i++)
		printf("%d\t",a[i]);
	for(i=1;i<=n;i++)
	{
		id[i]=-1;
	}
	while(m<n)
	{
		g=a[0];
		s=1;
		for(i=1;i<=n&&s;i++)
		{
			for(j=1;j<=n&&s;j++)
			{
				if(cost[i][j]==g)
				{
					u=i;
					v=j;
					cost[i][j]=cost[j][i]=0;
					s=0;
				}
			}
		}
		b=b-2;
		for(p=0;p<b;p++)
			a[p]=a[p+2];
		x=find(u);
		y=find(v);
		if(x!=y)
		{
			t[m][1]=u;
			t[m][2]=v;
			mincost=mincost+g;
			Union(x,y);
			m++;
		}
	}
	printf("\nminimum cost is %d\n",mincost);
}
void Union(int u,int v)
{
	id[u]=v;
}
int find(int i)
{
while(id[i]>=0)
	i=id[i];
return i;
}
void sort(int a[10],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	if(a[i]<a[j])
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}