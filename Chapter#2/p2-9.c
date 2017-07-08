#include <stdio.h>
int bitcount(unsigned x);

main(){
    unsigned x = 0120;
    unsigned y = 051;
    printf("%d\n", bitcount(x));
    return 0;
}

int bitcount(unsigned x){
    int b = 0;
    while (x){
        b++;
        x &= (x-1);
    }
    return b;
}