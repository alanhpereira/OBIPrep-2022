#include <stdio.h>

int main(){
    int x, t;
    scanf("%d", &x);
    while(scanf("%d", &t) != EOF && t != x){
        if(t > x) printf("menor\n");
        if(t < x) printf("maior\n");
    }
    printf("correto\n");
    return 0;
}