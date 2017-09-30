#include <stdio.h>

void strncat(char *s,char *t, int n);
void strncpy(char *s,char *t, int n);

main(){
    char v[50];
    char s[] = "adding";

    v[0] = 'H';
    v[1] = 'i';
    v[2] = '\0';

    strncat(v, s, 3);
    printf("Result = %s\n", v);
    strncpy(v, s, 4);
    printf("Result = %s\n", v);
    return 0;
}

void strncat(char *s,char *t, int n){
    while(*s++)
        ;
    s--;
    while((*s++ = *t++) && --n)
        ;
    *s = '\0';
}

void strncpy(char *s,char *t, int n){
    while((*s++ = *t++) && --n)
        ;
    *s = '\0';
}