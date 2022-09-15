#include <stdio.h>
#define MAX 100

int mtx[MAX][MAX];
bool bandeira[MAX][MAX];
int n;

void passa(int i, int j){
    bandeira[i][j] = true;
    if(i > 0){
        if(mtx[i - 1][j] >= mtx[i][j] && bandeira[i - 1][j] == 0){
            passa(i -1, j);
        }
    }
    if(j < n - 1){
        if(mtx[i][j + 1] >= mtx[i][j] && bandeira[i][j + 1] == 0){
            passa(i, j + 1);
        }
    }
    if(i < n - 1){
        if(mtx[i + 1][j] >= mtx[i][j] && bandeira[i + 1][j] == 0){
            passa(i + 1, j);
        }
    }
    if(j > 0){
        if(mtx[i][j - 1] >= mtx[i][j] && bandeira[i][j - 1] == 0){
            passa(i, j - 1);
        }
    }
}

int main(){
    scanf("%d", &n);
    int ii, jj;
    scanf("%d %d", &ii, &jj);
    for(int i = 0; i<n; i++){
        for(int j = 0; j< n; j++){
            scanf("%d", &mtx[i][j]);
        }
    }
    passa(ii-1, jj-1);
    int conta = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j< n; j++){
            if(bandeira[i][j]) conta++;
        }
    }
    printf("%d\n", conta);
    return 0;
}