#include <stdio.h>
#define MAX 10100
typedef long long ll;

ll bit[MAX];
int n;

void update(int i, ll val){
    for(int idx = i; idx <= n; idx += idx & -idx)
        bit[idx]+=val;        
}

ll query(int i){
    ll sum = 0;
    for(int idx = i; idx > 0; idx -= idx & -idx)
        sum+=bit[idx];
    return sum;
}

int main(){
    int t,nt;
    scanf("%d",&nt);
    for(t = 1; t <= nt; t++){
        int q;
        scanf("%d %d",&n,&q);
        for(int i = 1; i <=n ; i++){
            bit[i]=0;
        }
        for(int i = 0; i < q; i++){
            int l,r,val;
            scanf("%d%d%d",&l, &r, &val);
            update(l+1, val);
            update(r+2,-val);
        }
        scanf("%d",&q);
        for(int i = 0; i < q; i++){
            int k;
            scanf("%d",&k);
            printf("%lld\n",query(k+1));
        }
    }
}