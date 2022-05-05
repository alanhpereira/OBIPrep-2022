#include <stdio.h>
#include <vector>
#define MAX 1023
using namespace std;

vector<int> adj[MAX];
bool vis[MAX];

void dfs(int a){
    vis[a] = true;
    for(int i = 0; i < adj[a].size(); i++){
        if(!vis[adj[a][i]]){
            dfs(adj[a][i]);
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int cc = 0;
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            cc++;
            dfs(i);
        }
    }
    printf("%d\n", cc);
    return 0;
}