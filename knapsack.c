#include<stdio.h>

float knapsack(int m, int n, float W[10], float P[10],int[]);
int main(){
	int m, n, i, j, t,order[10];
	//fp = findProfit, dratio = dummyRatio
	float w, p, temp, Wt[10], Pf[10], ratio[10];
	printf("Enter the size of objects: ");
	scanf("%d", &n);
	printf("Enter the Capacity of objects: ");
	scanf("%d", &m);
	printf("Enter the Weights and profits of objects: \n");
	for(i=0; i<n; i++){
		order[i]=i;
		scanf("%f", &Wt[i]);
	}
	for(i=0; i<n; i++){
		scanf("%f",&Pf[i]);
	}
	for (i=0; i<n; i++) {
      ratio[i] = Pf[i] / Wt[i];

	}
	
	for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = Wt[j];
            Wt[j] = Wt[i];
            Wt[i] = temp;
 
            temp = Pf[j];
            Pf[j] = Pf[i];
            Pf[i] = temp;
       		
       		t=order[i];
       		order[i]=order[j];
       		order[j]=t;
	     }
      }
    }
	knapsack(m, n, Wt, Pf,order);	
	return 0;
}

float knapsack(int m, int n, float W[], float P[],int order[]){
	int i, j;
	float x[10], fp=0.0;
	for(i=0; i<=n; i++){
		x[i] = 0.0;
	}
	for(i=0; i<n; i++){
		if (W[i]<=m){
			x[order[i]] = 1.0;
			m = m - W[i];
			fp = fp+P[i];
		}
		else
			break;
	}
	if(i<n){
		x[order[i]] = m/W[i];
	}
	fp = fp+(x[i]*P[i]);
	
    for (i = 0; i < n; i++){
		printf("%f\t", x[i]);
    }
    printf("\nMaximum profit is: %f", fp);
}

