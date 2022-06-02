#include <stdio.h>
#include <algorithm>
#define MAX 100100
using namespace std;

int v[MAX];

int main(){
    int n, b;
    scanf("%d%d",&n,&b);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
    }
    sort(v, v+n);
    int ans = n;
    for(int i = 0, j = n-1; i<j; i++){
        while(v[i]+v[j] > b && i<j){
            j--;
        }
        if(i != j){
            ans--;
            j--;
        }
    }
    printf("%d\n",ans);
    return 0;
}