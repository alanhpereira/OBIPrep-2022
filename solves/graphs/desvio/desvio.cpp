#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#define MAX 256
#define F first
#define S second
#define INF 1123456
using namespace std;
typedef pair<int, int > pii;

vector<pii> adj[MAX];
bool processed[MAX];
int dist[MAX];
int n, c;

int dijkstra(int k){
    priority_queue<pii> q;
    for(int i = 0 ; i <= n+1; i++){
        dist[i] = INF;
        processed[i] = 0;
    }
    q.push({0,k});
    dist[k ] = 0;
    while(!q.empty()){
        int a = q.top().S;
        q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(int i = 0 ; i < adj[a].size(); i++){
            int e = adj[a][i].S;
            int w = adj[a][i].F;
            if((!(a < c-1) || e == a+1) && dist[e] > dist[a] + w && !processed[e]){
                dist[e] = dist[a] + w;
                q.push({-dist[e], e});
            }
        }
    }
    return dist[c-1];
}

int main(){
    int m,k;
    while(scanf("%d%d%d%d", &n, &m, &c, &k)!= EOF && n > 0){
        for(int i = 0; i < n; i++){
            adj[i].clear();
        }

        for(int i = 0 ; i < m ; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back({w, v});        
            adj[v].push_back({w, u});        
        }
        printf("%d\n",dijkstra(k));
        for(int i = 0 ; i <n ;i++){

            //printf("%d\n ",dist[i]);
        }
    }
    return 0;
}