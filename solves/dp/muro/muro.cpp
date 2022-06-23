#include <stdio.h>
#define MAX 100100
#define MOD 1000000007
typedef long long ll;

ll mem[MAX],n;

ll dp(int i){
    if(mem[i] == -1){
        if(i == n) return mem[i] = 1;
        if(i > n)  return mem[i] = 0;
        mem[i] = dp(i+1);
        mem[i] += 4 * dp(i+2);
        mem[i] += 2 * dp(i+3);
        mem[i] %= MOD;
    }
    return mem[i];
}

int main(){
    scanf("%lld", &n);
    for(int i = 0 ; i <= n ; i++){
        mem[i] = -1;
    }
    printf("%lld\n",dp(0));
    return 0;
}