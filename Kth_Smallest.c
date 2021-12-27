#include<stdio.h>
int partition(int, int);
int KthSmallest(int, int);
int arr[10];
int main(){
	int n, i, k;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements of array : \n");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the value of k: ");
	scanf("%d", &k);
	printf("%dth smallest element is : %d\n",k,KthSmallest(n, k));
}

int KthSmallest(int n, int k){
	int l, h, i, j; 
	
	l=1;
	h=n;
	while(1)
	{
		j=partition(l,h);
		if(j==k)
		return arr[j];
		else if(k<j)
		{
			h = j-1;
		}
		else
		{
			l = j+1;
		}
	}
}
int partition(int l, int h){
	int pivot, i, j, temp, t;
	pivot = arr[l];
	i = l;
	j = h;
	while(i<j){
		while(arr[i]<=pivot && i<=j)
			i++;
		while(arr[j]>pivot)
			j--;
		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	t = j;
	arr[l] = arr[t];
	arr[t] = pivot;
	return t;
}
