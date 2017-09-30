#include <stdio.h>
#define MAX 1000

int getline(char* s, int lim);
void reverse(char* s);

main(){
    char line[MAX];

    while (getline(line, MAX) > 0){
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}


int getline(char* s, int lim){
	int c,i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		*s++ = c;
	if (c == '\n'){
        *s++ = c;
        i++;
    }
	*s = '\0';
	return i;
}

void reverse(char* s){
    char* f = s;
	char tmp;
    for (; *s != '\n'; s++);
	for (; s > f ; --s, ++f){
		tmp = *s;
		*s = *f;
		*f = tmp;
	}
}