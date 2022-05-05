#include <stdio.h>
#include <utility>
#include <queue>
#define MAX 512
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
char m[MAX][MAX];

int main(){
    int n,f;
    scanf("%d%d",&n,&f);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c",&m[i][j]);
        }
    }
    queue<pii> q;
    f += '0';
    if(m[0][0] <= f){
        m[0][0] = '*';
        q.push(pii(0,0));
    }
    while(!q.empty()){
        int i,j;
        i = q.front().F;
        j = q.front().S;
        q.pop();
        if(i > 0){
            if(m[i-1][j] <= f && m[i-1][j] != '*'){
                m[i-1][j] = '*';
                q.push(pii(i-1,j));
            }
        }
        if(i + 1 < n){
            if(m[i+1][j] <= f && m[i+1][j] != '*'){
                m[i+1][j] = '*';
                q.push(pii(i+1,j));
            }
        }
        if(j > 0){
            if(m[i][j-1] <= f && m[i][j-1] != '*'){
                m[i][j-1] = '*';
                q.push(pii(i,j-1));
            }
        }
        if(j + 1 < n){
            if(m[i][j+1] <= f && m[i][j+1] != '*'){
                m[i][j+1] = '*';
                q.push(pii(i,j+1));
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%c",m[i][j]);
        }
        printf("\n");
    }
}