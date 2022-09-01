#include <stdio.h>
#define MAX 512345

int v[MAX];

int max(int a, int b){
    if(a > b) return a;
    return b;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        scanf("%d",&v[i]);
    }
    int c = 0;
    int em = 0;
    for(int i = 0; i<2*n; i++){
        if(v[i%n] + v[(i+1)%n] < 1000) c++;
        else c = 0;
        em = max(em, c);
    }
    if(em>n)em = n;
    printf("%d\n", em);
    return 0;
}