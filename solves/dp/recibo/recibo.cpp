#include <stdio.h>
#define MAXK 25
#define MAXR 128

int mem[MAXK][MAXR][MAXR];
int r,k;

int dp(int i,int v,int l){
    if(mem[i][v][l]==-1){
        if(i>=k||v>r){
            if(v==r)return mem[i][v][l]=1;
            else    return mem[i][v][l]=0;
        }
        mem[i][v][l]=0;
        for(int x=l+1;v+x<=r;x++){
            mem[i][v][l]+=dp(i+1,v+x,x);
        }
    }
    return mem[i][v][l];
}

int main(){
    scanf("%d%d",&r,&k);
    for(int i=0;i<=k;i++){
        for(int j=0;j<=r;j++){
            for(int l=0;l<=r;l++){
                mem[i][j][l]=-1;
            }
        }
    }
    printf("%d\n",dp(0,0,0));
    return 0;
}
