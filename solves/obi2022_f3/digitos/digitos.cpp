#include <stdio.h>
#include <vector>
#define MAX 1123
using namespace std;

vector<int> N;
int n;
int v[MAX];

void incN(){
    int co = 1;
    int i = 0;
    while (co){
        if(i == N.size()){
            N.push_back(0);
            //printf("size limit reached, increasing\n");
        }
        N[i]++;
        co = 0;
        if(N[i] == 10){
            //printf("Carrying over\n");
            N[i] = 0;
            co = 1;
        }
        i++;
    }
}

bool cmp(int k){
    for(int i = 0; i < N.size(); i++){
        //printf("%d==%d?",N[i], v[k+N.size()-i-1]);
        if(N[i] != v[k+N.size()-i-1]) return false;
    }
    return true;
}

void init(int k){
    N.clear();
    for(int i = k; i>= 0; i--){
        N.push_back(v[i]);
    }
}

bool test(int k){
    init(k);
    int i;
    for(i = 0 ; i + N.size() <= n; i+= N.size(), incN()){
        //printf("attempting start at %d\n", i);
        if(!cmp(i)){
            //printf("Fail\n\n"); 
            return 0;
        }
        //printf("Success\n\n");
        
    }
    if(i != n) return 0;
    return true;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
    }
    for(int i = 0; i < n; i++){
        if(test(i)){
            for(int j = 0; j <= i; j++)
                printf("%d",v[j]);
            printf("\n");
            return 0;
        }
    }
    return 0;
}