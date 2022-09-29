#include <stdio.h>
#define MAX 1123

char m[MAX][MAX];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c", &m[i][j]);
        }
    }
    int reg = 1;
    for(int i = 0; i < n ; i++){
        bool f1 = false, f2 = false;
        for(int j = 0; j < n; j++){
            char c = m[i][j];
            if(c=='*'){
                f1 = true;
                if(f2) reg = 0;
            }
            else{
                if(f1) f2=true;
            }
        }
    }
    for(int i = 0; i < n ; i++){
        bool f1 = false, f2 = false;
        for(int j = 0; j < n; j++){
            char c = m[j][i];
            if(c=='*'){
                f1 = true;
                if(f2) reg = 0;
            }
            else{
                if(f1) f2=true;
            }
        }
    }
    printf("%c\n", reg ? 'S' : 'N');
    return 0;
}
