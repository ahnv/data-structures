// Take two array dynamically and find out whether an array is subset of another array or not and also find which one is the subset.

#include <stdio.h>
#include <malloc.h>

int isSubset(int *x,int *y,int n1,int n2){
	int i,j;
	for (i =0 ; i < n1; i++){
		for (j = 0; j < n2; j++)
			if (y[i] == x[j])
				break;
		if ( j == n2)
			return 0;
	}
	return 1;
}

int main(){
	int *a, *b, n1, n2 , f=0;
	
	printf("Enter Number of Elements in Array 1: ");
	scanf("%d", &n1);
	a = (int *)malloc(sizeof(int)*n1);
	for (int i = 0; i<n1; i++)
		scanf("%d", &a[i]);

	printf("Enter Number of Elements in Array 2: ");
	scanf("%d", &n2);
	b = (int *)malloc(sizeof(int)*n2);
	for (int i = 0; i<n2; i++)
		scanf("%d", &b[i]);
	if (isSubset(a,b,n1,n2)){
		f =1;
		printf("A is a subset of B");
	}
	if(isSubset(b,a,n2,n1)){
		f =1;
		printf("B is a subset of A");
	}
	if (f ==0)
		printf("No Subset Exists");
}