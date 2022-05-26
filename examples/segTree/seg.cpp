#include <stdio.h>
#define MAX 1024

int seg[4*MAX];
int vec[MAX];
int idxl[4*MAX],idxr[4*MAX];
int midx;

void update(int idx, int l, int r, int i, int v){
    if(l > i || r < i) return;
    if(l == r){
        seg[idx] = v;
        return;
    }
    int mid = (l + r) / 2; 
    update(2*idx  , l, mid, i, v);
    update(2*idx+1, mid +1, r, i, v);
    seg[idx] = seg[2*idx] + seg[2*idx + 1];
}

int query(int idx, int l, int r, int i, int j){
    if(l > j || r < i) return 0;
    if(l >= i && r <= j) return seg[idx];
    int mid = (l + r) / 2; 
    return query(2 * idx, l, mid , i, j) + query(2 * idx +1, mid+1, r, i, j); 
}

void printRange(int idx, int l, int r){
    idxl[idx]=l;
    idxr[idx]=r;
    if(idx> midx) midx = idx;
    if(l==r)return;
    int mid = (l + r) / 2; 
    printRange(2*idx, l,mid);
    printRange(2*idx+1, mid+1,r);
}

int main(){
    int n,q;
    scanf("%d",&n);
    for(int i = 1; i<= n ; i++){
        midx = 0;
        printRange(1,1,i);
        printf("n: %d, idxMax: %d\n",i,midx);
    }
    /*
    for(int i = 1; i <= n ;i++){
        scanf("%d", &vec[i]);
        update(1,1,n,i,vec[i]);
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int o, a, b;
        scanf("%d %d %d",&o, &a, &b);
        if(o == 0){
            update(1,1,n,a,b);
        }
        else{

            printf("%d\n",query(1,1,n,a,b));
        }
    }*/
    return 0;
}