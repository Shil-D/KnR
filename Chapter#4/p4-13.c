#include <stdio.h>
#include <string.h>


void reverse(char s[], int first, int last){
    int tmp;
    if (last > first){
        tmp = s[first];
        s[first] = s[last];
        s[last] = tmp;
        reverse (s, first + 1, last - 1);
    }
}

main (){
    char s[] = "Kaptetka";

    reverse(s, 0, strlen(s)-1);
    printf("s = %s\n", s);
}