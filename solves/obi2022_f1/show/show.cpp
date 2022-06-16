#include <stdio.h>

int main(){
    int a, n, m;
    scanf("%d%d%d",&a,&n,&m);
    int ans = -1;
    for(int i = 0; i < n; i++){
        int ev = 0;
        for(int j = 0; j < m; j++){
            int e;
            scanf("%d",&e);
            if(e)
                ev = 0;
            else {
                ev++;
                if(ev >= a)
                    ans = n - i;
            }
        }
    }
    printf("%d\n",ans);
}