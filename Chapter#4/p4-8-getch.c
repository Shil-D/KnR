#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

int buf;
int flag = 0;

int getch(void){
    if (flag == 1) {
        flag = 0;
        return buf;
    }
    else return getchar();
}

void ungetch(int c){
    flag = 1;
    buf = c;
}

void ungets(char s[]){
    int len = strlen(s);
    int i;
    for (i = len-1; i >= 0; i--)
        ungetch(s[i]);
}