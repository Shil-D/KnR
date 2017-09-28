#include <stdio.h>


main(){
    char v[50];
    char s[] = "adding";

    v[0] = 'i';
    v[1] = 'n';
    v[2] = 'g';
    v[3] = '\0';

    
    printf("Result = %d\n", strend(s, v));
    return 0;
}

int strend(char *s,char *t ){
    char *sstart = s;
    char *tstart = t;

    while(*s++)
        ;
    while(*t++)
        ;
    t--;
    s--;
    for ( ; t >= tstart && s >= sstart; t--, s--)
        if (*t != *s)
            return 0;


    if (t > tstart)
        return 0;
    else return 1;
}