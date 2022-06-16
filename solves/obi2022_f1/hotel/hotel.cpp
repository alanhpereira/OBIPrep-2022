#include <stdio.h>
#define min(a, b) (a < b ? a : b)

int main(){
    int d,a,n;
    scanf("%d %d %d", &d, &a, &n);
    int preco = d +  min(14, n-1) * a;
    printf("%d\n",(32-n) * preco);
}