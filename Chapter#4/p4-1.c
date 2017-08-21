#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
int strindex(char source[], char search[]);
char pattern[] = "tty";

main(){
    int ind;
    char source[] = "Pretty woman walking towards gretty man";
    
    ind = strindex(source, pattern);
    printf("Index = %d\n", ind);
}

int getline(char s[], int lim){
	int c,i;
	while(--lim > 0 && (c=getchar())!=EOF && c!='\n')
		s[i++] = c;
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int strindex (char s[], char t[]){
    int i, j, k, last;

    last = -1;
    for ( i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if ( k > 0 && t[k] == '\0')
            last = i;
    }
    return last;
}