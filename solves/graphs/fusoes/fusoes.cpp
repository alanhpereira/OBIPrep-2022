#include <stdio.h>
#define MAX 112345

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
    int n, k;
    scanf("%d%d", &n,&k);
    for(int i = 1; i <= n ; i++)
        p[i] = i;
    
    for(int i = 0; i < k; i++){
        char c;
        int a, b;
        scanf(" %c %d %d",&c,&a,&b);
        if(c == 'C'){
            printf("%c\n", find(a) == find (b) ? 'S' : 'N');
        }
        else{
            join(a, b);
        }
    }
}