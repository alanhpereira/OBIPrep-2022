#include <stdio.h>

int main(){
    int b,h,r,g;
    scanf("%d%d%d%d", &b, &h, &r, &g);
    if(360 % g == 0 && b >= 2*r && h >= 2*r){
        printf("S\n");
    }
    else{
        printf("N\n");
    }
    return 0;
}