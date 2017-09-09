#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]){
    int len;
    if (n < 0){
        s[0] = '-';
        s[1] = '\0';
        n = -n;
    }

    if ( n / 10){
        itoa(n / 10, s);
    }
    len = strlen(s);
    s[len] = n % 10 + '0';
    s[len + 1] = '\0';
}

main (){
    char s[10];

    itoa(-345, s);
    printf("s = %s\n", s);
}