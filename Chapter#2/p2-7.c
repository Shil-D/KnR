#include <stdio.h>
unsigned invert(unsigned x, int p, int n);

main(){
    int x = 0114;
    int y = 051;
    printf("%u\n", invert(x, 4, 2));
    return 0;
}

unsigned invert(unsigned x, int p, int n){
    return x ^ ((~((~0U) << n)) << (p+1-n));
}