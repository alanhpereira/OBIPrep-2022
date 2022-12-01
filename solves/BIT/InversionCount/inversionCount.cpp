#include <stdio.h>
#define MAX 11234567
 
int bit[MAX];
 
int query(int idx){
	int sum =0;
	while(idx>0){
		sum+=bit[idx];
		idx-=(idx&-idx);
	}
	return sum;
}
 
void update(int idx,int v){
	while(idx<MAX){
		bit[idx]+=v;
		idx+=(idx&-idx);
	}
}
 
void reset(){
	for(int i=1;i<MAX;i++){
		bit[i]=0;
	}
}
 
int main(){
	int nt;
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		int n;
		scanf("%d",&n);
		reset();
		long long ans=0;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			ans+=i-query(a);
			update(a,1);
		}
		printf("%lld\n", ans);
	}
} 