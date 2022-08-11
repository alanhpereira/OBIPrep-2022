#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 100
using namespace std;

vector<int> adj[MAX];
int dist[MAX];
bool vis[MAX];

void rstVis(int n){
    for(int i = 0; i < n; i++){
        vis[i] = dist[i] = 0;
    }
}

void dfs(int a){
    if(vis[a]) return;
    printf("%d\n", a);
    vis[a] = 1;
    for(int i = 0 ; i < adj[a].size();i++)
        dfs(adj[a][i]);
}

void bfs(int a){
    queue<int> q;
    q.push(a);
    dist[a]= 0;
    vis[a] = 1;
    while(!q.empty()){
        a = q.front();
        q.pop();
        int d = dist[a];
        printf("%d\n", a);
        for(int i = 0; i< adj[a].size();i++){
            if(!vis[adj[a][i]]){
                vis[adj[a][i]] = 1;
                dist[adj[a][i]] = d + 1;
                q.push(adj[a][i]);
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printf("dfs:\n");
    rstVis(n);
    dfs(0);
    printf("bfs:\n");
    rstVis(n);
    bfs(0);
    printf("dist:\n");
    for(int i = 0; i < n ; i++){
        printf("%d\n", dist[i]);
    }
}