#include <stdio.h>

int somaDigitos(int n){
    int s = 0;
    for(s = 0; n > 0; n/=10){
        s += n % 10;
    }
    return s;
}

int main(){
    int n, m, s;
    int ans = -1;
    scanf("%d%d%d",&n,&m,&s);
    for( int i = n; i <= m; i++){
        if(somaDigitos(i) == s)
            ans = i;
    }
    printf("%d\n",ans);
    return 0;
}