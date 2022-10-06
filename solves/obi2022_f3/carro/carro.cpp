#include <stdio.h>
#include <vector>
#define MAX 1123
#define abs(a) ((a) < 0 ? -(a) : (a))
using namespace std;

vector<int> adj[MAX];
int vis[MAX];
int x[MAX], y[MAX];

void dfs(int a){
    if(vis[a]) return;
    vis[a] = 1;
    for(int i = 0; i < adj[a].size(); i++){
        dfs(adj[a][i]);
    }
}

int main(){
    int X, Y, n, a;
    scanf("%d %d", &X, &Y);
    scanf("%d %d", &n, &a);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x[i], &y[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if((abs(x[i]-x[j])+abs(y[i]-y[j])) <= a/100){
                adj[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }
    printf("%d\n", ans - 1);
}