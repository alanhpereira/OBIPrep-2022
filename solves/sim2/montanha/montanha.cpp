#include <stdio.h>
#define MAX 1024

int v[MAX];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&v[i]);
    int vp = 0;
    for(int i = 1; i < n - 1; i++)
        if(v[i-1] > v[i] && v[i+1] > v[i])
            vp = 1;
    printf("%c\n", vp ? 'S' : 'N');
    return 0;
}