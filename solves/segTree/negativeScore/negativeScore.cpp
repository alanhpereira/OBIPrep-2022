#include <stdio.h>
#define MAX 100100
#define INF 1123456789

int seg[4*MAX];

int min(int a, int b){
    return a < b ? a : b;
}

void update(int idx, int l, int r, int i, int v){
    if(l > i || r < i) return;
    if(l == r){
        seg[idx] = v;
        return;
    }
    int mid = (l+r)/2;
    update(2*idx, l , mid, i , v);
    update(2*idx + 1, mid+1 , r, i , v);
    seg[idx] = min(seg[2*idx], seg[2*idx+1]);
}

int query(int idx, int l, int r, int i, int j){
    if(l> j || r < i) return INF;
    if(l >= i && r <= j) return seg[idx];
    int mid = (l+r)/2;
    return min(query(2*idx, l, mid, i, j), query(2*idx +1, mid + 1, r, i, j));
}

int main(){
    int t;
    scanf("%d",&t);
    for(int k = 0 ; k <t; k++){
        int n, q;
        scanf("%d%d",&n,&q);
        for(int i = 1 ; i<=n ;i++){
            int a;
            scanf("%d",&a);
            update(1,1,n,i,a);
        }
        printf("Scenario #%d:\n",k+1);
        for(int i = 1 ; i<=q ;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%d\n",query(1,1,n,a,b));
        }
    }
    return 0;
}