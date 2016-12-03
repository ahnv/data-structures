#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void wordFound(char wordGrid[][128],int m,int n,int i,int j,char word[],char current[],int in,int length,int &ans)
{
    if(i<0||j<0||i>=m||j>=m)return;
    if(in==length)
    {
        current[in]='\0';
        for(int i=0;i<length;++i)
            if(current[i]!=word[i])
                return;
        ans =1;
        return;
    }

    current[in] = wordGrid[i][j];
    wordFound(wordGrid, m,  n,  i,      j-1,    word,   current,    in+1,   length, ans);
    wordFound(wordGrid, m,  n,  i-1,    j-1,    word,   current,    in+1,   length, ans);
    wordFound(wordGrid, m,  n,  i-1,    j,      word,   current,    in+1,   length, ans);
    wordFound(wordGrid, m,  n,  i-1,    j+1,    word,   current,    in+1,   length, ans);
    wordFound(wordGrid, m,  n,  i,      j+1,    word,   current,    in+1,   length, ans);
    wordFound(wordGrid, m,  n,  i+1,    j+1,    word,   current,    in+1,   length, ans);
    wordFound(wordGrid, m,  n,  i+1,    j,      word,   current,    in+1,   length, ans);
    wordFound(wordGrid, m,  n,  i+1,    j-1,    word,   current,    in+1,   length, ans);

}

bool findWordInAGrid(char grid[128][128], int m, int n, char word[32]) {
    int length;
    for(length = 0 ; word[length]!='\0' ; ++length );
    for(int i=0 ; i<m ; ++i )
    {
        for(int j=0 ; j<n ; ++j )
        {
            int ans = 0;
            char current[32];
            wordFound(grid , m , n , i , j , word , current , 0 , length , ans );
            if(ans)
                return 1;
        }
    }
    return false;
}

int main() {
    int m, n, k, i, j;
    char grid[128][128], word[32];
    printf("Enter Number of rows: ");
    scanf("%d",&m);
    printf("Enter Number of columns: ");
    scanf("%d",&n);
    for(i=0;i<m;i++)
    {
    	for(j=0;j<n;++j)
    	{
            printf("Enter Element[%d][%d] : ",i+1,j+1);
    		cin >> grid[i][j];
    	}
    }
    printf("Enter number of searches");
    scanf("%d",&k);
    while(k--) {
        printf("Enter Word: ");
        scanf("%s",word);
        printf("%s\n",findWordInAGrid(grid, m, n, word) ? "true" : "false");
    }
    return 0;
}
