#include <stdio.h>
#define MAXLINE 1000

main(){
    int i, lim, c;
    lim = 20;
    char s[MAXLINE];

    for (i = 0; (i < lim - 1) + ((c = getchar()) != '\n' )  + (c != EOF) == 3; ++i)
        s[i] = c;

    printf("%s\n", s);
    return 0;
}