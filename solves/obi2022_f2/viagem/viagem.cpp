#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#define MAX 11234
#define MAXV 212
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

vector<piii> adj[MAX];
int t[MAX][MAXV];
int n,m,v;

int best(int a, int b){
    if(a == -1) return b;
    if(b == -1) return a;
    if(a < b) return a;
    return b;
}

int dijkstra(int a, int b){
    priority_queue<piii> q;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= v; j++)
            t[i][j] = -1;

    q.push({0,{0,a}});
    while(!q.empty()){
        a = q.top().S.S;
        int va = -q.top().S.F;
        int ta = -q.top().F;
        q.pop();
        if(t[a][va] != -1) continue;
        t[a][va] = ta;
        for(int i = 0; i < adj[a].size();i++){
            if(va + adj[a][i].S.F <= v){
                q.push({-ta - adj[a][i].S.S, {-va - adj[a][i].S.F, adj[a][i].F}});
            }
        }
    }
    int ans = -1;
    for(int i = 0 ; i<= v; i++){
        ans = best(ans, t[b][i]);
    }
    return ans;
}

int main(){
    scanf("%d%d%d",&v,&n,&m);
    for(int i = 0 ; i <m; i++){
        int u,v,t,p;
        scanf("%d%d%d%d", &u, &v, &t,&p);
        adj[u].push_back({v,{p,t}});
        adj[v].push_back({u,{p,t}});
    }
    int a, b;
    scanf("%d %d", & a, &b);
    printf("%d\n",dijkstra(a,b));
    return 0;
}