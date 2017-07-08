#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y);

main(){
    int x = 032;
    int y = 051;
    printf("%u\n", setbits(x, 3, 2, y));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
    return (x & ~((~((~0) << n)) << (p+1-n))) | ((~((~0) << n) & y) << (p+1-n));
}