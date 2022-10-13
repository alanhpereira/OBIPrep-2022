#include <stdio.h>
#define MAX 512
#define INF 112345678
#define min(a, b) ((a < b) ? (a) : (b));
#define max(a, b) ((a > b) ? (a) : (b));

int mem[MAX][MAX];
int freq[MAX];

int dp(int i, int k){
    if(mem[i][k] != -1) return mem[i][k];
    if(i == 0) return mem[i][k] = 0;
    if(k == 0) return mem[i][k] = INF;
    mem[i][k] = INF;
    int sum = 0;
    for(int j = i; j >= 0; j--){
        sum += (i - j) * (freq[j]);
        mem[i][k] = min(mem[i][k], dp(j - 1, k - 1) + sum);
    }
    return mem[i][k];
}

int main(){
    int n, k, mx = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        int v;
        scanf("%d",&v);
        freq[v]++;
        mx = max(mx, v);
    }
    for(int i = 0; i < 512; i++){
        for(int j = 0; j < 512; j++){
            mem[i][j] = -1;
        }
    }
    printf("%d\n",dp(mx, k));
    return 0;
}
