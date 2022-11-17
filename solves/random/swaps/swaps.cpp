#include <algorithm>
#include <vector>
#include <stdio.h>
#define MAX 212345
using namespace std;

int v[MAX];
vector<int> v1, v2;

int main(){
    int n, k;
    scanf("%d%d",&n,&k);
    int s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        if(i & 1){
            v2.push_back(v[i]);
            s2 += v[i];
        }
        else{
            v1.push_back(v[i]);
            s1 += v[i];
        }
    }
    //printf("%d %d\n", s1, s2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i = 0, j = v2.size()-1 ; i < k && j >= 0 ; i++, j--){
        if(v1[i] >= v2[j]){
            break;
        }
        s2 += (v1[i] - v2[j]);
        s1 += (v2[j] - v1[i]);
    }
    //printf("%d %d\n", s1, s2);
    printf("%d\n", s1-s2);
}