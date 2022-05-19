#include <stdio.h>
#define MAX 100100
typedef long long ll;

ll bit[MAX];
ll v[MAX];
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
    int q;
    scanf("%d %d",&n ,&q);
    for(int i = 1; i <= n ; i++){
        scanf("%lld",&v[i]);
        update(i,v[i]);
    }
    for(int i = 0 ; i < q; i++){
        int qt;
        scanf("%d",&qt);
        if(qt){
            int k;
            scanf("%d",&k);
            printf("%lld\n",query(k));
        }
        else{
            int k,p;
            scanf("%d%d",&k,&p);
            update(k, p-v[k]);
            v[k] = p;
        }
    }
    return 0;
}