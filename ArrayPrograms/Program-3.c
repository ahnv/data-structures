//  Find the Maximum and Minimum of an array using minimum number of comparisons.

#include <stdio.h>
#include <malloc.h>

int main(){
	int *a, n, max, min;
	scanf("%d", &n);
	a = (int *)malloc(sizeof(int));

	for (int i = 0; i< n; i++) { scanf("%d", &a[i]); }
	
	if (a[0] > a[1]) { max = a[0]; min = a[1]; } else  { max = a[1]; min = a[0]; }
	
	for (int i = 2; i < n; i++)
	{
		if(a[i] > max) max = a[i];
		if(a[i] < min) min = a[i];
	}
	
	printf("Min = %d & Max = %d\n", min, max);
	
	return 0;
}