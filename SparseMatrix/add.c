#include <stdio.h>
#include <malloc.h>

int main() {
  int row,col, *sm1, *sm2, i, j , ri, ci, count=0, ind1 = 0, ind2 = 0, *tsm1, *tsm2, *rsm, *rsm2, ind = 0;
  int tot1, tot2, c1, c2, c3;
  // Enter Matrix 1
  printf("Enter Number of Rows");
  scanf("%d", &row);
  printf("Enter Number of Columns");
  scanf("%d", &col);
  printf("Enter Sparse 1\n\n");

  sm1 = (int *)malloc(sizeof(int)*col*row);
  for (i = 0; i < row*col;i++)
  {
    printf("Enter Value ");
    scanf("%d", sm1 + i);
    if (sm1[i] != 0)
      count++;
  }
  tsm1 = (int *)malloc(sizeof(int)*3*(count+1));
  tsm1[ind1++] = row;
  tsm1[ind1++] = col;
  tsm1[ind1++] = count;
  for (i = 0; i < row * col ; i++)
  {
    ri = i/row;
    ci = i - ri*row;
    if (sm1[i] != 0)
    {
      tsm1[ind1++] = ri;
      tsm1[ind1++] = ci;
      tsm1[ind1++] = sm1[i];
    }
  }
  ind1 =3;
  for (i = 0;i < count;i++)
  {
    printf("%d %d %d\n", tsm1[ind1],tsm1[ind1+1],tsm1[ind1+2]);
    ind1 += 3;
  }
  // Enter Matrix 2
  count = 0;
  printf("Enter Sparse 2\n");
  sm2 = (int *)malloc(sizeof(int)*col*row);
  for (i = 0; i < row*col;i++)
  {
    printf("Enter Value ");
    scanf("%d", sm2 + i);
    if (sm1[i] != 0)
      count++;
  }
  tsm2 = (int *)malloc(sizeof(int)*3*(count+1));
  tsm2[ind2++] = row;
  tsm2[ind2++] = col;
  tsm2[ind2++] = count;
  for (i = 0; i < row * col ; i++)
  {
    ri = i/row;
    ci = i - ri*row;
    if (sm2[i] != 0)
    {
      tsm2[ind2++] = ri;
      tsm2[ind2++] = ci;
      tsm2[ind2++] = sm2[i];
    }
  }
  ind2 = 0;
  for (i = 0;i < count+1;i++)
  {
    printf("%d %d %d\n", tsm2[ind2],tsm2[ind2+1],tsm2[ind2+2]);
    if (i != count+1)
      ind2 += 3;
  }
  ind1 = 3;
  ind2 = 3;
   //ADD
  rsm = (int *)malloc(sizeof(int)*3*(tsm1[2] + tsm2[2]));
  rsm[ind++] = row;
  rsm[ind++] = col;
  rsm[ind++] = 0;
  tot1 = tsm1[2];
  tot2 = tsm2[2];
  c1 = c2 = 1;
  while(c1 <= tot1 && c2 <= tot2)
  {

    if (tsm1[ind1] < tsm2[ind2])
    {
      printf("%d %d %d \n", tsm1[ind1], tsm1[ind1+1],tsm1[ind1+2]);
      rsm[ind++] = tsm1[ind1];
      rsm[ind++] = tsm1[ind1+1];
      rsm[ind++] = tsm1[ind1+2];
      if (c1 != tot1)
        ind1 +=2;
        rsm[2]++;
        c1++;
      }
      else if (tsm1[ind1] > tsm2[ind2])
      {
        rsm[ind++] = tsm2[ind2];
        rsm[ind++] = tsm2[ind2+1];
        rsm[ind++] = tsm2[ind2+2];
        if (c2 != tot2)
        ind2 +=2;
        rsm[2]++;
        c2++;
      }
      else if( tsm1[ind1] == tsm2[ind2])
      {
        if (tsm1[ind1+1] < tsm2[ind2+1])
        {
          printf("%d %d %d \n", tsm1[ind1], tsm1[ind1+1],tsm1[ind1+2]);
          rsm[ind++] = tsm1[ind1];
          rsm[ind++] = tsm1[ind1+1];
          rsm[ind++] = tsm1[ind1+2];
          if (c1 != tot1)
          ind1 +=2;
          rsm[2]++;
          c1++;
        }
        else if (tsm1[ind1+1] > tsm2[ind2+1])
        {
          printf("%d %d %d \n", tsm2[ind2], tsm2[ind2+1],tsm2[ind2+2]);
          rsm[ind++] = tsm2[ind2];
          rsm[ind++] = tsm2[ind2+1];
          rsm[ind++] = tsm2[ind2+2];
          if (c2 != tot2)
          ind2 +=2;
          rsm[2]++;
          c2++;
        }
        else
        {
          printf("%d %d %d \n", tsm2[ind2], tsm2[ind2+1],tsm1[ind1+2] + tsm2[ind2+2]);
          rsm[ind++] = tsm2[ind2];
          rsm[ind++] = tsm2[ind2+1];
          rsm[ind++] = tsm1[ind1+2] + tsm2[ind2+2];
          if (c1 != tot1)
          ind1 +=2;
          if (c2 != tot2)
          ind2 +=2;
          rsm[2]++;
          c1++;
          c2++;
        }
      }
    }
    while (c1 <= tot1) {
      rsm[ind++] = tsm1[ind1];
      rsm[ind++] = tsm1[ind1+1];
      rsm[ind++] = tsm1[ind1+2];
      rsm[2]++;
      c1++;
    }
    while (c2 <= tot2) {
      rsm[ind++] = tsm2[ind2];
      rsm[ind++] = tsm2[ind2+1];
      rsm[ind++] = tsm2[ind2+2];
      rsm[2]++;
      c2++;
    }
    for (i = 0,j = 3; i < rsm[0] * rsm[1]; i++)
    {
      ri = i/rsm[0];
      ci = i - ri*rsm[0];
      if (rsm[j+2] != 0)
      {
        printf ("%d \t",rsm[j+2]);
      }
      if (rsm[j+2] == 0)
      {
        printf ("0 \t");
      }
      if (ci == rsm[1] - 1)
      {
        printf("\n");
      }
      j = j + 3;
    }
  free(tsm1);
  free(tsm2);
  free(rsm);
  return 0;
}
