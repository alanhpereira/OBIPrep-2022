#include <stdio.h>
typedef long long ll;

int main(){
    ll n, p, q, r, s, x, y;
    ll i, j;
    scanf("%lld",&n);
    scanf("%lld%lld%lld%lld%lld%lld",&p,&q,&r,&s,&x,&y);
    scanf("%lld%lld",&i,&j);
    ll c = 0;
    for(int k = 1; k <= n; k++){
        c += ((p*i + q*k) % x) * ((r*k + s*j) % y);
    }
    printf("%lld\n",c);
    return 0;
}
