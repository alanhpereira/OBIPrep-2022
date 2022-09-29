#include <stdio.h>
#define MAX 10

int cnt[10][10];

int fat(int a){
    if(a <= 1) return 1;
    return a * fat(a-1);
}

int main(){
    int n, nfat, nfatm1;
    scanf("%d",&n);
    nfat = fat(n);
    nfatm1 = fat(n-1);
    for(int i = 0; i < nfat -1; i++){
        for(int j =0 ; j < n ; j++){
            int a;
            scanf("%d", &a);
            cnt[j][a]++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 1 ; j <= n ; j++){
            if(cnt[i][j]!= nfatm1){
                printf("%d ", j);
            }
        }
    }
    printf("\n");
    return 0;

}