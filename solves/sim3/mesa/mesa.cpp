#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d",&a, &b);
    a %= 3;
    b %= 3;
    if(a == b) b = (b+1) % 3;
    int c = 0;
    while(c == a || c == b) c++;
    printf("%d\n", c);
}