#include <stdio.h>
#define MAX 512

char s[MAX];
int n;

int findMax(int i){
    int a, b;
    a = i, b =i;
    int t_impar = -1;
    while(a >= 0 && b < n){
        if(s[a] == s[b]){
            t_impar+=2;
            a--; b++;
        }
        else
            break;
    }
    a = i, b = i+1;
    int t_par = 0;
    while(a >= 0 && b < n){
        if(s[a] == s[b]){
            t_par+=2;
            a--; b++;
        }
        else
            break;
    }
    if( t_impar > t_par) return t_impar;
    return t_par;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %c", &s[i]);
    }
    int best = 0;
    for(int i = 0 ; i < n; i++){
        int ans = findMax(i);
        if(best < ans) best = ans;
    }
    printf("%d\n", best);
    return 0;
}