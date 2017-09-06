#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define MAXOP 100
#define NUMBER '0'
#define N_VARS 26

int getop();
double pop(void);
void push(double);

main(){
    int type;
    double op2;
    char s[MAXOP];
    double vars[N_VARS];
    int i;
    int alpha;

    for (i = 0; i < N_VARS; i++){
        vars[i] = 0;
    }
    alpha = N_VARS + 1;

    while (( type = getop(s)) != EOF){
        if (isupper(type)){
            alpha = type - 'A';
            push(vars[alpha]);
        }
        else {
            switch(type){
                case NUMBER:
                    push(atof(s));
                    break;
                case '=':
                    if (alpha != N_VARS + 1){
                        pop();
                        clone();
                        vars[alpha] = pop();
                    }
                    else
                        printf ("No such variable\n");
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case 's':
                    push(sin(pop()));
                    break;
                case 'e':
                    push(exp(pop()));
                    break;
                case 'p':
                    op2 = pop();
                    push(pow(pop(), op2));
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else 
                        printf("error: zero divisor\n");
                    break;
                case '%':
                    op2 = pop();
                    if (op2 != 0.0)
                        push( (int)pop() % (int)op2);
                    else 
                        printf("error: zero divisor\n");
                    break;
                case '\n':
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
            alpha = N_VARS + 1;
        }
    }
    return 0;
}