#include <stdio.h>

#define swap(x,y) {x = x + y; y = x - y; x = x - y;}

main (){
    float a = 4.6, b = 3.2;

    swap(a,b)

    printf("a = %f, b = %f\n", a, b);
}