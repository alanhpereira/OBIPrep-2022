#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 512
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

vector<piii> edges;
int p[MAX];

int find(int a){
    if(p[a] == a) return a;
    return p[a] = find(p[a]);
}

void join(int a, int b){
    if(find(a) == find(b)) return;
    p[find(b)] = find(a);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges.push_back(piii(w,pii(u,v)));
    }
    sort(edges.begin(), edges.end());
    int c = 0;
    for(int i = 0; i < edges.size(); i++){
        if(find(edges[i].S.F) != find(edges[i].S.S)){
            c += edges[i].F;
            join(edges[i].S.F, edges[i].S.S);
        }
    }
    printf("%d\n", c);
    return 0;
}