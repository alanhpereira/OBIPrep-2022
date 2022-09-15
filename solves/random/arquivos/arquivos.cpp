#include <stdio.h>
#include <algorithm>
#define MAX 112345
using namespace std;

int arq[MAX];

int main(){
    int n, b;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++){
        scanf("%d", &arq[i]);
    }
    sort(arq, arq+n);
    int i = 0, j = n-1;
    int pasta = 0;
    while(i <= j){
        if(arq[i] + arq[j] <= b){
            i++;
        }
        pasta++;
        j--;
    }
    printf("%d\n", pasta);
    return 0;
}