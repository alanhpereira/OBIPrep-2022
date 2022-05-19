#include <stdio.h>
#include <utility>
#define MAX 100100
#define INF 1123456789
using namespace std;
#define F first
#define S second
typedef pair<int, int> pii;

pii seg[4*MAX];

pii max(pii a, pii b){
    if(a>b)return a;
    return b;
}
int max(int a, int b){
    if(a>b)return a;
    return b;
}

void update(int idx, int l, int r, int i, pii x){
    //printf("update(%d,%d,%d,%d,pii);\n",idx,l,r,i);
    if(i < l || i > r) return;
    if(l == r){ 
        seg[idx] = x;
        return;
    }
    int mid = (l+r)/ 2;
    update(2*idx, l , mid, i, x);
    update(2*idx+1, mid+1 , r, i, x);
    seg[idx] = max(seg[2*idx],seg[2*idx+1]);
}

pii query(int idx, int l, int r, int i, int j){
    if(idx == 0)return pii(-INF,0);
    if(i > r || j < l || r < l)return pii(-INF,0);
    if(l>= i && r <= j) return seg[idx];
    int mid = (l+r)/2;
    return max(query(2*idx,l,mid,i,j), query(2*idx+1,mid+1,r,i,j));
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <=n; i++){
        int a;
        scanf("%d",&a);
        update(1,1,n,i,pii(a,i));
    }
    int q;
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        char c;
        scanf(" %c", &c);
        if(c == 'U'){
            int i,x;
            scanf("%d%d",&i,&x);
            update(1,1,n,i,pii(x,i));
        }
        else{
            int x,y;
            scanf("%d%d",&x,&y);
            pii m = query(1,1,n,x,y);
            pii l = query(1,1,n, x, m.S - 1);
            pii r = query(1,1,n, m.S + 1, y);
            printf("%d\n", m.F + max(r,l).F);
        }
    }
    return 0;
}