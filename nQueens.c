#include<stdio.h>
int place(int, int);
void nQueen(int);
int n, x[10];
main(){
	int i, j;
	printf("Enter no. of queens: ");
	scanf("%d", &n);
 	nQueen(1);
}

int place(int k, int l){
	int i;	
	for(i=1; i<=k-1; i++){
		if(abs(i-k)==abs(l-x[i]) || (x[i]==l)){
			return 0;
		}
	}
	return 1;
}
void nQueen(int k){
	int i, j;
	for(i=1; i<=n; i++)
	{
		if(place(k, i)==1)
		{
			x[k] = i;
			if(k==n)
			{
				for(i=1;i<=n;i++){
					printf("%d ",x[i]); 
				}
				printf("\n");
			}
			else
				nQueen(k+1);
		}
	}
}
