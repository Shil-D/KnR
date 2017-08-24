#include <stdio.h>
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void showTop(void){
    if (sp > 0)
        printf("%f", val[sp-1]);
    else {
        printf("error: stack empty\n");
    }
}

void clone(void){
    double e;
    if (sp > 0){
        e = pop();
        push(e);
        push(e);
    }
    else 
        printf("error: stack empty\n");
}

void swap(void){
    double e1, e2;
    if (sp > 1){
        e1 = pop();
        e2 = pop();
        push(e1);
        push(e2);
    }
    else 
        printf("error: not enough elements\n");
}

void clean(void){
    sp = 0;
}