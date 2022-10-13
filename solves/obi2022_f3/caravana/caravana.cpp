#include <stdio.h>
#define MAX 1123

int v[MAX];

int main(){
    int n, m = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        m += v[i];
    }
    m /= n;
    
    for(int i = 0; i < n; i++){
        printf("%d\n", m - v[i]);
    }
}