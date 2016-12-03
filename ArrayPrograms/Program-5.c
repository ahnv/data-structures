//Assume that an array and one sum is given to you. Find whether a pair exists in the array that sums equal to given sum or not.

#include <stdio.h>
#include <malloc.h>

int main(){
	int *a, n, sum, f =0 ;
	printf("N = ");
	scanf("%d", &n);
	printf("Sum = ");
	scanf("%d", &sum);
	a = (int *)malloc(sizeof(int));
	for (int i = 0; i< n; i++) 
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i] + a[j] == sum){
				f = 1;
				printf("(%d, %d)\t", a[i], a[j]);
			}
	if (f == 0)
		printf("No elements Found\n");
	return 0;
}