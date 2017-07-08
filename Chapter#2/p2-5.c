#include <stdio.h>

int any(char s1[], char s2[]);

main(){
    char s1[] = "This is test string";
    char s2[] = "qw";
    printf("%d\n", any(s1, s2));
    return 0;
}

int any(char s1[], char s2[]){
    int i,k;

    for( i = 0; s1[i] != '\0'; i++)
        for (k = 0; s2[k] != '\0'; k++)
            if (s1[i] == s2[k])
                return i;
    return -1;
}