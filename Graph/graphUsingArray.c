#include <stdio.h>
void __cleanstdin(void) { int c;  do {  c = getchar(); } while (c != '\n' && c != EOF);  }
int _findarray(char a[100], int n, char ele){ for (int  i = 0 ; i < n ; i ++) if (a[i] == ele) return  i; return -1;}
void _initgraph(int a[100][100], int s){ for (int i = 0; i < s; i ++) for (int j = 0; j < s; j ++) a[i][j] = 0;}
void _datain(char a[100], int n){ 
	for (int i = 0 ; i < n ; i++) {
		printf("Enter data for %d : ", i+1 );
		__cleanstdin();
		scanf("%c", &a[i]);
	}
}
void addedge(char s, char d, char data[100], int g[100][100], int n){
	int source = _findarray(data,n,s);
	int destination = _findarray(data,n,d);
	if (source != -1 && destination != -1) g[source][destination] = 1;
	else printf("Missing source / destination ");
}
void removeedge(char s, char d, char data[100], int g[100][100], int n){
	int source = _findarray(data,n,s);
	int destination = _findarray(data,n,d);
	if (source != -1 && destination != -1) g[source][destination] = 0;
	else printf("Missing source / destination ");
}
void printgraph(int graph[100][100], int size, char data[100]){
	printf("\t");
	for (int i =0 ;i < size ;i ++) printf("%c\t", data[i]); printf("\n");
	for (int i =0 ;i < size ;i ++){
		printf("%c\t", data[i]);
		for (int j = 0; j < size ;j ++) printf("%d\t",graph[i][j]);
		printf("\n");
	}
}
void generategraph(int graph[100][100], int size, char data[100]){
	_datain(data, size);
	char a, b,ch = 'y';
	do {
		printf("Enter Source : ");__cleanstdin(); scanf("%c", &a);
		printf("Enter destination : ");__cleanstdin(); scanf("%c", &b);
		addedge(a,b,data, graph,size);
		printf("Do you wish to enter more edges ? ");__cleanstdin(); scanf("%c", &ch);
	} while (ch == 'y');
}
int main(){
	int array[100][100], size;
	char data[100];
	printf("Enter Size : ");
	scanf("%d", &size);
	generategraph(array,size,data);
	printgraph(array,size, data);
}