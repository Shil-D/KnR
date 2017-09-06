#include <ctype.h>
#include <stdio.h>
#define NUMBER '0'
#define MAXLEN 1000

int getline(char s[], int lim){
	int c,i;
	while(--lim > 0 && (c=getchar())!=EOF && c!='\n')
		s[i++] = c;
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}
char buf[MAXLEN];
int len = -1;
int g = 0;

int getop(char s[]){
    int i, c, sign, t;

    if (len < 0) len = getline(buf, MAXLEN);
    if (len == 0) return EOF;
    
    while ((s[0] = c = buf[g++]) == ' ' || c == '\t')
            ;

    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-'){
            if (c == '\n'){
            g = 0;
            len = -1;
        }
        return c;
    }
    
    if (c == '-' ){
        t = buf[g];

        if (!isdigit(t) && t != '.')
            return c;
    }
    i = 0;
    if (isdigit(c) || c == '-')
        while (isdigit(s[++i] = c = buf[g++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = buf[g++]))
            ;
    s[i] = '\0';

    if (c != EOF)
        g--;
    return NUMBER;
}

