#include <stdio.h>

int main(){
    int f, c, e, b;
    scanf("%d %d %d %d", &f, &c, &e, &b);
    int i = ((b-1)%c);
    int j = (b-1)/c+e;
    if(j > f){
        printf("PROXIMO VOO\n");
    }
    else{
        printf("%d %c\n", j , ('A' + i));
    }
    return 0;
}