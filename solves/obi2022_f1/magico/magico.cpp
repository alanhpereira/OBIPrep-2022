#include <stdio.h>
#define MAX 10

int m[MAX][MAX];


int main(){
    int n;
    scanf("%d",&n);
    int mi,mj;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            scanf("%d",&m[i][j]);
            if(m[i][j] == 0){
                mi = i;
                mj = j;
            }
        }
    }
    int f = n*(n*n+1)/2;
    for(int i = 0; i < n; i++){
        f-= m[i][mj];
    }
    printf("%d\n%d\n%d\n", f, mi+1, mj+1);
    return 0;
}