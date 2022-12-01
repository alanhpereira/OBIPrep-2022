#include <stdio.h>
#define MAX 100100
typedef long long ll;

ll seg[4*MAX];

ll query(int idx, int l, int r, int i, int j){
    if(l > j || r < i) return 0;
    if(l >= i && r <= j) return seg[idx];
    int mid = (l+r)/2;
    return query(2*idx, l, mid, i, j) + query(2*idx+1, mid+1, r, i, j);

}

void update(int idx, int l, int r, int i, int x){
    
    if(l > i || r < i) return;
    if(l == r) {
        seg[idx] = x;
        return;
    }
    int mid = (l+r)/2;
    update(2*idx, l, mid, i, x);
    update(2*idx+1, mid+1, r, i, x);
    seg[idx] = seg[2*idx] + seg[2*idx+1];
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