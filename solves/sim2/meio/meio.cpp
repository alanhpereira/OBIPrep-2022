#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    printf("%lld\n",((1LL<<n)+1)*((1LL<<n)+1));
    return 0;
}