#include <stdio.h>
#define MAX 1123456

int c[MAX];

int main(){
    int n, d;
    scanf("%d%d",&n, &d);
    for(int i = 0 ; i < n; i++){
        scanf("%d", &c[i]);
    }
    int sum = 0;
    int right = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(right < i + n && sum < d)
            sum+= c[(right++)%n];
        if(sum == d) ans ++;
        sum -= c[i];
    }
    printf("%d\n", ans);
    return 0;
}
