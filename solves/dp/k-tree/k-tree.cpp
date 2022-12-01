#include <stdio.h>
#define MAX 127
#define MOD 1000000007
 
long long mem[MAX][2];
int k,d;
 
long long dp(int r, int flag){
    if(mem[r][flag]==-1){
        if(r==0)return mem[r][flag]=flag;
        mem[r][flag]=0;
        int ct=k;
        if(ct>r)ct=r;
        for(int i=1;i<=ct;i++){
            mem[r][flag]+=dp(r-i,flag||i>=d);
            mem[r][flag]%=MOD;
        }
    }
    return mem[r][flag];
}
 
int main(){
    int n;
    scanf("%d%d%d",&n,&k,&d);
    for(int i=0;i<MAX;i++){
        mem[i][0]=mem[i][1]=-1;
    }
    printf("%d\n",dp(n,0));
    return 0;
}