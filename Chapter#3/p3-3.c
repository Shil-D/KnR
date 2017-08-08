#include <stdio.h>

int expand(char s1[], char s2[]);

main(){
    char t[] = "-ba-d-sz-";
    char s[200];

    
    printf("Text: %s\n", t);
    expand(t,s);
    printf("Expand Text: %s\n", s);

    return 0;
}

int expand(char s1[], char s2[]){
    int i,j;
    char c;
    i=j=0;
    while (s1[i] != '\0'){
        if (s1[i] == '-' && i>0 && s1[i+1] != '\0'){
            for (c = s1[i-1] + 1; c < s1[i+1]; c++)
                s2[j++] = c;
            i++;
        }
        else s2[j++] = s1[i++];
    }
    s2[j] = '\0';
}