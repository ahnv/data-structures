#include <stdio.h>
#include <malloc.h>

int main(){
      int row,col, *sm, i, count=0, *tsm, ind = 0, ri, ci, j;
      printf("Enter number of rows : "); scanf("%d",&row);
      printf("\nEnter number of cols : "); scanf("%d",&col);
      sm = (int *)malloc(sizeof(int)*col*row);
      for (i = 0; i < row*col;i++){
        printf("Enter value for SM");
        scanf("%d", sm+i);
        if (sm[i] != 0) count++;
      }
      tsm = (int *)malloc(sizeof(int)*3*(count+1));
      tsm[ind++] = row; tsm[ind++] = col; tsm[ind++] = count;
      for (i = 0; i < row * col ; i++){
        ri = i/row;
        ci = i - ri*row;
        if (sm[i] != 0){
          tsm[ind++] = ri;
          tsm[ind++] = ci;
          tsm[ind++] = sm[i];
        }
      }
      printf("\n");
      for (i = 0,j = 3; i < tsm[0] * tsm[1]; i++)
      {
        ri = i/tsm[0];
        ci = i - ri*tsm[0];
        if (tsm[j+2] != 0) printf ("%d \t",tsm[j+2]);
        if (tsm[j+2] == 0) printf ("0 \t");
        if (ci == tsm[1] - 1) printf("\n");
        j = j + 3;
      }
      free(sm);
}
