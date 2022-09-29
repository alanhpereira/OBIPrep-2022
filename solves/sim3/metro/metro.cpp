#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 112345
using namespace std;

int dista[MAX];
int pa[MAX];
int distb[MAX];
int pb[MAX];
int n, m;

vector<int> adja[MAX], adjb[MAX];

int bfsa(int a){
    for(int i = 0 ; i <= n; i++){
        dista[i] = pa[i] = -1;
    }
    queue<int> q;
    q.push(a);
    dista[a] = 0;
    while(!q.empty()){
        a = q.front();
        q.pop();
        for(int i = 0; i < adja[a][i]; i++){
            if(dista[adja[a][i]] == -1){
                dista[adja[a][i]] = dista[a] + 1;
                pa[adja[a][i]] = a;
                q.push(adja[a][i]);
            }
        }
    }
    return a;
}

int bfsb(int a){
    for(int i = 0 ; i <= m; i++){
        distb[i] = pb[i] = -1;
    }
    queue<int> q;
    q.push(a);
    distb[a] = 0;
    while(!q.empty()){
        a = q.front();
        q.pop();
        for(int i = 0; i < adjb[a][i]; i++){
            if(distb[adjb[a][i]] == -1){
                distb[adjb[a][i]] = distb[a] + 1;
                pb[adjb[a][i]] = a;
                q.push(adjb[a][i]);
            }
        }
    }
    return a;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adja[a].push_back(b);
        adja[b].push_back(a);
    }
    for(int i = 1; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adjb[a].push_back(b);
        adjb[b].push_back(a);
    }
    int aa = bfsa(1);
    int ba = bfsa(aa);
    int da = dista[ba];
    int ca = ba;
    while(dista[ca] > da/2){
        ca = pa[ca];
    } 
    int ab = bfsb(1);
    int bb = bfsb(ab);
    int db = distb[bb];
    int cb = bb;
    while(distb[cb] > db/2){
        cb = pb[cb];
    }
    printf("%d %d\n", ca, cb);
    return 0;
}