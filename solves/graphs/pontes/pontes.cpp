#include <stdio.h>
#include <queue>
#include <vector>
#define MAX 1123
#define F first
#define S second
#define INF 1123456
using namespace std;
typedef pair<int, int > pii;

vector<pii> adj[MAX];
bool processed[MAX];
int dist[MAX];
int n;

int dijkstra(){
    priority_queue<pii> q;
    for(int i = 0 ; i <= n+1; i++){
        dist[i] = INF;
    }
    dist[0] = 0;
    q.push({0, 0});
    while(!q.empty()){
        int a = q.top().S;
        q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(int i = 0 ; i < adj[a].size(); i++){
            int e = adj[a][i].S;
            int w = adj[a][i].F;
            if(dist[e] > dist[a] + w){
                dist[e] = dist[a] + w;
                q.push({-dist[e], e});
            }
        }
    }
    return dist[n+1];
}

int main(){
    int m;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < m ; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({w, v});        
        adj[v].push_back({w, u});        
    }
    printf("%d\n", dijkstra());
    return 0;
}
