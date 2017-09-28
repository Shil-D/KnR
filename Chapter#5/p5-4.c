#include <stdio.h>

main(){
    char v[50];
    char s = "adding";

    v[0] = 'n';
    v[1] = 'g';
    v[2] = '\0';

    strcat(v, s);
    printf("Result = %s", v);
    return 0;
}

int strend(char *s,char *t ){
    char *sstart = s;
    char *tstart = t;

    while(*s++)
        ;
    while(*t++)
        ;
    
    for ( ; t >= tstart && s >= sstart; t--, s--)
        if (*t != *s)
            return 0;
    
    return 1;
}