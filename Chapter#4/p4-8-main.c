#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int getop();
double pop(void);
void push(double);

main(){
    char b = 'B';
    int c;

    
    putchar(getch());
    ungetch(b);
    putchar(getch());

    return 0;
}