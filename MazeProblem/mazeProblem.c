#include <stdio.h>

int size;

int inBounds(int maze[size][size], int x, int y){
  if (x>=0 && y >= 0 && x <= size && y <= size && maze[x][y] == 1) return 1;
  return 0;
}

int solver(int maze[size][size], int x, int y, int m, int n, int sol[size][size]){

  if ((x == size - 1 && y == size -1) || (x == m && y == n)){ sol[x][y] = 1;  return 1; }

  if (inBounds(maze, x, y) == 1){
    sol[x][y] = 1;
    if (solver(maze, x+1, y, m, n, sol) == 1) return 1;
    if (solver(maze, x, y + 1, m, n, sol) == 1) return 1;
    sol[x][y] = 0;
    return 0;
  }
  return 0;
}

int main(){
  int x, y, m, n;
  scanf("%d", &size);
  int maze[size][size], sol[size][size];
  scanf("%d", &x);
  scanf("%d", &y);
  scanf("%d", &m);
  scanf("%d", &n);
  for (int i =0 ; i < size ; i++)
    for (int j = 0 ; j < size ; j++)
      scanf("%d", &maze[i][j]);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size;j++)
      sol[i][j] = 0;

  if (solver(maze,x,y,m,n,sol) == 0){ printf("No Solution \n");  return 0; }
  printf("Solution is \n");
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size;j++)
      printf("%d ", sol[i][j]);
    printf("\n");
  }  
  return 0;
}
