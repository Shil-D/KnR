#include <stdio.h>
unsigned rightrot(unsigned x, int n);

main(){
    unsigned x = ~0114;
    unsigned y = 051;
    printf("%u\n", rightrot(x, 2));
    return 0;
}

unsigned rightrot(unsigned x, int n){
    int i;
    unsigned res = x;
    for (i = 0; i < n; i++){
        if (res &  1)
            res = res >> 1 | ~(~0U >> 1);
        else res = res >> 1;
    }
    return res;
}