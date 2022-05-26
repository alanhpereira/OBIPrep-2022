#include <stdio.h>
#define MAX 100100
typedef long long ll;

ll seg[4*MAX], lazy[4*MAX];

void propagate(int idx,int l, int r){
    seg[idx] += (r - l + 1) * lazy[idx];
    if(l == r){
        lazy[idx] = 0;
    } 
    if(!lazy[idx]) return;
    printf("%d %d %d\n",idx, seg[idx],lazy[idx]);
    lazy[2*idx] += lazy[idx];
    lazy[2*idx+1] += lazy[idx];
    lazy[idx] = 0;
}

void update(int idx, int l, int r, int i, int j, ll v){
    propagate(idx, l ,r);
    if(l > j || r < i) return;
    if(l>= i && r <= j){
        lazy[idx] = v;
        propagate(idx, l ,r);
        return;
    }
    
    int mid = (l + r) / 2; 
    update(2*idx  , l, mid, i, j, v);
    update(2*idx+1, mid +1, r, i, j, v);
    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

ll query(int idx, int l, int r, int i, int j){
    propagate(idx, l, r);
    if(l > j || r < i) return 0;
    if(l >= i && r <= j) return seg[idx];
    int mid = (l + r) / 2; 
    return query(2 * idx, l, mid , i, j) + query(2 * idx +1, mid+1, r, i, j); 
}


int main(){
    int n, q;
    scanf("%d%d",&n,&q);
    for(int i = 1 ; i<=n; i++){
        ll u;
        scanf("%lld",&u);
        update(1,1,n,i,i,u);
    }
    for(int i = 0; i < q; i++){
        int t;
        scanf("%d",&t);
        if(t){
            int l,r,v;
            scanf("%d%d%d",&l, &r, &v);
            update(1,1,n,l,r,v);
        }
        else{
            int l,r;
            scanf("%d%d",&l, &r);
            printf("%lld\n",query(1,1,n,l,r));
        }
    }
    return 0;
}