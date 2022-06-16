#include <stdio.h>
#define MAX 100100

int v[MAX],za[MAX],zd[MAX];
int v0[MAX];

int main(){
    int n, s;
    scanf("%d %d", &n, &s);

    for(int i = 0 ; i <n ; i++){
        scanf("%d\n", &v0[i]);
    }
    if(s){
        int k = 0;
        for(int i = k; i < n ; i++){
            if(v0[i] == 0){
                if(k > 0)
                    zd[k - 1] ++;
                za[k]++;
            }
            else{
                v[k++] = v0[i];
            }
        }
        long long ans = 0;
        int sm = 0;
        for(int i = 0, j = 0; j < k; j++){
            sm += v[j];
            while (sm > s)
                sm -= v[i++];
            if(sm == s)
                ans += (za[i]+1LL)*(zd[j] + 1LL);
        }
        printf("%lld\n",ans);
    }
    else{
        int zc = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(v0[i]){
                zc = 0;
            }
            else{
                zc++;
            }
            ans += zc;
        }

        printf("%lld\n",ans);
    }
    return 0;
}