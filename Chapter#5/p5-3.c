#include <stdio.h>

main(){
    char v[50];
    char s = "adding";

    v[0] = 'H';
    v[1] = 'i';
    v[2] = '\0';

    strcat(v, s);
    printf("Result = %s", s);
    return 0;
}

void strcat(char *s,char *t ){
    while(*s++)
        ;
    i -= 2;
    while(*s++ = *t++)
        ;
}