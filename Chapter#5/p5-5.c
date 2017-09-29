#include <stdio.h>

void strcat(char *s,char *t );

main(){
    char v[50];
    char s[] = "adding";

    v[0] = 'H';
    v[1] = 'i';
    v[2] = '\0';

    strcat(v, s);
    printf("Result = %s", v);
    return 0;
}

void strncat(char *s,char *t, int n){
    while(*s++)
        ;
    s--;
    while(*s++ = *t++ && n--)
        ;
}

void strncpy(char *s,char *t, int n){
    while(*s++ = *t++ && n--)
        ;
}