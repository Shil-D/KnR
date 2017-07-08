#include <stdio.h>
int lower(int);

main(){
    unsigned x = 'B';
    unsigned y = 'c';
    printf("%c %c\n", lower(x), lower(y));
    return 0;
}

int lower(int x){
    return (x >= 'A' && x <= 'Z') ? x + 'a' - 'A' : x;
}