#include <stdio.h>
#include <algorithm>
#define MAX 100100
#define MAXM 10000
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;

pii o[MAXM];
int f[MAX], p[MAX], po[MAXM];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n -1; i++){
        scanf("%d",&f[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&p[i]);
    }

    for(int i = 0; i < m; i++){
        scanf("%d",&o[i].F);
        o[i].S = i;
    }
    sort(o,o+m);
    for(int j = 0, i = 0; i < m; i++){

        while( j < n - 1 && f[j] <= o[i].F)
            j++;

        po[o[i].S] = p[j];
    }

    for(int i = 0; i < m; i++)
        printf("%d ",po[i]);
    printf("\n");
    return 0;
}