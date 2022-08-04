#include <stdio.h>
#define MAX 112345

int c[MAX],n;

int gerado(int k){
    int s = 0;
    for(int i = 0; i < n; i++)
        s+= k/c[i];
    return s;
}

int bb(int i, int j, int v){
    if(i == j) return i;
    int mid = (i+j)/2;
    int gmid = gerado(mid);
    if(gmid < v)
        return bb(mid+1, j, v);
    return bb(i, mid, v);
}

int main(){
    int f;
    scanf("%d%d",&n,&f);
    for(int i = 0 ;i<n;i++)
        scanf("%d",&c[i]);
    printf("%d\n",bb(1,100000000,f));
    return 0;
}