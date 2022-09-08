#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#define MAX 512
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;

int dist[MAX][3];
vector<pii> adj[MAX];
int n;

int best(int a, int b){
    if(a == -1) return b;
    if(b == -1) return a;
    if(a < b) return a;
    return b;
}

int bfs(int s, int e){
    queue<pii> q;
    for(int i = 0 ; i < n; i++){
        dist[i][0] = -1;
        dist[i][1] = -1;
        dist[i][2] = -1;
    }
    dist[s][0] = 0;
    q.push({s,0});
    while(!q.empty()){
        int a = q.front().F;
        int d = q.front().S;
        q.pop();
        for(int i = 0 ; i < adj[a].size(); i++){
            if((adj[a][i].S == 0 && d%3 !=0) || (adj[a][i].S == 1 && d%3 == 0)){
                if(dist[adj[a][i].F][(d+1)%3] == -1){
                    dist[adj[a][i].F][(d+1)%3] = d + 1;
                    q.push({adj[a][i].F, d+1});
                }
            }
        }
    }
    return best(best(dist[e][0],dist[e][1]),dist[e][2]);
}

int main(){
    int m;
    int s, e;
    scanf("%d%d%d%d", &n, &s, &e, &m);
    for(int i = 0; i < m; i++){
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);
        adj[u].push_back({v, t});
    }
    int ans = bfs(s, e);
    if(ans == -1){
        printf("*\n");
    }
    else{
        printf("%d\n",ans);
    }
    return 0;
}