#include <stdio.h>
#define MAX 20
#define N 15

int m[MAX][MAX];

int di[] = {-1, -1, 0, 1, 1,  1,  0, -1};
int dj[] = {0 ,  1, 1, 1, 0, -1, -1, -1};

int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &m[i][j]);
        }
    }
    int winner = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(m[i][j]){
                for(int k = 0; k < 8; k++){
                    if(i + 4*di[k] >= 0 && i + 4*di[k] < N && j + 4*dj[k] >= 0 && j + 4*dj[k] < N){
                        bool flag = 1;
                        for(int l = 1; l < 5; l++){
                            flag = flag && (m[i][j] == m[i+ di[k] * l][j+ dj[k] * l]);
                        }
                        if(flag) winner = m[i][j]; 
                    }
                    
                }
            }
        }
    }
    printf("%d\n", winner);
    return 0;
}