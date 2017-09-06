#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int getop();
double pop(void);
void push(double);

main(){
    char s[] = "Test str";
    int c;

    ungetch(EOF);
    ungets(s);
    

    while ( (c = getch()) != EOF){
        putchar(c);
    }

    return 0;
}