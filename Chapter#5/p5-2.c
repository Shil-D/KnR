#include <stdio.h>
#include <ctype.h>

int getch(void);
int ungetch(int);

int getfloat(float *pn){
    int c, sign;
    float a,b;

    while(isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){
        c = getch();
        if (!isdigit(c)){
            ungetch(c);
            return 0;
        }
    }
    
    for (*pn = 0; isdigit(c) ; c = getch())
        *pn = 10 * *pn + (c - '0');

    if (c == '.'){
        c = getch();
        for (a = 0.0, b = 1 ; isdigit(c) ; c = getch()){
            a = 10 * a + (c - '0');
            b *= 10;
        }
        *pn += a/b;
    }
    
    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}

main(){
    float t = 0;
    int res = getfloat(&t);
    printf("%d, %f\n", res, t);
    return 0;
}