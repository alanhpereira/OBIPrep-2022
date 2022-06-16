#include <stdio.h>

int pontos(char f, char n, char nd){
    int p = 0;
    if ( n == nd)
        p += 4;
    if(f == 'A')
        return 10 + p;
    if(f == 'J')
        return 11 + p;
    if(f == 'Q')
        return 12 + p;
    if(f == 'K')
        return 13 + p;
    return 0;
}

int main(){
    char n, nd, f;
    int pl = 0, pe = 0;
    scanf(" %c %c", &f, &nd);
    for(int i = 0 ; i < 3; i++){
        scanf(" %c %c", &f, &n);
        pl += pontos(f, n, nd);
    }
    for(int i = 0 ; i < 3; i++){
        scanf(" %c %c", &f, &n);
        pe += pontos(f, n, nd);
    }
    if(pl > pe){
        printf("Luana\n");
    }
    else if(pe > pl){
        printf("Edu\n");
    }
    else{
        printf("empate\n");
    }
    return 0;
}