#include <stdio.h>
#include <vector>
#define MAX 212345
using namespace std;

vector<int> adj[MAX];
int vis[MAX];
int mrk[MAX];

int f = -1;

void dfs(int a, int i){
    //printf("%d %d %d\n", i, a, vis[a]);
    if(vis[a] == i) return;
    //printf("%d %d\n", i, a);
    vis[a] = i;
    if(!mrk[a]){
        f = a;
    }
    for(int j = 0; j < adj[a].size(); j++){
        dfs(adj[a][j], i);
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }
    for(int a = 1; a <= n; a++){
        mrk[a] = 1;
        for(int i = 0; i < adj[a].size(); i++)
            mrk[adj[a][i]] = 1;
        dfs(a, a);
        mrk[a] = 0;
        for(int i = 0; i < adj[a].size(); i++)
            mrk[adj[a][i]] = 0;
        if(f != -1){
            printf("%d %d\n",a ,f);
            return 0;
        }
    
    }
    printf("-1\n");
    return 0;
}