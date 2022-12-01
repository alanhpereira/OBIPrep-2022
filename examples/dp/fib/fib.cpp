#include <stdio.h>
#define MOD 1000000007

int ct;
int fib[5000];

int main(){
    int n;
    scanf("%d", &n);
    fib[1] = fib [2] = 1;
    for(int i = 3; i <= n ; i++){
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
    printf("%d ",fib[n]);
    printf("%d\n",ct);
    return 0;
}