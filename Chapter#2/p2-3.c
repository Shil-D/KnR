#include <stdio.h>

long htoi(char s[]){
    int n = 0;
    int i = 0;
    int p;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) i = 2;

    for (; s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'f' || s[i] >= 'A' && s[i] <= 'F'; i++){
        if (s[i] >= 'a') p = 10 + s[i] - 'a';
        else if (s[i] >= 'A') p = 10 + s[i] - 'A';
        else p = s[i] - '0';
        n = n * 16 +p;
    }
    return n;
}
main(){
    printf("%ld\n", htoi("0X5397FB1"));
    return 0;
}