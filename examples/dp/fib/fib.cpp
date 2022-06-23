#include <stdio.h>
#define MOD 1000000007

int ct;
int mem[5000];

int main(){
    int n;
    scanf("%d", &n);
    mem[1] = mem [2] = 1;
    for(int i = 3; i <= n ; i++){
        mem[i] = mem[i-1] + mem[i-2];
    }
    printf("%d ",mem[n]);
    printf("%d\n",ct);
    return 0;
}