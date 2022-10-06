#include <stdio.h>

char s[4];

void genWord(int i){
    for(int j = 0; j < 3; j++){

        s[2-j] = (i%26) + 'a';
        i/=26;
    }

}

int main(){
    s[3] = '\0';
    int n, m;
    scanf("%d %d", &n, &m);
    if(n < m/2) n = m/2;
    int c = 0;
    for(int i = 0 ; i < n; i++){
        genWord(i);
        printf("%s ", s);
    }
    printf("\n");
}