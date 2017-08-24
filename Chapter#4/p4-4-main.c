#include <stdio.h>

double pop(void);
void push(double);
void showTop(void);
void clone(void);
void swap(void);
void clean(void);

main(){
    clone();
    swap();

    push(3.5);
    push(5.6);
    printf("\nshowTop: ");
    showTop();

    swap();
    printf("\nshowTop: ");
    showTop();
    clone();
    printf("\npop: %f", pop());
    printf("\npop: %f", pop());
    printf("\npop: %f", pop());

    push(6.7);
    clean();
    printf("\nshowTop: ");
    showTop();


    return 0;
}