#include <stdio.h>
#define MAX 112

int M[MAX][MAX];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i <n;i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&M[i][j]);
    
    for(int i = 1 ; i <n;i++)
        for(int j = 1; j < n; j++)
            M[i][j] = !((M[i-1][j] + M[i-1][j-1] + M[i][j-1])/2);
    printf("%d\n",M[n-1][n-1]);
    return 0;
}