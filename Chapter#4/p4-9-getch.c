#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]){
    int len = strlen(s);
    int i;
    for (i = len-1; i >= 0; i--)
        ungetch(s[i]);
}