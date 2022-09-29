#include <stdio.h>
#define MAX 1000
// A-F B-D C-E

int dados[MAX][6];
int o[] = {5, 3, 4, 1, 2, 0}; 

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            scanf("%d", &dados[i][j]);
        }
    }
    int ans = 0;
    for(int b = 1; b <= 6; b++){
        int t = b;
        int sum = 0;
        for(int i = 0 ; i< n; i++){
            int ot = 0;
            for(int j = 0; j < 6; j++){
                if(dados[i][j] == t){
                    ot = dados[i][o[j]];
                    break;
                }
            }
            int best = 0;
            for(int j = 1; j <= 6; j++){
                if(j != t && j != ot) best = j;
            }
            sum += best;
            t = ot;
        }
        if(sum > ans) ans = sum;
    }
    printf("%d\n", ans);
    return 0;
}