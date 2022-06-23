#include <stdio.h>
#define MAXV 100100
#define MAXM 1123
 
char mem[MAXV][MAXM];
char calc[MAXV][MAXM];
int v[MAXM], n;
 
char dp(int k, int i){
    if(!calc[k][i]){
        calc[k][i] = 1;
        if(k == 0) return mem[k][i] = 1;
        if( i >= n)return mem[k][i] = 0;
        if(v[i] <= k) 
            mem[k][i] |= dp(k - v[i], i+1);
        if (! mem[k][i]) 
            mem[k][i] = dp(k, i+1);
    }
    return mem[k][i];
}
 
int main(){
    int m;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
 
    printf("%c\n", dp(m,0) ? 'S' : 'N');
} 