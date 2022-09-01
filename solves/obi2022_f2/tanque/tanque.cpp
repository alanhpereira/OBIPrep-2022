#include <stdio.h>

int main(){
    int c, d, t;
    scanf("%d %d %d", &c, &d, &t);
    float n = (((float) d) / c) - t;
    if( n < 0 ) n = 0;
    printf("%.1f\n", n );
}