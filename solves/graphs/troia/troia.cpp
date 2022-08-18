#include <stdio.h>
#define MAX 51234

int p[MAX];

int find(int a){
    if(p[a] == a) return a;
    return p[a] = find(p[a]);
}

void join(int a, int b){
    if(find(a) == find(b)) return;
    p[find(b)] = find(a);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <=n; i++){
        p[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        join(a, b);
    }
    int f = 0;

    for(int i = 1; i <=n; i++){
        if(p[i] == i) f++;
    }
    printf("%d\n", f);
    return 0;
}