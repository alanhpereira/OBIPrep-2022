#include <stdio.h>
#define MAXID 112345
#define MAXN 51234

int fila[MAXN];
bool sairam[MAXID];

int main(){
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &fila[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int s;
        scanf("%d", &s);
        sairam[s] = true;
    }

    for(int i = 0; i < n; i++){
        if(!sairam[fila[i]])
            printf("%d ", fila[i]);
    }
    printf("\n");
    return 0;
}
