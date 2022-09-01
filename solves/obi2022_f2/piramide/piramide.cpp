#include <stdio.h>
#define MAX 112

int min(int a, int b){
    if(a<b) return a;
    return b;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i <n; i++){
        for(int j = 0 ; j <n; j++)
            printf("%d ", min(min(i+1, n - i), min(j+1, n - j)));
        printf("\n");
    }
    return 0;
}