#include <stdio.h>

void squeeze(char s1[], char s2[]);

main(){
    char s1[] = "This is test string";
    char s2[] = "tes";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[]){
    int i,j,k,put;

    for( i = j = 0; s1[i] != '\0'; i++){
        put = 1;
        for (k = 0; s2[k] != '\0'; k++){
            if (s1[i] == s2[k]){
                put = 0;
            }
        }
        if (put) s1[j++] = s1[i];
    }
    s1[j] = '\0';
}