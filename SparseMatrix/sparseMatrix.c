#include <stdio.h>
#include <malloc.h>

int main(){
    int row = 5, col = 5, i, count = 0, *tsm, choice, sum = 0, ri , ci, j, ind = 0, *sm[row];
    for (i = 0; i < row; i++) sm[i] = (int *)malloc(col*sizeof(int));
    printf("1. Diagnol Matrix\n2. Upper Triangular\n3.Lower Triangular\nEnter Your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter Diagnol Elements of the Matrix : ");
            for (i = 0 ; i < row; i++){
                        scanf("%d", &sm[i][i]);
                        if (sm[i][i] == 0) count++;
            }
            tsm = (int *)malloc(sizeof(int)*3*(count+1));
            tsm[ind++] = row;
            tsm[ind++] = col;
            tsm[ind++] = count;
            for (i = 0; i < row; i++){
                if (sm[i][i] != 0){
                    tsm[ind++] = i;
                    tsm[ind++] = i;
                    tsm[ind++] = sm[i][i];
                }
            }
            for (int i = 3; i < tsm[2]; i = i + 3) sum += tsm[i + 2];
            printf("Sum = %d \n", sum );
            break;
        case 2:
            printf("Enter Upper Triangular Matrix : ");
            for (int  i = 0 ; i < row ; i++)
                for (int j = i ; j < col; j++){
                    printf("Element[%d][%d] : ", i+1, j+1);
                    scanf("%d", &sm[i][j]);
                    if (sm[i][j] != 0) count++
                }
            tsm = (int *)malloc(sizeof(int)*3*(count+1));
            tsm[ind++] = row;
            tsm[ind++] = col;
            tsm[ind++] = count;                
            for (int  i = 0 ; i < row ; i++)
                for (int j = i ; j < col; j++){
                    if (sm[i][j] != 0){
                        tsm[ind++] = i;
                        tsm[ind++] = j;
                        tsm[ind++] = sm[i][j];
                    }
                }
            for (int i = 3; i < tsm[2]; i = i + 3) sum += tsm[i + 2];
            printf("Sum = %d \n", sum );
            break;
        case 3: 
            printf("Enter Lower Triangular Matrix : ");
            for (int  i = 0 ; i < row ; i++)
                for (int j = 0 ; j < i; j++){
                    printf("Element[%d][%d] : ", i+1, j+1);
                    scanf("%d", &sm[i][j]);
                    if (sm[i][j] != 0) count++;
                }
            tsm = (int *)malloc(sizeof(int)*3*(count+1));
            tsm[ind++] = row;
            tsm[ind++] = col;
            tsm[ind++] = count;
            for (int  i = 0 ; i < row ; i++)
                for (int j = 0 ; j < i; j++){
                    if (sm[i][j] != 0){
                        tsm[ind++] = i;
                        tsm[ind++] = j;
                        tsm[ind++] = sm[i][j];
                    }
                }
            for (int i = 3; i < tsm[2]; i = i + 3) sum += tsm[i + 2];
            printf("Sum = %d \n", sum );
            break;
    }
    return 0;
}