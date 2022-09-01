#include <stdio.h>
#define MAX 50

int mtx[MAX][MAX];
int vis[MAX][MAX];
int n, m;

void dfs(int i, int j){
    if(vis[i][j] || mtx[i][j]) return;
    vis[i][j] = 1;
    if(i > 0){
        dfs(i-1, j);
    }
    if(j > 0){
        dfs(i, j-1);
    }
    if(i < n-1){
        dfs(i+1, j);
    }
    if(j < m-1){
        dfs(i, j+1);
    }
}

int main(){
    int k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0 ; i < k; i++){
        char d;
        int a, b;
        scanf("%d %d %c", &a, &b, &d);
        if(d == 'O'){
            for(int j = a -1 ; j >= 0 ; j--){
                mtx[j][b-1] = 1;
            }
        } 
        if(d == 'N'){
            for(int j = b -1 ; j >= 0 ; j--){
                mtx[a - 1][j] = 1;
            }
        } 
        if(d == 'L'){
            for(int j = a -1 ; j < n ; j++){
                mtx[j][b-1] = 1;
            }
        } 
        if(d == 'S'){
            for(int j = b -1 ; j < m ; j++){
                mtx[a - 1][j] = 1;
            }
        } 
    }
    /*for(int i = 0 ;i<n; i++){
        for(int j = 0 ;j<m; j++){
            printf("%d",mtx[i][j]);
        }
        printf("\n");
    }*/
    dfs(0,0);
    printf("%c\n", vis[n-1][m-1] ? 'S' : 'N');
    return 0;
}