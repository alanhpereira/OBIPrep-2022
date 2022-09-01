#include <stdio.h>
#include <algorithm>
#define MAX 10
using namespace std;

int v[MAX];

int main(){
    int n = 5;
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v, v+n);
    int p, s = 0;
    int cp = 1;
    int cs = 0;
    p = v[4];
    for(int i = 3; i >= 0; i--){
        if(v[i] != p && s == 0){
            s = v[i];
        }
        else if(v[i] == p)
            cp++;
        if(v[i] == s){
            cs++;
        }
    }
    printf("%d %d\n", cp, cs);
    return 0;
    
}