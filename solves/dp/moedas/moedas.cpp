#include <stdio.h>
#define MAXM 50500
#define MAXN 123

int mem[MAXM];
char calc[MAXM];
int v[MAXN];
int n;

int best(int a, int b){
    if(a == -1) return b;
    if(b == -1) return a;
    if(a < b) return a;
    return b;
}

int dp(int k){
    //printf("dp(%d, %d);\n",k,i);
    if(!calc[k]){
        calc[k] = 1;
        mem[k] = -1;
        if(k== 0 ) return mem[k] = 0;
        for(int i = 0 ; i <n; i++){
            if(v[i] <= k && dp(k-v[i]) != -1){
                mem[k] = best(mem[k], dp(k-v[i]) +1);
            }
        }
        //printf("dp(%d) = %d\n",k, mem[k]);
    }
    return mem[k];
}

int main(){
    int m;
    while(scanf("%d %d", &m, &n) != EOF && m ){
        for(int i = 0; i <= m; i++){
            calc[i] = 0;
        }
        for(int i = 0 ; i<n; i++){
            scanf("%d", &v[i]);
        }
        if(dp(m) == -1){
            printf("Impossivel\n");
        }
        else{
            printf("%d\n",dp(m));
        }
    }
    return 0;
}