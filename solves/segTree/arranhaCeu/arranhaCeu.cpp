#include <stdio.h>
#define MAX 100100

long long seg[4*MAX];

void update(int idx, int l, int r, int i, int v){
    if(l > i || r < i) return;
    if(l == r){
        seg[idx] = v;
        return;
    }
    int mid = (l+r)/2;
    update(2*idx, l , mid, i , v);
    update(2*idx + 1, mid+1 , r, i , v);
    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

long long query(int idx, int l, int r, int i, int j){
    if(l> j || r < i) return 0;
    if(l >= i && r <= j) return seg[idx];
    int mid = (l+r)/2;
    return query(2*idx, l, mid, i, j) + query(2*idx +1, mid + 1, r, i, j);
}

int main(){
    int n, q;
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n ;i++){
        int a;
        scanf("%d",&a);
        update(1,1,n,i,a);
    }
    for(int i = 0; i < q; i++){
        int o;
        scanf("%d",&o);
        if(o == 0){
            int k, p;
            scanf("%d %d", &k, &p);
            update(1,1,n,k,p);
        }
        else{
            
            int k;
            scanf("%d", &k);
            printf("%lld\n",query(1,1,n,1,k));
        }
    }
    return 0;
}