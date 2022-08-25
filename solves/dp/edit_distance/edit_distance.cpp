#include <stdio.h>
#include <string.h>
#define MAX 2123
#define INF 112345

char s1[MAX], s2[MAX];
int n, m;
int mem[MAX][MAX];

int min(int a, int b){
    if(a < b) return a;
    return b;
}

int dp(int i, int j){
    if(mem[i][j] != -1) return mem[i][j];
    if(i == n || j == m) return mem[i][j] = n - i + m - j;
    mem[i][j] = dp(i + 1, j + 1) + (s1[i] != s2[j]);
    mem[i][j] = min(mem[i][j], dp(i + 1, j) + 1);
    mem[i][j] = min(mem[i][j], dp(i, j + 1) + 1);
    return mem[i][j];
}

int main(){
    int t;
    scanf("%d", &t);
    for(int k = 0; k < t; k++){
        scanf("%s", s1);
        scanf("%s", s2);
        n = strlen(s1);
        m = strlen(s2);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                mem[i][j] = -1;
        printf("%d\n", dp(0,0));
    }
    return 0;
}
