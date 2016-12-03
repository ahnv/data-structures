#include <stdio.h>

void DFS(int);
int adj[10][10],state[10],n; 

void main(){
	printf("Enter number of vertices : ");
	scanf("%d", &n);
	printf("\nEnter adjecency matrix of the graph : \n");
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &adj[i][j]);
	for (int i = 0; i < n; ++i) state[i] = 0;
	DFS(0);
}

void DFS(int i){
	printf("\n%d", i);
	state[i] = 1;
	for (int j = 0; j < n; ++j) if (!state[j] && adj[i][j] == 1) DFS(j);
}