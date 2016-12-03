#include <stdio.h>

int main(){
	int t, n, p, dayslost;
	scanf("%d", &t);
	int dlost[t];
	for (int x = 0 ; x < t; x++){
		dayslost = 0;
		scanf("%d", &n);
		if (n <= 7 || n >= 3560) return -1;
		scanf("%d", &p);
		if (p <= 1 || p >= 100) return -2;
		int h[p];
		for (int i = 0 ; i< p ; i++) scanf("%d", &h[i]);
		for(int  i = 1, j = 0 ; i <= n; j++, j %=7, i++)
			if (j !=  5 && j != 6)
				for (int k = 0 ;k < p ;k++)
					if (i % h[k] == 0 ){
						dayslost++;
						break;
					}
		dlost[x] = dayslost;
	}
	for (int i =0 ;i < t; i++)
		printf("%d\n", dlost[i]);
	return 0;
}