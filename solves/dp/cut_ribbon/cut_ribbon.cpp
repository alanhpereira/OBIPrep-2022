#include <stdio.h>
#define MAX 4123
#define INF 112345

int n, a, b, c;
int mem[MAX];
bool calc[MAX];

int max(int a, int b){
    if(a > b) return a;
    return b;
}

int dp(int r){
    if(calc[r]) return mem[r];
    calc[r] = 1;
    if(r == 0) return mem[r] = 0;
    mem[r] = -INF;
    if(a <= r)
        mem[r] = max(mem[r], dp(r-a) + 1);
    if(b <= r)
        mem[r] = max(mem[r], dp(r-b) + 1);
    if(c <= r)
        mem[r] = max(mem[r], dp(r-c) + 1);
    return mem[r];
}

int main(){
    scanf("%d%d%d%d", &n, &a, &b, &c);
    printf("%d\n",dp(n));
    return 0;
}