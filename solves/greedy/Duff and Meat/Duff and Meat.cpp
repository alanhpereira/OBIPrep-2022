#include <stdio.h>
#define MAX 100100

int a[MAX];
int p[MAX];

int main(){
    int n;
    scanf("%d",&n);
    int bestp = 100;
    int ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i], &p[i]);
        if(p[i]<bestp)bestp = p[i];
        ans += bestp* a[i];
    }
    printf("%d\n",ans);
}