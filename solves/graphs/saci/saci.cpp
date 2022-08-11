#include <stdio.h>
#include <queue>
#include <utility>
#define MAX 1123
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;

int mtx[MAX][MAX], dist[MAX][MAX];
int n, m;

int bfs(){
    int i, j;
    queue<pii> q;
    for(i = 0; i < n; i++){
        for(j = 0; j < m ; j++){
            dist[i][j] = -1;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m ; j++){
            if(mtx[i][j] == 2){

                dist[i][j] = 1;
                q.push(pii(i,j));
            }
        }
    }
    while(!q.empty()){
        i = q.front().F;
        j = q.front().S;
        q.pop();
        int d = dist[i][j];
        if(i > 0 && dist[i-1][j] == -1 && mtx[i-1][j]){
            dist[i-1][j] = d + 1;
            q.push(pii(i-1,j));
        }
        if(i < n-1 && dist[i+1][j] == -1 && mtx[i+1][j]){
            dist[i+1][j] = d + 1;
            q.push(pii(i+1,j));
        }
        if(j > 0 && dist[i][j-1] == -1 && mtx[i][j-1]){
            dist[i][j-1] = d + 1;
            q.push(pii(i,j-1));
        }
        if(j < m-1 && dist[i][j+1] == -1 && mtx[i][j+1]){
            dist[i][j+1] = d + 1;
            q.push(pii(i,j+1));
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m ; j++){
            if(mtx[i][j] == 3)
                return dist[i][j];
        }
    }
    return dist[0][0];
}

int main(){
    scanf("%d%d",&n,&m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            scanf("%d",&mtx[i][j]);
        }
    }
    printf("%d\n",bfs());
    return 0;
}