#include <stdio.h>
#include <stdlib.h>

int isSpecial(int arr[], int n ){
	int t = 0, done[n];
	for (int i = 0 ; i < n ; i++){
		int diff = abs(arr[i] - arr[i+1]);
		if (diff < 1 || diff >= n)
			for (int j = 0 ; j < t; j++)
				if (done[j] == diff){
					return 0;
				}
		done[t++] = diff;
	}
	return 1;
}
int main()
{
	int n, t;
	scanf("%d", &n);
	if (n > 3000) return -1;
	int arr[n];
	for (int i = 0 ; i < n; i++)
		scanf("%d", &arr[i]);
	isSpecial(arr,n)? printf("Special Sequence \n"): printf("Not a Special Sequence \n");
	return 0;
}