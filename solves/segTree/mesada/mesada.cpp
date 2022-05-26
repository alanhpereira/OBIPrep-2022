// WIP

#include <stdio.h>
#include <utility>
#define MAX 100100
#define INF 1123456789123456789
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;


pli seg[4*MAX];
pli lazy[4*MAX];

pli max(pli a, pli b){
    if(a.F > b.F) return a;
    if(a.F < b.F) return b;
    if(a.S < b.S) return a;
    return b;
}

void propagate(int idx,int l, int r){
    seg[idx].F += lazy[idx].F;
    seg[idx].S += lazy[idx].S;
    if(l == r){
        lazy[idx] = pli(0,0);
    }
    if(!lazy[idx].F)return;
    lazy[2*idx].F += lazy[idx].F;
    lazy[2*idx].S += lazy[idx].S;
    lazy[2*idx + 1].F += lazy[idx].F;
    lazy[2*idx + 1].S += lazy[idx].S;
    lazy[idx] = pli(0,0);
}

void update(int idx, int l, int r, int i, int j, pli v){
    propagate(idx, l, r);
    if(l > j || r < i) return;
    if(l>= i && r <= j){
        lazy[idx].F += v.F;
        lazy[idx].S += v.S;
        propagate(idx, l ,r);
        return;
    }
    int mid = (l+r)/2;
    update(2*idx, l, mid, i, j ,v);
    update(2*idx+1, mid + 1, r, i, j, v);
    seg[idx] = max(seg[2*idx],seg[2*idx+1]);
}

pli query(int idx, int l, int r, int i, int j){
    propagate(idx, l, r);
    if(l > j || r < i) return pli(-INF, 0);
    if(l >= i && r <= j) return seg[idx];
    int mid = (l+r)/2;
    return max(query(2*idx, l, mid, i, j),query(2*idx+1, mid+1, r, i, j));
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n ; i++){
        int m;
        scanf("%d", &m);
        update(1,1,n,i,i,pli(m,i));
    }
    for(int i = 0; i < q; i++){
        char c;
        scanf(" %c",&c);
        if(c == 'A'){
            int l, r ,v;
            scanf("%d%d%d",&l,&r,&v);
            update(1,1,n,l,r,pli(v,0));
        }
        else if(c == 'C'){
            int l, r;
            scanf("%d%d",&l,&r);
            pli q = query(1,1,n,l,r);
            printf("%d\n",q.S);
        }
    }
    return 0;
}