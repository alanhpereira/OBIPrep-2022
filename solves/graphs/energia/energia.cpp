#include <stdio.h>
#include <vector>
#define MAX 112
using namespace std;

vector<int> adj[MAX];
bool vis[MAX];

void dfs(int a){
    if(vis[a]) return;
    vis[a] = 1;
    for(int i = 0 ; i <adj[a].size(); i++)
        dfs(adj[a][i]);
}

int main(){
    int n, m;
    int t = 1;
    while(scanf("%d %d", &n, &m)!= EOF && n != 0){
        for(int i = 0; i <= n; i++){
            vis[i] = 0;
            adj[i].clear();
        }
        for(int i = 0; i <m ;i++){
            int u, v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        int cnx = 1;
        for(int i = 1; i <= n; i++)
            if(!vis[i])
                cnx = 0;
        printf("Teste %d\n",t);
        t++;
        if(cnx)
            printf("normal\n\n");
        else
            printf("falha\n\n");
    }
    return 0;
}