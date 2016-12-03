//  Let assume an array A of size n. Perform an exchange such that ‘A[j]’ becomes ‘i’ if ‘A[i]’ is ‘j’

#include <stdio.h>
#include <malloc.h>

int main()
{
	int *a,n, i, j;
	printf("Enter The number of elements in array: ");
	scanf("%d", &n);
	a = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] < n){
			int temp = a[i];
			a[i] = a[temp];
			a[temp] = temp; 
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}