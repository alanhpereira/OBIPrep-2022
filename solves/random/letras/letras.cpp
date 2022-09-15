#include <stdio.h>
#include <string.h>
#define MAX 312345
#define MAXL 30

int mem[MAX][MAXL];
char s[MAX];

int max(int a, int b){
    return a<b ? b : a;
}

int main(){
    int n;
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0 ; i < n; i++){
        s[i] -= 'A';
    }
    for(int j = 0; j < 30; j++){
        mem[n][j] = 0;
    }
    for(int i = n-1 ; i >= 0; i--){
        for(int j = 0; j < 30; j++){
            mem[i][j] = mem[i+1][j];
            if(s[i] >= j){
                mem[i][j] = max(mem[i][j], mem[i+1][s[i]] + 1);
            }
        }
    }
    printf("%d\n", mem[0][0]);
}