#include <ctype.h>
#include <stdio.h>
#define NUMBER '0'

int getop(char s[]){
    int i, c, sign, t;
    static int buf = EOF;
    i=0;

    if (buf != EOF) c = buf;
    else c = getchar();

    while ((s[0] = c ) == ' ' || c == '\t')
        s[0] = c = getchar();

    buf = EOF;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    
    if (c == '-' ){
        t = getchar();
        if (!isdigit(t) && t != '.'){
            buf = t;
            return c;
        }
        else {
            s[++i] = t;
            c = t;
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';

    if (c != EOF)
        buf = c;
    return NUMBER;
}