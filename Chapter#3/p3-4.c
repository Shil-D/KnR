#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

main(){
    int n = -4235;
    char s[20];
    
    printf("N = %d\n", n);
    itoa(n,s);
    printf("Str N = %s\n", s);

    return 0;
}

void itoa(int n, char s[]){
    int i;
    unsigned int n2;
    
    if (n < 0) n2 = -n;
    else n2 = n;
    i=0;
    do{
        s[i++] = n2 % 10 + '0';
    } while ((n2 /= 10) > 0);
    if ( n < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void reverse(char s[]){
    int c,i,j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}