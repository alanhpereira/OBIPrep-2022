#include <stdio.h>

int preco(int i){
    if(i <= 17){
        return 15;
    }
    else if(i < 60){
        return 30;
    }
    return 20;
}

int main(){
    int i1, i2;
    scanf("%d%d",&i1,&i2);
    printf("%d\n",preco(i1)+preco(i2));
}