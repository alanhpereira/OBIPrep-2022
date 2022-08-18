#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 512
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

vector <piii> edges;
int p[MAX];

int min(int a, int b){
    if(a < b) return a;
    return b;
}

int find(int a){
    if(p[a] == a) return a;
    return p[a] = find(p[a]);
}

void join(int a, int b){
    p[find(b)] = find(a);
}

int main(){
    int n, m, t = 0;
    while(scanf("%d %d", &n, &m) != EOF && n != 0){
        edges.clear();
        for(int i = 1; i <= n; i++){
            p[i] = i;
        }
        for(int i = 0; i < m; i++){            
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edges.push_back(piii(w,pii(u,v)));
        }
        sort(edges.begin(), edges.end());
        t++;
        printf("Teste %d\n", t);
        for(int i = 0; i < edges.size(); i++){
            //printf("f: %d %d\n", edges[i].S.F, edges[i].S.S);
            if(find(edges[i].S.F) != find(edges[i].S.S)){
                int a = min(edges[i].S.F, edges[i].S.S);
                int b = edges[i].S.F + edges[i].S.S - a;
                printf("%d %d\n", a, b);
                join(edges[i].S.F, edges[i].S.S);
            }
        }
        printf("\n");
    }
    return 0;
}